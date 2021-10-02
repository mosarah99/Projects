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
	string name;
	string no;
	string grade;
	int year;
	int sem;
	int marks;
public:
	// -- getters --
	string getName() { return name; }
	string getID() { return no; }
	string getGrade() { return grade; }
	int getYear() { return year; }
	int getSem() { return sem; }
	int getMarks() { return marks; }

	// -- setters --
	void setName(string newName) { name = newName; }
	void setID(string newCourseID) { no = newCourseID; }
	void setGrade(string newGrade) { grade = newGrade; }
	void setYear(int newYear) { year = newYear; }
	void setSem(int newSem) { sem = newSem; }
	void setMarks(int newMarks) { marks = newMarks; }

	// -- constructor
	course(string courseName, string courseID, int Year, int semester)
	{
		name = courseName;
		no = courseID;
		year = Year;
		sem = semester;
	}

	// class functions
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
	string getUsername() { return username; }
	string getPassword() { return password; }
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
		// For year 1
		if (year == 1) {
			if (semester == 1) {
				// add courses for year 1 semester 1
				courses.push_back(course("Physics", "PHY1105", year, semester));
				courses.push_back(course("Electrical-circuits-I", "EEE1101", year, semester));
				courses.push_back(course("Eectrical-circuits LAB I", "EEE1102", year, semester));
				courses.push_back(course("Mathmatics I", "MATH1101", year, semester));
				// Not all courses are added
			}
			else {
				// add courses for year 1 semester 2
				courses.push_back(course("Electrical circuirts II", "EEE1203", year, semester));
				courses.push_back(course("Electrical-circuits II lab", "EEE1202", year, semester));
				courses.push_back(course("Simulation Lab - I", "EEE1210", year, semester));
				courses.push_back(course("Mathmatics II", "MATH1203", year, semester));
				// Not all courses are added
			}
		}
		// For year 2
		else if (year == 2) {
			if (semester == 1) {
				// add courses for year 2 semester 1
				courses.push_back(course("Electronics", "EEE2103", year, semester));
				courses.push_back(course("ELECTRONICS LAB", "EEE2104", year, semester));
				courses.push_back(course("Programming lab", "EEE2110", year, semester));
				courses.push_back(course("Mathmatics III", "MATH2103", year, semester));
				// Not all courses are added
			}
			else {
				// add courses for year 2 semester 2
				courses.push_back(course("Electronics II", "EEE2201", year, semester));
				courses.push_back(course("Electronics II LAB", "EEE2202", year, semester));
				courses.push_back(course("ENERGY CONVERSION II", "EEE2203", year, semester));
				courses.push_back(course("Mathmatics V", "MATH 2203", year, semester));
				// Not all courses are added
			}
		}
		// For year 3
		else if (year == 3) {
			if (semester == 1) {
				// add courses for year 3 semester 1
				courses.push_back(course("Digital Electronics", "EEE3103", year, semester));
				courses.push_back(course("Digital Electronics II", "EEE3104", year, semester));
				courses.push_back(course("Signal system", "EEE3105", year, semester));
				courses.push_back(course("Electromagnets", "EEE3106", year, semester));
				// Not all courses are added
			}
			else {
				// add courses for year 3 semester 2
				courses.push_back(course("solid device", "EEE3201", year, semester));
				courses.push_back(course("power", "EEE3202", year, semester));
				courses.push_back(course("comunication theory", "EEE3203", year, semester));
				courses.push_back(course("comunication theory lab", "EEE3204", year, semester));
				// Not all courses are added
			}
		}
		// For year 4
		else {
			if (semester == 1) {
				// add courses for year 4 semester 1
				courses.push_back(course("Elective I", "EEE4103", year, semester));
				courses.push_back(course("Elective II", "EEE4102", year, semester));
				courses.push_back(course("Elective III", "EEE4105", year, semester));
				courses.push_back(course("Control system 1", "EEE4119", year, semester));
				// Not all courses are added
			}
			else {
				// add courses for year 4 semester 2
				courses.push_back(course("Project and thesis", "EEE4200", year, semester));
				courses.push_back(course("Elective V", "EEE4204", year, semester));
				courses.push_back(course("Elective VI", "EEE4239", year, semester));
				courses.push_back(course("Elective VII", "EEE4206", year, semester));
				// Not all courses are added
			}
		}

	}

	// other class functions
	// add a new course for the student
	void addCourse(course newCourse) { courses.push_back(newCourse); }

	// set marks for a course
	void setCourseMarks(int courseIndex, int newMarks) {
		courses[courseIndex].setMarks(newMarks);
	}

	// set grade for a course
	void setCourseGrade(int courseIndex, string newGrade) {
		courses[courseIndex].setGrade(newGrade);
	}

	// search for a course and print its information
	void searchData(string courseID) {
		for (int i = 0; i < (int)courses.size(); i++) {
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
	void searchData() { // No-arg overloaded
		// The course no
		string courseno;

		// ask for course no
		cout << "\nEnter course ID to search for: ";
		cin >> courseno;

		// search for the course
		searchData(courseno);
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
		for (int i = 0; i < (int)courses.size(); i++) {
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
		for (int i = 0; i < (int)stu.getCourses().size(); i++) {
			int course_marks = stu.getCourses()[i].getMarks();
			total_mark += course_marks;
			++num_sub;

			if (course_marks >= 80) stu.setCourseGrade(i, "A+");
			else if (course_marks >= 75) stu.setCourseGrade(i, "A");
			else if (course_marks >= 70) stu.setCourseGrade(i, "A-");
			else if (course_marks >= 65) stu.setCourseGrade(i, "B+");
			else if (course_marks >= 60) stu.setCourseGrade(i, "B");
			else if (course_marks >= 55) stu.setCourseGrade(i, "B-");
			else if (course_marks >= 50) stu.setCourseGrade(i, "C+");
			else if (course_marks >= 45) stu.setCourseGrade(i, "C");
			else if (course_marks >= 40) stu.setCourseGrade(i, "D");
			else {
				stu.setCourseGrade(i, "F");
				hasFailed = true;
			}
		}

		// calculate overall grade
		if (hasFailed == true) { // if failed in at least 1 course, failed in the whole semester
			stu.setGrade("F");
		}
		else { // passed in all courses
			// average marks to calculate grade
			double avg_marks = (double)total_mark / num_sub;

			// calculate overall grade
			if (avg_marks >= 80.0) stu.setGrade("A+");
			else if (avg_marks >= 75.0) stu.setGrade("A");
			else if (avg_marks >= 70.0) stu.setGrade("A-");
			else if (avg_marks >= 65.0) stu.setGrade("B+");
			else if (avg_marks >= 60.0) stu.setGrade("B");
			else if (avg_marks >= 55.0) stu.setGrade("B-");
			else if (avg_marks >= 50.0) stu.setGrade("C+");
			else if (avg_marks >= 45.0) stu.setGrade("C");
			else if (avg_marks >= 40.0) stu.setGrade("D");
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
		for (int i = 0; i < (int)newStudent.getCourses().size(); i++) {
			int course_marks = 0;
			cout << "Course: " << newStudent.getCourses()[i].getName() << " - " << newStudent.getCourses()[i].getID() << endl;
			cout << "Enter marks: ";
			cin >> course_marks;
			newStudent.setCourseMarks(i, course_marks);
		}
		cout << "All marks recorded.\n" << endl;

		// calculate the grades
		result rslt;
		rslt.calculateResult(newStudent);

		// Add student to student vector
		all_students.push_back(newStudent);

		// confirmation
		cout << "New student added\n\n" << endl;
	}

	// edit student
	void editData() {
		cout << "Which student do you want to edit? [Enter number]: " << endl;
		for (int i = 0; i < (int)all_students.size(); i++) {
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
		else if (option == 2) {
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
		cout << "\nValue changed\n\n" << endl;
	}

	// delete student
	void deleteData(int studentId) {
		// find the student
		for (int i = 0; i < (int)all_students.size(); i++) {
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
		for (int i = 0; i < (int)all_students.size(); i++) {
			cout << i << ". " << all_students[i].getId() << "\t" << all_students[i].getName() << endl;
		}
		int option;
		cin >> option;
		deleteData(all_students[option].getId());
	}

	// view student info
	void viewData(int studentId) {
		for (int i = 0; i < (int)all_students.size(); i++) {
			if (all_students[i].getId() == studentId) {
				cout << "Information of Student:" << endl;
				cout << "Name: " << all_students[i].getName() << endl;
				cout << "Student ID: " << all_students[i].getId() << endl;
				cout << "Department: " << all_students[i].getDept() << endl;
				cout << "Year: " << all_students[i].getYear() << ",\t" << "Semester: " << all_students[i].getSem() << endl;
				cout << "Overall grade: " << all_students[i].getGrade() << endl << endl;
				return;
			}
		}
	}
	void viewData() { // no-arg overloaded
		cout << "Which student do you want to view? [Enter number]: " << endl;
		for (int i = 0; i < (int)all_students.size(); i++) {
			cout << i << ". " << all_students[i].getId() << "\t" << all_students[i].getName() << endl;
		}
		int option;
		cin >> option;
		viewData(all_students[option].getId());
	}

	// search for a student
	void searchData(int studentId) {
		// search for the existence of the id
		for (int i = 0; i < (int)all_students.size(); i++) {
			if (all_students[i].getId() == studentId) {
				cout << "Student Found" << endl;
				viewData(studentId);
				return;
			}
		}

		// id not found
		cout << "No student found" << endl;
	}

	// -- getter --
	vector<student> getStudents() { return all_students; }
};

int main() {

	studentInfo mgmt;

	// Did the program quit
	bool program_quit = false;

	// as long as the program is running
	while (program_quit == false) {
		// welcome message
		cout << "Welcome to Grading Management System for EEE Department" << endl << endl;
		cout << "Please login to continue:" << endl;
		cout << " 1. Admin" << endl;
		cout << " 2. Student" << endl;
		cout << " 3. Quit Program\n" << endl;
		int opt_login;
		cin >> opt_login;

		// If admin wants to login
		if (opt_login == 1) {
			// ask for username and password
			string username, password;
			cout << "Enter username: ";
			cin >> username;
			cout << "Enter password: ";
			cin >> password;

			// verify username and password
			if (username == "admin" && password == "austeee") {

				cout << "\n\nAdmin login successful" << endl;
				cout << "===============================" << endl;

				// Admin action option
				int opt_admin_access = 0;

				// Admin actions
				do
				{
					// select action
					cout << " 1. Register a student" << endl;
					cout << " 2. Modify student data" << endl;
					cout << " 3. Delete student data" << endl;
					cout << " 4. View student info" << endl;
					cout << " 5. Search for a student" << endl;
					cout << " 6. Logout\n" << endl;
					cout << "Select an option: ";

					cin >> opt_admin_access;

					// performing actions
					// Register a new student
					if (opt_admin_access == 1) {
						mgmt.newData();
					}
					// Modify an existing student
					else if (opt_admin_access == 2) {
						mgmt.editData();
					}
					// delete a student info
					else if (opt_admin_access == 3) {
						mgmt.deleteData();
					}
					// View student info
					else if (opt_admin_access == 4) {
						mgmt.viewData();
					}
					// Search for a student using student ID
					else if (opt_admin_access == 5) {
						int stu_id = 0;
						cout << "\n  Enter student ID: ";
						cin >> stu_id;
						mgmt.searchData(stu_id);
					}

				} while (opt_admin_access != 6); // Run the loop as long as admin does not logout

				cout << "\n\n Logout Successful" << endl;
				cout << " ==============================\n" << endl;
			} // end password verification
			else {
				cout << "\nWrong Password\n\n" << endl;
			}
		} // end admin login

		// Else student wants to login
		else if (opt_login == 2) {

			// Ask for student username and password
			string username, password;
			cout << "Enter username: ";
			cin >> username;
			cout << "Enter password: ";
			cin >> password;

			// index of the student in the student list: vector<student>
			int student_index;
			// if the student is found or not can be understood
			bool student_found = false;

			// search for a student with a matching username and password
			for (int i = 0; i < (int)mgmt.getStudents().size(); i++) {

				string stu_username = mgmt.getStudents()[i].getUsername();
				string stu_password = mgmt.getStudents()[i].getPassword();

				// check if username and password of student matches
				if (username == stu_username && password == stu_password) { // student found
					student_found = true;

					// record the index of the student for student access
					student_index = i;

					// break the loop because the student is already found
					break;
				}
			}

			// Check if the student was found with the username and password or not
			if (student_found == true) { // if the student is found

				// Getting the student information
				student stu = mgmt.getStudents()[student_index];

				// successful login information
				cout << "\n\nStudent login successful" << endl;
				cout << "===============================\n" << endl;

				// student action options
				int opt_student_action;

				do
				{
					cout << " 1. Search for course specific info" << endl;
					cout << " 2. View result" << endl;
					cout << " 3. Logout\n" << endl;
					cout << "Select an option: ";

					cin >> opt_student_action;

					// Performing actions
					// view course specific information
					if (opt_student_action == 1) {
						stu.searchData();
					}
					// View result
					else if (opt_student_action == 2) {
						stu.viewResult();
					}

				} while (opt_student_action != 3); // As long as student does not log out

				cout << "\n\n Logout Successful" << endl;
				cout << " ==============================\n" << endl;
			} // end student found
			// when student not found
			else {
				cout << "Login unsuccessful.\n\n" << endl;
			}
		} // end student login

		// Quit program
		else {
			program_quit = true;
		}

	} // end program_quit

	// program return
	return 0;
} // end main