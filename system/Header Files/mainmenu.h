#pragma once
#include "student.h"
#include "doctor.h"
#include <string>
#include <memory>

void studentmainmenue(std::shared_ptr<student> s);
void doctormainmenue(std::shared_ptr<doctor> d);
void signin();
void MainMenue();
