#include "Course.h"
#include<iostream>
#include<vector>
#include <algorithm>


Course::Course(const std::string& CourseID, int courseCredits,int capacity, int instructorId) : CourseID(CourseID), Credits(courseCredits) , Capacity(capacity), InstructorId(instructorId){};

//Getters
std::string Course::getCourseId() const{ return CourseID;}
int Course::getCredits() const{ return Credits;}
int Course::getCapacity() const{return Capacity;}
int Course::getEnrolledCount() const{return Enrolled_Students.size();}
  
//Course add/remove 
bool Course::isFull() const  {
    return Enrolled_Students.size() >= getCapacity();
}

bool Course::hasSpace() const {
    return !isFull(); 
}


bool Course::addStudent(int StudentID){

    if(isFull() || std::find(Enrolled_Students.begin(), Enrolled_Students.end(), StudentID) != Enrolled_Students.end()){
        return false;
    }
    else {
        Enrolled_Students.push_back(StudentID);
        return true;
     };

}

bool Course::removeStudent(int StudentID){

    auto RemoveStu = std::find(Enrolled_Students.begin(), Enrolled_Students.end(), StudentID);

    if (RemoveStu != Enrolled_Students.end()) {
        Enrolled_Students.erase(RemoveStu);
        return true;
    }

    return false;
};
