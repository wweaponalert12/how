#include <iostream>
#include <fstream>
#include  <string.h>
#include <sstream>
using namespace std;

void add()
{
	bool move = false;
	system("CLS");
	char id[25];
    char fn[25];
    char dt[25];
    fstream file;
    file.open("covidd.txt", ios::app);
    cout << "Add Patient\n";
    cin.ignore();
    do
    {
    cout<<"Patient ID: ";
    cin.getline(id,250);
	} while(move);
    cout<<"Full name: ";
    cin.getline(fn,250);
    cout<<"Date got confined: ";
    cin.getline(dt,250);
    file << id << ", " << fn << ", " << dt;
    file << endl;
    cout << "\nSuccessfully added.";
    file.close();
}

void list()
{
	system("CLS");
	ifstream file("covidd.txt");
	string line;
	
	if
	(
		!file.is_open()
	)
	{
		cout << "\nOh no! File wont open! Try again later.";
		cin.get();
	}
	else
	{
		cout << "COVID-19 PATIENTS" << endl;
		cout << "\nList:" << endl;
		while (getline(file, line))
		{
			cout << line << endl;
		}
		cout << "\nPress Enter to continue.";
		cin.get();
		file.close();
	}
}

void search()
{
	system("CLS");
	string search, id, fn, dt;
	ifstream file("covidd.txt");
	bool found = false;
	string line;
	cout << "SEARCH A PATIENT\n";
	cout << "Enter Patient ID.: ";
	cin >> search;
	
	if (file.is_open())
	{
		while (getline(file,line))
		{
			id = line.substr(0,2);
			if (id == search)
			{
				found = true;
				break;
			}
			else
			{
				found = false;
			}
		}
			if (found == true)
			{
				fn = line.substr(3,line.length() - 6);
				dt = line.substr(line.length() - 2, line.length());
				cout << "\nID No.: " << id << endl;
				cout << "Name: " << fn << endl;
				cout << "Date Confined: " << dt << endl;
				
				cout << "\nPatient found. Enter to continue.";
				cin.get();
			}
			else
			{
				cout << "\nSorry. Patient not found.";
				cin.get();
			}
	}
	else
	{
		cout << "\nNOTICE: File opening error.";
		cin.get();
	}
	file.close();
}			

void edit()
{
string search, id, nfn, ndt;
	char fn[25];
	char dt[25];
	ifstream file("covidd.txt");
	int recno;
	bool found;
	int counter = 0;
	string line;
	string lineArr[100];
	system("CLS");
	cout << "Edit Patient info\n";
	cout << "Enter ID: ";
	cin >> search;
	
	if (file.is_open())
	{
		found = false;
		while (getline(file,line))
		{
			id = line.substr(0,2);
			if (id == search)
			{
				found = true;
				break;
			}
			else
			{
				found = false;
			}
		}
		ifstream file2("temp.txt");
		while (getline(file2,line))
		{
			lineArr[counter] = line;
			
			id = line.substr(0,2);
			if (id == search)
			{
				recno = counter;
			}
			counter++;
		}
		file2.close();
		if (found == true)
		{
			system("CLS");
			cout << "Edit Patient info\n";
			cout << "Patient info: " << lineArr[recno ] << endl;
			cout << "\n";
			cout << "New ID.: ";
			cin >> id;
			cout << "New name: ";
			cin.getline(fn,25);
			cin.getline(fn,25);
			cout << "New confined date: ";
			cin.getline(dt,25);
			lineArr[recno] = id + ", " + nfn + ", " + ndt;
			ofstream file3("covidd.txt");
			for (int i = 0; i < counter; i++)
			{
				file3 << lineArr[i] << endl;
			}
			cout << "\nPatient successfully updated.";
		}
		else
		{
			cout << "\nSorry. Patient not found.";
		}
		
		cin.get();
	}	
}

void remove()
{
	string line;
	string id, fn, dt;
	ofstream temp;
	temp.open("temp.txt");
	ifstream file("covidd.txt");
	if(file.is_open())
	{
		string deleteline;
		string id, fn, dt;
		string ans;
		cout << "Enter ID: ";
		cin >> deleteline;
		while(getline(file, line))
		{
			
			if(line.substr(0, 2) == deleteline)
			{
				id = line.substr(0, 2);
				fn = line.substr(4, line.length() - 8);
				dt = line.substr(line.length() - 2, line.length());
				cout << "Patient info: " << id << ", " << fn << ", " << dt << endl;
				cout << "Are you sure you want to remove patient info? type YES to release" << endl;
				cin >> ans;
				if(ans == "yes" || ans == "YES")
				{
					cout << "\nPlayer Released!" << endl;
					continue;
				}
			}
			temp << line << endl;
		}
	}
	file.close();
	temp.close();
	remove("covidd.txt");
	rename("temp.txt", "covidd.txt");
	cin.get();
}

int main()
{
    bool quit = true;
	do
	{
		system("CLS");
		int option;
		cout << "COVID-19 PATIENTS" << endl;
		cout << "1 - Add Patient" << endl;
		cout << "2 - List of Patients" << endl;
		cout << "3 - Search Patients" << endl;
		cout << "4 - Edit Patients info" << endl;
		cout << "5 - Delete Patient info" << endl;
		cout << "6. Exit" << endl;
		cout << "Enter a number: "; cin >> option;
	
		switch (option)
		{
			case 1: add(); break;
			case 2: list(); break;
			case 3: search(); break;
			case 4: edit(); break;
			case 5: remove(); break;
			case 6: quit = false; break;
			default: cout << "\nOh no! you entered an invalid number... Press enter to continue.\n"; cin.get();
			break;
		}
		
		cin.get();
	} while (quit);
	cout << "\nThank you...Remember to always wash your hands!.\n";
}
