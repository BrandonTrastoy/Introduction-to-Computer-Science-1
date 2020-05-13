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
             float &, float &, float &, float &, float &, float &, float &);

    float employeeTotalSalary(float, string);

    void processing(float, float, float, float, float, float, float, float,
                    float, float, float, float, float &, float &);



int main()
{
    float contractCost, electrician, plumber, roofer, landscaper, totalEmployeeSalary,
    costPerEmployee = 0.0, woodCost, concreteCost, windowCost, doorCost, sheetrockCost,
    spackleCost, totalCosts, profitLoss;
    
    setdata(contractCost, electrician, plumber, roofer, landscaper, totalEmployeeSalary,
            costPerEmployee, woodCost, concreteCost, windowCost, doorCost, sheetrockCost,
            spackleCost, totalCosts, profitLoss);
    
    return 0;
}


void setdata(float & contract, float & electric, float & plumb, float & roof, float & land,
             float & totalEmploy, float costPerEmploy, float & wood, float & concrete,
             float & window, float & door, float & sheetrock, float & spackle,
             float & totalCost, float & profitLos)
{
    int contractAmount, sentinel = 0;
    cout << "Enter the amount of contracts accepted: "; cin >> contractAmount;
    
    while (sentinel < contractAmount)
    {
        string filename;
        cout << "Enter the name for contract # " << sentinel + 1 << ": "; cin >> filename;
        ifstream fin;
        fin.open ("filename.txt");
        
        cout << "Enter the cost of the contract: "; cin >> contract;
        
        cout << endl << "\tSubcontractors: " << endl << endl;
        
        cout << "Enter the amount paid to electrician: "; cin >> electric;
        cout << "Enter the amount paid to plumber: "; cin >> plumb;
        cout << "Enter the amount paid to roofer: "; cin >> roof;
        cout << "Enter the amount paid to the landscaper: "; cin >> land;
        
        totalEmploy = employeeTotalSalary(costPerEmploy, filename);
        
        cout << endl << "\tMaterials: " << endl << endl;
        
        cout << "Enter the total amount paid for wood: "; cin >> wood;
        cout << "Enter the total amount paid for concrete: "; cin >> concrete;
        cout << "Enter the total amount paid for windows: "; cin >> window;
        cout << "Enter the total amount paid for doors: "; cin >> door;
        cout << "Enter the total amount paid for sheetrock: "; cin >> sheetrock;
        cout << "Enter the total amount paid for spackle: "; cin >> spackle;
        
        processing(contract, electric, plumb, roof, land, totalEmploy, wood,
                   concrete, window, door, sheetrock, spackle, totalCost, profitLos);

        
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
            cout << "Enter the total amount of employees: "; cin >> amountOfEmployee;
            if (amountOfEmployee < 5)
                cout << "RE-ENTER VALUE!! THERE IS A MINIMUM OF 5 EMPLOYEES!!" << endl;
        }
        
        while (sentinel < amountOfEmployee)
        {
            cout << "Enter the salary cost for employee #" << sentinel + 1 << ": "; cin >> costPerEmploy;
            total += costPerEmploy;
            
            sentinel += 1;
            fin.close();
            
        }
        
        return total;
    }

    void processing(float contractCost, float electrician, float plumber, float roofer, float landScaper,
                    float totalEmployeeSalary, float woodCost, float concreteCost, float windowCost,
                    float doorCost, float sheetrockCost,float spackleCost, float & totalCosts,
                    float & profitLoss)
    {
        totalCosts = electrician + plumber + roofer + landScaper + totalEmployeeSalary + woodCost + concreteCost
        + windowCost + doorCost + sheetrockCost + spackleCost;
        
        profitLoss = contractCost - totalCosts;
        
        
    }

