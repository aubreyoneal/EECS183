//
//  test1.cpp
//  Project4
//
//  Created by Aubrey O'Neal on 3/10/14.
//  uniquename: aubreyo
//  Copyright (c) 2014 EECS183. All rights reserved.
//  This tests the various functions for bugs.

#include <iostream>
#include "arrays.h"

using namespace std;

void test_leapYear();
void test_printArrayAsChar();
void test_stringToChar();
void test_caesarCipher();
void test_charToInt();
void test_toUpper();
void test_copyArray();
void test_erase();
void test_removeNonAlphas();
void test_putCharInRange();
void test_caesarCipher2();
void test_vigenereCipher();
void test_find();
void test_removeDuplicates();
void test_monoAlphabetCipher();
void test_remove_I_or_J();
void test_make_2D_array();
void test_find_matrix_coordinates();
void test_EECS183Cipher();

int main () {
    test_leapYear();
    
}

void test_leapYear(){
    cout << "TEST leapYear()" << endl;
    //1 2 3 4
    int arr[SIZE] = {1, 2, 3, 4};
    printArray(arr, 4);
    cout << endl;
    
    //1
    int arr2[SIZE] = {1};
    printArray(arr2, 1);
    cout << endl;
    

}









