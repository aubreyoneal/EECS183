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

void test_printArray();
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
    test_printArray();
    test_printArrayAsChar();
    test_charToInt();
    test_stringToChar();
    test_caesarCipher();
    test_toUpper();
    test_copyArray();
    test_erase();
    test_removeNonAlphas();
    test_putCharInRange();
    test_caesarCipher2();
    test_vigenereCipher();
    test_find();
    test_removeDuplicates();
    test_monoAlphabetCipher();
    test_remove_I_or_J();
    test_make_2D_array();
    test_find_matrix_coordinates();
    test_EECS183Cipher();
    
}

void test_printArray(){
    cout << "TEST printArray Int" << endl;
    //1 2 3 4
    int arr[SIZE] = {1, 2, 3, 4};
    printArray(arr, 4);
    cout << endl;
    
    //1
    int arr2[SIZE] = {1};
    printArray(arr2, 1);
    cout << endl;
    
    //ABCD
    cout << "TEST printArray Char" << endl;
    char arr3[SIZE] = {'A','B','C','D'};
    printArray(arr3, 4);
    cout << endl;
    
    //1
    char arr4[SIZE] = {'1'};
    printArray(arr4, 1);
    cout << endl;
    
    //AB
    //CD
    cout << "TEST 2 Dimentional Array" << endl;
    char a[SIZE][SIZE_PLAYFAIR] = {{'A','B'},{'C','D'}};
    printArray(a, 2, 2);
    
    //123
    //456
    //789
    char b[SIZE][SIZE_PLAYFAIR] =
    {{'1', '2', '3'},{'4', '5', '6'}, {'7', '8', '9'}};
    printArray(b, 3, 3);
    
    //abcde
    //~!@#$
    char c[SIZE][SIZE_PLAYFAIR] =
    {{'a', 'b', 'c', 'd', 'e'},{'~', '!', '@', '#', '$'}};
    printArray(c, 2, 5);
    
    //1
    char d[SIZE][SIZE_PLAYFAIR] = {"1"};
    printArray(d, 1, 1);
}

void test_printArrayAsChar(){
    cout << "TEST printArrayAsChar" << endl;
    
    //ABCD
    int arr[SIZE] = {65,66,67,68};
    printArrayAsChar(arr, 4);
    cout << endl;
    
    //xyz{
    int arr2[SIZE] = {120,121,122,123};
    printArrayAsChar(arr2, 4);
    cout << endl;
    
    //~
    int arr3[SIZE] = {32, 126};
    printArrayAsChar(arr3, 2);
    cout << endl;
    
}

void test_charToInt(){
    cout << "TEST charToInt" << endl;
   
    //69 110 106 111 121 33
    //Size is: 6
    int arr[SIZE];
    int size;
    charToInt("Enjoy!", arr, size);
    printArray(arr, size);
    cout << "Size is: " << size << endl << endl;
    
    //49 50 51 52
    //Size is: 4
    int arr2[SIZE];
    charToInt("1234", arr2, size);
    printArray(arr2, size);
    cout << "Size is: " << size << endl << endl;
    
    //72 69 76 76 79
    //Size is: 5
    int arr3[SIZE];
    charToInt("HELLO", arr3, size);
    printArray(arr3, size);
    cout << "Size is: " << size << endl << endl;
    
    //97 98 99 49 50 51 33 64 35 36 37 94
    //Size is: 12
    int arr4[SIZE];
    charToInt("abc123!@#$%^", arr4, size);
    printArray(arr4, size);
    cout << "Size is: " << size << endl << endl;
}

void test_stringToChar(){
    cout << "TEST stringToChar" << endl;
    
    //Enjoy!
    //Size is: 6
    char arr[SIZE];
    int size;
    string str = "Enjoy!";
    stringToChar(str, arr, size);
    printArray(arr, size);
    cout << "Size is: " << size << endl << endl;
    
    //Do this again
    //Size is: 13
    str = "Do this again";
    stringToChar(str, arr, size);
    printArray(arr, size);
    cout << "Size is: " << size << endl << endl;
    
    //1234
    //Size is: 4
    str = "1234";
    stringToChar(str, arr, size);
    printArray(arr, size);
    cout << "Size is: " << size << endl << endl;
    
}

void test_caesarCipher(){
    cout << "TEST caesarCipher" << endl;
    
    //77 106 113 113 116 38 (to see the shift numerically)
    int	arr[SIZE] =	{72, 101, 108, 108, 111, 33};
    int	size = 6;
    caesarCipher(arr, size, 5);
    printArray(arr,	size);
    cout << endl;
    
    //Mjqqt& (Encrypting)
    string str = "Hello!";
    int	arr2[SIZE];
    size = (int)str.size();
    charToInt(str, arr2, size);
    caesarCipher(arr2, size, 5);
    printArrayAsChar(arr2, size);
    cout << endl;
    
    //Hello! (Decrypting)
    caesarCipher(arr2, size, -5);
    printArrayAsChar(arr2, size);
    cout << endl;
}

void test_toUpper(){
    cout << "TEST toUpper" << endl;
    
    //ABCD
    char arr[SIZE] = {'a','b','c','d'};
    toUpper(arr, 4);
    printArray(arr, 4);
    cout << endl;
    
    //A1C! Testing that nonalphas aren't changed
    char arr2[SIZE] = {"A1C!"};
    toUpper(arr2, 4);
    printArray(arr2, 4);
    cout << endl;
    
    //A SPOONFUL OF SUGAR HELPS THE MEDICINE GO DOWN!234
    string str = "a spoonful of sugar helps the medicine go down!234";
    int size = (int)str.size();
    char arr3[SIZE] = {"a spoonful of sugar helps the medicine go down!234"};
    toUpper(arr3, size);
    printArray(arr3, size);
    cout << endl;
    
}

void test_copyArray(){
    cout << "TEST copyArray" << endl;
    
    //abcd
    //copy: abcd
    char arr[SIZE] = {'a','b','c','d'};
    char arr1[4];
    copyArray(arr, 4, arr1);
    printArray(arr, 4);
    cout << "copy: ";
    printArray(arr1, 4);
    cout << endl;
    
    //Debugging just makes my life hard... !@#52!
    //copy: Debugging just makes my life hard... !@#52!
    string str = "Debugging just makes my life hard... !@#52!";
    char arr2[SIZE] = {"Debugging just makes my life hard... !@#52!"};
    int size = (int)str.size();
    char arr3[SIZE];
    copyArray(arr2, size, arr3);
    printArray(arr2, size);
    cout << "copy: ";
    printArray(arr3, size);
    cout << endl;
    
}

void test_erase(){
    cout << "TEST erase" << endl;
    
    //ABD
    int size = 4;
    char arr[SIZE] = {'A','B','C','D'};
    erase(arr, size, 2, 1);
    printArray(arr, size);
    cout << endl;
    
    //ABC
    size = 6;
    char arr2[SIZE] = {'A','B','C','D','E','F'};
    erase(arr2, size, 3, 4);
    printArray(arr2, size);
    cout << endl;
    
    //Hello
    size = 6;
    char arr3[SIZE] = {"Hello!"};
    erase(arr3, size, 5, 5);
    printArray(arr3, size);
    cout << endl;
    
    //ABCGHI
    size = 9;
    char arr5[SIZE] = {'A','B','C','D','E','F', 'G', 'H', 'I'};
    erase(arr5, size, 3, 3);
    printArray(arr5, size);
    cout << endl;
    
    
    //The will to win, the succeed, the urge to reach your full potential...
    //these are the keys that will unlock the door to personal excellence.
    string more1 = "The will to win, the desire to succeed, the urge to reach ";
    string more2 = "your full potential... these are the keys that will unlock";
    string more3 = " the door to personal excellence.";
    size = (int)more1.size() + (int)more2.size() + (int)more3.size();
    char arr4[SIZE];
    stringToChar(more1 + more2 + more3, arr4, size);
    erase(arr4, size, 20, 10);
    printArray(arr4, size);
    cout << endl;
    
    //A
    size = 1;
    char arr6[SIZE] = {"ABCD"};
    erase(arr6, size, 3, 1);
    printArray(arr6, size);
    cout << endl;
    
    //F
    size = 6;
    char arr7[SIZE] = {"ABCDEF"};
    erase(arr7, size, 0, 5);
    printArray(arr7, size);
    cout << endl;
}

void test_removeNonAlphas(){
    cout << "TEST removeNonAlphas" << endl;
    
    //HI
    string str = "H I2!";
    char arr[SIZE] = {"H I2!"};
    int size = (int)str.size();
    removeNonAlphas(arr, size, true);
    printArray(arr, size);
    cout << endl;
    
    //Hellofrom
    str = "Hello from 183!";
    size = (int)str.size();
    char arr2[SIZE] = {"Hello from 183!"};
    removeNonAlphas(arr2, size, true);
    printArray(arr2, size);
    cout << endl;
    
    // go jump in a hole
    str = "183 go jump in a hole!";
    size = (int)str.size();
    char arr3[SIZE] = {"183 go jump in a hole!"};
    removeNonAlphas(arr3, size, false);
    printArray(arr3, size);
    cout << endl;
    
    //II
    char arr4[SIZE] = {'I', '\n', '1', 'I'};
    size = 4;
    removeNonAlphas(arr4, size, false);
    printArray(arr4, size);
    cout << endl;
    

}

void test_putCharInRange(){
    cout << "TEST putCharInRange" << endl;
    cout << putCharInRange(68); // will print 'D'
    cout << putCharInRange(42); // will print 'D'
    cout << putCharInRange(16); // will print 'D'
    cout << putCharInRange(94); // will print 'D'
    cout << putCharInRange(120); // will print 'D'
    cout << endl;
    cout << putCharInRange('A'); // will print 'A'
    cout << putCharInRange(65); // will print 'A'
    cout << putCharInRange(39); // will print 'A'
    cout << putCharInRange(13); // will print 'A'
    cout << endl << endl;
}

void test_caesarCipher2(){
    cout << "TEST caesarCipher2" << endl;
    
    //Hello from the 183 staff!
    //MJQQT KWTR YMJ  XYFKK
    //HELLO FROM THE  STAFF
    string str = "Hello from the 183 staff!";
    int	size = (int)str.size();
    char arr2[SIZE];
    stringToChar(str, arr2, size);
    printArray(arr2, size);
    caesarCipher(arr2, size, 5);
    printArray(arr2, size);
    caesarCipher(arr2, size, -5);
    printArray(arr2, size);
    cout << endl;
    
    //@ 1:00 Meet me at the Big House
    //RJJY RJ FY YMJ GNL MTZXJ
    //MEET ME AT THE BIG HOUSE
    str = "@ 1:00 Meet me at the Big House";
    size = (int)str.size();
    stringToChar(str, arr2, size);
    printArray(arr2, size);
    caesarCipher(arr2, size, 5);
    printArray(arr2, size);
    caesarCipher(arr2, size, -5);
    printArray(arr2, size);
    cout << endl;
    
}

void test_vigenereCipher(){
    //HELLO FROM EECS STAFF
    //HGZCB FTCD REEG JGAHT
    //HELLO FROM EECS STAFF
    cout << "TEST vigenereCipher" << endl;
    string str = "HELLO FROM EECS STAFF";
    string key = "ACORN";
    char code = 'E';
    char code2 = 'D';
    char arr2[SIZE];
    int	size = (int)str.size();
    stringToChar(str, arr2, size);
    printArray(arr2, size);
    vigenereCipher(arr2, size, key, code);
    printArray(arr2, size);
    char arr[SIZE];
    str = "HGZCB FTCD REEG JGAHT";
    stringToChar(str, arr, size);
    vigenereCipher(arr, size, key, code2);
    printArray(arr, size);
    cout << endl;
    
    //HELLO FROM EECS Staff
    //HGZCB FTCD REEG JGAHT
    //HELLO FROM EECS STAFF
    str = "HELLO FROM EECS Staff";
    string key2 = "Acorn";
    char arr3[SIZE];
    size = (int)str.size();
    stringToChar(str, arr3, size);
    printArray(arr3, size);
    vigenereCipher(arr3, size, key2, code);
    printArray(arr3, size);
    char arr4[SIZE];
    str = "HGZCB FTCD REEG JGAHT";
    stringToChar(str, arr4, size);
    vigenereCipher(arr4, size, key2, code2);
    printArray(arr4, size);
    cout << endl;
    
    //Hello FROM EECS 183 STAFF
    //Hope you are doing GREAT!!! now
    //HGZCB FTCD REEG  JGAHT YBPG MFH ATS UBIPU XEECH EBW
    //HELLO FROM EECS  STAFF HOPE YOU ARE DOING GREAT NOW
    str = "Hello FROM EECS 183 STAFF \nHope you are doing GREAT!!! now";
    char arr5[SIZE];
    size = (int)str.size();
    stringToChar(str, arr5, size);
    printArray(arr5, size);
    vigenereCipher(arr5, size, key, code);
    printArray(arr5, size);
    char arr6[SIZE];
    str = "HGZCB FTCD REEG  JGAHT YBPG MFH ATS UBIPU XEECH EBW";
    stringToChar(str, arr6, size);
    vigenereCipher(arr6, size, key, code2);
    printArray(arr6, size);
    cout << endl;
    
}

void test_find(){
    //1
    cout << "TEST find" << endl;
    char arr[SIZE] = {"A2ubrey"};
    int size = 7;
    cout << find(arr, size, '2', 0) << endl;
    cout << endl;
}

void test_removeDuplicates(){
    cout << "TEST removeDuplicates" << endl;
    
    //Aubrey
    char arr[SIZE] = {"AAAAAAAAAAAAAAubbrey"};
    int size = 20;
    removeDuplicates(arr, size);
    printArray(arr, size);
    cout << endl;
    
    //Aubrey
    char arr2[SIZE] = {"Aubreeyy"};
    size = 7;
    removeDuplicates(arr2, size);
    printArray(arr2, size);
    cout << endl;
}

void test_monoAlphabetCipher(){
    cout << "TEST monoAlphabetCipher" << endl;
    
    char code = 'E';
    char code2 = 'D';
    
    //HELLO FROM EECS STAFF
    //XNTTP ZKPS NNOJ JIAZZ
    //HELLO FROM EECS STAFF
    string key = "ACORN";
    int orig_keysize = (int)key.size();
    string str = "HELLO FROM EECS STAFF";
    cout << str << endl;
    int arrsize = (int)str.size();
    char arr3[SIZE] = {"HELLO FROM EECS STAFF"};
    char orig_key1[SIZE] = {"ACORN"};
    monoAlphabetCipher(arr3, arrsize, orig_key1, orig_keysize, code);
    printArray(arr3, arrsize);
    cout << endl;
    char arr4[SIZE] = {"XNTTP ZKPS NNOJ JIAZZ"};
    monoAlphabetCipher(arr4, arrsize, orig_key1, orig_keysize, code2);
    printArray(arr4, arrsize);
    cout << endl;
    
    //Hi FROM EECS 183 STAFF
    //Hope you are doing GREAT!!! now
    //XW ZKPS NNOJ  JIAZZ XPMN DPH RPWQY YKNAI QPF
    //HI FROM EECS  STAFF HOPE YOU DOING GREAT NOW
    key = "AcOrN";
    orig_keysize = (int)key.size();
    str = "Hi FROM EECS 183 STAFF \nHope you are doing GREAT!!! now";
    cout << str << endl;
    arrsize = (int)str.size();
    char arr5[SIZE] = {"Hi FROM EECS 183 STAFF \nHope you doing GREAT!!! now"};
    char orig_key2[SIZE] = {"AcOrN"};
    monoAlphabetCipher(arr5, arrsize, orig_key2, orig_keysize, code);
    printArray(arr5, arrsize);
    cout << endl;
    char arr6[SIZE] = {"XW ZKPS NNOJ  JIAZZ XPMN DPH RPWQY YKNAI QPF"};
    monoAlphabetCipher(arr6, arrsize, orig_key2, orig_keysize, code2);
    printArray(arr6, arrsize);
    cout << endl;
    
    //HELLO FROM EECS STAFF
    //XNTTP ZKPS NNOJ JIAZZ
    //HELLO FROM EECS STAFF
    key = "A-CORN42";
    orig_keysize = (int)key.size();
    str = "HELLO FROM EECS STAFF";
    cout << str << endl;
    char arr7[SIZE] = {"HELLO FROM EECS STAFF"};
    char orig_key3[SIZE] = {"A-CORN42"};
    monoAlphabetCipher(arr7, arrsize, orig_key3, orig_keysize, code);
    printArray(arr7, arrsize);
    cout << endl;
    char arr8[SIZE] = {"XNTTP ZKPS NNOJ JIAZZ"};
    monoAlphabetCipher(arr8, arrsize, orig_key3, orig_keysize, code2);
    printArray(arr8, arrsize);
    cout << endl;
    
    //Hello from EECS 183 Staff
    //WHCCXBRQXZBHHAOBBONFRR
    //HELLO FROM EECS  STAFF
    key = "FEATHER WITH SPACES";
    orig_keysize = (int)key.size();
    str = "Hello from EECS 183 Staff";
    cout << str << endl;
    arrsize = (int)str.size();
    char arr[SIZE] = {"Hello from EECS 183 Staff"};
    char orig_key[SIZE] = {"FEATHER WITH SPACES"};
    monoAlphabetCipher(arr, arrsize, orig_key, orig_keysize, code);
    printArray(arr, arrsize);
    cout << endl;
    char arr2[SIZE] = {"WHCCXBRQXZBHHAOBBONFRR"};
    monoAlphabetCipher(arr2, arrsize, orig_key, orig_keysize, code2);
    printArray(arr2, arrsize);
    cout << endl;
}

void test_remove_I_or_J(){
    cout << "TEST remove_I_or_J" << endl;
    string str = "THIS IS JUNK";
    int size = (int)str.size();
    char key[SIZE];
    stringToChar(str, key, size);
    removeDuplicates(key, size);
    printArray(key, size);  // prints:  THIS JUNK"
    remove_I_or_J(key, size);
    printArray(key, size);  // prints:  THIS UNK
    cout << endl;
    
    str = "JUNK IS GREAT";
    stringToChar(str, key, size);
    removeDuplicates(key, size);
    removeNonAlphas(key, size, true);
    remove_I_or_J(key, size);
    printArray(key, size);     // prints:  JUNKSGREAT
    cout << endl;
}

void test_make_2D_array(){
    cout << "TEST make_2D_array" << endl;
    
    //PLAYF
    //IRBCD
    //EGHKM
    //NOQST
    //UVWXZ
    int size = 25;
    char key[SIZE] = {"PLAYFIRBCDEGHKMNOQSTUVWXZ"};
    char key_arr[SIZE_PLAYFAIR][SIZE_PLAYFAIR];
    make_2D_array(key, size, key_arr);
    printArray(key_arr, SIZE_PLAYFAIR, SIZE_PLAYFAIR);
    cout << endl;
}

void test_find_matrix_coordinates(){
    cout << "find_matrix_coordinates" << endl;
    
    int size = 25;
    char key[SIZE] = {"ISNTGRADEWLFUBCHKMOPQVXYZ"};
    char key_arr[SIZE_PLAYFAIR][SIZE_PLAYFAIR];
    make_2D_array(key, size, key_arr);
    printArray(key_arr, SIZE_PLAYFAIR, SIZE_PLAYFAIR);
    cout << endl;
    
    //G: 0 4
    //F: 2 1
    //I: 0 0
    //W: 1 4
    //f: 2 1
    //J: 0 0
    //j: 0 0
    char test[SIZE] = {"GFIWfJj"};
    int x, y;
    for (int i = 0; i < 7; ++i){
    find_matrix_coordinates(key_arr, test[i], x, y);
    cout << test[i] << ": " << x << ' ' << y << endl;
    }
    cout << endl;
}
void test_EECS183Cipher(){
    cout << "EECS183Cipher" << endl << endl;
    
    //EHLLURORNHCES
    string str = "Hello from 183 EECS";
    string keystr = "CIPHER";
    int size = (int)str.size();
    int keysize2 = (int)keystr.size();
    char message2[SIZE] = {"Hello from 183 EECS"};
    const char key2[SIZE] = {"CIPHER"};
    EECS183Cipher(message2, size, key2, keysize2);
    printArray(message2, size);
    
    //GDDOGDRQPRBEGICPPFDOUGGIRP
    str = "MEET ME AT THE BIG HOUSE TONIGHT";
    keystr = "c h1arles";
    size = (int)str.size();
    int keysize = (int)keystr.size();
    char message[SIZE] = {"Meet Me At The Big House Tonight"};
    const char key[SIZE] = {"CHARLES"};
    EECS183Cipher(message, size, key, keysize);
    printArray(message, size);
    cout << endl;
    
    //SITNASHUNAIDTMSAUATBTASITNASRXBNMHTMSAUETP
    str = "ISNTITGRANDISNTITGREATISNTITSWELLISNTITFUN";
    keystr = "chicago";
    size = (int)str.size();
    int keysize3 = (int)keystr.size();
    char message3[SIZE] = {"ISNTITGRANDISNTITGREATISNTITSWELLISNTITFUN"};
    const char key3[SIZE] = {"chiacgo"};
    EECS183Cipher(message3, size, key3, keysize3);
    printArray(message3, size);
    cout << endl;
}









