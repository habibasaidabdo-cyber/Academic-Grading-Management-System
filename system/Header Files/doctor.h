#pragma once
#include <string>
#include <vector>
#include <memory>
using std::vector;
using std::string;
using std::shared_ptr;
#include "course.h"

struct doctor {
    string Id;
    string UserName;
    string Password;
    string Name;
    vector<shared_ptr<course>> TeachingCourse;
};