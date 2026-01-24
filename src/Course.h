#include <string>

#ifndef COURSE_H
#define COURSE_H

class Course {
    private:
        std::string name;
        int credits;

    public:
        Course(const std::string& courseName, int courseCredits);
};

#endif