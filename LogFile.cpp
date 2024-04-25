#include "LogFile.h"

LogFile::LogFile()
{
	LoadfromFile();
}

void LogFile::AddContact()
{
	PhoneBook* newcontact = new PhoneBook;
	newcontact->AddRecord();
	contacts.push_back(newcontact);
}

void LogFile::LoadfromFile()
{
	ifstream file("phonebook.txt");
	if (!file.is_open())
	{
		cout << "Error opening file\n";
		return;
	}

	while (file)
	{
		PhoneBook* newcontact = new PhoneBook;
		if (newcontact->GetFromFile(file))
		{
			contacts.push_back(newcontact);
		}
		else
		{
			delete newcontact; // Delete the object if the read operation fails
		}
	}

	file.close();
}

void LogFile::ShowAll()
{
	if (contacts.empty())
	{
		cout << "Phonebook is empty!!!!|\a\n"; 
		return;
	}
		
	
	
	std::cout << "==================================================================================================\n";
	std::cout << std::setw(5) << "ID" << std::setw(20) << "Name" << std::setw(30) << "PhoneNumber" << std::setw(30) << "Address\n";
	std::cout << "==================================================================================================\n";



	for (auto& x : contacts)
	{
		x->ShowRecord();
	}

}

void LogFile::LoadtoFile()
{
	fstream file("phonebook.txt");

	if (!file.is_open())
	{
		std::cout << "Error opening file\n";
		return;
	}

	for (const auto& x : contacts)
	{
		x->AddtoFile(file);
	}

	// The file will be automatically closed when 'file' goes out of scope
}

void LogFile::Deleterecord(string id)
{
	for (vector<PhoneBook*> ::iterator it = contacts.begin(); it != contacts.end();it++)
	{
		if ((*it)->GetId()==id)
		{
			delete (*it);
			it = contacts.erase(it);
			cout << "Record Deleted\n";
			return;
		}
	}
	cout << "\t\nNo Data with this Id\n";
}

void LogFile::UpdateRecord(string id)
{
	for (auto it = contacts.begin(); it != contacts.end(); it++)
	{
		if ((*it)->GetId() == id)
		{
			
			(*it)->UpdateRecord();
			cout << "\t\nRecord Updated.........\n";
			return;
		}
	}

	cout << "\t\nNo Data with this Id\n";
}
