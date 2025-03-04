#include "StudentFunctions.h"
#include <string>  


int compareNames(const Student& student1, const Student& student2) {
    if (student1.getName() == student2.getName()) {
        return 0;  
    } else if (student1.getName() > student2.getName()) {
        return 1;  
    } else {
        return -1;  
    }
}

int compareMathGrades(const Student& student1, const Student& student2) {
    if (student1.getMathGrade() == student2.getMathGrade()) {
        return 0;  
    } else if (student1.getMathGrade() > student2.getMathGrade()) {
        return 1; 
    } else {
        return -1;  
    }
}

int compareEnglishGrades(const Student& student1, const Student& student2) {
    if (student1.getEnglishGrade() == student2.getEnglishGrade()) {
        return 0; 
    } else if (student1.getEnglishGrade() > student2.getEnglishGrade()) {
        return 1;  
    } else {
        return -1;  
    }
}

int compareHistoryGrades(const Student& student1, const Student& student2) {
    if (student1.getHistoryGrade() == student2.getHistoryGrade()) {
        return 0;  
    } else if (student1.getHistoryGrade() > student2.getHistoryGrade()) {
        return 1; 
    } else {
        return -1;  
    }
}

int compareAverageGrades(const Student& student1, const Student& student2) {
    if (student1.getAverageGrade() == student2.getAverageGrade()) {
        return 0;  
    } else if (student1.getAverageGrade() > student2.getAverageGrade()) {
        return 1;  
    } else {
        return -1; 
    }
}
