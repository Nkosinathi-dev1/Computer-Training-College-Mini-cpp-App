#include "RunSemTest2.h"
#include <fstream>
#include <sstream>

void loadStudentInfo(std::string filename, SecondYearStudent students[]) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string subjectCodes[4] = { "DSO", "TPG", "ISY", "SSF" };

    std::string line;
    int index = 0;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string token;
        std::getline(iss, token, ','); 
        std::getline(iss, token, ','); 

        std::string surname;
        std::getline(iss, surname, ',');

        double assignmentMarks[4], testMarks[4];
        for (int i = 0; i < 4; ++i) {
            std::getline(iss, token, ','); 
            assignmentMarks[i] = std::stod(token);
            std::getline(iss, token, ','); 
            testMarks[i] = std::stod(token);
        }
        students[index].setStudent(index + 201601, surname.c_str(), surname.c_str(), subjectCodes, assignmentMarks, testMarks);
        ++index;
    }
    file.close();
}
