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

void infile(int, float &, float &, float &, float &, float &, float &, float, float &,
            float &, float &, float &, float &, float &);
    void setdata(float &, float &, float &, float &, float &, float &, float, float &,
                 float &, float &, float &, float &, float &);
        float employeeTotalSalary(float);

void processing(float, float, float, float, float, float, float, float,
                float, float, float, float, float &, float &);



int main()
{
    float contractCost, electrician, plumber, roofer, landscaper, totalEmployeeSalary,
    costPerEmployee = 0.0, woodCost, concreteCost, windowCost, doorCost, sheetrockCost,
    spackleCost, totalCosts, profitLoss;
    int contractAmount = 0;
    
    infile(contractAmount, contractCost, electrician, plumber, roofer, landscaper, totalEmployeeSalary,
           costPerEmployee, woodCost, concreteCost, windowCost, doorCost, sheetrockCost, spackleCost);
    
    processing(contractCost, electrician, plumber, roofer, landscaper, totalEmployeeSalary, woodCost,
               concreteCost, windowCost, doorCost, sheetrockCost, spackleCost, totalCosts, profitLoss);
    
    return 0;
}

void infile(int contract, float & contractC, float & electric, float & plumb, float & roof, float & land,
            float & totalEmployee, float costPerEmploy, float & wood, float & concrete,
            float & window, float & door, float & sheetrock, float & spackle)
{
    int contractAmount;
    cout << "Enter the amount of contracts accepted: "; cin >> contractAmount;
    
    int sentinel = 0;
    while (sentinel < contractAmount)
    {
        string filename;
        cout << "Enter the name for contract # " << sentinel + 1 << ": "; cin >> filename;
        ofstream fin;
        fin.open ("filename.txt");
        setdata(contractC, electric, plumb, roof, land, totalEmployee, costPerEmploy, wood, concrete,
                window, door, sheetrock, spackle);
        sentinel += 1;
        fin.close();
    }
}

    void setdata(float & contract, float & electrician, float & plumber, float & roofer, float & landScaper,
                 float & totalEmployeeCost, float costPerEmployee, float & woodCost, float & concreteCost,
                 float & windowCost, float & doorCost, float & sheetrockCost, float & spackleCost)
    {
        cout << "Enter the cost of the contract: "; cin >> contract;
        
        cout << endl << "\tSubcontractors: " << endl << endl;
        
        cout << "Enter the amount paid to electrician: "; cin >> electrician;
        cout << "Enter the amount paid to plumber: "; cin >> plumber;
        cout << "Enter the amount paid to roofer: "; cin >> roofer;
        cout << "Enter the amount paid to the landscaper: "; cin >> landScaper;
        
        totalEmployeeCost = employeeTotalSalary(costPerEmployee);
        
        cout << endl << "\tMaterials: " << endl << endl;
        
        cout << "Enter the total amount paid for wood: "; cin >> woodCost;
        cout << "Enter the total amount paid for concrete: "; cin >> concreteCost;
        cout << "Enter the total amount paid for windows: "; cin >> windowCost;
        cout << "Enter the total amount paid for doors: "; cin >> doorCost;
        cout << "Enter the total amount paid for sheetrock: "; cin >> sheetrockCost;
        cout << "Enter the total amount paid for spackle: "; cin >> spackleCost;
        
        
}

        float employeeTotalSalary(float costPerEmploy)
        {
            int sentinel = 0, amountOfEmployee = 0;
            float total = 0;
            
            cout << endl << "\tEmployees: " << endl << endl;
            
            while (amountOfEmployee < 5)
            {
                cout << "Enter the total amount of employees: "; cin >> amountOfEmployee;
                if (amountOfEmployee < 5)
                    cout << "RE-ENTER VALUE!! THERE IS A MINIMUM OF 5 EMPLOYEES!!" << endl;
            }
            
            while (sentinel < amountOfEmployee)
            {
                cout << "Enter the salary cost for employee #" << sentinel + 1 << ": "; cin >> costPerEmploy;
                total += costPerEmploy;
                
                sentinel += 1;
                
            }
            
            return total;
        }

void processing(float contract, float electric, float plumb, float roof, float land,
                float totEmploySalary, float wood, float concrete, float window,
                float door, float sheetrock,float spackle, float & totalCost,
                float & profitLos)
{
    totalCost = electric + plumb + roof + land + totEmploySalary + wood + concrete
                + window + door + sheetrock + spackle;
    
    profitLos = contract - totalCost;
    
    
}

