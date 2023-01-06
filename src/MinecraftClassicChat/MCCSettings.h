#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace System::Text;

namespace MinecraftClassicChat
{
	public ref class MCCSettings
	{
	public:
		Dictionary<String^, String^>^ Entries;

		MCCSettings()
		{
			Entries = gcnew Dictionary<String^, String^>();
			Entries->Add("cpe", "true");
			Entries->Add("chatLogging", "true");
			Entries->Add("chatLoggingFilePath", Environment::GetFolderPath(Environment::SpecialFolder::MyDocuments) + "\\MCCLog.log");
		}

		bool Load(String^ path)
		{
			try
			{
				array<String^>^ entries = File::ReadAllLines(path);

				for (int entryIndex = 0; entryIndex < entries->Length; entryIndex++)
				{
					String^ entry = entries[entryIndex];

					if (entry->Contains(":"))
					{
						array<String^>^ entrySplitted = entry->Split(':', 2);

						if (entrySplitted->Length == 2)
						{
							String^ entryName = entrySplitted[0];
							String^ entryKey = entrySplitted[1];
							Entries[entryName] = entryKey;
						}
					}
				}
			}
			catch (Exception^ ex)
			{
				return false;
			}
			
			return true;
		}

		bool Save(String^ path)
		{
			try
			{
				String^ data = "";

				for each(KeyValuePair<String^, String^> entry in Entries)
				{
					data += entry.Key + ":" + entry.Value + Environment::NewLine;
				}

				File::WriteAllText(path, data, Encoding::ASCII);
			}
			catch (Exception^ ex)
			{
				return false;
			}

			return true;
		}
	};
}