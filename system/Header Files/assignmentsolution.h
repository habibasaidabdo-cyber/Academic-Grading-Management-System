#pragma once
#include <string>
#include <vector>
#include <memory>
using std::vector;
using std::string;
using std::shared_ptr;
struct student ;
struct assignment ;
struct assignmentsolution {
    int Grade;
    string Answer;
    shared_ptr<assignment> Assignment;
    shared_ptr<student> Student;
};