/**
 * birthdays.cpp
 *
 * Meredith Gilbert
 * meregilb@umich.edu
 *
 * EECS 183: Project 2
 *
 * In this program, we are determining the day in which
 an individual was born.  We do this by creating a program
 that prompts them the date of their birth and then returns
 with the day of the week they were born on.
 */

#include <iostream>
#include <cmath>
using namespace std;


/**
 * Requires: Nothing.
 * Modifies: cout.
 * Effects:  Prints out the initial heading for the program.
 */
void printHeading();



/**
 * Requires: year is a Gregorian year.
 * Modifies: Nothing.
 * Effects:  Returns true if the year is a leap year, otherwise returns false.
 */
bool isLeapYear(int year);


/**
 * Requires: Month, day and year are positive integers representing a
 *           valid calendar date.
 * Modifies: Nothing.
 * Effects:  Returns true if the date is on or after September 14, 1752,
 *           otherwise returns false. Remember that if input violates the
 *           Requires clause, the behavior of a function is undefined.
 */
bool isGregorian(int month, int day, int year);


/**
 * Requires: month, day, year may represent a date.
 * Modifies: Nothing.
 * Effects:  Returns true if the date is valid, otherwise returns false.
 */
bool isValidDate(int month, int day, int year);


/**
 * Requires: month, day, year form a valid date.
 * Modifies: Nothing.
 * Effects:  Returns the value that Zeller's formula calculates.
 */
int determineDay(int month, int day, int year);


/**
 * Requires: 0 <= day and day <= 6.
 * Modifies: cout.
 * Effects:  Prints the day you were born on. day 0 is Sat, day 1 is Sun, etc.
 * Example:  You were born on a: Sunday
 */
void printDayBornOn(int day);


int main() {

    int zday; //declares for the answer gotten from Zeller's Rule
    char slash; //accounts for when user enters '/' in date
    int day; //day entered in birthday
    int month; //month entered in birthday
    int year; //year entered in birthday

    printHeading(); //prints heading from function mentioned later on

    cout << "Enter your date of birth --> ";
    cin >> month; //accounts for the date of birth entered by user
    cin >> slash;
    cin >> day;
    cin >> slash;
    cin >> year;
    cout << endl;

    if (isValidDate(month, day, year)) { //determines what is valid birthday
        zday = determineDay(month, day, year);
        printDayBornOn(zday);
        cout << endl;

        cout << "Have a great birthday!!!" << endl; //if birthday is valid
    }
    else {
        cout << "Invalid date"; //if birthday is invalid
    }
 
    return 0;
}

void printHeading() { //function for heading
    
    cout << "*******************************" << endl
         << "      Birthday Calculator      " << endl
         << "*******************************" << endl << endl;

}

bool isLeapYear(int year) { //determines if year inputted is leap year

    if (year % 100 == 0) { //not leap year if divisible by 100, but...
        if (year % 400 == 0) { //leap year if divisible by 400
            return true;
        }
        else {
            return false;
        }
    }
    else if (year % 4 == 0) { //all years divisible by 4 are leap year
        return true;
    }
    else {
        return false;
    }
}

bool isGregorian(int month, int day, int year) {

    if (year == 1752) { //in the year 1752...
        if (month == 9) { //only September 13 and onward is valid
            if (day > 13) {
                return true;
            }
            else {
                return false;
            }
        }
        else if (month > 9) {
            if (day > 0) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }
    else if (year > 1752) { //everything above 1752 is in Gregorian calendar
        return true;
    }
    else {
        return false;
    }
}

bool isValidDate(int month, int day, int year) { //determines if date is valid
    if (month >= 1 && month <= 12) { //only months 1-12 are valid
        if (isGregorian(month, day, year)) { //only Gregorian dates register
            if (month == 4 || 6 || 9 || 11) { //certain months have only 30 days
                if (day > 0 && day <= 30) {
                    return true;
                }
                else {
                    return false;
                }
            }
            else if (month == 1 || 3 || 5 || 7 || 8 || 10 || 12) {
                if (day > 0 && day <= 31) { //regular months
                    return true;
                }
                else {
                    return false;
                }
            }
            else if (month == 2) { //February can have 29 days if leap year
                if (isLeapYear(year)) {
                    if (day > 0 && day <= 29) {
                        return true;
                    }
                    else {
                        return false;
                    }
                }
                else if (day > 0 && day <= 28) { //Feb usually have 28 days
                    return true;
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}


int determineDay(int month, int day, int year) { //assign months #s for Zell Rule
    if (isValidDate(month, day, year)) {
        if (month == 1) { //January = 13th month and year - 1
            month = 13;
            year = year - 1;
        }
        else if (month == 2) { //February = 14th month and year -1
            month = 14;
            year = year - 1;
        }
    }


int Years = year % 100; //year in Zell Rule, gets last 2 #s in 4 digit year
int Centuries = floor(year / 100); //century in Zell Rule, first 2 #s in year
int zday = (day + ((13 * (month + 1)) / 5) 
            + Years + (Years / 4) + (Centuries / 4) + (5 * Centuries)) % 7;
return zday; //Zeller's Rule Equation
}


void printDayBornOn(int day) { //states what day you were born on

    if (day == 0) {
        cout << "You were born on a: Saturday";
    }
    else if (day == 1) {
        cout << "You were born on a: Sunday";
    }
    else if (day == 2) {
        cout << "You were born on a: Monday";
    }
    else if (day == 3) {
        cout << "You were born on a: Tuesday";
    }
    else if (day == 4) {
        cout << "You were born on a: Wednesday";
    }
    else if (day == 5) {
        cout << "You were born on a: Thursday";
    }
    else if (day == 6) {
        cout << "You were born on a: Friday";
    }
    cout << endl;

}

