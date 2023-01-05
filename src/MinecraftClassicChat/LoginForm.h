#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Threading;

#include "ImportURLForm.h"

namespace MinecraftClassicChat 
{
	public delegate void ClientConnectDelegate(String^, int, String^, String^);

	public ref class LoginForm : public System::Windows::Forms::Form
	{
	public:
		LoginForm();

	protected:
		~LoginForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnLogin;
	private: System::Windows::Forms::Button^  btnImportURL;
	protected: 

	protected: 

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  txtUsername;
	private: System::Windows::Forms::TextBox^  txtServer;


	private: System::Windows::Forms::TextBox^  txtMPPass;


#pragma region Windows Form Designer generated code
	private:
		System::ComponentModel::Container ^components;

		void InitializeComponent(void)
		{
			this->btnLogin = (gcnew System::Windows::Forms::Button());
			this->btnImportURL = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->txtUsername = (gcnew System::Windows::Forms::TextBox());
			this->txtServer = (gcnew System::Windows::Forms::TextBox());
			this->txtMPPass = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// btnLogin
			// 
			this->btnLogin->Location = System::Drawing::Point(172, 181);
			this->btnLogin->Name = L"btnLogin";
			this->btnLogin->Size = System::Drawing::Size(75, 23);
			this->btnLogin->TabIndex = 0;
			this->btnLogin->Text = L"Login";
			this->btnLogin->UseVisualStyleBackColor = true;
			this->btnLogin->Click += gcnew System::EventHandler(this, &LoginForm::btnLogin_Click);
			// 
			// btnImportURL
			// 
			this->btnImportURL->Location = System::Drawing::Point(91, 181);
			this->btnImportURL->Name = L"btnImportURL";
			this->btnImportURL->Size = System::Drawing::Size(75, 23);
			this->btnImportURL->TabIndex = 1;
			this->btnImportURL->Text = L"Import URL";
			this->btnImportURL->UseVisualStyleBackColor = true;
			this->btnImportURL->Click += gcnew System::EventHandler(this, &LoginForm::btnImportURL_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(2, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(245, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Please enter the requested information to proceed:\r\n";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(5, 37);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(58, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Username:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(5, 88);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(97, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"MPPass (Optional):";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(5, 139);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(88, 13);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Server (IP[:Port]):";
			// 
			// txtUsername
			// 
			this->txtUsername->Location = System::Drawing::Point(8, 53);
			this->txtUsername->Name = L"txtUsername";
			this->txtUsername->Size = System::Drawing::Size(239, 20);
			this->txtUsername->TabIndex = 6;
			// 
			// txtServer
			// 
			this->txtServer->Location = System::Drawing::Point(8, 155);
			this->txtServer->Name = L"txtServer";
			this->txtServer->Size = System::Drawing::Size(239, 20);
			this->txtServer->TabIndex = 7;
			// 
			// txtMPPass
			// 
			this->txtMPPass->Location = System::Drawing::Point(8, 106);
			this->txtMPPass->Name = L"txtMPPass";
			this->txtMPPass->Size = System::Drawing::Size(239, 20);
			this->txtMPPass->TabIndex = 8;
			this->txtMPPass->UseSystemPasswordChar = true;
			// 
			// LoginForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(259, 217);
			this->Controls->Add(this->txtMPPass);
			this->Controls->Add(this->txtServer);
			this->Controls->Add(this->txtUsername);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnImportURL);
			this->Controls->Add(this->btnLogin);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"LoginForm";
			this->ShowIcon = false;
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Login";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		
	public:
		event ClientConnectDelegate^ ClientConnect;
	private: 
		Void btnLogin_Click(Object^ sender, EventArgs^ e);
		Void btnImportURL_Click(Object^ sender, EventArgs^ e);
		Void ImportURLForm_URLImport(String^ url);
	};
}
