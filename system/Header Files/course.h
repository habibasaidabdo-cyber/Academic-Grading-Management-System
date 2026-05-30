#pragma once
#include <string>
#include <vector>
#include <memory>
using std::vector;
using std::string;
using std::shared_ptr;
struct doctor ;
struct student ;
struct assignment;
struct course {
    string Id;
    string Name;
    string Code;
    shared_ptr<doctor> Doctor;
    vector<shared_ptr<student>> RegisteredStudents;
    vector<shared_ptr<assignment>> Assignment;
};