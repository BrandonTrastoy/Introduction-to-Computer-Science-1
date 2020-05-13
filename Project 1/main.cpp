/*
    Author: Brandon Trastoy
    Date: February 15, 2017
    Title: Customer Bill Calculator
    
    Description: This program takes in data from the user, then uses this data to calculate
                    a bill and then outputs it back to the console.
 
 */


#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Function prototype for customer information, it takes a string 5 ints and a
// float, all values are returned by reference.
void customerInformation(string &, int &, int &, float &, int &, int &, int &);

// Function prototype for calculations, takes 10 float, 9 of which are passed
// by reference, 5 ints that are returned by reference, and a constant float by value.
void calculations(float &, float &, float &, float &, float &, float &, float &,
                  float &, float &, float, int, int, int, int, int, const float);

// Function prototype for print bill, takes one string, 4 ints, 10 float, and one
// constant float and does not return anything.
void printBill(string, int, int, float, float, const float, float, float, float,
               float, float, float, int, float, int, float);


int main()
{
    
    // Variables -----------------------------------------
    string customerName;
    
    const float DESSERT_COST = 3.00;
    
    int numAdultsServed, numChildrenServed, numOfDesserts,
        roomFee, amountOfDeposit;
    
    float adultMealPrice, childMealPrice, totalAdultCost,
          totalChildCost, totalDessertCost, totalFoodCost,
          taxCost, gratuityCost, totalBill, balanceDue;
    // ---------------------------------------------------
    
    
    // Function call for customer information
    customerInformation(customerName, numAdultsServed, numChildrenServed,
                        adultMealPrice, numOfDesserts, roomFee, amountOfDeposit);
    
    // Function call for calculations
    calculations(childMealPrice, totalAdultCost, totalChildCost, totalDessertCost,
                 totalFoodCost, taxCost, gratuityCost, totalBill, balanceDue, adultMealPrice,
                 numAdultsServed, numChildrenServed, numOfDesserts, roomFee, amountOfDeposit, DESSERT_COST);
    
    // Function call for print bill
    printBill(customerName, numAdultsServed, numChildrenServed, adultMealPrice, childMealPrice, DESSERT_COST,
              totalAdultCost, totalChildCost, totalDessertCost, totalFoodCost, taxCost, gratuityCost,
              roomFee, totalBill, amountOfDeposit, balanceDue);
    
    return 0;
}

// Function definition for customer information
void customerInformation(string & customerName, int & numAdult, int & numChild,
                         float & adultMeal, int & numDes, int & room, int & deposit) {
    
    cout << "Enter Customer Name: ";
    getline(cin, customerName);
    
    cout << "Enter the Amount of Adults in Party: ";
    cin >> numAdult;
    
    cout << "Enter the Amount of Children in Party: ";
    cin >> numChild;
    
    cout << "Enter the Cost Per Adult Meal: ";
    cin >> adultMeal;
    
    cout << "Enter the Number of Desserts Ordered: ";
    cin >> numDes;
    
    cout << "Enter the cost of the Room Fee: ";
    cin >> room;
    
    cout << "Enter the Amount of Deposit: ";
    cin >> deposit;
    
    cout << endl << endl;
}

// Function definition for calculations
void calculations(float & totAdult, float & childMeal, float & totChild, float & totDes,
                  float & totFood, float & tax, float & tip, float & totBill, float & balance,
                  float adultMeal, int numAdult, int numChild, int numDes, int room, int deposit,
                  const float DESSERT_COST) {
    
    const float TAX_RATE = 0.07, GRATUITY = 0.15,
                CHILD_MEAL_PERCENT = 0.6;
    
    
    totAdult = adultMeal * numAdult;
    
    childMeal = CHILD_MEAL_PERCENT * adultMeal;
    totChild = childMeal * numChild;
    
    totDes = DESSERT_COST * numDes;
    
    totFood = totAdult + totChild + totDes;
    
    tax = totFood * TAX_RATE;
    
    tip = totFood * GRATUITY;
    
    totBill = totFood + tax + tip + room + deposit;
    
    balance = totBill - deposit;
}

// Function definition for print bill
void printBill(string customerName, int numAdultsServed, int numChildrenServed, float adultMealPrice,
               float childMealPrice, const float DESSERT_COST, float totalAdultCost,
               float totalChildCost, float totalDessertCost, float totalFoodCost, float taxCost,
               float gratuityCost, int roomFee, float totalBill, int amountOfDeposit, float balanceDue) {
    
    cout << "\t\tPassaic County Catering & Convention Services		Final Bill" << endl << endl << endl;
    
    cout << "Customer:                     " << customerName << endl;
    cout << "Number Of Adults:             " << numAdultsServed << endl;
    cout << "Number Of Children:           " << numChildrenServed << endl << endl;
    
    cout << fixed << showpoint << setprecision(2);
    
    cout << "Cost Of Meal Per Adult:       $" << adultMealPrice << endl;
    cout << "Cost Of Meal Per Child:       $" << childMealPrice << endl;
    cout << "Cost Per Dessert:             $" << DESSERT_COST << endl << endl;
    
    cout << "Total Cost For Adult Meals:   $" << totalAdultCost << endl;
    cout << "Total Cost For Child Meals:   $" << totalChildCost << endl;
    cout << "Total Cost For Dessert:       $" << totalDessertCost << endl;
    cout << "Total Food Cost:              $" << totalFoodCost << endl << endl;
    
    cout << "Plus 7.00 % Taxes:            $" << taxCost << endl;
    cout << "Plus 15.00 % Tips:            $" << gratuityCost << endl;
    cout << "Plus Room Fee:                $" << roomFee << endl << endl;
    
    cout << "Total Bill:                   $" << totalBill << endl;
    cout << "Less Deposit:                 $" << amountOfDeposit << endl << endl;
    
    cout << "Balance Due:                  $" << balanceDue << endl << endl << endl;
    
    cout << "\t\tThank you for using Passaic County Catering Services." << endl;
    
}
