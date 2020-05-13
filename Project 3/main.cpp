/*
     Author: Brandon Trastoy
     April 10, 2017
     CIS - 160
     If Statements and Functions
     Description:    This program is designed to calculate the total amount
                     thats patients at St. Joseph Hospital will have to pay.
                     It firsts asks for the of the patient's name and how
                     many days they stayed at the hospital, it then proceeds
                     to asks if they had any additional amenities. Such as
                     the room they stayed in, phone access and tv acces. It
                     totals the amounts of the stay and then prints it out
                     at the end.
 */

#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstdlib>
#include <string>

using namespace std;

//Function prototype for setdata, returns values through reference
void setdata(string &, int &);
//Function for prototype for setroom, returns values through reference and return
float setroom(int, string &);
    //Function prototype for setroomHeading, sub-function of setdata, returns values
    //through reference
    void setroomHeading(string &, const float SINGLE_ROOM,
                        const float DOUBLE_ROOM, const float WARD);
    //Function prototype for setroomIf, sub-function of setdata, returns values through
    //reference
    void setroomIf(string &, int, float &, const float SINGLE_ROOM,
                   const float DOUBLE_ROOM, const float WARD);
//Function protoype for setphone, returns values through reference and return
float setphone(int, string &);
    //Function prototype for phoneaccess, sub-function of setphone, returns value through
    //reference
    void phoneaccess(int, string &, float &);
        //Function prototype for setphoneHeading, sub-function of phoneaccess, returns
        //value through reference
        void setphoneHeading(int, string &, const float, const float);
        //Function prototype for setphoneIf, sub-function of phoneaccess, returns value
        //through reference
        void setphoneIf(string &, int, float &, const float, const float);
//Function protoype for settv, returns values through reference and return
float settv(int, string &);
    //Function prototype for tvaccess, sub-function of settv, returns value through
    //reference
    void tvaccess(int, string &, float &);
        //Function prototype for settvHeading, sub-function of tvaccess, returns value
        //through reference
        void settvHeading(int, string &, const float, const float);
        //Function prototype for settvIf, sub-function of tvaccess, returns value through
        //reference
        void settvIf(string &, int, float &, const float, const float);
//Function prototype for print, doesn't return a value, displays results
void print(string, int, float, float, float, string, string, string, float);


int main()
{
    //String variable for patient name
    string name;
    //String variable for room type, phone type, and tv type
    string roomtype, phonetype, tvtype;
    //Int varible for the number of days stayed in the hospital
    int days;
    //Float varibles for the room charge, phone charge, tv charge, and the total charges
    float roomcharges,phonecharges,tvcharges, totalcharges = 0; //Calculated
    
    //Function call for setdata
    setdata(name,days);
    //Function call for setroom, returns a value and sets as roomcharges
    roomcharges = setroom(days,roomtype);
    //Function call for setphone, returns a value and sets as phonecharges
    phonecharges = setphone(days,phonetype);
    //Function call for tvcharges, returns a value and sets as tvcharges
    tvcharges = settv(days,tvtype);
    //Function call for print, does not return a value, displays results
    print(name,days,roomcharges,phonecharges,tvcharges,roomtype, phonetype, tvtype,
          totalcharges);
    
    
    cin.get();
    cin.ignore();
    
    return 0;
}

//Function declaration for setdata, pass by referencing patient name and number
//of days in hospital
void setdata(string & patName, int & numDays)
{
    cout << "Enter Patient Name: "; getline(cin, patName);
    cout << "Enter The Number of Days in Hospital: "; cin >> numDays;
    cout << endl;
}

//Function declaration for setroom, referencing room type, calling two functions inside
float setroom(int numDays, string & rT)
{
    //Constant float variables for single room cost, double room cost, ward room cost
    const float SINGLE_ROOM = 1325.00, DOUBLE_ROOM = 1525.00, WARD = 1650.00;
    
    //local variable for roomCharges, didn't want to mess with the functions given
    float roomCharges;
    
    //Function call for setroomHeading, references room type "r", sub-function of setroom
    setroomHeading(rT, SINGLE_ROOM, DOUBLE_ROOM, WARD);
    
    //Function call for setroomif, references number of days "numDays",
    //sub-function of setroom
    setroomIf(rT, numDays, roomCharges, SINGLE_ROOM, DOUBLE_ROOM, WARD);
    
    //setroom returns roomCharges and saves it in main
    return roomCharges;
    
}

    //Function declaration for setroomHeading, displays options to the user, then
    //references the result
    void setroomHeading(string & r, const float SINGLE_ROOM, const float DOUBLE_ROOM,
                        const float WARD)
    {
        
        cout << "\t\tRoom Used" << endl << endl;
        
        cout << fixed << showpoint << setprecision(2);
        
        cout << "1. Single Room - One Bed  \t\t $" << SINGLE_ROOM << endl;
        cout << "2. Double Room - Two Beds \t\t $" << DOUBLE_ROOM << endl;
        cout << "3. Ward                   \t\t $" << WARD << endl << endl;
        
        cout << "You May Enter 1, S or s for a \"Single Room\"; 2, D or d for a \"Double Room\";\n";
        cout << "3, W or w for a \"Ward\" " << endl;
        
        cout << "ENTER CHOICE: "; cin >> r;
        
        cout << endl << endl;
        
    }

    //Function declaration for setroomIf, compares user input to options given then
    //calculates room charges and redefines room type, both are rerferenced
    void setroomIf (string & r, int days, float & roomCharg, const float SINGLE_ROOM,
                    const float DOUBLE_ROOM, const float WARD)
    {
        
        if (r == "1" or r == "S" or r == "s")
        {
            roomCharg = days * SINGLE_ROOM;
            r = " (SINGLE):   ";
        }
        
        
        if (r == "2" or r == "D" or r == "d")
        {
            roomCharg = days * DOUBLE_ROOM;
            r = " (DOUBLE):   ";
        }
        
        
        if (r == "3" or r == "W" or r == "w")
        {
            roomCharg = days * WARD;
            r = " (WARD):     ";
        }
        
        if (r == "0")
        {
            r = ":            ";
        }
        
    }

//Function declaration for setphone, returns a value by return and by reference
float setphone(int numDays, string & phoneT)
{
    //Local variable for phone charges
    float phoneCharge;
    //Function call for phoneaccess, sub-function of setphone, references phone
    //type "phoneT", and phone charge "phoneCharge"
    phoneaccess(numDays, phoneT, phoneCharge);
    
    //setphones returns the value of phone charges
    return phoneCharge;
}

    //Function declaration for phoneaccess, returns values by reference
    void phoneaccess(int days, string & phone, float & phoneCharg)
    {
        //Constant float variables for shared line cost, dedicated line cost
        const float SHARED_LINE = 5.95, DEDICATED_LINE = 9.95;
        
        //String variable for user choice, only used locally
        string choice;
        
        cout << "Phone Usage (Y/N): "; cin >> choice;
        cout << endl;
        
        //The if statements below compare the user input to the arguments given, if
        //"yes" is input the user will get to input more data, otherwise phonecharge
        //equals zero
        if (choice == "Y" or choice == "y" or choice == "YES" or choice == "yes")
        {
            //Function call for setphoneHeading, sub-function of phoneaccess,
            //only run if choice is true, references phone type "phone"
            setphoneHeading(days, phone, SHARED_LINE, DEDICATED_LINE);
            //Function call for setphoneIf, sub-function of phoneaccess,
            //only run if choice is true, references phone type "phone" and
            //phone charge (phone type is redefined and will be displayed back to user)
            setphoneIf(phone, days, phoneCharg, SHARED_LINE, DEDICATED_LINE);
        }
        
        else
        {
            //defines phone charges as zero if condition not met
            phoneCharg = 0;
            //this is for visual purposes
            phone = ":            ";
        }
    }

        //Function declaration for setphoneHeading, displays menu to user and asks them
        // to make a choice, saves choice as phone type, , returns phone type by
        // reference,
        void setphoneHeading(int numDays, string & phoneType,
                             const float SHARED_LINE, const float DEDICATED_LINE)
        {
            cout << "\t\tPhone Access" << endl << endl;
            
            cout << fixed << showpoint << setprecision(2);
            
            cout << "1. Shared Line            \t\t $" << SHARED_LINE << endl;
            cout << "2. Dedicated Line         \t\t $" << DEDICATED_LINE << endl << endl;
            
            cout << "You May Enter 1, S or s for a \"Shared Line\"; 2, D or d for a \"Dedicated Line\"\n";
            cout << "ENTER CHOICE: "; cin >> phoneType;
            
            cout << endl << endl;
        }


        //Function declaration for setphoneIf, creates an if statement and compares
        //results of phone type to the conditions, calculates phone charges and
        //redefines phone type as the type of phone line the user chose
        void setphoneIf(string & phoneType, int days, float & phoneCharge,
                        const float SHARED_LINE, const float DEDICATED_LINE)
        {
            
            if (phoneType == "1" or phoneType == "S" or phoneType == "s")
            {
                phoneCharge = days * SHARED_LINE;
                phoneType = " (SHARED):   ";
            }
            
            
            if (phoneType == "2" or phoneType == "D" or phoneType == "d")
            {
                phoneCharge = days * DEDICATED_LINE;
                phoneType = " (DEDICATED):";
            }
            
        }

//Function declaration for settv, returns a value by return and by reference
float settv(int numDays, string & tvT)
{
    //Locally defined variable for tv charges, "tv charge
    float tvCharge;
    //Function call for tvaccess, references tv type "tvT" and tv charge "tvCharge",
    //sub-function of settv
    tvaccess(numDays, tvT, tvCharge);
    
    //settv returns tvCharges
    return tvCharge;
}

    //Function declaration for tvaccess, returns values by reference
    void tvaccess(int days, string & tv, float & tvCharg)
    {
        //Constant float variables for basic channel cost, and cable channel cost
        const float BASIC_CHANNELS = 5.95, CABLE_CHANNELS = 9.95;
        
        //String variable for user choice, only used locally
        string choice;
        
        cout << "TV Usage (Y/N): "; cin >> choice;
        cout << endl;
        
        //The if statements below compare the user input to the arguments given, if
        //"yes" is input the user will get to input more data, otherwise tvcharge
        //equals zero
        if (choice == "Y" or choice == "y" or choice == "YES" or choice == "yes")
        {
            //Function call for settvHeading, references tv type sub-function of
            //tvaccess
            settvHeading(days, tv, BASIC_CHANNELS, CABLE_CHANNELS);
            //Function call for settvIf, references tv type and tv charges,
            //sub-function of tvaccess
            settvIf(tv, days, tvCharg, BASIC_CHANNELS, CABLE_CHANNELS);
        }
        
        else
        {
            //sets tv charges as zero if user inputs anything but "yes"
            tvCharg = 0;
            //Sets tv as white space, for aestetic purposes
            tv = ":            ";
        }
        
    }

        //Function call for settvHeading, displays a menu to the user then asks them to
        //make a choice, result is referenced as tv type "tvType"
        void settvHeading(int numDays, string & tvType,
                          const float BASIC_CHANNELS, const float CABLE_CHANNELS)
        {
            cout << "\t\tTV Access" << endl << endl;
            
            cout << fixed << showpoint << setprecision(2);
            
            cout << "1. Basic Channels         \t\t $" << BASIC_CHANNELS << endl;
            cout << "2. Cable Channels         \t\t $" << CABLE_CHANNELS << endl << endl;
            
            cout << "You May Enter 1, B or b for a \"Basic Channels\"; 2, C or c for a \"Cable Channels\"\n";
            cout << "ENTER CHOICE: "; cin >> tvType;
        }

        //Function declaration for settvIf, compares user choice to conditions,
        //if conditions met then the statement calculates tv charges and redefines
        //tv type to display later, both are reference
        void settvIf(string & tvType, int days, float & tvCharge,
                     const float BASIC_CHANNELS, const float CABLE_CHANNELS)
        {
            
            if (tvType == "1" or tvType == "B" or tvType == "b")
            {
                tvCharge = days * BASIC_CHANNELS;
                tvType = " (BASIC):     ";
            }
            
            
            if (tvType == "2" or tvType == "C" or tvType == "c")
            {
                tvCharge = days * CABLE_CHANNELS;
                tvType = " (CABLE):    ";
            }
    
}

//Function declaration of print, displays the receipt for the patient, does not return a value
//ONLY DISPLAYS RESULTS
void print(string patName, int numDays, float roomCharg, float phoneCharg, float tvCharg,
           string roomT,string phoneT, string tvT, float totalCharg)
{
    cout << endl << endl << endl;
    
    cout << "\t\t\tSt. Joseph's Hospital" << endl << endl << endl;
    
    cout << patName << "'s Billing Statement" << endl << endl << endl;
    
    cout << "Number of Days in the Hospital:  \t" << numDays << endl << endl;
    cout << "Room Charges" << roomT << "\t\t$" << roomCharg << endl << endl;
    cout << "Phone Charges" << phoneT << "\t\t$" << phoneCharg << endl << endl;
    cout << "Televison Charges" << tvT << "\t\t$" << tvCharg << endl << endl << endl;
    
    totalCharg = roomCharg + phoneCharg + tvCharg;
    
    cout << "Total Charges:\t\t\t\t$" << totalCharg << endl << endl << endl;
    
    cout << "Hope you are satisfied with St. Joseph's Hospital services, Stay well.";
    cout << endl;
}

/* -----------------------------------------TEST 1-----------------------------------
 Enter Patient Name: Brandon Trastoy
 Enter The Number of Days in Hospital: 5
 
 Room Used
 
 1. Single Room - One Bed                 $1325.00
 2. Double Room - Two Beds                $1525.00
 3. Ward                                  $1650.00
 
 You May Enter 1, S or s for a "Single Room"; 2, D or d for a "Double Room";
 3, W or w for a "Ward"
 ENTER CHOICE: 1
 
 
 Phone Usage (Y/N): y
 
 Phone Access
 
 1. Shared Line                           $5.95
 2. Dedicated Line                        $9.95
 
 You May Enter 1, S or s for a "Shared Line"; 2, D or d for a "Dedicated Line"
 ENTER CHOICE: 2
 
 
 TV Usage (Y/N): y
 
 TV Access
 
 1. Basic Channels                        $5.95
 2. Cable Channels                        $9.95
 
 You May Enter 1, B or b for a "Basic Channels"; 2, C or c for a "Cable Channels"
 ENTER CHOICE: 1
 
 
 
 St. Joseph's Hospital
 
 
 Brandon Trastoy's Billing Statement
 
 
 Number of Days in the Hospital:         5
 
 Room Charges (SINGLE):                  $6625.00
 
 Phone Charges (DEDICATED):              $49.75
 
 Televison Charges (BASIC):              $29.75
 
 
 Total Charges:                          $6704.50
 
 
 Hope you are satisfied with St. Joseph's Hospital services, Stay well.
 */

/* -----------------------------------------TEST 2-----------------------------------
 Enter Patient Name: Timothy Schutte
 Enter The Number of Days in Hospital: 10
 
 Room Used
 
 1. Single Room - One Bed                 $1325.00
 2. Double Room - Two Beds                $1525.00
 3. Ward                                  $1650.00
 
 You May Enter 1, S or s for a "Single Room"; 2, D or d for a "Double Room";
 3, W or w for a "Ward"
 ENTER CHOICE: 2
 
 
 Phone Usage (Y/N): n
 
 TV Usage (Y/N): n
 
 
 
 
 St. Joseph's Hospital
 
 
 Timothy Schutte's Billing Statement
 
 
 Number of Days in the Hospital:         10
 
 Room Charges (DOUBLE):                  $15250.00
 
 Phone Charges:                          $0.00
 
 Televison Charges:                      $0.00
 
 
 Total Charges:                          $15250.00
 
 
 Hope you are satisfied with St. Joseph's Hospital services, Stay well.
 */

/* -----------------------------------------TEST 3-----------------------------------
 Enter Patient Name: Muhammed Izeiroski
 Enter The Number of Days in Hospital: 10
 
 Room Used
 
 1. Single Room - One Bed                 $1325.00
 2. Double Room - Two Beds                $1525.00
 3. Ward                                  $1650.00
 
 You May Enter 1, S or s for a "Single Room"; 2, D or d for a "Double Room";
 3, W or w for a "Ward"
 ENTER CHOICE: w
 
 
 Phone Usage (Y/N): y
 
 Phone Access
 
 1. Shared Line                           $5.95
 2. Dedicated Line                        $9.95
 
 You May Enter 1, S or s for a "Shared Line"; 2, D or d for a "Dedicated Line"
 ENTER CHOICE: d
 
 
 TV Usage (Y/N): y
 
 TV Access
 
 1. Basic Channels                        $5.95
 2. Cable Channels                        $9.95
 
 You May Enter 1, B or b for a "Basic Channels"; 2, C or c for a "Cable Channels"
 ENTER CHOICE: C
 
 
 
 St. Joseph's Hospital
 
 
 Muhammed Izeiroski's Billing Statement
 
 
 Number of Days in the Hospital:         10
 
 Room Charges (WARD):                    $16500.00
 
 Phone Charges (DEDICATED):              $99.50
 
 Televison Charges (CABLE):              $99.50
 
 
 Total Charges:                          $16699.00
 
 
 Hope you are satisfied with St. Joseph's Hospital services, Stay well.
 */

/* -----------------------------------------TEST 4-----------------------------------
 Enter Patient Name: Jahmil
 Enter The Number of Days in Hospital: 4
 
 Room Used
 
 1. Single Room - One Bed                 $1325.00
 2. Double Room - Two Beds                $1525.00
 3. Ward                                  $1650.00
 
 You May Enter 1, S or s for a "Single Room"; 2, D or d for a "Double Room";
 3, W or w for a "Ward"
 ENTER CHOICE: 2
 
 
 Phone Usage (Y/N): n
 
 TV Usage (Y/N): y
 
 TV Access
 
 1. Basic Channels                        $5.95
 2. Cable Channels                        $9.95
 
 You May Enter 1, B or b for a "Basic Channels"; 2, C or c for a "Cable Channels"
 ENTER CHOICE: 1
 
 
 
 St. Joseph's Hospital
 
 
 Jahmil's Billing Statement
 
 
 Number of Days in the Hospital:         4
 
 Room Charges (DOUBLE):                  $6100.00
 
 Phone Charges:                          $0.00
 
 Televison Charges (BASIC):              $23.80
 
 
 Total Charges:                          $6123.80
 
 
 Hope you are satisfied with St. Joseph's Hospital services, Stay well.
 */

