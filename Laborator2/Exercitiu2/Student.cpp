#include "Student.h"

Student::Student() {
    this->grade[0] = 1;
    this->grade[1] = 1;
    this->grade[2] = 1;
}

string Student::getName() const {
    return name; 
}

void Student::setName(const string& name) {
    this->name = name; 
}

float Student::getMathGrade() const {
    return grade[0]; 
}

void Student::setMathGrade(float grade) {
    if (grade >= 1 && grade <= 10)
        this->grade[0] = grade;  
}

float Student::getEnglishGrade() const {
    return grade[1];  
}

void Student::setEnglishGrade(float grade) {
    if (grade >= 1 && grade <= 10)
        this->grade[1] = grade; 
}

float Student::getHistoryGrade() const {
    return grade[2];
}

void Student::setHistoryGrade(float grade) {
    if (grade >= 1 && grade <= 10)
        this->grade[2] = grade;  
}

float Student::getAverageGrade() const {
    return (grade[0] + grade[1] + grade[2]) / 3.0;
}
