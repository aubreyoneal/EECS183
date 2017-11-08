/*
 * PROGRAM: functions.h
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

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

//NOTE for every function
// The last line should end with an 'endl'
// There should be no blank lines printed at the beginning
// nor at the end


// Requires: rows must be > 0,
//           cols must be > 0
// Effects: prints a rectangle of *'s
// Note: printBoard(3,2);
//       cout << endl;
//       printBoard(1,3);
//       cout << endl;   //will print
// Note:  no spaces at the end of lines
//**
//**
//**
//           Note this blank line is printed by the testing cpp
//***
//           Note this blank line is printed by the testing cpp
void printBoard(int rows, int cols);



// Requires: n must be > 0
// Modifies: nothing
// Effects: prints a right triangle
//  with a parameter of 3 gives
// Note: no spaces at the end of lines
//*
//**
//***
void printRight(int n);



// Requires: n must be > 0
// Modifies: nothing
// Effects: prints a right triangle with the *'s right justified
//   with a parameter of 3 gives
// Note: no spaces at the end of lines
//  *
// **
//***
void printRight_rightJustified(int n);



// Requires: n must be > 0
// Modifies: nothing
// Effects: prints a right triangle upside down
//   with a parameter of 3 gives
// Note: no spaces at the end of lines
//***
// **
//  *
void printRight_upsideDown_rightJustified(int n);



// Requires n must be > 0
// Modifies: nothing
// Effects: prints a right triangle upside down
//         with a parameter of 3 gives
// Note: no spaces at the end of lines
//***
//**
//*
void printRight_upsideDown(int n);



// Requires:  n must be > 0
// Modifies:  nothing
// Effects:   prints a series of values
//        if n is even, halve it
//        if n is odd, triple it and add one
//        continue until n is 1
// threeSeries(3) gives
// 3, 10, 5, 16, 8, 4, 2, 1
// threeSeries(1) gives
// 1
// (yes you also need to print the commas)
// Note: \b will not give the effect you want
void threeSeries (int n);



// Requires: nothing
// Modifies: x and y
// Effects: will swap the values of x and y
//         if x = 7 and y = 13 upon entry
//         when this function ends, x = 13 and y = 7
void swap(int & x, int & y);



// Requires: num must be >= 0
//           digit is between 0 and 9 inclusive
// Modifies: nothing
// Effects: will return true if 'digit' occurs anywhere within 'num'
//          returns false otherwise
//          if num=42 and digit = 5  this will return false
//          if num=42 and digit = 4  this will return true
//          if num=142 and digit = 1  this will return true
bool equalsDigit(int num, int digit);



// Requires: start must be > 0; end must be > 0;
//           digit is between 0 and 9 inclusive
// Modifies: nothing
// Effects: runs the range of numbers from start to end inclusive
// if (end < start), it will swap start and end
// prints the number if any digit of the number is the
// same as 'digit'
// printIfHoldsDigit(5, 10, 7) //prints: 7
// printIfHoldsDigit(5, 30, 8) //prints: 8, 18, 28
// printIfHoldsDigit(1, 30, 2)  prints: 2, 12, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29
// and yes you need to print the commas
void printIfHoldsDigit(int start, int end, int digit);



// Requires: n must be >= 0
// Modifies: nothing
// Effects: returns the int formed by reversing the digits of n
//  a parameter of 123 will return 321
//  a parameter of 1234 will return 4321
//  a parameter of 1230 will return 321  (or 0321)
//   NOTE: in C++ literals that begin with a 0 are interpreted to be octal
//         numbers and not decimal numbers
//   NOTE:  Numbers that start with 0, example  0321
//          note it is an octal number not decimal
//          the autograder will NOT check for octal numbers
int reverseNumber(int n);



// Requires: n must be >= 0;
// Modifies:  n
// Effects: alters n to be the integer formed by reversing its digits
//          if n = 123, then it will be altered to be 321
//          if n = 1234, then it will be altered to be 4321
//          if n = 1230, then it will be altered to be 321
//   NOTE: in C++ literals that begin with a 0 are interpreted to be octal
//         numbers and not decimal numbers
//   NOTE:  Numbers that start with 0, example  0321 --
//          note this is an octal number not decimal
//          the autograder will not check for octal numbers
void reverseNum(int & n);



// Requires: val must be >= 0
// Modifies: nothing
// Effects: returns how many hundreds there are in val
//         if the val is not an exact number of 100's, it
//         adds one
//         if val = 1300, it returns 13
//         if val = 1324, it returns 14
//         if val = 0, it return 0
//         if val = 1, it returns 1
//         if val = 100, it returns 1
//         if val = 101, it returns 2
int calcNum(int val);


// Requires: store1, store2, store3, store4, and store5 must be >= 0
//          these represent the sales of 5 stores
// Modifies: nothing
// Effects:  prints a bar chart for the sales
//          one * for each $100 of sales
// printBarChart(500,510,120,750,812);  // prints the following --
//                                      // including the header
// SALES BAR CHART
// (Each * = $100)
// Store 1: *****
// Store 2: ******
// Store 3: **
// Store 4: ********
// Store 5: *********
void printBarChart(int store1, int store2, int store3,
				   int store4, int store5);



// Requires: val must be > 0
// Modifies: nothing
// Effects: returns true is val is a prime
//         returns false otherwise
// Note:  in modern mathematical usage, 1 is NOT considered to be prime
bool isPrime(int val);



// Requires: start must be > 0; end must be > 0
// Modifies: nothing
// Effects: prints out the primes between start and end inclusive
// if start > end, it will swap them
// if start = 5, end = 10 this prints
// 5
// 7
void printPrimes(int start, int end);



// same as 'printPrimes' except this will be a 'pretty' print
// 5 primes per line
// if start = 1, end = 101, this prints
//
// Prime numbers from 1 to 101 are:
// --------------------------------
//     2    3    5    7   11
//    13   17   19   23   29
//    31   37   41   43   47
//    53   59   61   67   71
//    73   79   83   89   97
//   101
//
// you will want a setw(5) on this one to get the columns
void prettyPrintPrimes(int start, int end);



// Requires: n must be >= 0
// Modifies: nothing
// Effects: returns the sum of the first 'n' primes
//  a parameter of 5 will return
//    2 + 3 + 5 + 7 + 11 or 28
int sumPrimes(int n);



// Requires: start must be > 0; end must be > 0
// Modifies: nothing
// Effects: prints out the twin primes between start and end inclusive
// if start > end, it will swap them
// if start = 1, end = 20 this prints
// (3, 5) (5, 7) (11, 13) (17, 19)
// FYI: twin primes are 2 prime numbers whose difference is 2
void printTwinPrimes(int start, int end);



// Requires: start must be > 0; end must be > 0
// Modifies: nothing
// Effects: prints out the cousin primes between start and end inclusive
// if start > end, it will swap them
// if start = 1, end = 25 this prints
// (3, 7) (7, 11) (13, 17) (19, 23)
// if start = 1, end = 22 this prints
// (3, 7) (7, 11) (13, 17)
// FYI: cousin primes are 2 prime numbers whose difference is 4
void printCousinPrimes(int start, int end);



// Requires: n must be > 0
// Modifies: nothing
// Effects: prints an arrow
//   starting with one *
//   the next row has 2 additional *'s
//   the longest row has 4 * n + 3  *'s
//   and the the *'s decrease by 2 per row unti it is back to one *
//   Note: no spaces on the end of the lines
//   There should be an <Enter> at the end of each line of *'s
//   printArrow(2);  
//   cout << endl << endl;
//   printArrow(3);  // will print
//      *
//      ***
//***********
//      ***
//      *
//                 Note the blank lines are printed by the testing cpp
//
//        *
//        ***
//        *****
//***************   
//        *****
//        ***
//        *
void printArrow(int n);


#endif