#include <string>
#include<vector>
#include <iostream>

#ifndef COURSE_H
#define COURSE_H

class Course {
    private:
        std::string CourseID;
        std::vector<int> Enrolled_Students;
        int InstructorId;
        int Credits;
        int Capacity;
        


    public:
        // Constructor - initialize everything
        Course(const std::string& CourseID, int courseCredits, int capacity, int instructorId);

        // Enrollment operations - only need student ID
        bool addStudent(int studentId);
        bool removeStudent(int studentId);
        
        // Status checks - return bool, no parameters
        bool isFull() const;
        bool hasSpace() const;
        
        // Getters - const, no parameters
        std::string getCourseId() const;
        int getCredits() const;
        int getCapacity() const;
        int getEnrolledCount() const;
        
        // File I/O
        void Save(std::ostream& out) const;
        void Load(std::istream& in);
};

#endif