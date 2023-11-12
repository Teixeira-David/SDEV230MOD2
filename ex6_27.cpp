// ----------------------------------------------------------------
// Author: David Teixeira 
// Project: Unit 6 Exercise 6-27
// Course: SDEV-230
// Creation Date: 11/04/2023
// ----------------------------------------------------------------

// Import the Preprocessor Directives
#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <sstream>

// Provide scope to identifiers inside the standard library
using namespace std;

// Create the constants
const int intMaxHour = 23;
const int intMaxMin = 59;

// Place the headers for each function
bool Sentinel_Control();
string Get_Time_Of_Day();
int Get_Hour();
int Get_Minute();
int Get_Second();
void Get_Military_Time(int intHourInput, int intMinuteInput, int intSecondInput, string& strMilitaryTime);
void Get_Standard_Time(int intHourInput, int intMinuteInput, int intSecondInput, string& strStandardTime);

int main() 
{
    // Create the Local Variables
    int intHourInput, intMinuteInput, intSecondInput;
    string strTimeResult, strTimeOfDay;
    bool blnFlag = true;

    // Get the sentinel control value
    blnFlag = Sentinel_Control();

    // Create the while loop until the user wants to exit the program
    while (blnFlag != false) {
        // Display instruction message to user
        cout << "----------------------------------------------------------------" << endl;
        cout << "You will be prompted to enter a time, either military format (HH:MM) " << endl;
        cout << "or 12 hour format (HH:MM)." << endl;
        cout << "----------------------------------------------------------------" << endl;

        // Get the input of the hour
        intHourInput = Get_Hour();

        // Get the input of the minute
        intMinuteInput = Get_Minute();

        // Get the input of the second
        intSecondInput = Get_Second();

        // Knowing the choice of military or standardized time, display the output of the time 
        Get_Standard_Time(intHourInput, intMinuteInput, intSecondInput, strTimeResult);

        // Get the sentinel control value
        blnFlag = Sentinel_Control();
    }

    // Display the time result
    cout << "The time is: " << strTimeResult << endl;

    // Main should return an int   
    return 0;  
}    

bool Sentinel_Control()
/*
Function Name: Sentinel_Control
Function Purpose: Function is to gets the continuation selection from the user.
*/
{
    // Declare Local Variables
    int intSentinelInput;
    bool blnFlag = false;

    // Get the user input for time of day, either AM or PM
    cout << "Please enter '1' for Military Time, or '2' for Standard Time to get the time." << endl;
    cout << "Otherwise, enter '99' to exit and display the time result: ";
    while (true) {
        cin >> intSentinelInput;
        // Check if the input is either 1 or 99
        if (intSentinelInput == 1 || intSentinelInput == 2) {
            blnFlag = true;
            return blnFlag;
        } else if (intSentinelInput == 99) {
            blnFlag = false;
            return blnFlag;
        } else {
            // Display error message to user about the incorrect input
            cout << "Invalid input. Input must be '1' or '99'. Please try again." << endl;
            // Clear the error flag and ignore the rest of the line
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}  

string Get_Time_Of_Day()
/*
Function Name: Get_Time_Of_Day
Function Purpose: Function is to get the time of day from the user.
*/
{
    // Declare Local Variables
    string strInput;

    // Get the user input for time of day, either AM or PM
    cout << "Please enter 'AM' for morning, or 'PM' for afternoon time: ";
    while (true) {
        cin >> strInput;
        // Check if the input is either 'AM' or 'PM'
        if (strInput == "AM" || strInput == "PM") {
            return strInput;
        } else {
            // Display error message to user about the incorrect input
            cout << "Invalid input. Input must be 'AM' or 'PM'. Please try again." << endl;
            // Clear the error flag and ignore the rest of the line
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}  

int Get_Hour()
/*
Function Name: Get_Hour
Function Purpose: Function is to get the hour of day from the user.
*/
{
    // Declare Local Variables
    int intHourInput;

    // Get the input for the hours
    cout << "Please enter the hour (0-23): ";
    while (true) {
        // Check if the hours input is within the range of 0-23 
        if (cin >> intHourInput && intHourInput >= 0 && intHourInput <= intMaxHour) {
            return intHourInput;
        } else {
            cout << "Invalid hour. Please enter a value between 0 and 23: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

int Get_Minute()
/*
Function Name: Get_Minute
Function Purpose: Function is to get the minute of day from the user.
*/
{
    // Declare Local Variables
    int intMinuteInput;

    // Get the input for the minutes
    cout << "Please enter the minute (0-59): ";
    while (true) { 
        // Check if the minute input is within the range of 0-59
        if (cin >> intMinuteInput && intMinuteInput >= 0 && intMinuteInput <= intMaxMin) {
            return intMinuteInput;
        } else {
            cout << "Invalid minute. Please enter a value between 0 and 59: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

int Get_Second()
/*
Function Name: Get_Second
Function Purpose: Function is to get the second of day from the user.
*/
{
    // Declare Local Variables
    int intSecondInput;

    // Get the input for the seconds
    cout << "Please enter the second (0-59): ";
    while (true) { 
        // Check if the second input is within the range of 0-59
        if (cin >> intSecondInput && intSecondInput >= 0 && intSecondInput <= intMaxMin) {
            return intSecondInput;
        } else {
            cout << "Invalid second. Please enter a value between 0 and 59: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

void Get_Military_Time(int intHourInput, int intMinuteInput, int intSecondInput, string& strMilitaryTime)
/*
Function Name: Get_Military_Time
Function Purpose: Function is to format the military time.
*/
{
    // Delcare Local Variables
    stringstream ss;

    // Format the compound string output
    ss << setw(2) << setfill('0') << intHourInput << ":" << setw(2) << setfill('0') << intMinuteInput << ":" << setw(2) << setfill('0') << intSecondInput;
    strMilitaryTime = ss.str();
}

void Get_Standard_Time(int intHourInput, int intMinuteInput, int intSecondInput, string& strStandardTime)
/*
Function Name: Get_Military_Time
Function Purpose: Function is to format the military time.
*/
{
    // Delcare Local Variables
    stringstream ss;
    int displayHour = ((intHourInput == 0 || intHourInput == 12) ? 12 : intHourInput % 12);

    // Format the compound string output
    ss << setw(2) << setfill('0') << displayHour << ":" << setw(2) << setfill('0') << intMinuteInput << ":" << setw(2) << setfill('0') << intSecondInput;
    ss << (intHourInput < 12 ? " AM" : " PM");
    strStandardTime = ss.str();
}