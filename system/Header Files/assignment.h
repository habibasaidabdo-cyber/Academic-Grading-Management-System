#pragma once
#include <string>
#include <vector>
#include <memory>

using std::vector;
using std::string;
using std::shared_ptr;
struct course ;
struct assignmentsolution ;


struct assignment {
    string Id;
    string Content;
    int MaxGrade ;
    shared_ptr<course> Course;
    vector<shared_ptr<assignmentsolution>> AssignmentSoultion;
};
