#include "stdafx.h"
#include "ImportURLForm.h"

namespace MinecraftClassicChat 
{
	ImportURLForm::ImportURLForm()
	{
		InitializeComponent();
	}

	Void ImportURLForm::btnImport_Click(Object^ sender, EventArgs^ e)
	{
		String^ url = txtURL->Text;

		if (String::IsNullOrEmpty(url) || !url->StartsWith("mc://") || url->Split('/')->Length != 5)
		{
			MessageBox::Show("The specified URL is invalid!", "Error", 
				MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		Close();
		URLImport(url);
	}
}