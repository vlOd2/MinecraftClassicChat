#pragma once

#include "MCCSettings.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;

namespace MinecraftClassicChat 
{
	public ref class SettingsForm : public Form
	{
	public:
		SettingsForm(MCCSettings^ settings, String^ settingsFilePath)
		{
			InitializeComponent();
			this->settings = settings;
			this->settingsFilePath = settingsFilePath;
			cbCPEEnable->Checked = settings->Entries["cpe"]->Equals("true");
			cbCLEnable->Checked = settings->Entries["chatLogging"]->Equals("true");
			txtCLFilePath->Text = settings->Entries["chatLoggingFilePath"];
		}

	protected:
		~SettingsForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::CheckBox^  cbCLEnable;
	private: System::Windows::Forms::TextBox^  txtCLFilePath;
	protected: 


	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  btnCLBrowse;
	private: System::Windows::Forms::Button^  btnSave;

	private: System::Windows::Forms::SaveFileDialog^  sfdBrowse;
	private: System::Windows::Forms::CheckBox^  cbCPEEnable;
	private: System::Windows::Forms::Label^  label2;



	protected: 

	protected: 

#pragma region Windows Form Designer generated code
	private:
		System::ComponentModel::Container ^components;

		void InitializeComponent(void)
		{
			this->cbCLEnable = (gcnew System::Windows::Forms::CheckBox());
			this->txtCLFilePath = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnCLBrowse = (gcnew System::Windows::Forms::Button());
			this->btnSave = (gcnew System::Windows::Forms::Button());
			this->sfdBrowse = (gcnew System::Windows::Forms::SaveFileDialog());
			this->cbCPEEnable = (gcnew System::Windows::Forms::CheckBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// cbCLEnable
			// 
			this->cbCLEnable->AutoSize = true;
			this->cbCLEnable->BackColor = System::Drawing::Color::DimGray;
			this->cbCLEnable->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->cbCLEnable->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->cbCLEnable->ForeColor = System::Drawing::Color::White;
			this->cbCLEnable->Location = System::Drawing::Point(12, 38);
			this->cbCLEnable->Name = L"cbCLEnable";
			this->cbCLEnable->Size = System::Drawing::Size(117, 17);
			this->cbCLEnable->TabIndex = 0;
			this->cbCLEnable->Text = L"Enable chat logging";
			this->cbCLEnable->UseVisualStyleBackColor = false;
			// 
			// txtCLFilePath
			// 
			this->txtCLFilePath->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtCLFilePath->Location = System::Drawing::Point(12, 78);
			this->txtCLFilePath->Name = L"txtCLFilePath";
			this->txtCLFilePath->Size = System::Drawing::Size(354, 20);
			this->txtCLFilePath->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(9, 62);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(44, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Log file:";
			// 
			// btnCLBrowse
			// 
			this->btnCLBrowse->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->btnCLBrowse->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnCLBrowse->ForeColor = System::Drawing::Color::White;
			this->btnCLBrowse->Location = System::Drawing::Point(12, 104);
			this->btnCLBrowse->Name = L"btnCLBrowse";
			this->btnCLBrowse->Size = System::Drawing::Size(75, 23);
			this->btnCLBrowse->TabIndex = 3;
			this->btnCLBrowse->Text = L"Browse";
			this->btnCLBrowse->UseVisualStyleBackColor = true;
			this->btnCLBrowse->Click += gcnew System::EventHandler(this, &SettingsForm::btnCLBrowse_Click);
			// 
			// btnSave
			// 
			this->btnSave->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->btnSave->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSave->ForeColor = System::Drawing::Color::White;
			this->btnSave->Location = System::Drawing::Point(291, 230);
			this->btnSave->Name = L"btnSave";
			this->btnSave->Size = System::Drawing::Size(75, 23);
			this->btnSave->TabIndex = 4;
			this->btnSave->Text = L"Save";
			this->btnSave->UseVisualStyleBackColor = true;
			this->btnSave->Click += gcnew System::EventHandler(this, &SettingsForm::btnSave_Click);
			// 
			// sfdBrowse
			// 
			this->sfdBrowse->DefaultExt = L"log";
			this->sfdBrowse->Filter = L"Log files|*.log|All files|*.*";
			this->sfdBrowse->OverwritePrompt = false;
			// 
			// cbCPEEnable
			// 
			this->cbCPEEnable->AutoSize = true;
			this->cbCPEEnable->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->cbCPEEnable->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->cbCPEEnable->ForeColor = System::Drawing::Color::White;
			this->cbCPEEnable->Location = System::Drawing::Point(12, 15);
			this->cbCPEEnable->Name = L"cbCPEEnable";
			this->cbCPEEnable->Size = System::Drawing::Size(225, 17);
			this->cbCPEEnable->TabIndex = 5;
			this->cbCPEEnable->Text = L"* Enable CPE (Classic Protocol Extensions)";
			this->cbCPEEnable->UseVisualStyleBackColor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(127, 235);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(158, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"* applies only after reconnecting";
			// 
			// SettingsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DimGray;
			this->ClientSize = System::Drawing::Size(378, 265);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->cbCPEEnable);
			this->Controls->Add(this->btnSave);
			this->Controls->Add(this->btnCLBrowse);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txtCLFilePath);
			this->Controls->Add(this->cbCLEnable);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"SettingsForm";
			this->ShowIcon = false;
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Settings";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &SettingsForm::SettingsForm_FormClosing);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		MCCSettings^ settings;
		String^ settingsFilePath;
		bool noClosePrompt;

		void ShowError(String^ body)
		{
			MessageBox::Show(body, "Error", 
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

		Void SettingsForm_FormClosing(Object^ sender, FormClosingEventArgs^ e) 
		{
			if (noClosePrompt) return;

			System::Windows::Forms::DialogResult closePrompt = MessageBox::Show("Are you sure you want to close the settings?" + 
				Environment::NewLine +
				"Any unsaved settings will be lost!", "Warning", 
				MessageBoxButtons::YesNo, MessageBoxIcon::Warning);

			if (closePrompt == System::Windows::Forms::DialogResult::No)
			{
				e->Cancel = true;
			}
		}

		Void btnCLBrowse_Click(Object^ sender, EventArgs^ e) 
		{
			System::Windows::Forms::DialogResult browsePrompt = sfdBrowse->ShowDialog();
			if (browsePrompt == System::Windows::Forms::DialogResult::OK)
			{
				String^ file = sfdBrowse->FileName;
				sfdBrowse->FileName = nullptr;
				txtCLFilePath->Text = file;
			}
		}

		Void btnSave_Click(Object^ sender, EventArgs^ e)
		{
			bool cpe = cbCPEEnable->Checked;
			bool chatLogging = cbCLEnable->Checked;
			String^ chatLoggingFilePath = txtCLFilePath->Text;

			if (chatLogging)
			{
				bool valid = false;
				try { valid = Path::GetFullPath(chatLoggingFilePath) != nullptr; } catch (Exception^ ex) {}
				
				if (String::IsNullOrEmpty(chatLoggingFilePath) || !valid)
				{
					ShowError("The specified path for \"Log file\" is invalid!");
					return;
				}

				settings->Entries["chatLoggingFilePath"] = chatLoggingFilePath;
			}
			settings->Entries["chatLogging"] = chatLogging ? "true" : "false";
			settings->Entries["cpe"] = cpe ? "true" : "false";
			settings->Save(settingsFilePath);

			noClosePrompt = true;
			Close();
		}
	};
}
