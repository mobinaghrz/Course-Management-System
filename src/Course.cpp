#include "Course.h"
#include<iostream>
#include<vector>

Course::Course(const std::string& courseName, int courseCredits): name(courseName), credits(courseCredits) {};

bool Course::addStudent(int StudentID){
    if(std::find(Enrolled_Students.begin(), Enrolled_Students.end(), StudentID) != Enrolled_Students.end()){
        return 0;
    }

    else {
        Enrolled_Students.insert(Enrolled_Students.end(),StudentID);
        return 1;
    };
};
