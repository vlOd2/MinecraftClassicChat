#pragma once

#include "LoginForm.h"

#define byte unsigned char

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Net::Sockets;
using namespace System::Threading;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace System::IO;

namespace MinecraftClassicChat 
{
	public ref class MainForm : public System::Windows::Forms::Form
	{
		static String^ ApplicationName = "MCC v1.0";

	public:
		MainForm();
	protected:
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
			if (loginForm)
			{
				delete loginForm;
			}
		}
	protected: System::Windows::Forms::RichTextBox^  txtChat;
	protected: System::Windows::Forms::TextBox^  txtInput;
	protected: System::Windows::Forms::Button^  btnSend;






	protected: System::Windows::Forms::Button^  btnConnect;
	protected: System::Windows::Forms::Button^  btnDisconnect;
	protected: System::Windows::Forms::Button^  btnClearChat;
	private: System::Windows::Forms::Button^  btnLogin;


	private: System::ComponentModel::IContainer^  components;
	protected: 

	protected: 

	protected: 

#pragma region Windows Form Designer generated code
	private:


		void InitializeComponent(void)
		{
			this->txtChat = (gcnew System::Windows::Forms::RichTextBox());
			this->txtInput = (gcnew System::Windows::Forms::TextBox());
			this->btnSend = (gcnew System::Windows::Forms::Button());
			this->btnConnect = (gcnew System::Windows::Forms::Button());
			this->btnDisconnect = (gcnew System::Windows::Forms::Button());
			this->btnClearChat = (gcnew System::Windows::Forms::Button());
			this->btnLogin = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// txtChat
			// 
			this->txtChat->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->txtChat->BackColor = System::Drawing::Color::DimGray;
			this->txtChat->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtChat->ForeColor = System::Drawing::Color::White;
			this->txtChat->Location = System::Drawing::Point(3, 28);
			this->txtChat->Name = L"txtChat";
			this->txtChat->ReadOnly = true;
			this->txtChat->Size = System::Drawing::Size(591, 267);
			this->txtChat->TabIndex = 0;
			this->txtChat->Text = L"";
			// 
			// txtInput
			// 
			this->txtInput->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->txtInput->BackColor = System::Drawing::Color::DimGray;
			this->txtInput->ForeColor = System::Drawing::Color::White;
			this->txtInput->Location = System::Drawing::Point(3, 303);
			this->txtInput->MaxLength = 64;
			this->txtInput->Name = L"txtInput";
			this->txtInput->Size = System::Drawing::Size(510, 20);
			this->txtInput->TabIndex = 1;
			this->txtInput->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::txtInput_KeyPress);
			// 
			// btnSend
			// 
			this->btnSend->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->btnSend->BackColor = System::Drawing::Color::DimGray;
			this->btnSend->Enabled = false;
			this->btnSend->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->btnSend->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSend->ForeColor = System::Drawing::Color::White;
			this->btnSend->Location = System::Drawing::Point(518, 302);
			this->btnSend->Name = L"btnSend";
			this->btnSend->Size = System::Drawing::Size(75, 23);
			this->btnSend->TabIndex = 2;
			this->btnSend->Text = L"Send";
			this->btnSend->UseVisualStyleBackColor = false;
			// 
			// btnConnect
			// 
			this->btnConnect->Location = System::Drawing::Point(0, 0);
			this->btnConnect->Name = L"btnConnect";
			this->btnConnect->Size = System::Drawing::Size(75, 23);
			this->btnConnect->TabIndex = 0;
			// 
			// btnDisconnect
			// 
			this->btnDisconnect->BackColor = System::Drawing::Color::DimGray;
			this->btnDisconnect->Enabled = false;
			this->btnDisconnect->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->btnDisconnect->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnDisconnect->ForeColor = System::Drawing::Color::White;
			this->btnDisconnect->Location = System::Drawing::Point(84, 2);
			this->btnDisconnect->Name = L"btnDisconnect";
			this->btnDisconnect->Size = System::Drawing::Size(75, 23);
			this->btnDisconnect->TabIndex = 10;
			this->btnDisconnect->Text = L"Disconnect";
			this->btnDisconnect->UseVisualStyleBackColor = false;
			// 
			// btnClearChat
			// 
			this->btnClearChat->BackColor = System::Drawing::Color::DimGray;
			this->btnClearChat->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->btnClearChat->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnClearChat->ForeColor = System::Drawing::Color::White;
			this->btnClearChat->Location = System::Drawing::Point(165, 2);
			this->btnClearChat->Name = L"btnClearChat";
			this->btnClearChat->Size = System::Drawing::Size(75, 23);
			this->btnClearChat->TabIndex = 11;
			this->btnClearChat->Text = L"Clear Chat";
			this->btnClearChat->UseVisualStyleBackColor = false;
			// 
			// btnLogin
			// 
			this->btnLogin->BackColor = System::Drawing::Color::DimGray;
			this->btnLogin->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->btnLogin->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnLogin->ForeColor = System::Drawing::Color::White;
			this->btnLogin->Location = System::Drawing::Point(3, 2);
			this->btnLogin->Name = L"btnLogin";
			this->btnLogin->Size = System::Drawing::Size(75, 23);
			this->btnLogin->TabIndex = 12;
			this->btnLogin->Text = L"Login";
			this->btnLogin->UseVisualStyleBackColor = false;
			this->btnLogin->Click += gcnew System::EventHandler(this, &MainForm::btnLogin_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DimGray;
			this->ClientSize = System::Drawing::Size(596, 333);
			this->Controls->Add(this->btnLogin);
			this->Controls->Add(this->btnClearChat);
			this->Controls->Add(this->btnDisconnect);
			this->Controls->Add(this->btnSend);
			this->Controls->Add(this->txtInput);
			this->Controls->Add(this->txtChat);
			this->MinimumSize = System::Drawing::Size(250, 113);
			this->Name = L"MainForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: 
		Dictionary<int, int>^ packetSizeMap;
		Dictionary<wchar_t, int>^ textColors;
		LoginForm^ loginForm;
		bool connected;
		bool serverSupportsCPE;
		bool supportsLongerMessages;
		String^ cpeClientName;
		String^ serverIP;
		array<String^>^ messagesToSend;
		int serverPort;
		short extCount;
		short recievedExts;
		String^ serverSoftwareName;
		Dictionary<String^, int>^ serverCPEExtensions;
		byte lastLevelPercentange;
		TcpClient^ tcpClient;
		NetworkStream^ tcpStream;
		Thread^ tcpThread;

		System::Void txtInput_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
		{
			if (e->KeyChar == '\r')
			{
				btnSend->PerformClick();
				e->Handled = true;
			}
		}
		
		void Log(String^ header, String^ body);
		void Connect(String^ ip, int port, String^ username, String^ mppass);
		void Disconnect();
		void tcpThread_Func();
		void SendChatMessage(String^ message);
		void SendCpeInfo();
		void SendExtInfo(String^ extName, int^ extVer);
		void ReceivedPacket(byte id, array<byte>^ data);
		void RegisterExtension(String^ extName, int^ extVer);
		void ShowLoginForm();
		Void btnSend_Click(Object^ sender, EventArgs^ e);
		Void btnLogin_Click(Object^ sender, EventArgs^ e);
		Void btnDisconnect_Click(Object^ sender, EventArgs^ e);
		Void btnClearChat_Click(Object^ sender, EventArgs^ e);
		Void MainForm_FormClosing(Object^ sender, FormClosingEventArgs^ e);
	};
}