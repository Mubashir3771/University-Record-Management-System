

#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct record
{
	string name, father_name, designation;
	int emp_id, bps, salary, age;

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
	}

};

void insert();
void update();
void show();
void search();
void search_id();
void search_name();
void search_age();
void search_youngest();
void search_eldest();
void search_bps();
void search_designation();
void save_record();
void load_record();
record employ[50];
int index = 0, index2 = 0, check = 0;
fstream fs;

int main()
{
	load_record();
	int option;
	do
	{
		cout << "\n 1. Insert New Employee Record \n 2. Update Employee Record \n 3. Search Existing Record \n 4. Show all Records \n 5. Exit \n";
		cout << "Please select from the given options ";
		cin >> option;

		while (option < 1 || option > 5)
		{
			cout << "Please choose from the given options ";
			cin >> option;
		}

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
			break;


	} while (option >= 1 && option <= 5);
	save_record();
	return 0;
}

void insert()
{
	int opt = 0;

	do
	{
		employ[index].setdata();
		index++;
		cout << "Press 1 to continue or 2 to stop ";
		cin >> opt;

		if (opt < 1 || opt > 2)
		{
			cout << "Press 1 to continue or 2 to stop ";
			cin >> opt;
		}

	} while (opt == 1);
}

void search()
{
	char selection;

	cout << " a. Select by emp_id \n b. Seatch by Name \n c. Search by age \n d. Search Youngest Employee \n e. Search Eldest Employee \n f. Search by BPS \n g. Search by designation \n";
	cin >> selection;

	if (selection == 'a')
	{
		search_id();
		employ[index2].showdata();
	}

	else if (selection == 'b')
	{
		search_name();
	}

	else if (selection == 'c')
	{
		search_age();
	}

	else if (selection == 'd')
	{
		search_youngest();
	}

	else if (selection == 'e')
	{
		search_eldest();
	}

	else if (selection == 'f')
	{
		search_bps();
	}

	else if (selection == 'g')
	{
		search_designation();
	}
	else
	{
		cout << "Wrong Entry! \n";
	}
}

void update()
{
	search_id();
	if (check == 1)
	{
		cout << "*** You can only update employ's designation *** \n Enter new designation: " << endl;
		cin >> employ[index2].designation;
	}
}

void show()
{
	for (int i = 0; i < index; i++)
	{
		employ[i].showdata();
		cout << endl;
	}
}

void search_id()
{
	check = 0;
	int ID;
	cout << "Enter employ's Id ";
	cin >> ID;
	for (int i = 0; i < index; i++)
	{
		if (employ[i].emp_id == ID)
		{
			index2 = i;
			check = 1;
		}
	}
	if (check != 1)
		cout << "No record found " << endl;
}

void search_name()
{
	check = 0;
	string Name;
	cout << "Enter employ's Name ";
	cin >> Name;
	for (int i = 0; i < index; i++)
	{
		if (employ[i].name == Name)
		{
			employ[i].showdata();
			check = 1;
		}
	}
	if (check != 1)
		cout << "No record found " << endl;
}

void search_age()
{
	check = 0;
	int age;
	cout << "Enter employ's age ";
	cin >> age;
	for (int i = 0; i < index; i++)
	{
		if (employ[i].age == age)
		{
			employ[i].showdata();
			check = 1;
		}
	}
	if (check != 1)
		cout << "No record found " << endl;
}

void search_youngest()
{
	record youngest;
	youngest = employ[0];
	for (int i = 1; i < index; i++)
	{
		if (youngest.age > employ[i].age)
		{
			youngest = employ[i];
		}
	}
	youngest.showdata();
}

void search_eldest()
{
	record eldest;
	eldest = employ[0];
	for (int i = 1; i < index; i++)
	{
		if (eldest.age < employ[i].age)
		{
			eldest = employ[i];
		}
	}
	eldest.showdata();
}

void search_bps()
{
	check = 0;
	int bps;
	cout << "Enter employ's BPS ";
	cin >> bps;
	for (int i = 0; i < index; i++)
	{
		if (employ[i].bps == bps)
		{
			employ[i].showdata();
			check = 1;
		}
	}
	if (check != 1)
		cout << "No record found " << endl;
}

void search_designation()
{
	check = 0;
	string Designation;
	cout << "Enter employ's designation ";
	cin >> Designation;
	for (int i = 0; i < index; i++)
	{
		if (employ[i].designation == Designation)
		{
			employ[i].showdata();
			check = 1;
		}
	}
	if (check != 1)
		cout << "No record found " << endl;
}

void save_record()
{
	fs.open("Recodrs.dat", ios::out | ios::binary);

	fs.write(reinterpret_cast<char*>(&index), sizeof(int));

	for (int i = 0; i < index; i++)
	{
		fs.write(reinterpret_cast<char*>(&employ[i]), sizeof(record));
	}

	fs.close();
	cout << endl <<"The records of "<< index << " employee has been saved \n";
}

void load_record()
{
	
	fs.open("Recodrs.dat", ios::in | ios::binary);
	if (fs.fail())
	{
		cout << "The \"Recodrs.dat\" file was not found " << endl;
		return;
	}
	int end_of_file;
	fs.read(reinterpret_cast<char*>(&end_of_file), sizeof(int));

	for (int i = 0; i < end_of_file; i++)
	{
		fs.read(reinterpret_cast<char*>(&employ[i]), sizeof(record));
		index++;
	}
	cout << end_of_file << " records have been loaded \n";
	fs.close();
}
