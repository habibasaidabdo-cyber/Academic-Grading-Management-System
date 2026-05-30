#pragma once
#include <string>
#include <vector>
#include <memory>
#include "student.h"
#include "course.h"

void regcourses(const std::string& filename,std::shared_ptr<course> c, std::shared_ptr<student> s);
void addsolution(const std::string& filename, std::shared_ptr<assignment> a, std::shared_ptr<student> s);
