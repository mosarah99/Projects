/*!	\author	mosarah99
*	\date Oct 2021
* 
*	Grading Management System for EEE Department 
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class course {

};

class student {
private:
	string name;
	int id;
	vector<course> courses;
	string username;
	string password;
	int year;
	int semester;
	string department;
	string grade;
public:
	// accessors
	int getYear() { return year; }
	int getSem() { return semester; }
	string getName() { return name; }
	int getId() { return id; }
	string username() { return username; }
	string password() { return password; }
	string getDept() { return department; }
	string getGrade() { return grade; }
	vector<course> getCourses() { return courses; }

	// mutators
	void setYear(int newYear) { year = newYear; }
	void setSem(int newSem) { semester = newSem; }
	void setName(string newName) { name = newName; }
	void setId(int ID) { id = ID; }
	void setDept(string dept) { department = dept; }
	void setGrade(string overallGrade) { grade = overallGrade; }

	// constructor
	student(string name, int id, int year, int semester) {
		// assign name and id
		setName(name);
		setId(id);

		// assign year and semester
		setYear(year);
		setSem(semester);

		// assign username and password
		username = to_string(id);
		password = "student";
		
		// assign dept
		setDept("Electrical and Electronic Engineering");

		// create course objects according to the year and semester
		/*		:::: EXAMPLE ::::
		
		if (year == 1) {
			if (semester == 1) {
				courses.push_back(course("Physics", "PHY1105", 1, 1));
				// Add other courses similarly
			}
			else {
				// add courses for year 1 semester 2
			}
		}
		else if (year == 2) {
			// repeat
		}

		*/
	}

	// other class functions
	// add a new course for the student
	void addCourse(course newCourse) { courses.push_back(newCourse); }

	// search for a course and print its information
	void searchData(string courseID) {
		for (int i = 0; i < courses.size(); i++) {
			if (courses[i].getID() == courseID) {
				// relevant course found

				course info = courses[i];
				// info of student
				cout << "Information of Student:" << endl;
				cout << "Name: " << getName() << endl;
				cout << "Student ID: " << getId() << endl;
				cout << "Department: " << getDept() << endl;
				cout << "Year: " << getYear() << ",\t" << "Semester: " << getSem() << endl << endl;
				// info of course
				cout << "Information of Course: " << endl;
				cout << "Course name: " << info.getName() << endl;
				cout << "Course Code: " << info.getID() << endl;
				cout << "Course grade: " << info.getGrade() << endl << endl;
				return;
			}
		}

		// no course found
		cout << "Error: No such course. " << endl;
	}

	// view the result of a student
	void viewResult() {
		// info of student
		cout << "Information of Student:" << endl;
		cout << "Name: " << getName() << endl;
		cout << "Student ID: " << getId() << endl;
		cout << "Department: " << getDept() << endl;
		cout << "Year: " << getYear() << ",\t" << "Semester: " << getSem() << endl;
		cout << "Overall grade: " << getGrade() << endl << endl;

		// info of courses
		for (int i = 0; i < courses.size(); i++) {
			// info of course
			cout << "Information of Course: " << endl;
			cout << "Course name: " << courses[i].getName() << endl;
			cout << "Course Code: " << courses[i].getID() << endl;
			cout << "Course grade: " << courses[i].getGrade() << endl << endl;
		}
	}
};

class result {
public:
	// calculates the grades from the marks
	void calculateResult(student& stu) {
		// variables to calculate overall grade
		int num_sub = 0, total_mark = 0;
		bool hasFailed = false;

		// calculate marks for every course
		for (int i = 0; i < stu.getCourses().size(); i++) {
			int course_marks = stu.getCourses()[i].getMarks();
			total_mark += course_marks;
			++num_sub;

			if (course_marks >= 80) stu.getCourses()[i].setGrade("A+");
			else if (course_marks >= 75) stu.getCourses()[i].setGrade("A");
			else if (course_marks >= 70) stu.getCourses()[i].setGrade("A-");
			else if (course_marks >= 65) stu.getCourses()[i].setGrade("B+");
			else if (course_marks >= 60) stu.getCourses()[i].setGrade("B");
			else if (course_marks >= 55) stu.getCourses()[i].setGrade("B-");
			else if (course_marks >= 50) stu.getCourses()[i].setGrade("C+");
			else if (course_marks >= 45) stu.getCourses()[i].setGrade("C");
			else if (course_marks >= 40) stu.getCourses()[i].setGrade("D");
			else {
				stu.getCourses()[i].setGrade("F");
				hasFailed = true;
			}
		}

		// calculate overall grade
		if (hasFailed == true) { // if failed in at least 1 course, failed in the whole semester
			stu.setGrade("F");
		}
		else { // passed in all courses
			// average marks to calculate grade
			int avg_marks = (double)total_mark / (num_sub * 100);

			// calculate overall grade
			if (avg_marks >= 80) stu.setGrade("A+");
			else if (avg_marks >= 75) stu.setGrade("A");
			else if (avg_marks >= 70) stu.setGrade("A-");
			else if (avg_marks >= 65) stu.setGrade("B+");
			else if (avg_marks >= 60) stu.setGrade("B");
			else if (avg_marks >= 55) stu.setGrade("B-");
			else if (avg_marks >= 50) stu.setGrade("C+");
			else if (avg_marks >= 45) stu.setGrade("C");
			else if (avg_marks >= 40) stu.setGrade("D");
			else stu.setGrade("F");
		}

	}

	// view result of a student
	void viewResult(student& stu) {
		// call the function/method of the student object
		stu.viewResult();
	}
};

class studentInfo {
	vector<student> all_students;
public:
	// adds new student
	void newData() {
		cout << "Registering new student . . ." << endl;
		
		// required variables
		string stu_name;
		int stu_year, stu_sem, stu_id;

		// input for new student
		cout << "Enter student name: ";
		cin >> stu_name;
		cout << "Enter student ID: ";
		cin >> stu_id;
		cout << "Enter year: ";
		cin >> stu_year;
		cout << "Enter semester: ";
		cin >> stu_sem;

		// add student
		student newStudent(stu_name, stu_id, stu_year, stu_sem);

		// Add marks for the courses
		cout << "Enter marks for the courses: " << endl;
		for (int i = 0; i < newStudent.getCourses().size(); i++) {
			int course_marks = 0;
			cout << "Course: " << newStudent.getCourses()[i].getName() << " - " << newStudent.getCourses()[i].getID() << endl;
			cout << "Enter marks: ";
			cin >> course_marks;
			newStudent.getCourses()[i].setMarks(course_marks);
		}
		cout << "All marks recorded." << endl;

		// calculate the grades
		result rslt;
		rslt.calculateResult(newStudent);

		// Add student to student vector
		all_students.push_back(newStudent);

		// confirmation
		cout << "New student added" << endl;
	}

	// edit student
	void editData() {
		cout << "Which student do you want to edit? [Enter number]: " << endl;
		for (int i = 0; i < all_students.size(); i++) {
			cout << i << ". " << all_students[i].getId() << "\t" << all_students[i].getName() << endl;
		}
		int student_index = 0;
		cin >> student_index;

		// variable to edit
		cout << "Which one do you want to edit? [Enter number]" << endl;
		cout << "1. Name" << endl;
		cout << "2. ID" << endl;
		cout << "3. Department" << endl;
		cout << "4. Year" << endl;
		cout << "5. Semester" << endl;
		int option = 0;
		cin >> option;

		// performing operation
		cout << "Enter new value: ";
		if (option == 1) {
			string newName;
			cin >> newName;
			all_students[student_index].setName(newName);
		}
		else if(option == 2){
			int id;
			cin >> id;
			all_students[student_index].setId(id);
		}
		else if (option == 3) {
			string dept;
			cin >> dept;
			all_students[student_index].setDept(dept);
		}
		else if (option == 4) {
			int year;
			cin >> year;
			all_students[student_index].setYear(year);
		}
		else {
			int sem;
			cin >> sem;
			all_students[student_index].setSem(sem);
		}

		// confirmation
		cout << "Value changed" << endl;
	}

	// delete student
	void deleteData(int studentId) {
		// find the student
		for (int i = 0; i < all_students.size(); i++) {
			if (all_students[i].getId() == studentId) {
				all_students.erase(all_students.begin() + i);

				// confirmation
				cout << "Student deleted" << endl;

				return;
			}
		}

		// failure
		cout << "Student not found" << endl;
	}
	void deleteData() { // no-arg overloaded function
		cout << "Which student do you want to delete? [Enter number]: " << endl;
		for (int i = 0; i < all_students.size(); i++) {
			cout << i << ". " << all_students[i].getId() << "\t" << all_students[i].getName() << endl;
		}
		int option;
		cin >> option;
		deleteData(all_students[option].getId());
	}

	// view student info
	void viewData(int studentId) {
		for (int i = 0; i < all_students.size(); i++) {
			if (all_students[i].getId() == studentId) {
				cout << "Information of Student:" << endl;
				cout << "Name: " << getName() << endl;
				cout << "Student ID: " << getId() << endl;
				cout << "Department: " << getDept() << endl;
				cout << "Year: " << getYear() << ",\t" << "Semester: " << getSem() << endl;
				cout << "Overall grade: " << getGrade() << endl << endl;
				return;
			}
		}
	}
	void viewData() { // no-arg overloaded
		cout << "Which student do you want to view? [Enter number]: " << endl;
		for (int i = 0; i < all_students.size(); i++) {
			cout << i << ". " << all_students[i].getId() << "\t" << all_students[i].getName() << endl;
		}
		int option;
		cin >> option;
		viewData(all_students[option].getId());
	}

	// search for a student
	student searchData(int studentId) {
		// search for the existence of the id
		for (int i = 0; i < all_students.size(); i++) {
			if (all_students[i].getId() == studentId) {
				cout << "Student Found" << endl;
				viewData(studentId);
				return all_students[i];
			}
		}

		// id not found
		cout << "No student found" << endl;
	}
};