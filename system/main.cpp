#include "dataloader.h"
#include "mainmenu.h"






int main(int argc, char* argv[]) {
    Lstudent("student.txt");
    Ldoctors("doctor.txt");
    Lcourse("course.txt");
    Lassignment("assignment.txt");
    Lregistered("registerd.txt");
    Lsolution("assignmentsolution.txt");

   
    MainMenue();

    return 0;
}
