#include <iostream>
#include "Student.h"
#include "StudentFunctions.h"

using namespace std; 

int main() {
    Student student;
    student.setName("John Smith");
    student.setMathGrade(10);
    student.setEnglishGrade(7.8f);
    student.setHistoryGrade(8.5f);

    cout << "Student's Name: " << student.getName() << endl;
    cout << "Math Grade: " << student.getMathGrade() << endl;
    cout << "English Grade: " << student.getEnglishGrade() << endl;
    cout << "History Grade: " << student.getHistoryGrade() << endl;
    cout << "Average Grade: " << student.getAverageGrade() << endl;

    Student student2;
    student2.setName("Jane Smith");
    student2.setMathGrade(-11.1f);
    student2.setEnglishGrade(0);
    student2.setHistoryGrade(9999);
    //nu vor merge si vor ramane 1
    cout << "Student's Name: " << student2.getName() << endl;
    cout << "Math Grade: " << student2.getMathGrade() << endl;
    cout << "English Grade: " << student2.getEnglishGrade() << endl;
    cout << "History Grade: " << student2.getHistoryGrade() << endl;
    cout << "Average Grade: " << student2.getAverageGrade() << endl;

    student2.setMathGrade(7.6);
    student2.setEnglishGrade(10);
    student2.setHistoryGrade(8.5);
    cout << "Student's Name: " << student2.getName() << endl;
    cout << "Math Grade: " << student2.getMathGrade() << endl;
    cout << "English Grade: " << student2.getEnglishGrade() << endl;
    cout << "History Grade: " << student2.getHistoryGrade() << endl;
    cout << "Average Grade: " << student2.getAverageGrade() << endl;

    cout << endl;
    cout << "Name comparison result: " << compareNames(student, student2) << endl;
    cout << "Math grade comparison result: " << compareMathGrades(student, student2) << endl;
    cout << "English grade comparison result: " << compareEnglishGrades(student, student2) << endl;
    cout << "History grade comparison result: " << compareHistoryGrades(student, student2) << endl;
    cout << "Average grade comparison result: " << compareAverageGrades(student, student2) << endl;


    return 0;
}
