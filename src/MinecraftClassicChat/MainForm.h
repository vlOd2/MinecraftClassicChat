#pragma once

#include "MainFormBase.h"
#define byte unsigned char

namespace MinecraftClassicChat 
{
	using namespace System;
	using namespace System::Windows::Forms;
	using namespace System::Net::Sockets;
	using namespace System::Threading;
	using namespace System::Text;
	using namespace System::Collections::Generic;
	using namespace System::IO;

	public ref class MainForm : public MainFormBase
	{
	private:
		Dictionary<int, int>^ packetSizeMap;
		bool connected;
		String^ serverIP;
		int serverPort;
		TcpClient^ tcpClient;
		NetworkStream^ tcpStream;
		Thread^ tcpThread;

	public:
		MainForm() : MainFormBase()
		{
			packetSizeMap = gcnew Dictionary<int, int>();
			packetSizeMap->Add(0x00, 130);
			packetSizeMap->Add(0x01, 0);
			packetSizeMap->Add(0x02, 0);
			packetSizeMap->Add(0x03, 1027);
			packetSizeMap->Add(0x04, 6);
			packetSizeMap->Add(0x06, 7);
			packetSizeMap->Add(0x07, 73);
			packetSizeMap->Add(0x08, 9);
			packetSizeMap->Add(0x09, 6);
			packetSizeMap->Add(0x0a, 4);
			packetSizeMap->Add(0x0b, 3);
			packetSizeMap->Add(0x0c, 1);
			packetSizeMap->Add(0x0d, 65);
			packetSizeMap->Add(0x0e, 64);
			packetSizeMap->Add(0x0f, 1);

			btnSend->Click += gcnew EventHandler(this, &MainForm::btnSend_Click);
			btnConnect->Click += gcnew EventHandler(this, &MainForm::btnConnect_Click);
			btnDisconnect->Click += gcnew EventHandler(this, &MainForm::btnDisconnect_Click);
			btnClearChat->Click += gcnew EventHandler(this, &MainForm::btnClearChat_Click);
			FormClosing += gcnew FormClosingEventHandler(this, &MainForm::MainForm_FormClosing);
		}

	private:
		List<byte>^ convertByteArray(array<byte>^ arr)
		{
			List<byte>^ lst = gcnew List<byte>();
			
			for (int entryIndex = 0; entryIndex < arr->Length; entryIndex++)
			{
				lst->Add(arr[entryIndex]);
			}

			return lst;
		}

		delegate void LogDelegate(String^, String^);
		void Log(String^ header, String^ body)
		{
			txtChat->Text += "[" + header + "] " + body + "\n";
			txtChat->SelectionStart = txtChat->Text->Length;
			txtChat->ScrollToCaret();
		}

		void Connect(String^ ip, int port, String^ username, String^ mppass)
		{
			try
			{
				serverIP = ip;
				serverPort = port;
				tcpClient = gcnew TcpClient();

				btnConnect->Enabled = false;
				btnDisconnect->Enabled = false;
				btnSend->Enabled = false;

				Log("Connection", "Connecting to " + ip + ":" + port);
				tcpClient->Connect(ip, port);
				tcpThread = gcnew Thread(gcnew ThreadStart(this, &MainForm::tcpThread_Func));
				tcpStream = tcpClient->GetStream();

				btnConnect->Enabled = false;
				btnDisconnect->Enabled = true;
				btnSend->Enabled = true;

				connected = true;
				tcpThread->Start();
				Log("Connection", "Connected to " + ip + ":" + port);

				// Login packet
				Log("Connection", "Authenticating as " + username + " (MPPass: " + mppass + ")");
				username = username->PadRight(64, ' ');
				mppass = mppass->PadRight(64, ' ');
				List<byte>^ packet = gcnew List<byte>();
				packet->AddRange(convertByteArray(gcnew array<byte> { 0x00, 0x07 }));
				packet->AddRange(convertByteArray(Encoding::ASCII->GetBytes(username)));
				packet->AddRange(convertByteArray(Encoding::ASCII->GetBytes(mppass)));
				packet->AddRange(convertByteArray(gcnew array<byte> { 0x00 }));
				tcpStream->Write(packet->ToArray(), 0, packet->ToArray()->Length);
			}
			catch (Exception^ ex)
			{
				connected = true;
				Disconnect();

				Log("Connection", "Unable to connect: " + ex->Message);
				MessageBox::Show("Unable to connect: " + ex->Message, "Connection Error", 
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

		delegate void DisconnectDelegate();
		void Disconnect()
		{
			if (!connected) return;
			connected = false;
			btnConnect->Enabled = true;
			btnDisconnect->Enabled = false;
			btnSend->Enabled = false;
			serverIP = nullptr;
			serverPort = 0;
			delete tcpClient;
			delete tcpStream;
			delete tcpThread;
			Log("Connection", "Disconnected");
		}

		void tcpThread_Func()
		{
			while (connected)
			{
				try
				{
					if (tcpStream->DataAvailable)
					{
						int packetID = tcpStream->ReadByte();
						if (packetSizeMap->ContainsKey(packetID))
						{
							int packetSize = packetSizeMap[packetID];
							array<byte>^ buffer = gcnew array<byte>(packetSize);

							int readBytesTotal = 0;
							int readBytes = readBytesTotal = tcpStream->Read(buffer, 0, packetSize);

							while (readBytesTotal < packetSize)
							{
								readBytes = tcpStream->Read(buffer, readBytes, packetSize - readBytes);
								readBytesTotal += readBytes;
							}

							this->Invoke(gcnew ReceivedPacketDelegate(this, &MainForm::ReceivedPacket), (byte)packetID, buffer);
						}
						else 
						{
							this->Invoke(gcnew LogDelegate(this, &MainForm::Log), 
								"Connection", "Received invalid packet " + packetID + "! Disconnecting...");
							throw gcnew SocketException();
						}
					} 
					else 
					{
						if (connected && tcpClient->Client->Poll(1, SelectMode::SelectRead))
						{
							array<byte>^ buffer = gcnew array<byte>(1);
							if (connected && tcpClient->Client->Receive(buffer, 1, SocketFlags::Peek) == 0)
							{
								throw gcnew SocketException();
							}
						}
					}
				}
				catch (Exception^ ex)
				{
					if (IsDisposed) return;
					this->Invoke(gcnew DisconnectDelegate(this, &MainForm::Disconnect));

					if (!(ex->GetType() == SocketException::typeid || 
						ex->GetType() == IOException::typeid))
					{
						this->Invoke(gcnew LogDelegate(this, &MainForm::Log), 
							"Error", "Something went wrong: " + ex->Message);
						MessageBox::Show("Something went wrong: " + ex->Message, "Error", 
							MessageBoxButtons::OK, MessageBoxIcon::Error);
					}
				}
			}
		}

		void SendChatMessage(String^ message)
		{
			if (!connected) return;
			message = message->PadRight(64, ' ')->Substring(0, 64);
			List<byte>^ packet = gcnew List<byte>();
			packet->AddRange(convertByteArray(gcnew array<byte> { 0x0d, 0xFF }));
			packet->AddRange(convertByteArray(Encoding::ASCII->GetBytes(message)));
			tcpStream->Write(packet->ToArray(), 0, packet->ToArray()->Length);
		}

		delegate void ReceivedPacketDelegate(byte, array<byte>^);
		void ReceivedPacket(byte id, array<byte>^ data)
		{
			//Log("Connection", "Received packet " + id + ": " + BitConverter::ToString(data));

			// 0x00: Login packet
			// 0x0d: Chat packet
			// 0x0e: Kick packet
			if (id == 0x00)
			{
				array<byte>^ serverNameRaw = gcnew array<byte>(64);
				array<byte>^ serverMOTDRaw = gcnew array<byte>(64);
				Array::Copy(data, 1, serverNameRaw, 0, 64);
				Array::Copy(data, 65, serverMOTDRaw, 0, 64);

				String^ serverName = Encoding::UTF8->GetString(serverNameRaw);
				String^ serverMOTD = Encoding::UTF8->GetString(serverMOTDRaw);
				Log("Connection", "Server name: " + serverName);
				Log("Connection", "Server MOTD: " + serverMOTD);
				MessageBox::Show(serverMOTD, serverName,
					MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			else if (id == 0x0d)
			{
				array<byte>^ chatMessageRaw = gcnew array<byte>(64);
				Array::Copy(data, 1, chatMessageRaw, 0, 64);
				String^ chatMessage = Encoding::UTF8->GetString(chatMessageRaw);
				Log("Chat", chatMessage);
			}
			else if (id == 0x0e)
			{
				Disconnect();
				String^ kickReason = Encoding::UTF8->GetString(data);
				Log("Connection", "You have been kicked: " + kickReason);
				MessageBox::Show(kickReason, "You have been kicked",
					MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}

		Void btnSend_Click(Object^ sender, EventArgs^ e)
		{
			String^ message = txtInput->Text;
			txtInput->Text = nullptr;
			if (String::IsNullOrEmpty(message))
			{
				MessageBox::Show("The specified message is invalid!", "Error", 
					MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			SendChatMessage(message);
		}

		Void btnConnect_Click(Object^ sender, EventArgs^ e)
		{
			String^ serverIP = txtServer->Text;
			String^ username = txtUsername->Text;
			String^ mppass = txtMPPass->Text;
			int serverPort = 25565;
			if (serverIP->Contains(":"))
			{
				if (serverIP->Split(':')->Length != 2 || 
					!int::TryParse(serverIP->Split(':')[1], serverPort) || 
					serverPort < 1 || 
					serverPort > 65535)
				{
					MessageBox::Show("The specified server port is invalid!", "Error", 
						MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}
				serverIP = serverIP->Split(':')[0];
			}

			if (String::IsNullOrEmpty(serverIP))
			{
				MessageBox::Show("The specified server IP is invalid!", "Error", 
					MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			if (String::IsNullOrEmpty(username))
			{
				MessageBox::Show("The specified username is invalid!", "Error", 
					MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			Connect(serverIP, serverPort, username, mppass);
		}

		Void btnDisconnect_Click(Object^ sender, EventArgs^ e)
		{
			Disconnect();
		}

		Void btnClearChat_Click(Object^ sender, EventArgs^ e)
		{
			txtChat->Text = nullptr;
		}

		Void MainForm_FormClosing(Object^ sender, FormClosingEventArgs^ e)
		{
			Disconnect();
		}
	};
}