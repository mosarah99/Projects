// Doctor's Appointment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

class Doctor
{

	const unsigned days = 5;
	const unsigned time_slot = 4;
	string Name;
	int appointments[5][4];

public:
	Doctor(string name, string appointment_loc)
	{
		Name = name;
		ifstream file(appointment_loc);
		for (unsigned i = 0; i < days; i++)
		{
			for (unsigned j = 0; j < time_slot; j++)
			{
				char ch;
				file >> ch;
				// 1 represents the doctor is booked
				//0 represents the doctor is free
				if (ch == 'Y')
				{
					appointments[i][j] = 1;
				}
				else
				{
					appointments[i][j] = 0;
				}

			}
		}


	}
	
	
	bool is_available(int day,int timeslot)
	{
		return appointments[day][timeslot] == 0;
	}
	bool is_booked(int day, int timeslot)
	{
		return !is_available(day, timeslot);
	}
	string getName()
	{
		return Name;
	}
};


class Hospital
{

	vector<Doctor> all_doctors;
public:
	
    vector<Doctor> getDoc()
	{
		return all_doctors;
	}
	void add_doc(Doctor doc)
	{
		all_doctors.push_back(doc);

	}
};


class Registration
{    
	string docName;
	string day;
	string time_slot;
    string Name;
	string Cell;
	int Age;
public:
	Registration(string name, int age , string cell)
	{
		Name = name;
		Age = age;
		Cell = cell;
	}
	
	

	void printReceipt()
	{
		ofstream rpt("report.txt");
		rpt << "Name: " << Name << endl;
		rpt << "Age: " << Age << endl;
		rpt << "Cell No: " << Cell << endl;
		rpt << "======================================================\n";
		rpt << "Doctor's Name: " << docName << endl;
		rpt << "Day: " << day << endl;
		rpt << "Time: " << time_slot << endl;
		rpt << "======================================================\n";
		rpt.close();
	}
	void addAppointment(string doc_Name, string Day, string timeslot)
	{
		 
		docName = doc_Name;
		day = Day;
		time_slot = timeslot;

	}
};

void printDocinfo()
{
	cout << "  Select one of the following doctors: \n";
	cout << "----------------------------------------\n";
	cout << "0.Dr.A\n";
	cout << "1.Dr.B\n\n\n";
}
void printBookingDays()
{
	cout << "  Select one of the following days:" << endl;
	cout << "------------------------------------" << endl;
	cout << "0:Monday" << endl;
	cout << "1:Tuesday" << endl;
	cout << "2:Wednesday" << endl;
	cout << "3:Thursday" << endl;
	cout << "4:Friday" << endl;
}
void printTimeslot()
{
	cout << "  Select one of the following times:" << endl;
	cout << "------------------------------------" << endl;
	cout << "0: 10-11 AM\n";
	cout << "1: 11-12 AM\n";
	cout << "2: 12-01 PM\n";
	cout << "3: 01-02 PM\n";
}
void printBookingConfirm()
{
	cout << "Do you want to confirm booking?\n"
		<< "------------------------------------\n"
		<< "0. Yes \n"
		<< "1. No \n\n";
	
}
int main()
{	

	Doctor doc1("Dr Tanima", "drA.txt");
    Hospital ibn_sina;
	ibn_sina.add_doc(doc1);
	Doctor doc2("Dr Mika", "drB.txt");
	ibn_sina.add_doc(doc2);
	const string days[5] = 
	{
		"Monday",
		"Tuesday",
		"Wednesday",
		"Thursday",
		"Friday"
	};
	const string timeslot[4] =
	{
		"10 AM - 11 AM",
		"11 AM - 12 PM",
		"12 PM - 1 PM",
		"1 PM - 2 PM"
	};

	bool has_Registered = false;

	while (has_Registered== false)
	{
		cout << "  A Medical College and Hospital  \n";
		cout << "----------------------------------\n";
		cout << "\n";
		printDocinfo();
		int opt_Doc;
		cin >> opt_Doc;
		printBookingDays();
		int opt_bookingDay;
		cin >> opt_bookingDay;
		printTimeslot();
		int opt_timeslot;
		cin >> opt_timeslot;

		if (ibn_sina.getDoc()[opt_Doc].is_available(opt_bookingDay, opt_timeslot))
		{
			cout << ibn_sina.getDoc()[opt_Doc].getName() << " is available \n";
			printBookingConfirm();
			int opt_confirm;
			cin >> opt_confirm;
			if (opt_confirm == 0)
			{
				//Registration
				string Patient_Name, Cell;
				int Age;
				cout << "Registration\n";
				cout << "----------------------------------\n";
				cout << setw(-10) << "Name"<< ": ";
				cin >> Patient_Name;
				cout << setw(-10) << "Age" << ": ";
				cin >> Age;
				cout << setw(-10) << "Cell No" << ": ";
				cin >> Cell;
				Registration reg(Patient_Name, Age, Cell);
				reg.addAppointment(ibn_sina.getDoc()[opt_Doc].getName(),days[opt_bookingDay],timeslot[opt_timeslot]);
				reg.printReceipt();



				//Set has_Registered to true
				has_Registered = true;
			}
		}
		else
		{
			if (ibn_sina.getDoc()[(opt_Doc==1?0:1)].is_available(opt_bookingDay, opt_timeslot))
			{
				cout << ibn_sina.getDoc()[opt_Doc].getName() << " is not available \n";
				cout << ibn_sina.getDoc()[(opt_Doc == 1 ? 0 : 1)].getName() << " is available at the same time \n";
				printBookingConfirm();
				int opt_confirm;
				cin >> opt_confirm;
				if (opt_confirm == 0)
				{
					//Registration
					string Patient_Name, Cell;
					int Age;
					cout << "Registration\n";
					cout << "----------------------------------\n";
					cout << setw(-10) << "Name" << ": ";
					cin >> Patient_Name;
					cout << setw(-10) << "Age" << ": ";
					cin >> Age;
					cout << setw(-10) << "Cell No" << ": ";
					cin >> Cell;
					Registration reg(Patient_Name, Age, Cell);
					reg.addAppointment(ibn_sina.getDoc()[opt_Doc].getName(), days[opt_bookingDay], timeslot[opt_timeslot]);
					reg.printReceipt();
					 
					//Set has_Registered to true
					has_Registered = true;
				}
			}
			else
			{
				cout << "No doctors are available at that time.\n"
					<< "Please Try Again! \n\n\n";
			}
		}
	}
	
}

