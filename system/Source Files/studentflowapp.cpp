#include "studentflowapp.h"
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "student.h"
#include "doctor.h"
#include "dataloader.h"
#include "downloadingdata.h"
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::shared_ptr;
//===================================//
void coursereg(shared_ptr<student> s)
{
    while (true) {
        cout << "Your available courses are:\n";

        vector<shared_ptr<course>> unregistered;
        for (auto& c : C) {

            bool alreadyRegistered = false;
            for (auto& rc : s->RegisterCourse) {
                if (rc->Id == c->Id) {
                    alreadyRegistered = true;
                    break;
                }
            }

            if (!alreadyRegistered) {
                unregistered.push_back(c);
            }
        }
        if (unregistered.empty()) {
            cout << "You already registered in all courses.\n";
            return;
        }

        int i = 1;
        for (auto& c : unregistered) {
            cout << i++ << ". " << c->Name
                << " | Code: " << c->Code
                << " | ID: " << c->Id << "\n";
        }

        cout << "What you can do: \n1.Register for a course.\n2.back.\nEnter your choice: ";
        int b;
        cin >> b;
        if (cin.fail()) {
            cout << "Please ,enter an integer number.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        if (b == 1)
        {
            cout << "Choose your course number from the above list.\nEnter your choice: ";
            cin >> b;
            if (cin.fail()||b<1||b>=i) {
                cout << "Please ,enter a valid number.\n";
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }
            auto selected = unregistered[b - 1];
            regcourses("registerd.txt", selected, s);
            cout << "Successfully registered in: " << selected->Name << "\n";
        }
        else if (b == 2) {
            return;
        }
        else
        {
            cout << "You enter a wrong number .Try again";
        }
    }
}
//==================================//
void courselist(shared_ptr<student> s)
{
    while (true)
    {
        cout << "Your course list is: \n";
        if (s->RegisterCourse.empty()) {
            cout << "You are not registered in any courses yet.\n";
            return;
        }
        int i = 1;
      
            for (auto& rc : s->RegisterCourse) {
              
                    cout << i++ << ". " << rc->Name
                        << " | Code: " << rc->Code
                        << " | ID: " << rc->Id << "\n";
                
            }
        
        cout << "You can either : \n1.view any of your courses.\n2.back.\nEnter your choice: \n";
        int b;
        cin >> b;
        if (cin.fail()) {
            cout << "Please, enter an integer.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        if (b == 1) {
            cout << "Select the number of the course you want to view.\nEnter your choice: \n";
            int coursenumber;
            cin >> coursenumber;
            if (cin.fail() || coursenumber<1 || coursenumber >=i) {
                cout << "Please, enter a valid number.\n ";
                cin.clear();
                cin.ignore(1000,'\n');
            }
            else{
                auto selected = s->RegisterCourse[coursenumber - 1];
                cout << "Your course: " << selected->Name << " course code: " << selected->Code
                    << " taught by: " << selected->Doctor->Name;
                cout << " your assignment: \n";
                if (selected->Assignment.empty()) {
                    cout << "You have no assignment.\n";
                }
                else{
                    i = 1;
                    for (auto& a : selected->Assignment) {
                         
                            cout << "\nCourse assignments: \n" << i++ << ". "<<a->Content << " |Maxgrade: "
                                << a->MaxGrade<<"\n";
                        
                    }
                }
            }
        }
        else if (b == 2) {
            return;
        }
        else {
            cout << "Please, enter 1 or 2.\n";
        }
    }
}
//=================================//
void showgrade(shared_ptr<student>s)
{
   while(true) {
       cout << "You have three option: \n1.Show your grade.\n2.Add solution for your assignment.\n3.back.\nEnter your choice: ";
       int b;
       cin >> b;
       if (cin.fail() || b < 1 || b>3) {
           cout << "Please enter a valid number.\n";
           cin.clear();
           cin.ignore(1000,'\n');
       }
       if(b==1)
       {
           cout << "You can now see your grade now: \n";
           vector<shared_ptr<assignmentsolution>> grade1;
           for (auto& as : AS) {
               if (as->Student == s)
                   grade1.push_back(as);
           }
           if (grade1.empty()) {
               cout << "You don't have any grade avliable.\n";
               continue;
           }
           int i = 1;
           for (auto& g : grade1) {
               cout << i++ << "your course name: " << g->Assignment->Course->Name << " |your content: " << g->Assignment->Content<<
                   " |your answer: "<<g->Answer << "|your grade: " << g->Grade << ".\n";
           }
       }
       if (b == 2) {
           cout << "Your needed assignmentsolution: \n";
           vector<shared_ptr<assignment>> solution1;
           for (auto& a : A) {
               bool alreadyhaving = false;
               for (auto& g : s->AssignmentSoultion) {
                   if (g->Assignment == a) {
                       alreadyhaving = true;
                       break;
                   }
                   
               }
               if (!alreadyhaving) {
                   solution1.push_back(a);
               }
           }
           if (solution1.empty()) {
               cout << "You ends all your assignment.\n";
               continue;
           }
          int  i = 1;
           for (auto& n : solution1) {
               cout << i++ << "." << "Course: " << n->Course->Name << " |Content" << n->Content <<
                   n->MaxGrade<<"\n";
           }
           cout << "Plese, either enter your assignment number or you can click -1 to go back.\n";
           int choice;
           cin >> choice;
           if (cin.fail() || choice < -1 || choice >= i) {
               cout << "Please, enter a valid number.\n";
               cin.clear();
               cin.ignore(1000, '\n');
           }
           if (choice == -1) {
               continue;
           }
           auto selected = solution1[choice - 1];
           addsolution("assignmentsolution.txt", selected, s);
           cout << "\nYou added a new solution.\n";
       }
       if (b == 3) {
           return;
       }
   }
   
}