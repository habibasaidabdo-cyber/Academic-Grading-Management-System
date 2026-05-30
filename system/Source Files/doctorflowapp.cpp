#include "doctorflowapp.h"
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "student.h"
#include "doctor.h"
#include "dataloader.h"
#include "downloadingdata.h"
#include "fstream"
#include <limits>
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::shared_ptr;
using std::ofstream;
//============================================//
void createcourse(std::shared_ptr<doctor> d)
{
	while(true){
		cout << "\nYou can now create a course.If you want to continue press 1 if you want to go back press 0\n";
		int choice;
		cin >> choice;
		if (cin.fail() || choice < 0 || choice>1) {
			cout << "Please enter a valid number.\n";
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}
		if (choice == 0) {
			return;
		}
		if (choice == 1) {
			while(true){
				cout << "First enter your course id: ";
				string courseid;
				cin >> courseid;
				cout << "\nThen enter your course code: ";
				string coursecode;
				cin >> coursecode;
				cout << "\nThen enter your course name: ";
				string coursename;
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::getline(cin, coursename);
				cout << "Click 1 to confirm that is the right data either click 0\n";
				cin >> choice;
				if (cin.fail() || choice < 0 || choice>1) {
					cout << "Please enter a valid number and data.\n";
					cin.clear();
					cin.ignore(1000, '\n');
					continue;
				}
				if (choice == 0) {
					return;
				}
				if (choice == 1) {
					cout << "your course will be avliable now on the system.\n";
					auto newCourse = std::make_shared<course>();
					newCourse->Id = courseid;
					newCourse->Code = coursecode;
					newCourse->Name = coursename;
					newCourse->Doctor = d;
					d->TeachingCourse.push_back(newCourse);
					C.push_back(newCourse);
					ofstream newcourses;
					string outpath = "course.txt";
					newcourses.open(outpath.c_str(), std::ios::app);
					newcourses << courseid << "," << coursecode << "," << coursename << "," << d->Id;
					newcourses.close();
					break;
				}

			}
		}
	}
}
//===========================================//
void addassignment(std::shared_ptr<doctor> d)
{
	while (true) {
		cout << "\nYou can add new assignment to your courses.\n";
		int i = 1;
		cout << "\nYour courses are: \n";
		vector<shared_ptr<course>> doccourse;
		for (auto c : C) {
			if (c->Doctor == d) {
				cout << i++ << "." << c->Name << " |" << c->Code<<"\n";
				doccourse.push_back(c);
			}
		}
		if (doccourse.empty()) {
			cout << "You have no courses yet. Please create a course first.\n";
			return;
		}
		cout << "click 1 of you want to choose one of your course or click 0 to go back.\n";
		int choice;
		cin >> choice;
		if (cin.fail() || choice < 0 || choice>1) {
			cout << "Please enter a valid number.\n";
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}
		if (choice == 0) {
			return;
		}
		if (choice == 1) {
			while(true){
				cout << "now choose the course you want to add assignment to.\nEnter your choice: ";
				cin >> choice;
				if (cin.fail() || choice < 1 || choice >= i) {
					cout << "Please enter a valid number.\n";
					cin.clear();
					cin.ignore(1000, '\n');
					continue;
				}
				auto selected = doccourse[choice - 1];
				cout << "\nEnter assignment id: ";
				string assignmentid;
				cin >> assignmentid;
				cout << "\nEnter assignment content: ";
				string assignmentcontent;
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::getline(cin, assignmentcontent);
				cout << "\nEnter max grade: ";
				int maxgrade;
				cin >> maxgrade;
				if (cin.fail() || maxgrade < 0) {
					cout << "Please, enter a logical grade for your assignment.\n";
					cin.clear();
					cin.ignore(1000, '\n');
					continue;
				}
				cout << "\nClick 1 to confirm 0 to go back.\n";
				cin >> choice;
				if (cin.fail() || choice < 0 || choice>1) {
					cout << "Please enter a valid number and data.\n";
					cin.clear();
					cin.ignore(1000, '\n');
					continue;
				}
				if (choice == 0) {
					break;
				}
				if (choice == 1) {
					auto newassignment = std::make_shared<assignment>();
					newassignment->Id = assignmentid;
					newassignment->Content = assignmentcontent;
					newassignment->MaxGrade = maxgrade;
					newassignment->Course = selected;
					selected->Assignment.push_back(newassignment);
					A.push_back(newassignment);
					ofstream newAssignment;
					string outpath = "assignment.txt";
					newAssignment.open(outpath.c_str(), std::ios::app);
					newAssignment << assignmentid << "," << selected->Id << "," << assignmentcontent << "," << maxgrade;
					newAssignment.close();
					cout << "You added a new assignment on the system.\n";
					break;
				}
				
			}
		}
	}
}
//==========================================//
