#include "downloadingdata.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include "course.h"
#include "assignment.h"
#include "assignmentsolution.h"
#include "doctor.h"
#include "student.h"
#include <limits>
#include "dataloader.h"

using std::string;
using std::vector;
using std::shared_ptr;
using std::ofstream;

void regcourses(const string& filename,shared_ptr<course> c,shared_ptr<student> s) 
{
	s->RegisterCourse.push_back(c);
	c->RegisteredStudents.push_back(s);
	ofstream ecourse;
	string outpath = filename;
	ecourse.open(outpath.c_str(), std::ios::app);
	ecourse << s->Id << "," << c->Id;
	ecourse.close();


}
void addsolution(const string& filename, std::shared_ptr<assignment> a, std::shared_ptr<student> s) 
{

	std::cout << "Enter your answer: ";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	string answer;
	std::getline(std::cin, answer);
	ofstream newanswer;
	auto sol = std::make_shared<assignmentsolution>();
	sol->Assignment = a;
	sol->Student = s;
	sol->Answer = answer;
	sol->Grade = 0; 

	
	s->AssignmentSoultion.push_back(sol);
	a->AssignmentSoultion.push_back(sol);
	AS.push_back(sol);
	string outpath = filename;
	newanswer.open(outpath.c_str(), std::ios::app);
	newanswer << a->Id << "," << s->Id << "," << answer << ",0";
	newanswer.close();


}