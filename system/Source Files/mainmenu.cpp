#include "mainmenu.h"
#include "studentflowapp.h"
#include "doctorflowapp.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "student.h"
#include "doctor.h"
#include "dataloader.h"
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::shared_ptr;


void studentmainmenue(shared_ptr<student> s) {
	while (true) {
		cout << "Welcome ,student " << s->Name << " .You are logged in.\n";
		cout << "Please, make a choice: \n";
		cout << "1.Register in course.\n2.List my courses.\n3.Grade reports.\n4.Log out.\nEnter your choice: \n";
		int b;
		cin >> b;
		if (cin.fail()) {
			cout << "Please enter an integer number.\n";
			cin.clear();
			cin.ignore(1000,'\n');
			continue;
		}

		else if (b == 1)
		{
			coursereg(s);
		}
		else if (b == 2)
		{
			courselist(s);
		}
		else if (b == 3)
		{
			showgrade(s);
		}
		else if (b == 4) 
		{
			cout << "You are logging out.\n";
			return;
		}
		else
		{
			cout << "Please, enter an integer number from 1 to 4";
		}
	}
}
void doctormainmenue(shared_ptr<doctor> d) {
	while (true) {
		cout << "Welcome ,Doctor " << d->Name << ". You are logged in.\n";
		cout << "Please, make a choice: \n";
		cout << "1.create new course.\n" << "2.add new assignment.\n" << "3.log out.\n";
		cout << "Enter your choice: \n";
		int choice;
		cin >> choice;
		if (cin.fail() || choice < 1 || choice>3) {
			cout << "Please enter a valid number.\n";
			cin.clear();
			cin.ignore(1000,'\n');
			continue;
		}
		if (choice == 1) {
			createcourse(d);
		}
		if (choice == 2) {
			addassignment(d);
		}
		
		if (choice == 3) {
			cout << "You are logged out.\n";
			return;
		}

	}
}

void signin() {
	while (true) {
		string us, ps;
		cout << "ENTER YOUR USERNAME: \n";
		cin >> us;
		cout << "ENTER YOUR PASSWORD: \n";
		cin >> ps;
		
		for (auto& s : S) {
			if (s->UserName == us && s->Password == ps) {
				studentmainmenue(s);
				return;

			}

		}

		for (auto& d : D) {
			if (d->UserName == us && d->Password == ps) {
				doctormainmenue(d);
				return;
			}

		}
		cout << "Either your password or user name are incrroct ,please try again.\n";
		cout << "If you want to go back to the main menu click 1.\nIf you want to try again click any other number.\n";
		int b;
		cin >> b;
		if (cin.fail()) {
			cout << "You didn't choose an integer but you will go back to the sign in bage.\n";
			cin.clear();
			cin.ignore(1000, '\n');
		}
		if (b == 1) {
			return;
		}
	}
		

}
void MainMenue() 
{ 
	
	cout << "This your main menu .\nyou can \n1.sign in\n2.shut down the program\nchoose 1 to sign or 2 to shut down\nEnter your choice: ";
	int number;
	cin >> number;
	if (cin.fail()) {
		cout << "Please, Enter an integer number .\n";
		cin.clear();
		cin.ignore(1000, '\n');
		return MainMenue();
	}
	if (number == 1) {
		signin();
		MainMenue();
	}

	else if (number == 2) {
		return ;
	}

	else {
		cout << "Please , Enter number 1 to sign in or 2 to shut down.\n";
		cin.clear();
		cin.ignore(1000, '\n');
		return MainMenue();
	}
	

}