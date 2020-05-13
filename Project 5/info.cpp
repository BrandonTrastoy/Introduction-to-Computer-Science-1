#include "info.h"

Info :: Info()
{
    idNumber = 0;
    test1 = 0.0;
    test2 = 0.0;
    test3 = 0.0;
}

Info :: ~Info()
{
    
}

void Info :: setName(const string &)
{
    getline(cin, name);
}
void Info :: setIdNumber(const int &)
{
    cin >> idNumber;
}
void Info :: setTest1(const short &)
{
    cin >> test1;
}
void Info :: setTest2(const short &)
{
    cin >> test2;
}
void Info ::setTest3(const short &)
{
    cin >> test3;
}



string Info :: getName(){
    return name;
}
int Info :: getIdNumber(){
    return idNumber;
}
short Info :: getTest1(){
    return test1;
}
short Info :: getTest2(){
    return test2;
}
short Info :: getTest3(){
    return test3;
}



float Info :: getAverage() const
{
    return (test1 + test2 + test3)/3;
}

char Info:: getGrade() const
{
    char grade;
    
    if (getAverage() >= 90)
        grade = 'A';
    else if (getAverage() >= 80)
        grade = 'B';
    else if (getAverage() >= 70)
        grade = 'C';
    else if (getAverage() >= 60)
        grade = 'D';
    else
        grade = 'F';
    
    return grade;
}

void Info :: print ()
{
    cout << "Average: " << getAverage() << endl;
    cout << "Grade:   " << getGrade();
    
    if (getGrade() == 'D' || getGrade() == 'F')
        cout << "\tYou Failed!!" << endl;
    else
        cout << "\tYou Passed!!" << endl;
}


