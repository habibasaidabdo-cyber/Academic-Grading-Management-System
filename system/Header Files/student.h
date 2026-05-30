#pragma once
#include <string>
#include <vector>
#include <memory>
#include <tuple>
#include <map>
using std::map;
using std::tuple;
using std::vector;
using std::vector;
using std::string;
using std::shared_ptr;


#include "course.h"
#include "assignmentsolution.h"
#include "assignment.h"
struct student {
 
    string UserName;
    string Password;
    string Name;
    string Id;
    string Email;
    vector<shared_ptr<course>> RegisterCourse;
    vector<shared_ptr<assignmentsolution>> AssignmentSoultion;
};