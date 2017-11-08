#ifndef __arrays_h
#define __arrays_h

#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
using namespace std;


const int SIZE = 200;            // max size of all messages
const int SIZE_PLAYFAIR = 5;    // size of arrays in PlayFair Cipher
const int ALPHABET_SIZE = 26;

// Note:  All of the "printArray" functions will be very similar.
//        Don't worry about "duplicated code" in these functions
//        We expect it



// Requires: The size of array arr is size && size > 0 && size <= SIZE
// Effects: Prints the elements of the array with one space between
//          Prints an endl at the end
//
// Example:  If array arr contains {1,2,3,4} then the following code:
//
//         printArray(arr, 4);
//         cout << "Hello";
//
//         will print
//
//         1 2 3 4
//         Hello
//
// Note: there must be no space after the 4 in the above example
void printArray(const int arr[], int size);




// Requires: The size of array arr is size && size > 0 && size <= SIZE
// Effects: Prints the elements of the array with no spaces between
//          Prints an endl at the end
//
// Example:  If array arr contains {'A','B','C','D'} then the following code:
//
//         printArray(arr, 4);
//         cout << "Hello";
//
//         will print
//
//         ABCD
//         Hello
//
// Note: there must be no space after the 'D' in the above example
void printArray(const char arr[], int size);



// Requires: The size of array arr is numRows x numCols
//           and 0 < numRows && numRows <= SIZE_PLAYFAIR
//           and 0 < numCols && numCols <= SIZE_PLAYFAIR
//
//           i.e., Even though array arr is allocated with SIZE columns,
//                 only the first numCols columns are being used
//
// Effects:  Prints the elements of the array
//             one row per line
//           Prints an endl at the end
//
// Example:  If array arr contains {{'A','B'},{'C','D'}} then the following code:
//
//                 printArray(arr, 2, 2);
//                 cout << "Hello";
//
//                 will print:
//
//                 AB
//                 CD
//                 Hello
//
// Note: there must be no spaces after 'B' and 'D' above
void printArray(const char arr[][SIZE_PLAYFAIR], int numRows, int numCols);



// Requires: The size of array arr is size && size > 0 && size <= SIZE
//           All values within arr must be >= 32 and < 127
//           otherwise it will print as an escape character
// Effects: Prints the elements of the array as the ASCII character they
//          represent
//          Prints an endl at the end
//
// Example:  If array arr contains {65,66,67,68} then the following code:
//
//         printArrayAsChar(arr, 4);
//         cout << "Hello";
//
//         will print
//
//         ABCD
//         Hello
//
// Note: there must be no space after the D in the above example
//
//        int arr[] = {120,121,122,123};
//        printArrayAsChar(arr, 4);
//             prints: xyz{
//        int arr1[] = {120, 130, 135, 140};
//        printArrayAsChar(arr1, 4);
//             prints: x\202\207\214
//             because 130, 135, and 140 are ouside range of char's
//
void printArrayAsChar(const int arr[], int size);



// Rquires:   The size of array arr is size && size >= 0 &&
//                size <= SIZE
// Modifies:  arr and size
// Effects:   Takes characters in str and stores their ASCII equivalent
//              in array arr in the corresponding locations
//            It also updates size accordingly to the length of str
//
// Example:   The following code:
//
//            int arr[SIZE];
//            int size;
//            charToInt("Enjoy!", arr, size);
//            printArray(arr, size);
//            cout << "Size is: " << size << endl;
//
//            will print:
//            69 110 106 111 121 33
//            Size is: 6
//
// Note: this function will make testing some of the following functions easier
void charToInt(string str, int arr[], int& size);



// Rquires:   The size of array arr is size && size >= 0 &&
//                size <= SIZE
// Modifies:  arr and size
// Effects:   Takes characters in str and stores the character
//              in array arr in the corresponding locations
//            It also updates size accordingly to the length of str
//
// Example:   The following code:
//
//            char arr[SIZE];
//            int size;
//            string str = "Enjoy!";
//            stringToChar(str, arr, size);
//            printArray(arr, size);
//            cout << "Size is: " << size << endl;
//            str = "Do this again";
//            stringToChar(str, arr, size);
//            printArray(arr, size);
//            will print:
//            Enjoy!
//            Size is: 6
//            Do this again
//
// Note: this function will make testing some of following functions easier
void stringToChar(string str, char arr[], int& size);



// Requires: The size of array arr is size && size > 0 && size <= SIZE
// Modifies: arr
// Effects:  Encrypts and decrypts arr using the key
//           For more details on Caesar cipher see the spec
void caesarCipher(int arr[], int size, int key);



// Requires: The size of array arr is size && size > 0 && size <= SIZE
// Modifies: arr
// Effects:  Will uppercase all letters within arr
//           It will not alter any non-alpha characters
void toUpper(char arr[], int size);



// Requires:  a and b are the same SIZE
//            The size of array arr is size && size > 0 && size <= SIZE
// Modifies:  array b
// Effects:   copies all elements from a to b
void copyArray(const char a[], int size, char b[]);



// Requires:  The size of array arr is size && size > 0 && size <= SIZE
// Modifies:  arr and size
// Effects:   Starting with the element at position, erase removes
//            count elements from arr
// Example:   If array arr contains {'A','B','C','D'} then the following code:
//
//          int size = 4;
//          erase(arr, size, 2, 1);
//          printArray(arr, size);
//
//          will print:   A B D
// erase removed 1 element at index 2
//
//          if arr contains {'A','B','C','D','E','F'} with size being 6
//          erase(arr, size, 3, 4);
//          printArray(arr, size);
//
//          will print: A B C
// Note: trying to erase more elements than are possible is not an error
//          as in the above example
void erase(char arr[], int& size, int position, int count);




// Requires:  The size of array arr is size && size > 0 && size <= SIZE
// Modifies:  arr, size
// Effects: Removes all non-alpha characters from arr
//          if space is true, it also removes spaces from arr
//          if space is false, it leaves spaces in arr
// Example:     char arr1[] = "Hello from 183 Staff";
//              removeNonAlphas(arr, size, true);
//              printArray(arr1, size);
//              // will print: HellofromStaff
// Example:     char arr2[] = "Hello from 183 Staff";
//              removeNonAlphas(arr, size, false);
//              printArray(arr2, size);
//              // will print: Hello from  Staff
// Calls:  copyArray
//         erase
void removeNonAlphas(char arr[], int& size, bool space);



// Effects: If val is outside of the range 65 - 90 inclusive,
//          val will be shifted by ALPHABET_SIZE until it is in the
//          range of 65 - 90
//          Returns the corresponding character in range of 'A' - 'Z'
// Example:  cout << putCharInRange(68); // will print 'D'
//           cout << putCharInRange(42); // will print 'D'
//           cout << putCharInRange(16); // will print 'D'
//           cout << putCharInRange(94); // will print 'D'
//           cout << putCharInRange(120); // will print 'D'
//           cout << putCharInRange('D'); // will print 'D'
char putCharInRange(int val);



// Requires:  The size of array arr is size && size > 0 && size <= SIZE
// Effects:  Encrypts and decrypts arr using the key
//           For more details on Caesar cipher see the spec

// Note: you will want to cast the character to an int BEFORE you add the key
//           int val = int(message[i]) + key;
//       If you don't, you may easily overflow max char

// Calls:  toUpper
//         removeNonAlphas
//         putCharInRange
void caesarCipher(char message[], int& size, int key);



// Requires:  The size of array arr is size && size > 0 && size <= SIZE
//           If code is 'E' or 'e', it will encrypt
//           Otherwise, it will decrypt
// Modifies:  arr
// Effects:  Encrypts and decrypts arr using the key
//           For more details on Vinenere cipher see the spec
void vigenereCipher(char arr[], int& size, string key, char code);



// Requires:  The size of array arr is size && size > 0 && size <= SIZE
// Effects:   Tries to find target in the array arr starting at index position
//            If target is found, returns the index it was found at
//            Otherwise, returns size
int find(const char arr[], int size, char target, int position);



// Requires:  The size of array arr is size && size > 0 && size <= SIZE
// Modifies:  arr and size
// Effects:   Removes all duplicates within arr
// Example:     char arr[] = {'A','B','C','B','D','E','C'};
//              int size = 7;
//              removeDuplicates(arr, size);
//              printArray(arr, size); // will print: ABCDE
//              cout << "Size is: " << size << endl; // prints:  5
// Calls:   find
//          erase
void removeDuplicates(char arr[], int& size);


// Requires: The size of array arr is arr_size and arr_size > 0 && arr_size <= SIZE
//           The size of array orig_key is orig_key_size and
//                orig_key_size > 0 && orig_key_size <= SIZE
//           If code is 'E' or 'e', it will encrypt
//              otherwise it will decrypt
// Modifies: arr and arr_size
// Effects:  Encrypts or decrypts arr and reassigns back into arr
//           For details on this cipher, see the specifications
// Calls:  toUpper
//         removeDuplicates
//         removeNonAlphas -- leaving spaces
//         find
void monoAlphabetCipher(char arr[], int& arr_size,
                        char orig_key[], int orig_key_size,  char code);



// Requires: The size of array key is size && size > 0 && size <= SIZE
//           duplicates have been removed
//           key holds capital letters only
// Effects:  Removes either I or J from key
//           The one that occurs first in key is kept
//           The other is removed
// Example:  string str = "THIS IS JUNK";
//           int size;
//           char key[SIZE];
//           stringToChar(str, key, size);
//           removeDuplicates(key, size);
//           printArray(key, size);  // prints:  THIS JUNK"
//           remove_I_or_J(key, size);
//           printArray(key, size);  // prints:  THIS UNK
//
// Example 2: str = "JUNK IS GREAT";
//           stringToChar(str, key, size);
//           removeDuplicates(key, size);
//           removeNonAlphas(key, size, true);
//           remove_I_or_J(key, size);
//           printArray(key, size);     // prints:  JUNKSGREAT
void remove_I_or_J(char key[], int& size);



// Requires: the size of key is 25
//           key_arr is sized SIZE_PLAYFAIR x SIZE_PLAYFAIR
// Modifies: key_arr
// Effects:  Assigns the values in key into key_arr one row at a time
// Example:  If key = "PLAYFIRBCDEGHKMNOQSTUVWXZ"
//           key_arr will be    P L A Y F
//                              I R B C D
//                              E G H K M
//                              N O Q S T
//                              U V W X Z
void make_2D_array(char key[], int size, char key_arr[][SIZE_PLAYFAIR]);



// Requires: key_arr is sized SIZE_PLAYFAIR x SIZE_PLAYFAIR
//           Elements of arr[][] are uppercase letters only
//           All letters are unique
// Modifies: x and y
// Effects:  finds char ch in array arr.  When it finds it,
//           x is the index of the row where it was found
//           y is the index of the col where it was found
// Note:     I and J are "together" in the same array location
//           If arr is:         P L A Y F
//                              I R B C D
//                              E G H K M
//                              N O Q S T
//                              U V W X Z
//  and if ch is 'J', then on return x will be 1 and y will be 0
void find_matrix_coordinates(const char arr[][SIZE_PLAYFAIR], char ch,
                             int& x, int& y);



// Requires:  The size of array message is size && size > 0 && size <= SIZE
// Requires:  The size of array key is key_size && key_size > 0 && key_size <= SIZE
// Modifies: message, size
// Effects:  Encrypts and decrypts arr using the key
//           For more details on EECS183 cipher see the spec
//Calls:
//       removeNonAlpha
//       removeDuplicates(key)
//       remove_I_or_J(key)
//       make_2D_array
//       find_matrix_coordinates
void EECS183Cipher(char message[], int& size, const char key[], int key_size);






#endif /* defined(__arrays_h) */
