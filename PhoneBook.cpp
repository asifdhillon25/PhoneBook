#include "PhoneBook.h"

PhoneBook::PhoneBook()
{
	Name = "N/A";
	PhoneNumber1= "N/A";
	Address= "N/A";
	id ="N/A" ;
}

void PhoneBook::AddRecord()
{
	cout << "Enter Person Name: ";
	cin.ignore();
	getline(cin, Name);

	cout << "Enter Person phonenumber: ";
	cin.ignore();
	getline(cin, PhoneNumber1);

	cout << "Enter Person Address: ";
	cin.ignore();
	getline(cin, Address);
	
	cout << "Enter A unique Id : ";
	cin.ignore();
	getline(cin, id);

}

void PhoneBook::ShowRecord()
{
	std::cout << std::setw(5) << id << std::setw(20) << Name << std::setw(30) << PhoneNumber1 << std::setw(30) << Address << "\n";

}


void PhoneBook::UpdateRecord()
{
	cout << "\t\n**Enter New Data**\n";

	cout << "Enter Person Name: ";
	getline(cin, Name);

	cout << "Enter Person phonenumber: ";
	getline(cin, PhoneNumber1);

	cout << "Enter Person Address: ";
	getline(cin, Address);

	cout << "Enter A unique Id : ";
	getline(cin, id);
}


void PhoneBook::AddtoFile(fstream& file)
{
	file << Name<<"\n";
	file << PhoneNumber1 << "\n";
	file << Address << "\n";
	file << id << "\n";
}

bool PhoneBook::GetFromFile(std::ifstream& file)
{
	if (std::getline(file, Name) &&
		std::getline(file, PhoneNumber1) &&
		std::getline(file, Address) &&
		std::getline(file, id))
	{
		// Data successfully read from the file
		return true;
	}
	else
	{
		// Failed to read data from the file
		return false;
	}
}

string PhoneBook::GetId()
{
	return id;
}


