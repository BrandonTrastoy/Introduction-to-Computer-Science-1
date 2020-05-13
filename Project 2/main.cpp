/*  Author: Brandon Trastoy
    March 20, 2017
    CIS - 160
    Functions
    Description: This program calculates the bill for customers at the
                 Passaic County Community Carpet Center.
 
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <math.h>
#include <stdio.h>
using namespace std;

//Constant variables for Labor Cost and Tax Rate
const float LABOR_COST = 1.65, TAX_RATE = 0.07;

//String variables for the customers name and ID number
string customerName, idNumber;
//Integer varibles for the length and with in feet and inches
int lengthFeet, lengthInch, widthFeet, widthInch;

//Float variables for: cost of carpet, disount rate, total carpet cost, cost of
//                     labor, installation price, cost of discount, subtotal,
//                     taxes, the total, and square feet
float costCarpet, dicountPercent, totalCarpet, costLabor, installedPrice,
      discount, subtotal, taxes, total, squareFeet;

//Function Prototype for setdata (INPUT)
float setdata(string &, string &, int &, int &, int &, int &, float &, float &);

//Function prototype for calculations (PROCESS)
void calculations(float &, float &, float &, float &, float &, float &, float &);
    //Function prototype for installation price, will be called in calcuations
    float calcInstalled(float &, float &);
    //Function prototype for subtotal amount, will be called in calcuations
    float calcSubtotal(float &, float &);
    //Function prototype for the total amount, will be called in calcuations
    float calcTotal(float &, float &);

//Function prototype for showResults (OUTPUT)
void showResult();
    //Function prototype for headings
    void headings();
    //Function prototype for measurements
    void measurement();
    //Function prototype for the charges
    void charges();



int main() {
    
    //Function call for setdata into main, saves returned value as squarefeet
    squareFeet = setdata(customerName, idNumber, lengthFeet, lengthInch, widthFeet,
                         widthInch, costCarpet, dicountPercent);
    
    //Function call for calculations into main
    calculations(costLabor, totalCarpet, installedPrice, discount, subtotal,
                 taxes, total);
    
    //Function call for showResults into main
    showResult();
    
    return 0;
}

//Input -----------------------------------------------------------------------
float setdata(string & cusName, string & idNum, int & lengthFt, int & lengthIn,
             int & widthFt, int & widthIn, float & cosCarp, float & disPer) {
    
    //Asks for the customer name and saves in cusName
    cout << "Enter Customer Name: ";
    getline(cin, cusName);
    
    //Asks for the customers ID # and saves in idNum
    cout << "Enter your Customer ID #: ";
    getline(cin, idNum);
    
    //Asks for the length of the room in ft and inches then saves in lengthFt, lengthIn
    cout << "Enter the Length of the room in feet followed by inches: ";
    cin >> lengthFt >> lengthIn;
    
    //Asks for the width of the room in ft and inches then saves in widthFt, widthIn
    cout << "Enter the Width of the room in feet followed by inches: ";
    cin >> widthFt >> widthIn;
    
    //Asks for the cost per square foot of carpet, and saves in cosCarp
    cout << "Enter the cost of the carpet per square foot: ";
    cin >> cosCarp;
    
    //Asks for the discount percent and saves in disPer
    cout << "Enter the discount percent in decimal form: ";
    cin >> disPer;
    
    return (round(((lengthFeet + (lengthInch / 12.0)) * (widthFeet + (widthInch / 12.0))) * 100)) / 100;
}
//Input -----------------------------------------------------------------------

//Process ---------------------------------------------------------------------

//calclations calls its three subfunctions into it: calcInstalled, calcSubtotal, calcTotal
void calculations(float & laborCost, float & totalCarp, float & installed,
                  float & dis, float & sub, float & tax, float & tot) {
    
    //Function call for calcInstalled
    calcInstalled(laborCost, totalCarp);
    //Function call for calcSubtotal, saves returned value as sub
    sub = calcSubtotal(installed, dis);
    //Function call for calcTotal
    calcTotal(tax, tot);
    
}

    float calcInstalled(float & labCos, float & totCarp) {
        
        //Calculates square foot cost, then rounds
        float squareFt = (round(((lengthFeet + (lengthInch / 12.0)) * (widthFeet + (widthInch / 12.0))) * 100)) / 100;
        //Calculates the labor cost, then rounds
        labCos = (round((LABOR_COST * squareFt) * 100)) / 100;
        //Calculates the total carpet cost, then rounds
        totCarp = (round((costCarpet * squareFt) * 100)) / 100;
    
        //Returns the value zero
        return 0;
    }

    float calcSubtotal(float & install, float & disCount) {
    
        //Calculates the installation price
        install = costLabor + totalCarpet;
        //Calculates the discount total, then rounds
        disCount  = (round((install * dicountPercent) * 100)) / 100;
    
        //Returns the subtotal value
        return install - disCount;
    
    }

    float calcTotal(float & taxes, float & total) {
        
        //Calculates the total taxes, then rounds
        taxes = (round((subtotal * TAX_RATE) * 100)) / 100;
        //Calulates the total amount
        total  = subtotal + taxes;
        
        //Returns zero because there is nothing left to return
        return 0;
    
    }
//Process ---------------------------------------------------------------------

//Output ----------------------------------------------------------------------

//showResults call its three subfunctions into it: headings, measuments, charges ; only prints
void showResult() {
    
    //Funtion call for headings
    headings();
    //Funtion call for measurement
    measurement();
    //Funtion call for charges
    charges();
    
}

    void headings() {
    
        cout << endl << endl;
        cout << "+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+" << endl << endl;
        cout << "               Passaic County Community Carpet Center " << endl;
        cout << "                          123 Main Street " << endl;
        cout << "                        Paterson, NJ 07505 " << endl << endl;
        cout << "+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+" << endl << endl;
    
        cout << "Customer Name: \t\t " << customerName << endl;
        cout << "Customer ID #: \t\t " << idNumber << endl;
    
        cout << endl << endl;
    
    }

    void measurement() {
    
        cout << fixed << showpoint << setprecision(2);
    
        cout << "Room Measurements: " << endl << endl;
        cout << "\t\t\t\t Length: " << lengthFeet << "' " << lengthInch << "\" " << endl;
        cout << "\t\t\t\t Width:  " << widthFeet << "' " << widthInch << "\" " << endl;
        cout << "\t\t\t\t Area:   " << squareFeet << " Sq/Ft" << endl;
    
        cout << endl << endl;
    
    }

    void charges() {
    
        cout << fixed << showpoint << setprecision(2);
    
        cout << "Charges: " << endl << endl;
        cout << "\t\t Description\t\t Cost Sq/Ft\t\t Charges Room" << endl;
        cout << "\t\t ___________\t\t __________\t\t ____________" << endl << endl;
        cout << "\t\t Carpet:    \t\t $" << costCarpet << "\t\t\t $" << totalCarpet << endl;
        cout << "\t\t Labor:     \t\t $" << LABOR_COST << "\t\t\t $" << costLabor << endl;
        
        cout << endl;
        cout << "\t\t            \t\t           \t\t ____________" << endl << endl;
    
        cout << "\t\t Installed Price: \t\t     \t\t $" << installedPrice << endl;
        cout << "\t\t Discount:        \t " << dicountPercent * 100 << "%    \t\t $" << discount << endl;
    
        cout << endl;
        cout << "\t\t            \t\t           \t\t ____________" << endl << endl;

        cout << "\t\t Subtotal:        \t\t     \t\t $" << subtotal << endl;
        cout << "\t\t Tax:             \t\t     \t\t $" << taxes << endl;
    
        cout << endl;
        cout << "\t\t            \t\t           \t\t ____________" << endl << endl;
        
        cout << "\t\t Total:           \t\t     \t\t $" << total << endl << endl << endl;
    
        cout << "\t Thank You for Using PCCCC as Your Professional Carpet Store\n\n\n";
    
    }
//Output ----------------------------------------------------------------------


/* Test 1 +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
 
 Enter Customer Name: Adnan I. Atshan
 Enter your Customer ID #: 12345
 Enter the Length of the room in feet followed by inches: 30 5
 Enter the Width of the room in feet followed by inches: 18 11
 Enter the cost of the carpet per square foot: 18.23
 Enter the discount percent in decimal form: 0.09
 
 
 +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
 
 Passaic County Community Carpet Center
 123 Main Street
 Paterson, NJ 07505
 
 +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
 
 Customer Name: 		 Adnan I. Atshan
 Customer ID #: 		 12345
 
 
 Room Measurements:
 
 Length: 30' 5"
 Width:  18' 11"
 Area:   575.38 Sq/Ft
 
 
 Charges:
 
 Description		 Cost Sq/Ft		 Charges Room
 ___________		 __________		 ____________
 
 Carpet:    		 $18.23			 $10489.18
 Labor:     		 $1.65			 $949.38
 
                                     ____________
 
 Installed Price: 		     		 $11438.56
 Discount:        	 9.00%    		 $1029.47
 
                                     ____________
 
 Subtotal:        		     		 $10409.09
 Tax:             		     		 $728.64
 
                                     ____________
 
 Total:           		     		 $11137.73
 
 
 Thank You for Using PCCCC as Your Professional Carpet Store
 
 
 Program ended with exit code: 0
 
  */

/* Test 2 +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
 
 Enter Customer Name: Brandon Trastoy
 Enter your Customer ID #: 0286203
 Enter the Length of the room in feet followed by inches: 12 0
 Enter the Width of the room in feet followed by inches: 11 9
 Enter the cost of the carpet per square foot: 10.50
 Enter the discount percent in decimal form: 0.05
 
 
 +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
 
 Passaic County Community Carpet Center
 123 Main Street
 Paterson, NJ 07505
 
 +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
 
 Customer Name: 		 Brandon Trastoy
 Customer ID #: 		 0286203
 
 
 Room Measurements:
 
 Length: 12' 0"
 Width:  11' 9"
 Area:   141.00 Sq/Ft
 
 
 Charges:
 
 Description		 Cost Sq/Ft		 Charges Room
 ___________		 __________		 ____________
 
 Carpet:    		 $10.50			 $1480.50
 Labor:     		 $1.65			 $232.65
 
                                     ____________
 
 Installed Price: 		     		 $1713.15
 Discount:        	 5.00%    		 $85.66
 
                                     ____________
 
 Subtotal:        		     		 $1627.49
 Tax:             		     		 $113.92
 
                                     ____________
 
 Total:           		     		 $1741.41
 
 
 Thank You for Using PCCCC as Your Professional Carpet Store
 
 
 Program ended with exit code: 0
 
 */

/* Test 3 +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
 
 Enter Customer Name: Fetty Wap
 Enter your Customer ID #: 1738
 Enter the Length of the room in feet followed by inches: 17 5
 Enter the Width of the room in feet followed by inches: 38 3
 Enter the cost of the carpet per square foot: 15
 Enter the discount percent in decimal form: 0.5
 
 
 +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
 
 Passaic County Community Carpet Center
 123 Main Street
 Paterson, NJ 07505
 
 +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
 
 Customer Name: 		 Fetty Wap
 Customer ID #: 		 1738
 
 
 Room Measurements:
 
 Length: 17' 5"
 Width:  38' 3"
 Area:   666.19 Sq/Ft
 
 
 Charges:
 
 Description		 Cost Sq/Ft		 Charges Room
 ___________		 __________		 ____________
 
 Carpet:    		 $15.00			 $9992.85
 Labor:     		 $1.65			 $1099.21
 
                                     ____________
 
 Installed Price: 		     		 $11092.06
 Discount:        	 50.00%    		 $5546.03
 
                                     ____________
 
 Subtotal:        		     		 $5546.03
 Tax:             		     		 $388.22
 
                                     ____________
 
 Total:           		     		 $5934.25
 
 
 Thank You for Using PCCCC as Your Professional Carpet Store
 
 
 Program ended with exit code: 0
 
 */

/* Test 4 +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
 
 Enter Customer Name: Flan Flanders
 Enter your Customer ID #: 35266
 Enter the Length of the room in feet followed by inches: 10 0
 Enter the Width of the room in feet followed by inches: 10 0
 Enter the cost of the carpet per square foot: 2.50
 Enter the discount percent in decimal form: 0.01
 
 
 +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
 
 Passaic County Community Carpet Center
 123 Main Street
 Paterson, NJ 07505
 
 +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
 
 Customer Name: 		 Flan Flanders
 Customer ID #: 		 35266
 
 
 Room Measurements:
 
 Length: 10' 0"
 Width:  10' 0"
 Area:   100.00 Sq/Ft
 
 
 Charges:
 
 Description		 Cost Sq/Ft		 Charges Room
 ___________		 __________		 ____________
 
 Carpet:    		 $2.50			 $250.00
 Labor:     		 $1.65			 $165.00
 
                                     ____________
 
 Installed Price: 		     		 $415.00
 Discount:        	 1.00%    		 $4.15
 
                                     ____________
 
 Subtotal:        		     		 $410.85
 Tax:             		     		 $28.76
 
                                     ____________
 
 Total:           		     		 $439.61
 
 
 Thank You for Using PCCCC as Your Professional Carpet Store
 
 
 Program ended with exit code: 0
 
 */





