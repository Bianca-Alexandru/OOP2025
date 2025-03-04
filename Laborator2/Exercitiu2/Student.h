#ifndef STUDENT_H
#define STUDENT_H

#include <string> 
using namespace std; 

class Student {
private:
    string name;     
    float grade[3];   //grade[0] = Math, grade[1] = English, grade[2] = History

public:
    Student();

    string getName() const;
    void setName(const string& name); 

    float getMathGrade() const;
    void setMathGrade(float grade);

    float getEnglishGrade() const;
    void setEnglishGrade(float grade);

    float getHistoryGrade() const;
    void setHistoryGrade(float grade);

    float getAverageGrade() const;
};

#endif
