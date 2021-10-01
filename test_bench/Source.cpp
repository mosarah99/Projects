// Doctor's Appointment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include < fstream>
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
};

class Hospital
{
    vector<Doctor> all_doctors;
public:
    Hospital()
    {

    }
    //void setDoc(vector<Doctor> doc)
    //{
    //    all_doctors = doc;
    //}
    vector<Doctor> getDoc()
    {
        return all_doctors;
    }
    void add_doc(Doctor doc)
    {
        all_doctors.push_back(doc);

    }
};



int main()
{
    int opt;
    cout << "  A Medical College and Hospital  \n";
    cout << "----------------------------------\n";
    cout << "\n";
    cout << "  Select one of the following doctors: \n";
    cout << "----------------------------------------\n";
    cout << "1.Dr.A\n";
    cout << "2.Dr.B\n\n\n";
    cout << "Enter your choice: \n";
    cin >> opt;
    Doctor doc1("Dr Nafi", "drA.txt");



}