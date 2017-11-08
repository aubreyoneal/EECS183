/*
 * PROGRAM: test1.cpp
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

void test_printBoard();
void test_printRight();
void test_printRight_rightJustified();
void test_printRight_upsideDown_rightJustified();
void test_printRight_upsideDown();
void test_threeSeries();
void test_swap();
void test_equalsDigit();
void test_printIfHoldsDigit();
void test_reverseNumber();
void test_reverseNum();
void test_calcNum();
void test_printBarChart();
void test_isPrime();
void test_printPrimes();
void test_prettyPrintPrimes();
void test_sumPrimes();
void test_printTwinPrimes();
void test_printCousinPrimes();
void test_printArrow();

int main ()
{
    test_printBoard();
    test_printRight();
    test_printRight_rightJustified();
    test_printRight_upsideDown_rightJustified();
    test_printRight_upsideDown();
    test_threeSeries();
    test_swap();
    test_equalsDigit();
    test_printIfHoldsDigit();
    test_reverseNumber();
    test_reverseNum();
    test_calcNum();
    test_printBarChart();
    test_isPrime();
    test_printPrimes();
    test_prettyPrintPrimes();
    test_sumPrimes();
    test_printTwinPrimes();
    test_printCousinPrimes();
    test_printArrow();
    return 0;
    
}
void test_printBoard(){
    cout << "Board" << endl;
    printBoard(1,1); //single star
    cout << endl;
    printBoard(1,2); //row less than col
    cout << endl;
    printBoard(2,2); //square
    cout << endl;
    printBoard(2,1); //col less than row
    cout << endl;
    printBoard(3,2); //given
    cout << endl;
    printBoard(1,3); //given
}
void test_printRight(){
    cout << "Left Aligned Triangle" << endl;
    printRight(1); //lower limit
    printRight(2); //even numer
    printRight(3); //odd numer
    printRight(5); //noramal
}
void test_printRight_rightJustified(){
    cout << "Right Aligned  Triangle" << endl;
    printRight_rightJustified(1);
    printRight_rightJustified(2); //even numer
    printRight_rightJustified(3);
    printRight_rightJustified(5);
}
void test_printRight_upsideDown_rightJustified(){
    cout << "Right Upside Down Triangle" << endl;
    printRight_upsideDown_rightJustified(1);
    printRight_upsideDown_rightJustified(2); //even numer
    printRight_upsideDown_rightJustified(3);
    printRight_upsideDown_rightJustified(5);
}
void test_printRight_upsideDown(){
    cout << "Left Aligned Triangle" << endl;
    printRight_upsideDown(1);
    printRight_upsideDown(2); //even number
    printRight_upsideDown(3);
    printRight_upsideDown(5);
}
void test_threeSeries(){
    cout << "Three Series" << endl;
    threeSeries(1); // 1 odd
    threeSeries(2); // 1 even
    threeSeries(3); // 3, 10, 5, 16, 8, 4, 2, 1
    threeSeries(11);
    threeSeries(20);
    threeSeries(101);
    cout << endl;
}
void test_swap(){
    int x = 7;
    int y = 13;
    cout << "Swap" << endl << x << " " << y;
    swap(x, y);
    cout << x << " " << y << endl;
    int a = 7;
    int b = 7;
    cout << "Swap" << endl << a << " " << b;
    swap(a, b);
    cout << a << " " << b << endl;
    int d = 2;
    int e = 1;
    cout << "Swap" << endl << d << " " << e;
    swap(d, e);
    cout << d << " " << e << endl;
    int f = 0;
    int g = 1;
    cout << "Swap" << endl << f << " " << g;
    swap(f, g);
    cout << f << " " << g << endl;
    int h = 0;
    int i = 0;
    cout << "Swap" << endl << h << " " << i;
    swap(h, i);
    cout << h << " " << i << endl;
    
}
void test_equalsDigit(){
    cout << "Check if Number contains digit" << endl;
    cout << equalsDigit(42, 4) << endl; //true
    cout << equalsDigit(2, 1) << endl; // false
    cout << equalsDigit(1, 1) << endl; // true
    cout << equalsDigit(0, 0) << endl; // true!
    cout << equalsDigit(1, 9) << endl; //false
    cout << equalsDigit(999, 9) << endl; //true
    cout << equalsDigit(10, 0) << endl; // true!
    cout << equalsDigit(101, 0) << endl; // true!
    cout << equalsDigit(11, 1) << endl; //true
}
void test_printIfHoldsDigit(){
    cout << "Check if a range holds digit" << endl;
    printIfHoldsDigit(2, 2, 2);//2
    printIfHoldsDigit(2, 2, 1);//nothing
    printIfHoldsDigit(5, 10, 7);//7
    printIfHoldsDigit(10, 5, 7);//7, test swap
    printIfHoldsDigit(5, 10, 5);//5
    printIfHoldsDigit(5, 30, 8);//8, 18, 28
    printIfHoldsDigit(1, 30, 2);//2, 12, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29
    printIfHoldsDigit(1, 30, 0);//10, 20, 30
    printIfHoldsDigit(1, 101, 0);//check when zero not at end
    printIfHoldsDigit(5, 95, 5);//start and ends contains 5, check commas
}
void test_reverseNumber(){
    cout << "Reverse number" << endl;
    cout << "321 " << reverseNumber(321) << endl;
    cout << "107 " << reverseNumber(107) << endl;
    cout << "54321 " << reverseNumber(54321) << endl;
    cout << "10203 " << reverseNumber(10203) << endl;
    cout << "111 " << reverseNumber(111) << endl;
    cout << "0 " << reverseNumber(0) << endl;
}
void test_reverseNum(){
    int n = 456;
    cout << "Reverse number" << endl;
    reverseNum(n);
    cout << "456 " << n << endl;
    n = 10203;
    reverseNum(n);
    cout << "10203 " << n << endl;
    n = 54321;
    reverseNum(n);
    cout << "54321 " << n << endl;
    n = 111;
    reverseNum(n);
    cout << "111 " << n << endl;
    n = 0;
    reverseNum(n);
    cout << "0 " << n << endl;
    
}

void test_calcNum(){
    cout << "Find hundreds in a number" << endl;
    cout << calcNum(0) << endl; // it return 0
    cout << calcNum(1) << endl; // returns 1
    cout << calcNum(10) << endl; // returns 1
    cout << calcNum(99) << endl; // returns 1
    cout << calcNum(100) << endl; // it return 1
    cout << calcNum(102) << endl; // it return 2
    cout << calcNum(1300) << endl; // it returns 13
    cout << calcNum(1324) << endl; // it returns 14
    cout << calcNum(43210) << endl; // it returns 433
}
void test_printBarChart(){
    printBarChart(500,510,120,750,812);
    cout << endl;
    printBarChart(0, 1, 0, 99, 300);
    cout << endl;
    printBarChart(2, 300, 399, 201, 101);
    cout << endl;
}
void test_isPrime(){
    cout << "Check if number is prime" << endl;
    cout << isPrime(1) << endl;  //false
    cout << isPrime(2) << endl;  //true
    cout << isPrime(9) << endl; // false
    cout << isPrime(7) << endl; //true
    cout << isPrime(11) << endl; //true
    cout << isPrime(12) << endl; //false
    cout << isPrime(99) << endl; //false
    cout << isPrime(103) << endl;//true
    cout << isPrime(121) << endl; //false
    cout << isPrime(169) << endl; //false
    cout << isPrime(361) << endl; //false
    cout << isPrime(729) << endl; //false
}

void test_printPrimes(){
    cout << "Prints Prime numbers in a range " << endl;
    printPrimes(1, 9); //checks 1
    cout << endl;
    printPrimes(5, 5); //start and end the same
    cout << endl;
    printPrimes(5, 7); //start end prime, no primes in between
    cout << endl;
    printPrimes(11, 20); //checks for prime between 9 and 23
    cout << endl;
    printPrimes(83, 200); //prime to not prime
    cout << endl;
    printPrimes(16, 18); //not prime to not prime
    cout << endl;
    printPrimes(16, 19); //not prime to prime
    cout << endl;
    printPrimes(18, 16); //start > end
    cout << endl;
}
void test_prettyPrintPrimes(){
    cout << "Organizes Primes in a range " << endl;
    prettyPrintPrimes(1, 101);
    prettyPrintPrimes(101, 201);
    prettyPrintPrimes(1, 9); //checks 1
    prettyPrintPrimes(5, 5); //start and end the same
    prettyPrintPrimes(5, 7); //start end prime, no primes in between
    prettyPrintPrimes(11, 20); //checks for prime between 9 and 23
    prettyPrintPrimes(83, 200); //prime to not prime
    prettyPrintPrimes(16, 18); //not prime to not prime
    prettyPrintPrimes(16, 19); //not prime to prime
}
void test_sumPrimes(){
    cout << "Print sum of primes " << endl;
    cout << sumPrimes(1) << endl;
    cout << sumPrimes(2) << endl;
    cout << sumPrimes(5) << endl;
}
void test_printTwinPrimes(){
    cout << "Print primes 2 apart" << endl;
    printTwinPrimes(1, 2);//print nothing
    printTwinPrimes(2, 3);//print nothing
    printTwinPrimes(1, 9); //checks 1
    printTwinPrimes(5, 5); //start and end the same
    printTwinPrimes(5, 7); //start end prime, no primes in between
    printTwinPrimes(11, 20); //checks for prime between 9 and 23
    printTwinPrimes(83, 200); //prime to not prime
    printTwinPrimes(16, 18); //not prime to not prime
    printTwinPrimes(16, 19); //not prime to prime
    printTwinPrimes(1, 101);
    printTwinPrimes(101, 201);
    printTwinPrimes(201, 101); //start > end
}
void test_printCousinPrimes(){
    cout << "Print primes 4 apart" << endl;
    printCousinPrimes(1, 2);//print nothing, lower limit
    printCousinPrimes(2, 1);//print nothing
    printCousinPrimes(2, 3);//print nothing
    printCousinPrimes(2, 5);//print nothing
    printCousinPrimes(3, 7);// (3, 7) start and end on cousin
    printCousinPrimes(1, 9);//checks 1, print (3, 7)
    printCousinPrimes(5, 5);//start and end the same, print nothing
    printCousinPrimes(5, 7);//start end prime, no primes in between
    printCousinPrimes(5, 9);
    printCousinPrimes(11, 20);//checks for prime between 9 and 23
    printCousinPrimes(1, 25);//given (3, 7) (7, 11) (13, 17) (19, 23)
    printCousinPrimes(1, 22);//given (3, 7) (7, 11) (13, 17)
    printCousinPrimes(83, 200);//prime to not prime
    printCousinPrimes(16, 18);//not prime to not prime
    printCousinPrimes(16, 19);//not prime to prime
    printCousinPrimes(1, 101);
    printCousinPrimes(101, 201);
    printCousinPrimes(201, 101); //start > end

}
void test_printArrow(){
    cout << "Print Arrow" << endl;
    printArrow(1);
    cout << endl;
    printArrow(2);
    cout << endl;
    printArrow(3);
    cout << endl;
    
}

