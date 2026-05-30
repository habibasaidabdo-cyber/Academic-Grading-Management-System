#pragma once
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
extern vector<shared_ptr<student>> S;
extern vector<shared_ptr<doctor>> D;
extern vector<shared_ptr<assignment>> A;
extern vector<shared_ptr<assignmentsolution>> AS;
extern vector<shared_ptr<course>> C;
void Lstudent(const string & filename);
void Ldoctors(const string& filename);
void Lcourse(const string& filename);
void Lassignment(const string& filename);
void Lregistered(const string& filename);
void Lsolution(const string& filename);

