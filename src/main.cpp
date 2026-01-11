#include <iostream>
#include <string>
#include <list>
using namespace std;


int main(){
    //Choosing the Action
    list<string> Actions = {
                                "Add Student",
                                "Add Course",
                                "Add Instructor",
                                "Enroll Student in Course",
                                "Drop Course",
                                "Add Grade",
                                "View Student Details",
                                "View Course Details",
                                "List All Students",
                                "List All Courses",
                                "Search Students by Name",
                                "Calculate Student GPA",
                                "Save Data to Files",
                                "Load Data from Files",
                                "Exit Program"
                            };

    for (string i : Actions){
        cout<< i<<endl;
    };
    string Action ;
    
    while(true){
        cin>>Action;
        cout << "Action: " << Action;


    };
    return 0;
};
