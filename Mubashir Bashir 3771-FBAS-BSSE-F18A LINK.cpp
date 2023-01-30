      // Mubashir Bashir 3771-FBAS-BSSE-F18 Link.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct record
{
	string name, father_name, designation;
	int emp_id, bps, salary, age;
	record *next;
	void setdata()
	{
		cout << "Enter employ's name ";
		cin >> name;
		cout << "Enter employ's father name ";
		cin >> father_name;
		do
		{
			cout << "Enter employ's designation(must be either Admin/Tech/Managerial/Others only.";
			cin >> designation;
		} while ((designation != "Admin") && (designation != "Tech") && (designation != "Managerial") && (designation != "Others") && (designation != "admin") && (designation != "tech") && (designation != "managerial") && (designation != "others"));
		do
		{
			cout << "Enter employ's Id(must be 7777-9999) ";
			cin >> emp_id;
		} while (emp_id < 7777 || emp_id > 9999);
		do
		{
			cout << "Enter employ's bps(must be 1 to 22) ";
			cin >> bps;
		} while (bps < 1 || bps >22);
		do
		{
			cout << "Enter employ's age (must be 18 to 60) ";
			cin >> age;
		} while (age < 18 || age > 60);
		cout << endl;
	}

	void showdata()
	{
		cout << "The employ's name is " << name << endl;
		cout << "The employ's father name is " << father_name << endl;
		cout << "The employ's designation is " << designation << endl;
		cout << "The employ's ID is " << emp_id << endl;
		cout << "The employ's bonus points are " << bps << endl;
		cout << "The employ's salary is " << (bps * 10000) + (bps * 10000 * 45 / 100) << endl;
		cout << "The employ's age is " << age << endl;
		cout << endl;
	}

};

void insert();
void update();
void show();
void Delete();
void search();
void search_id();
void search_name();
void search_age();
void search_youngest();
void search_eldest();
void search_bps();
void search_designation();
void load_record();
void save_record();

record *ptr = NULL, *first = NULL, *last = NULL, *padress = NULL, *d = NULL, *Search = NULL;
int limit = 0, check = 0;
fstream fs;
int main()
{
	load_record();
	int option;
	do
	{
		cout << "\n 1. Insert New Employee Record \n 2. Update Employee Record \n 3. Search Existing Record \n 4. Show all Records \n 5. Delete Record \n 6. Exit \n";
		cout << "Please select from the given options ";
		cin >> option;

		if (option == 1)
		{
			insert();

		}
		else if (option == 2)
		{
			update();

		}
		else if (option == 3)
		{

			search();
		}
		else if (option == 4)
		{

			show();

		}
		else if (option == 5)
		{
			Delete();

		}
		else if (option == 6)
		{
			break;
		}
		else
		{
			cout << "Please select from the given options " << endl;
		}
	} while (option >= 1 && option <= 6);
	save_record();
	return 0;
}

void insert()
{
	int opt = 1;
	if (limit < 1)
	{
		ptr = new record;
		ptr->setdata();
		first = ptr;
		last = ptr;
		ptr->next = NULL;
		limit = 1;
		cout << "Press 1 to continue or 2 to stop ";
		cin >> opt;
	}
	if (limit >= 1)
	{
		while (opt == 1 && limit < 50)
		{
			if (opt == 1)
			{
				if (limit >= 50)
				{
					cout << "Memory Full!" << endl;
				}
				else
				{
					ptr = new record;
					ptr->setdata();
					ptr->next = NULL;
					last->next = ptr;
					last = ptr;
					limit++;
				}
			}
			cout << "Press 1 to continue or 2 to stop ";
			cin >> opt;
		}
	}
}
void show()
{
	record *show_data;
	show_data = first;
	while (show_data != NULL)
	{
		show_data->showdata();
		show_data = show_data->next;
	}
}
void update()
{
	search_id();
	if (d != NULL)
	{
		cout << "***You can only update employe's designation*** \n Enter new designation: ";
		cin >> d->designation;
	}
}
void Delete()
{
	search_id();
	if (d != NULL)
	{
		if (d->emp_id == first->emp_id)
		{
			first = first->next;
		}
		else if (d->emp_id == last->emp_id)
		{
			last = padress;
			last->next = NULL;
		}
		else
		{
			padress->next = d->next;
		}
		delete d;
		limit = limit - 1;
	}
}
void search()
{
	char selection;
	cout << " a. Select by emp_id \n b. Search by Name \n c. Search by age \n d. Search Youngest Employee \n e. Search Eldest Employee \n f. Search by BPS \n g. Search by designation \n";
	cin >> selection;

	switch (selection)
	{
	case 'a':
		search_id();
		if (d != NULL)
			d->showdata();
		break;
	case 'b':
		search_name();
		break;
	case 'c':
		search_age();
		break;
	case 'd':
		search_youngest();
		break;
	case 'e':
		search_eldest();
		break;
	case'f':
		search_bps();
		break;
	case 'g':
		search_designation();
		break;
	default:
		cout << "Please enter from the given options \n  a.Select by emp_id \n b.Seatch by Name \n c.Search by age \n d.Search Youngest Employee \n e.Search Eldest Employee \n f.Search by BPS \n g.Search by designation \n";
		cin >> selection;
	}
}

void search_id()
{
	int id;
	check = 0;
	Search = first;
	cout << "Enter employ's Id ";
	cin >> id;
	while (Search != NULL)
	{
		if (id == Search->emp_id)
		{
			d = Search;
			check = 1;
			break;
		}
		else
		{
			padress = Search;
			Search = Search->next;
		}
	}
	if (check != 1)
	{
		d = NULL;
		cout << "No record exists \n";
	}
}
void search_name()
{
	check = 0;
	string name;
	Search = first;
	cout << "Enter employ's name ";
	cin >> name;
	while (Search != NULL)
	{
		if (name == Search->name)
		{
			Search->showdata();
			check = 1;
		}
		Search = Search->next;
	}
	if (check != 1)
		cout << "No record exists \n";
}
void search_age()
{
	int age,
		check = 0;
	Search = first;
	cout << "Enter employ's age ";
	cin >> age;
	while (Search != NULL)
	{
		if (age == Search->age)
		{
			Search->showdata();
			check = 1;
		}
		Search = Search->next;
	}
	if (check != 1)
		cout << "No record exists \n";
}
void search_youngest()
{
	record *youngest = first;
	Search = youngest->next;
	while (Search != NULL)
	{
		if (youngest->age > Search->age)
			youngest = Search;

		Search = Search->next;
	}
	youngest->showdata();
}
void search_eldest()
{
	record *eldest = first;
	Search = eldest->next;
	while (Search != NULL)
	{
		if (eldest->age < Search->age)
			eldest = Search;

		Search = Search->next;
	}
	eldest->showdata();
}
void search_bps()
{
	int bps;
	check = 0;
	Search = first;
	cout << "Enter employ's bps ";
	cin >> bps;
	while (Search != NULL)
	{
		if (bps == Search->bps)
		{
			Search->showdata();
			check = 1;
		}
		else
			Search = Search->next;
	}
	if (check != 1)
		cout << "No record exists \n";
}
void search_designation()
{
	string Designation;
	check = 0;
	Search = first;
	cout << "Enter employ's designation ";
	cin >> Designation;
	while (Search != NULL)
	{
		if (Designation == Search->designation)
		{
			Search->showdata();
			check = 1;
		}
		else
			Search = Search->next;
	}
	if (check != 1)
		cout << "No record exists \n";
}
void save_record()
{
	fs.open("Recodrs.dat", ios::out | ios::binary);

	fs.write(reinterpret_cast<char*>(&limit), sizeof(int));

	record *tempv;
	tempv = first;
	while (tempv != NULL)
	{
		fs.write(reinterpret_cast<char*>(tempv), sizeof(record));
		tempv = tempv->next;
	}
	fs.close();
	cout << endl << "The records of " << limit << " employee has been saved \n";
}

void load_record()
{
	int limit2 = 0;
	fs.open("Recodrs.dat", ios::in | ios::binary);
	if (fs.fail())
	{
		cout << "The \"Recodrs.dat\" file was not found" << endl;
		return;
	}
	int end_of_file;
	fs.read(reinterpret_cast<char*>(&end_of_file), sizeof(int));

	record *tempp = NULL;

	if (first == NULL)
	{
		tempp = new record;
		fs.read(reinterpret_cast<char*>(tempp), sizeof(record));

		ptr = new record;
		ptr->name = tempp->name;
		ptr->father_name = tempp->father_name;
		ptr->emp_id = tempp->emp_id;
		ptr->designation = tempp->designation;
		ptr->bps = tempp->bps;
		ptr->salary = tempp->salary;
		ptr->age = tempp->age;
		ptr->next = NULL;
		first = ptr;
		last = ptr;
		limit++;
		limit2++;
	}

	while (limit2 != end_of_file)
	{
		tempp = new record;
		fs.read(reinterpret_cast<char*>(tempp), sizeof(record));

		ptr = new record;
		ptr->name = tempp->name;
		ptr->father_name = tempp->father_name;
		ptr->emp_id = tempp->emp_id;
		ptr->designation = tempp->designation;
		ptr->bps = tempp->bps;
		ptr->salary = tempp->salary;
		ptr->age = tempp->age;

		last->next = ptr;
		last = ptr;
		ptr->next = NULL;
		limit++;
		limit2++;

	}

	cout << end_of_file << " records have been loaded in the memory \n";
	fs.close();
}

