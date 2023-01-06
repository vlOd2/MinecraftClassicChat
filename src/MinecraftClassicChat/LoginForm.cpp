#include "stdafx.h"
#include "LoginForm.h"

namespace MinecraftClassicChat 
{
	LoginForm::LoginForm()
	{
		InitializeComponent();
	}

	Void LoginForm::btnLogin_Click(Object^ sender, EventArgs^ e)
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

		ClientConnect(serverIP, serverPort, username, mppass);
		Close();
	}

	Void LoginForm::btnImportURL_Click(Object^ sender, EventArgs^ e)
	{
		ImportURLForm^ importURLForm = gcnew ImportURLForm();
		importURLForm->URLImport += gcnew URLImportDelegate(this, &LoginForm::ImportURLForm_URLImport);
		importURLForm->ShowDialog();
		delete importURLForm;
	}

	Void LoginForm::ImportURLForm_URLImport(String^ url)
	{
		array<String^>^ splittedURL = url->Split('/');
		String^ server = splittedURL[2];
		String^ username = splittedURL[3];
		String^ mppass = splittedURL[4];
		txtServer->Text = server;
		txtUsername->Text = username;
		txtMPPass->Text = mppass;
	}
}