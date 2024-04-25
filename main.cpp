
#include <iostream>
#include<fstream>
#include <string>
#include "LogFile.h"
using namespace std;

int main()
{
    // This program serves as a phonebook record management system.
 // It reads data from a text file, performs various operations on it,
 // and then stores the modified data back to the text file.
    

    LogFile Myobj;
    char choice;
    do {
        system("cls");
        cout << "\n\n\t  Main Menu\n\n"
            << "\t1: Add Contact\n\n"
            << "\t2: Show All Contacts\n\n"
            << "\t3: Delete a Contact\n\n"
            << "\t4: Update a Contact\n\n"
            << "\t5: Exit\n";
        cout << "\n\n\t***PROPERLY EXIT THE PROGRAM TO STORE DATA\n";
        cout << "\n\tEnter your choice: ";
        cin >> choice;
        system("cls");
        string ID = "0";


        //switcth case to manage different actions
        switch (choice) {
        case '1':
            Myobj.AddContact();
            break;
        case '2':
            Myobj.ShowAll();
            break;
        case '3':
            Myobj.ShowAll();
            cout << "\n\n\nEnter Id of Contact to Delete\n";
            cin.ignore();
            std::getline(cin, ID);
            Myobj.Deleterecord(ID);
            break;
        case '4':
            Myobj.ShowAll();
            cout << "\n\n\nEnter Id of Contact to Update\n";
            cin.ignore();
            std::getline(cin, ID);
            Myobj.UpdateRecord(ID);
            break;
        case '5':
            cout << "\t\nSaving Data....\n\n";
            Myobj.LoadtoFile();
            cout << "\t\nExiting...\n";
            break;
        default:
            cout << "INVALID INPUT!!!!\n";
            cout << "\a";
        }
       
        system("pause");
        system("cls");
    } while (choice != '5');

}

