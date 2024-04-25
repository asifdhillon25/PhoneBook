#pragma once
#include <iostream>
#include<fstream>
#include <string>
#include <iomanip>
#include <vector>
#include "PhoneBook.h"
#include <algorithm> 
using namespace std;
class LogFile
{
	vector<PhoneBook*> contacts;
public:
	LogFile();
	void AddContact();//to add new conatact
	void LoadfromFile();//it will at start to load value from text file
	void ShowAll();//to print all data
	void LoadtoFile();//it saves modified data back to file 
	void Deleterecord(string id);//to delete record
	void UpdateRecord(string id);//to update record

};

