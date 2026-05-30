#pragma once
#include <memory>
#include "doctor.h"
void createcourse(std::shared_ptr<doctor> d);
void addassignment(std::shared_ptr<doctor> d);
void addgrades(std::shared_ptr<doctor> d);