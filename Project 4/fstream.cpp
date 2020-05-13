/*
	Author: Brandon Trastoy
	Class: CIS - 160
	Date: April 19, 2017
	Program: Loops and Functions
	Description:
 
 */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void setdata(float &, float &, float &, float &, float &, float &, float, float &,
             float &, float &, float &, float &, float &);

    float employeeTotalSalary(float, string);

int main()
{
    float contractCost, electrician, plumber, roofer, landscaper, totalEmployeeSalary,
          costPerEmployee = 0.0, woodCost, concreteCost, windowCost, doorCost, sheetrockCost,
          spackleCost;
    
    setdata(contractCost, electrician, plumber, roofer, landscaper, totalEmployeeSalary,
            costPerEmployee, woodCost, concreteCost, windowCost, doorCost, sheetrockCost,
            spackleCost);
    
    return 0;
}


void setdata(float & contract, float & electrician, float & plumber, float & roofer, float & landScaper,
             float & totalEmployeeCost, float costPerEmployee, float & woodCost, float & concreteCost,
             float & windowCost, float & doorCost, float & sheetrockCost, float & spackleCost)
{
    int contractAmount, sentinel = 0;
    cout << "Enter the amount of contracts accepted: "; cin >> contractAmount;
    
    while (sentinel < contractAmount)
    {
        string filename;
        cout << "Enter the name for contract # " << sentinel + 1 << ": "; cin >> filename;
        ifstream fin;
        fin.open ("filename.txt");
    
        cout << "Enter the cost of the contract: "; fin >> contract;
        
        cout << endl << "\tSubcontractors: " << endl << endl;
        
        cout << "Enter the amount paid to electrician: "; fin >> electrician;
        cout << "Enter the amount paid to plumber: "; fin >> plumber;
        cout << "Enter the amount paid to roofer: "; fin >> roofer;
        cout << "Enter the amount paid to the landscaper: "; fin >> landScaper;
        
        totalEmployeeCost = employeeTotalSalary(costPerEmployee, filename);
        
        cout << endl << "\tMaterials: " << endl << endl;
        
        cout << "Enter the total amount paid for wood: "; fin >> woodCost;
        cout << "Enter the total amount paid for concrete: "; fin >> concreteCost;
        cout << "Enter the total amount paid for windows: "; fin >> windowCost;
        cout << "Enter the total amount paid for doors: "; fin >> doorCost;
        cout << "Enter the total amount paid for sheetrock: "; fin >> sheetrockCost;
        cout << "Enter the total amount paid for spackle: "; fin >> spackleCost;
        
        sentinel += 1;
        fin.close();
    }
}

    float employeeTotalSalary(float costPerEmploy, string filename)
    {
        int sentinel = 0, amountOfEmployee = 0;
        float total = 0;
        
        ifstream fin;
        fin.open ("filename.txt");
        
        cout << endl << "\tEmployees: " << endl << endl;
        
        while (amountOfEmployee < 5)
        {
            cout << "Enter the total amount of employees: "; fin >> amountOfEmployee;
            if (amountOfEmployee < 5)
                cout << "RE-ENTER VALUE!! THERE IS A MINIMUM OF 5 EMPLOYEES!!" << endl;
        }
        
        while (sentinel < amountOfEmployee)
        {
            cout << "Enter the salary cost for employee #" << sentinel + 1 << ": "; fin >> costPerEmploy;
            total += costPerEmploy;
            
            sentinel += 1;
            fin.close();
            
        }
        
        return total;
    }
