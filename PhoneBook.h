#pragma once
#include <iostream>
#include<fstream>
#include <string>
#include <iomanip>
using namespace std;
class PhoneBook
{
	
	string Name;
	string PhoneNumber1;
	string Address;
	string id;
public:
	//these functions will perform actions on single instances of each record
	PhoneBook();
	void AddRecord();
	void ShowRecord();
	void UpdateRecord();
	void AddtoFile(fstream &file);
	bool GetFromFile(ifstream &file);
	string GetId();

};

