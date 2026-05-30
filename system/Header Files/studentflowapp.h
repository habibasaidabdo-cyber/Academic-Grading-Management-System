#pragma once
#include "dataloader.h"
#include <string>
#include <memory>
using std::string;
using std::shared_ptr;

void coursereg( shared_ptr<student> s);
void courselist( shared_ptr<student> s);
void showgrade(shared_ptr<student>s);
