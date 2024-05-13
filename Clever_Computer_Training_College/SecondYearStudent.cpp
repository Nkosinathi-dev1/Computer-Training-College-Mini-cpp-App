#include "SecondYearStudent.h"
#include <cstdlib>

SecondYearStudent::SecondYearStudent() : testWeight(60), assignmentWeight(40) {
    for (int i = 0; i < 4; ++i) {
        code[i] = "";
        assignment[i] = 0.0;
        test[i] = 0.0;
        predicate[i] = 0.0;
        exam[i] = 0.0;
        final[i] = 0.0;
    }
}

void SecondYearStudent::setStudent(int number, const char studentName[], 
    const char studentSurname[], std::string subjectCodes[], 
    double assignmentMarks[], double testMarks[]) 
{
    Student::setStudent(number, studentName, studentSurname);

    for (int i = 0; i < 4; ++i) {
        code[i] = subjectCodes[i];
        assignment[i] = assignmentMarks[i];
        test[i] = testMarks[i];
    }
}

void SecondYearStudent::calcPredicate() {
    for (int i = 0; i < 4; ++i) {
        predicate[i] = (assignment[i] * assignmentWeight + test[i] * testWeight) / 100.0;
    }
}

void SecondYearStudent::calcFinalMark() {
    for (int i = 0; i < 4; ++i) {
        exam[i] = rand() % 101;
    }

    for (int i = 0; i < 4; ++i) {
        final[i] = (predicate[i] + exam[i]) / 2.0;
    }
}

double SecondYearStudent::determineStudentAvg() {
    double totalFinalMark = 0.0;

    for (int i = 0; i < 4; ++i) {
        totalFinalMark += final[i];
    }

    return totalFinalMark / 4.0;
}

void SecondYearStudent::displayStudent() {
    Student::displayStudent();

    calcPredicate();
    calcFinalMark();

    for (int i = 0; i < 4; ++i) {
        std::cout << "\t\t" << code[i];
        std::cout << "\t: " << std::round(predicate[i] * 10.0) / 10.0;
        std::cout << "\t" << exam[i];
        std::cout << "\t" << final[i] <<"%"<< std::endl;
    }

    std::cout << "Average: " << determineStudentAvg() << std::endl;
}
