#pragma once

#include "Student.h"
#include <string>

class SecondYearStudent : public Student {
private:
    std::string code[4];
    double assignment[4];
    double test[4];
    double predicate[4];
    double exam[4];
    double final[4];
    int testWeight;
    int assignmentWeight;

public:
    SecondYearStudent();
    void setStudent(int number, const char studentName[], const char studentSurname[], std::string subjectCodes[], double assignmentMarks[], double testMarks[]);
    void calcPredicate();
    void calcFinalMark();
    double determineStudentAvg();
    void displayStudent();
};
