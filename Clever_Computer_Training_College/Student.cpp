#pragma warning(disable: 4996) // Disable warning about strncpy being unsafe
#include "Student.h"

Student::Student() : studentNumber(0) {
    std::memset(name, '\0', sizeof(name));
    std::memset(surname, '\0', sizeof(surname));
}

void Student::setStudent(int number, const char studentName[], const char studentSurname[]) {
    studentNumber = number;
    std::strncpy(name, studentName, sizeof(name) - 1);
    name[sizeof(name) - 1] = '\0';
    std::strncpy(surname, studentSurname, sizeof(surname) - 1);
    surname[sizeof(surname) - 1] = '\0';
}

void Student::displayStudent() {
    std::cout << studentNumber <<"\t";
    std::cout << name <<"\t";
    std::cout << surname << std::endl;
}
