#include <iostream>
#include <string>

#ifndef INFO_H
#define INFO_H

using namespace std;

class Info
{
    
private:
    string name;
    int idNumber;
    short test1, test2, test3;
    
   	float getAverage() const;
    char getGrade() const;
    
    
    
public:
    //Default Constructor
    Info();
    
    //Default Destructor
    ~Info();
    
    //Setter functions for each member data
    void setName(const string &);
    void setIdNumber(const int &);
    void setTest1(const short &);
    void setTest2(const short &);
    void setTest3(const short &);
    
    //Getter Functions for each member data
    string getName();
    int getIdNumber();
    short getTest1();
    short getTest2();
    short getTest3();
    
    //Function to print out average, grade and passFail
    void print();
    
    
};

#endif
