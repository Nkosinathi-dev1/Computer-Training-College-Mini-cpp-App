#pragma once

#include <iostream>
#include <cstring>

class Student {
private:
    int studentNumber;
    char name[30];
    char surname[30];

public:
    Student();
    void setStudent(int number, const char studentName[], const char studentSurname[]);
    void displayStudent();
};
