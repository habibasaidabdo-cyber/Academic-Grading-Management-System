#include "dataloader.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include "course.h"
#include "assignment.h"
#include "assignmentsolution.h"
#include "doctor.h"
#include "student.h"
using std::string;
using std::vector;
using std::shared_ptr;
using std::ifstream;


vector<shared_ptr<student>> S;
vector<shared_ptr<doctor>> D;
vector<shared_ptr<assignment>> A;
vector<shared_ptr<assignmentsolution>> AS;
vector<shared_ptr<course>> C;
//==============================================//
void Lstudent(const string& filename)
{
	ifstream inputstream(filename);
	string line ;
	
	while (std::getline(inputstream,line)) {
		std::stringstream s(line);
		string id, username, password, name, email;
		std::getline(s, id,',');
		std::getline(s, username, ',');
		std::getline(s, password, ',');
		std::getline(s, name, ',');
		std::getline(s, email);
		auto ss = std::make_shared<student>();
		ss->Id = id;
		ss->UserName = username;
		ss->Password = password;
		ss->Name = name;
		ss->Email = email;
		S.push_back(ss);
	}
}
//=============================================//
void Ldoctors(const string& filename)
{
	ifstream inputstream(filename);
	string line;

	while (std::getline(inputstream, line)) {
		std::stringstream s(line);
		string id, username, password, name, email;
		std::getline(s, id, ',');
		std::getline(s, username, ',');
		std::getline(s, password, ',');
		std::getline(s, name);
		
		auto ss = std::make_shared<doctor>();
		ss->Id = id;
		ss->UserName = username;
		ss->Password = password;
		ss->Name = name;
	
		D.push_back(ss);
	}
}
//============================================//
void Lcourse(const string& filename)
{
	ifstream inputstream(filename);
	string line;

	while (std::getline(inputstream, line)) {
		std::stringstream s(line);
		string id, code, name, doctorid;
		std::getline(s, id, ',');
		std::getline(s, code, ',');
		std::getline(s, name, ',');
		std::getline(s, doctorid);

		auto ss = std::make_shared<course>();
		ss->Id = id;
		ss->Code = code;
		ss->Name = name;
		for (auto& d : D) {
			if (d->Id == doctorid) {
				ss->Doctor = d;               // point to doctor
				d->TeachingCourse.push_back(ss); // doctor also points to course
				break;
			}


		}
		C.push_back(ss);
	}
}
//============================================//
void Lassignment(const string& filename)
{
	ifstream inputstream(filename);
	string line;

	while (std::getline(inputstream, line)) {
		std::stringstream s(line);
		string id, courseid, content, maxgrade;
		std::getline(s, id, ',');
		std::getline(s, courseid, ',');
		std::getline(s, content, ',');
		std::getline(s, maxgrade);
		int a;
		std::stringstream b(maxgrade);
		b >> a;


		auto ss = std::make_shared<assignment>();
		ss->Id = id;
		ss->Content = content;
		ss->MaxGrade = a;
		for (auto& j : C) {
			if (j->Id == courseid) {
				ss->Course = j;
				j->Assignment.push_back(ss);
				break;
			}


		}
		A.push_back(ss);
	}
}
//============================================//
void Lregistered(const string& filename)
{
	ifstream inputstream(filename);
	string line;

	while (std::getline(inputstream, line)) {
		std::stringstream s(line);
		string studentId, courseId;

		// parse line: "S1,C1"
		std::getline(s, studentId, ',');
		std::getline(s, courseId);

		// find course
		shared_ptr<course> foundCourse = nullptr;
		for (auto& c : C) {
			if (c->Id == courseId) {
				foundCourse = c;
				break;
			}
		}

		// find student and link both ways
		for (auto& st : S) {
			if (st->Id == studentId && foundCourse) {
				st->RegisterCourse.push_back(foundCourse);
				foundCourse->RegisteredStudents.push_back(st);
				break; // done, no need to keep looping
			}
		}
	}
}
//============================================//
void Lsolution(const string& filename)
{

	ifstream inputstream(filename);
	string line;

	while (std::getline(inputstream, line)) {
		std::stringstream s(line);
		string studentId, solutionId,content2,grade;

		// parse line: "S1,C1"
		std::getline(s, solutionId, ',');
		std::getline(s, studentId,',');
		std::getline(s, content2, ',');
		std::getline(s,grade);
		int a;
		std::stringstream b(grade);
		b >> a;
		
		auto ss = std::make_shared<assignmentsolution>();
		ss->Grade = a;
		ss->Answer = content2;




		// find course
		shared_ptr<assignment> foundsolution = nullptr;
		for (auto& a : A) {
			if (a->Id == solutionId) {
				foundsolution = a;
				break;
			}
		}

		// find student and link both ways
		shared_ptr<student> foundStudent = nullptr;
		for (auto& st : S) {
			if (st->Id == studentId ) {
				foundStudent = st;
				break;
			}
		}
		if (foundsolution && foundStudent) {
			ss->Assignment = foundsolution;
			ss->Student = foundStudent;

			foundsolution->AssignmentSoultion.push_back(ss);
			foundStudent->AssignmentSoultion.push_back(ss);
		}
		AS.push_back(ss);
	}
}
//============================================//


