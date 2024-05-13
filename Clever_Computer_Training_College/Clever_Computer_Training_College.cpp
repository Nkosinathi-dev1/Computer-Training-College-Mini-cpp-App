#include <iostream>
#include "RunSemTest2.h"
#include "SecondYearStudent.h"

int main() {
    const int numStudents = 4;
    SecondYearStudent students[numStudents];
    loadStudentInfo("Students.txt", students);

    std::cout << "Loaded Student Information:" << std::endl;
    for (int i = 0; i < numStudents; ++i) {
        students[i].displayStudent();
        std::cout << std::endl;
    }

    return 0;
}
