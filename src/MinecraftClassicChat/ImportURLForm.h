#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

namespace MinecraftClassicChat 
{
	public delegate void URLImportDelegate(System::String^);

	public ref class ImportURLForm : public System::Windows::Forms::Form
	{
	public:
		ImportURLForm();

	protected:
		~ImportURLForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  txtURL;
	private: System::Windows::Forms::Button^  btnImport;


	protected: 

#pragma region Windows Form Designer generated code
	private:
		System::ComponentModel::Container ^components;

		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtURL = (gcnew System::Windows::Forms::TextBox());
			this->btnImport = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(2, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(194, 26);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Please enter the direct connection URL\r\nyou would like to import:";
			// 
			// txtURL
			// 
			this->txtURL->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->txtURL->Location = System::Drawing::Point(5, 38);
			this->txtURL->Name = L"txtURL";
			this->txtURL->Size = System::Drawing::Size(224, 20);
			this->txtURL->TabIndex = 1;
			// 
			// btnImport
			// 
			this->btnImport->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->btnImport->Location = System::Drawing::Point(154, 66);
			this->btnImport->Name = L"btnImport";
			this->btnImport->Size = System::Drawing::Size(75, 23);
			this->btnImport->TabIndex = 2;
			this->btnImport->Text = L"Import";
			this->btnImport->UseVisualStyleBackColor = true;
			this->btnImport->Click += gcnew System::EventHandler(this, &ImportURLForm::btnImport_Click);
			// 
			// ImportURLForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(234, 92);
			this->Controls->Add(this->btnImport);
			this->Controls->Add(this->txtURL);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"ImportURLForm";
			this->ShowIcon = false;
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Import URL";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public:
		event URLImportDelegate^ URLImport;
	private:
		Void btnImport_Click(Object^ sender, EventArgs^ e);
	};
}
