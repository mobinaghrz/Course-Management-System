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

void Course::Save(std::ostream& out) const {
    // 1. Save CourseID (string - save length first, then data)
    size_t len = CourseID.length();
    out.write(reinterpret_cast<const char*>(&len), sizeof(len));
    out.write(CourseID.c_str(), len);
    
    // 2. Save Credits (int - direct write)
    out.write(reinterpret_cast<const char*>(&Credits), sizeof(Credits));
    
    // 3. Save Capacity (int)
    out.write(reinterpret_cast<const char*>(&Capacity), sizeof(Capacity));
    
    // 4. Save InstructorId (int)
    out.write(reinterpret_cast<const char*>(&InstructorId), sizeof(InstructorId));
    
    // 5. Save student count (how many students enrolled)
    size_t studentCount = Enrolled_Students.size();
    out.write(reinterpret_cast<const char*>(&studentCount), sizeof(studentCount));
    
    // 6. Loop and save each student ID
    for (int studentId : Enrolled_Students) {
        out.write(reinterpret_cast<const char*>(&studentId), sizeof(studentId));
    }
}

void Course::Load(std::istream& in) {
    // 1. Load CourseID (read length first, then read that many characters)
    size_t len;
    in.read(reinterpret_cast<char*>(&len), sizeof(len));
    CourseID.resize(len);
    in.read(&CourseID[0], len);
    
    // 2. Load Credits
    in.read(reinterpret_cast<char*>(&Credits), sizeof(Credits));
    
    // 3. Load Capacity
    in.read(reinterpret_cast<char*>(&Capacity), sizeof(Capacity));
    
    // 4. Load InstructorId
    in.read(reinterpret_cast<char*>(&InstructorId), sizeof(InstructorId));
    
    // 5. Load student count
    size_t studentCount;
    in.read(reinterpret_cast<char*>(&studentCount), sizeof(studentCount));
    
    // 6. Clear existing students and load each student ID
    Enrolled_Students.clear();
    for (size_t i = 0; i < studentCount; ++i) {
        int studentId;
        in.read(reinterpret_cast<char*>(&studentId), sizeof(studentId));
        Enrolled_Students.push_back(studentId);
    }
}