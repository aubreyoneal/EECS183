/*
 * PROGRAM: functions.cpp
 * AUTHOR: Aubrey O'Neal
 * UNIQNAME: aubreyo
 * GSI Name: Jill
 *
 *
 * EECS 183 - Winter 2014
 * Project Number: 3
 * Due Date: February 26, 2014
 * SUMMARY:
 *    This program does ???? -- that's a really good question
 * We do NOT believe this code is good, appropriate, nor acceptable
 * However, it is good for debugging purposes
 *
 */

#include <iostream>
#include <iomanip>
#include "functions.h"

using namespace std;

void printBoard(int rows, int cols){
    int countRow = 0, countCol = 0;
    while (countCol < cols){
        while (countRow < rows){
            cout << '*';
            ++countRow;
        }
        countRow = 0;
        ++countCol;
        cout << endl;
    }
}

void printRight(int n){
    for (int countLine = 0; countLine <= n; ++countLine){
        for (int countStar = 0; countStar < countLine; ++countStar){
            cout << "*";
        }
        cout << endl;
    }
}

//An example of the logic flow: n = 3, spaces = 2, stars = 3-2
//Then spaces becomes 1, so in the next iteration stars = 3-1
void printRight_rightJustified(int n){
    int stars, spaces;
    for(spaces = (n - 1); spaces >= 0; --spaces){
        cout << setw(spaces + 1);
        for(stars = 1; stars <= (n - spaces); ++stars){
            cout << "*";
        }
        cout << endl;
    }
}

//An example of the logic flow: n = 3, spaces = 0, stars = 3
//Then spaces become 2, so stars = 2
void printRight_upsideDown_rightJustified(int n){
    int stars, spaces;
    for(spaces = 0; spaces <= (n - 1); ++spaces){
        cout << setw(spaces + 1);
        for(stars = n; stars > spaces; --stars){
            cout << "*";
        }
        cout << endl;
    }
}

//An example of the logic flow: n = 3, spaces = 0, stars = 3
//Then spaces becomes 2, so stars = 2
void printRight_upsideDown(int n){
    int stars, spaces;
    for(spaces = 0; spaces <= (n - 1); ++spaces){
        cout << setw(spaces - n);
        for(stars = n; stars > spaces; --stars){
            cout << "*";
        }
        cout << endl;
    }
}

void threeSeries(int n){
    if(n == 1){
        cout << n << endl;
    }
    else {
        cout << n << ", ";
    }
    while (n != 1){
        if (n % 2 == 0){// is even
            n /= 2;
            if (n != 1){//checks for end of function
                cout << n << ", ";
            }
            else {
                cout << n << endl;
            }
        }
        else {// is odd
            n = n * 3 + 1;
            cout << n << ", ";
        }
    }
}

void swap(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
    cout << endl;
}


bool equalsDigit(int num, int digit){
    if ((digit == 0 && (num % 10 == 0)) || (digit == num)){
        return true;
    }
    while (num > 0){
        if (num % 10 == digit) {
            return true;
        }
        else {
            num /= 10;
        }
    }
    return false;
}


void printIfHoldsDigit(int start, int end, int digit){
    if (start > end){
        swap(start, end);
    }
    for (start = start; start <= end; ++ start){
        if (equalsDigit(start, digit)){
            if ((start < end - digit && digit != 0) ||
                (equalsDigit(end, digit) && start < end)){
                cout << start << ", ";
            }
            else {
                cout << start << endl;
                return;
            }
        }
    }
}


int reverseNumber(int n){
    int reverse = 0;
    while (n > 0){
        reverse = 10 * reverse + n % 10;
        n /= 10;
    }
    return reverse;
}


void reverseNum(int & n){
    n = reverseNumber(n);
}

int calcNum(int val){
    int total = 0;
    if (val < 100 && val > 0){
        total = 1;
    }
    else if (val % 100 != 0){
        total = (val / 100 + 1);
    }
    else {
        total = val / 100;
    }
    return total;
}

//This function is used to make the bar chart cleaner
//Requires: money >= 0
//Modifies: nothing
//Effects: It calculates how many stars need to be printed
//         Ex) money = 101 would calculate to stars = 2
int starRounder();

int starRounder(int money){
    int stars;
    if (money >= 100 && money % 100 != 0) {
        stars = (money / 100) + 1;
    }
    else if (money >= 100){
        stars = money / 100;
    }
    else if (money < 100 && money > 0){
        stars = 1;
    }
    else {
        stars = 0;
    }
    return stars;
}
void printBarChart(int store1, int store2, int store3,
				   int store4, int store5){
    cout << "SALES BAR CHART" << endl
         << "(Each * = $100)" << endl;
    cout << "Store 1: " ;
    printBoard(starRounder(store1), 1);
    cout << "Store 2: " ;
    printBoard(starRounder(store2), 1);
    cout << "Store 3: " ;
    printBoard(starRounder(store3), 1);
    cout << "Store 4: " ;
    printBoard(starRounder(store4), 1);
    cout << "Store 5: " ;
    printBoard(starRounder(store5), 1);

}

bool isPrime(int val){
    if (val < 2){
        return false;
    }
    for (int count = val -1; count >= 2; --count){
        if (val == 2){
            return true;
        }
        if(val % count == 0 ){
            return false;
        }
    }
    return true;
}

void printPrimes(int start, int end){
    if (start > end){
        swap(start, end);
    }
    for (start = start; start <= end; ++start){
        if (isPrime(start)){
                cout << start << endl;
            }
    }
}

void prettyPrintPrimes(int start, int end){
    cout <<  "Prime numbers from " << start << " to " << end << " are:" << endl
    << "--------------------------------" << endl;
    int primeCount = 0;
    while (start <= end){
        for (start = start; start <= end; ++start){
            if (isPrime(start)){
                if (primeCount >= 5){
                    cout << endl;
                    primeCount = 0;
                }
                ++primeCount;
                cout << setw(5) << start;
            }
        }
        cout << endl;
    }
}

int sumPrimes(int n){
    int primeCount = 1, total = 0, increasingNumber = 2;
    while (primeCount <= n){
            if (isPrime(increasingNumber)){
                ++primeCount;
                total += increasingNumber;
        }
        ++increasingNumber;
    }
    return total;
}


void printTwinPrimes(int start, int end){
    int tempPrime = 2; //stores the previous start to use for comparison
    if (start == 1){
        ++start;
    }
    if (start > end){
        swap(start, end);
    }
    for (start = start; start <= end; ++start){
        if (isPrime(start)){
            if (start - tempPrime == 2){
                cout << "(" << tempPrime << ", " << start << ") ";
            }
                tempPrime = start;
        }
    }
    cout << endl;
}


void printCousinPrimes(int start, int end){
    int temp1 = 0, temp2 = 0;
    if (start > end){
        swap(start, end);
    }
    for(start = start; start <= end; ++start){
        if(isPrime(start)){
            temp1 = start;
            temp2 = temp1 - 4;
            if(isPrime(temp2) && temp2 == start - 4 && temp2 > 0){
                cout << "(" << temp2 << ", " << start << ") ";
            }
        }
    }
    cout << endl;
}

void printArrow(int n){
    int count = 0, starCount = 1;
    for (count = 0; count < n; ++count){
        cout << setw(2 * n + 2) << " ";
        printBoard(starCount, 1);
        starCount += 2;
    }
    printBoard((starCount * 2 + 1), 1);
    starCount -= 2;
    for (count = n; count >= 1; --count){
        cout << setw(2 * n + 2) << " ";
        printBoard(starCount, 1);
        starCount -= 2;
    }
}

