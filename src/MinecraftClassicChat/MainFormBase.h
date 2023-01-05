#pragma once

namespace MinecraftClassicChat 
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Net::Sockets;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class MainFormBase : public System::Windows::Forms::Form
	{
	public:
		MainFormBase(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainFormBase()
		{
			if (components)
			{
				delete components;
			}
		}
	protected: System::Windows::Forms::RichTextBox^  txtChat;

	protected: System::Windows::Forms::TextBox^  txtInput;
	protected: System::Windows::Forms::Button^  btnSend;
	protected: System::Windows::Forms::TextBox^  txtServer;

	protected: System::Windows::Forms::TextBox^  txtUsername;
	protected: System::Windows::Forms::TextBox^  txtMPPass;
	protected: 

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	protected: System::Windows::Forms::Button^  btnConnect;

	protected: System::Windows::Forms::Button^  btnDisconnect;
	protected: System::Windows::Forms::Button^  btnClearChat;
	protected: 



	protected:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->txtChat = (gcnew System::Windows::Forms::RichTextBox());
			this->txtInput = (gcnew System::Windows::Forms::TextBox());
			this->btnSend = (gcnew System::Windows::Forms::Button());
			this->txtServer = (gcnew System::Windows::Forms::TextBox());
			this->txtUsername = (gcnew System::Windows::Forms::TextBox());
			this->txtMPPass = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->btnConnect = (gcnew System::Windows::Forms::Button());
			this->btnDisconnect = (gcnew System::Windows::Forms::Button());
			this->btnClearChat = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// txtChat
			// 
			this->txtChat->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->txtChat->BackColor = System::Drawing::Color::Black;
			this->txtChat->ForeColor = System::Drawing::Color::White;
			this->txtChat->Location = System::Drawing::Point(3, 28);
			this->txtChat->Name = L"txtChat";
			this->txtChat->ReadOnly = true;
			this->txtChat->Size = System::Drawing::Size(724, 300);
			this->txtChat->TabIndex = 0;
			this->txtChat->Text = L"";
			// 
			// txtInput
			// 
			this->txtInput->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->txtInput->Location = System::Drawing::Point(3, 336);
			this->txtInput->MaxLength = 64;
			this->txtInput->Name = L"txtInput";
			this->txtInput->Size = System::Drawing::Size(643, 20);
			this->txtInput->TabIndex = 1;
			this->txtInput->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainFormBase::txtInput_KeyPress);
			// 
			// btnSend
			// 
			this->btnSend->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->btnSend->Enabled = false;
			this->btnSend->Location = System::Drawing::Point(652, 333);
			this->btnSend->Name = L"btnSend";
			this->btnSend->Size = System::Drawing::Size(75, 23);
			this->btnSend->TabIndex = 2;
			this->btnSend->Text = L"Send";
			this->btnSend->UseVisualStyleBackColor = true;
			// 
			// txtServer
			// 
			this->txtServer->Location = System::Drawing::Point(53, 2);
			this->txtServer->Name = L"txtServer";
			this->txtServer->Size = System::Drawing::Size(100, 20);
			this->txtServer->TabIndex = 3;
			// 
			// txtUsername
			// 
			this->txtUsername->Location = System::Drawing::Point(223, 2);
			this->txtUsername->Name = L"txtUsername";
			this->txtUsername->Size = System::Drawing::Size(100, 20);
			this->txtUsername->TabIndex = 4;
			// 
			// txtMPPass
			// 
			this->txtMPPass->Location = System::Drawing::Point(384, 2);
			this->txtMPPass->Name = L"txtMPPass";
			this->txtMPPass->Size = System::Drawing::Size(100, 20);
			this->txtMPPass->TabIndex = 5;
			this->txtMPPass->UseSystemPasswordChar = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 5);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(41, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Server:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(159, 5);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(58, 13);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Username:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(329, 5);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(49, 13);
			this->label3->TabIndex = 8;
			this->label3->Text = L"MPPass:";
			// 
			// btnConnect
			// 
			this->btnConnect->Location = System::Drawing::Point(490, 2);
			this->btnConnect->Name = L"btnConnect";
			this->btnConnect->Size = System::Drawing::Size(75, 23);
			this->btnConnect->TabIndex = 9;
			this->btnConnect->Text = L"Connect";
			this->btnConnect->UseVisualStyleBackColor = true;
			// 
			// btnDisconnect
			// 
			this->btnDisconnect->Enabled = false;
			this->btnDisconnect->Location = System::Drawing::Point(571, 2);
			this->btnDisconnect->Name = L"btnDisconnect";
			this->btnDisconnect->Size = System::Drawing::Size(75, 23);
			this->btnDisconnect->TabIndex = 10;
			this->btnDisconnect->Text = L"Disconnect";
			this->btnDisconnect->UseVisualStyleBackColor = true;
			// 
			// btnClearChat
			// 
			this->btnClearChat->Location = System::Drawing::Point(652, 2);
			this->btnClearChat->Name = L"btnClearChat";
			this->btnClearChat->Size = System::Drawing::Size(75, 23);
			this->btnClearChat->TabIndex = 11;
			this->btnClearChat->Text = L"Clear Chat";
			this->btnClearChat->UseVisualStyleBackColor = true;
			// 
			// MainFormBase
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(729, 366);
			this->Controls->Add(this->btnClearChat);
			this->Controls->Add(this->btnDisconnect);
			this->Controls->Add(this->btnConnect);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txtMPPass);
			this->Controls->Add(this->txtUsername);
			this->Controls->Add(this->txtServer);
			this->Controls->Add(this->btnSend);
			this->Controls->Add(this->txtInput);
			this->Controls->Add(this->txtChat);
			this->MinimumSize = System::Drawing::Size(737, 393);
			this->Name = L"MainFormBase";
			this->ShowIcon = false;
			this->Text = L"Minecraft Classic Chat";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void txtInput_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (e->KeyChar == '\r')
			 {
				 btnSend->PerformClick();
				 e->Handled = true;
			 }
		 }
};
}