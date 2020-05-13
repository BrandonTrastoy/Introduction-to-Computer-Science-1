/*
 Name: Brandon Trastoy
 Class: CIS - 161
 Date: October 9, 2017
 Program: Classes
 
 Description: This program creates a class in a header file, that
                file is then included into two separate cpp files, one
                being main the other info. Info creates a definition for
                each function described in the the class. Then main calls
                those functions and the values are printed. This program
                asks the user for their name, id number, and 3 test scores.
                It then prints out the results of those scores, being their
                average, grade and pass or fail.
 */

#include <iostream>
#include "info.h"

using namespace std;

int main ()
{
    string name;
    int idNumber;
    short test1, test2, test3;
    
    Info data;
    cout << "Enter your name: "; data.setName(name);
    cout << "Enter your ID number: "; data.setIdNumber(idNumber);
    cout << "Enter the grade for Test 1: "; data.setTest1(test1);
    cout << "Enter the grade for Test 2: "; data.setTest2(test2);
    cout << "Enter the grade for Test 3: "; data.setTest3(test3);
    
    cout << endl << endl;
    
    // ----------------------------------------------------------
    
    cout << "\tResults:" << endl << endl;
    
    cout << "Student Name: " << data.getName() << endl;
    cout << "Id Number:    " << data.getIdNumber() << endl << endl;
    
    cout << "Tests: " << endl;
    
    cout << "\t 1 - " << data.getTest1() << endl;
    cout << "\t 2 - " << data.getTest2() << endl;
    cout << "\t 3 - " << data.getTest3() << endl << endl;
    
    data.print();
    
    return 0;
}
