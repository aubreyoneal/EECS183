//************************************************************************
//  Programmer:   Aubrey O'Neal
//      uniqname: aubreyo
//  Partner:      NA
//      uniqname: NA
//  Class:        EECS 183 at U. Of Michigan
//  Date:         March 2014
//  Assignment:   Project 4
//  Description:  <Utilize arrays to encrypt and decrypt messages>
//************************************************************************

#include <iostream>
#include "arrays.h"
#include <string>

using namespace std;


void printArray(const int arr[], int size){
    for(int i = 0; i < size; ++i){
        if ((size - i - 1) > 0){
            cout << arr[i] << " ";
        }
        else {
            cout << arr[i];
        }
    }
    cout << endl;
}


void printArray(const char arr[], int size){
    for(int i = 0; i < size; ++i){
        cout << arr[i];
    }
    cout << endl;
}


void printArray(const char arr[][SIZE_PLAYFAIR], int numRows, int numCols){
    for(int i = 0; i < numRows; ++i){
        for(int j = 0; j < numCols; ++j){
            cout << arr[i][j];
        }
        cout << endl;
    }
    cout << endl;
}


void printArrayAsChar(const int arr[], int size){
    for(int i = 0; i < size; ++i){
        char ascii = arr[i];
        cout << ascii;
    }
    cout << endl;
}


void charToInt(string str, int arr[], int& size){
    size = (int)str.size();
    char individual = str.at(0);
    for (int i = 0; i < size; ++i){
        individual = str.at(i);
        arr[i] = (int)individual;
    }
}


void stringToChar(string str, char arr[], int& size){
    size = (int)str.size();
    for (int i = 0; i < size; ++i){
        arr[i] = str.at(i);
    }
}


void caesarCipher(int arr[], int size, int key){
    for (int i = 0; i < size; ++i){
        arr[i] = arr[i] + key;
    }
}


void toUpper(char arr[], int size){
    for(int i = 0; i < size; ++i){
        arr[i] = toupper(arr[i]);
    }
}


void copyArray(const char a[], int size, char b[]){
    char temp;
    for (int i = 0; i < size; ++i){
        temp = a[i];
        b[i] = temp;
    }
}


void erase(char arr[], int& size, int position, int count){
    if (position < size){
        // an alterable variable for size
        int tempSize = size;
        // holds original size for clarity
        int tempSize2 = size;
        
        // For each deleted element, run through positions that need to shift
        for(int i = 0; i < count; ++i){
            for(int j = position; j < tempSize2; ++j){
                arr[j] = arr[j + 1];
                --tempSize;
            }
        }
        //checks for illogical input and resizes
        if(position + count > size){
            size = position;
        }
        //otherwise simply resize by subtracting erased elements
        else {
            size = size - count;
        }
    }
}


void removeNonAlphas(char arr[], int& size, bool space){
    char arr2[SIZE];
    //counter for alpha index and end size
    int j = 0;
    copyArray(arr, size, arr2);
    //deletes nonAlphas, including spaces
    if (space){
        for (int i = 0; i < size; ++i){
            if(isalpha(arr2[i])){
                arr[j] = arr2[i];
                ++j;
            }
        }
    }
    //deletes nonAlphas, excluding spaces
    else {
        for (int i = 0; i < size ; ++i){
            if(isalpha(arr2[i]) || (int) arr2[i] == ' '){
                arr[j] = arr2[i];
                ++j;
            }
        }
    }
    size = j;
}


char putCharInRange(int val){
    while(val < 65){
        val += ALPHABET_SIZE;
    }
    while(val > 90){
        val -= ALPHABET_SIZE;
    }
    return val;
}


void caesarCipher(char message[], int& size, int key){
    int val = 0;
    toUpper(message, size);
    removeNonAlphas(message, size, false);
    //This loop runs through each element in message to alter it
    for (int i = 0; i < size; ++i){
        if (message[i] != ' ') {
            val = (int)message[i] + key;
            message[i] = putCharInRange(val);
        }
    }
}


void vigenereCipher(char arr[], int& size, string key, char code){
    removeNonAlphas(arr, size, false);
    toUpper(arr, size);
    int arr2[SIZE];
    //Changes arr from char to an int array
    for (int i = 0; i < size; ++i){
        arr2[i] = arr[i];
    }
    
    int keySize = (int)key.size();
    char keyArr[SIZE];
    stringToChar(key, keyArr, keySize);
    toUpper(keyArr, keySize);
    removeNonAlphas(keyArr, keySize, true);
    
    //step through the key and convert it to a number that may be added
    for (int x = 0; x < keySize; ++x){
        keyArr[x] -= 65;
    }
    //keeps track of spot in the key
    int keyIndex = 0;
    //repopulates the array with the key int added/subtracted to it
    for (int y = 0; y < size; ++y) {
        if (arr2[y] == ' ') {
            --keyIndex;
        }
        //encodes
        else if (code == 'E' || code == 'e'){
            arr2[y] = arr2[y] + keyArr[keyIndex];
        }
        //decodes
        else {
            arr2[y] = arr2[y] - keyArr[keyIndex];
        }
        ++keyIndex;
        if (keyIndex == keySize){
            //loop key back to beginning
            keyIndex = 0;
        }
    }
    for (int z = 0; z < size; ++z) {
        if (arr2[z] != ' ') {
            arr[z] = putCharInRange(arr2[z]);
        }
    }
}


int find(const char arr[], int size, char target, int position){
    for (int i = position; i < size; ++i){
		if (target == arr[i]){
			return i;
		}
	}
    return size;
}


void removeDuplicates(char arr[], int& size){
    char element;
    int deletePosition;
    
    //starting at end of array, loop through whole array for one element
    //if duplicate elements are found, delete them, then move to next element
    for (int i = size; i >= 0; --i) {
        element = arr[i];
        for (int j = size; j >= 0; --j) {
            deletePosition = find(arr, size, element, j);
            if (deletePosition > i){
                erase(arr, size, deletePosition, 1);
            }
        }
    }
}


void monoAlphabetCipher(char arr[], int& arr_size,
                        char orig_key[], int orig_key_size,  char code){
    char alpha = 'Z';
    char new_key[SIZE], alphabet[SIZE] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ "};
    int new_key_size = orig_key_size;
    
    removeNonAlphas(arr, arr_size, false);
    toUpper(arr, arr_size);
    copyArray(orig_key, new_key_size, new_key);
    toUpper(new_key, new_key_size);
    removeNonAlphas(new_key, new_key_size, false);
    
    //populate the new key with the backwards alphabet and space
    for (int i = new_key_size; i < new_key_size + ALPHABET_SIZE + 1; ++i){
        if (i >= new_key_size + ALPHABET_SIZE){
            new_key[i] = ' ';
        }
        else {
            new_key[i] = alpha;
            --alpha;
        }
    }
    
    new_key_size += ALPHABET_SIZE;
    removeDuplicates(new_key, new_key_size);
    int encrypt, decrypt;
    
    //To encrypt, find arr[i] letter in alphabet array, return position
    //Assign same position from key into the array.
    //To decrypt, find arr[i] position in the key
    //Use position in the alphabet to reassign arr[i]
    for (int j = 0; j < arr_size; ++j){
        encrypt = find(alphabet, ALPHABET_SIZE, arr[j], 0);
        decrypt = find(new_key, new_key_size, arr[j], 0);
        if (code == 'E' || code == 'e'){
            arr[j] = new_key[encrypt];
        }
        else {
            arr[j] = alphabet[decrypt];
        }
    }
}


void remove_I_or_J(char key[], int& size){
    removeDuplicates(key, size);
    int jPosition = find(key, size, 'J', 0);
    int iPosition = find(key, size, 'I', 0);
    if (jPosition < iPosition){
        erase(key, size, iPosition, 1);
    }
    else if (iPosition < jPosition){
        erase(key, size, jPosition, 1);
    }
}


void make_2D_array(char key[], int size, char key_arr[][SIZE_PLAYFAIR]){
    int count = 0;
    //Runs through the rows
    for (int i = 0; i < 5; i ++){
         //runs through the columns
        for (int j = 0; j < 5; j ++){
            key_arr[i][j] = key[count];
            ++count;
        }
    }
}


void find_matrix_coordinates(const char arr[][SIZE_PLAYFAIR], char ch,
                             int& x, int& y){
    //will act as whatever char isn't inputed
    char ch2;
    ch = toupper(ch);
    //Runs through the rows
    for (int i = 0; i < 5; i ++){
        //runs through the columns
        for (int j = 0; j < 5; j ++){
            if (ch == 'I'){
                ch2 = 'J';
            }
            else if (ch == 'J'){
                ch2 = 'I';
            }
            else {
                ch2 = '!';
            }
            if (ch == arr[i][j] || ch2 == arr[i][j]){
                x = i;
                y = j;
            } 
        }
    }
}

void EECS183Cipher(char message[], int& size, const char key[], int key_size){
    //prepare a key that follows all guidlines
    char newKey[SIZE];
    copyArray(key, key_size, newKey);
    int new_key_size = key_size;
    toUpper(newKey, new_key_size);
    removeNonAlphas(newKey, new_key_size, true);
    char alpha = 'A';
    
    //Adds alphabet to key and updates size
    for (int i = new_key_size; i < key_size + ALPHABET_SIZE; ++i){
        newKey[i] = alpha;
        ++alpha;
        ++new_key_size;
    }
    remove_I_or_J(newKey, new_key_size);
    removeDuplicates(newKey, new_key_size);
    char squareKey[SIZE_PLAYFAIR][SIZE_PLAYFAIR];
    make_2D_array(newKey, key_size, squareKey);
    
    //prepare a message that follows all guidelines
    char newMessage[SIZE];
    copyArray(message, size, newMessage);
    toUpper(newMessage, size);
    removeNonAlphas(newMessage, size, true);
    
    //look up a pair's coordinates in 2-dim array
    int end = size;
    //add will be used for the second element in the pair.
    const int add = 1;
    int x1, x2, y1, y2;
    
    //steps through the message array in pairs
    for (int i = 0; i < size - 1; i += 2){
        find_matrix_coordinates(squareKey, newMessage[i], x1, y1);
        find_matrix_coordinates(squareKey, newMessage[i + add], x2, y2);
        //check if the size of the message is odd (and has no last pair)
        if (i == end && end % 2 != 0){
            newMessage[i] = newMessage[i];
        }
        //check if pair is in the same row
        else if (x1 == x2 || y1 == y2){
                char temp = newMessage[i];
                newMessage[i] = newMessage[i + add];
                newMessage[i + 1] = temp;
            }
        //encode message using new coordinates
        else {
                newMessage[i] = squareKey[x1][y2];
                newMessage[i + add] = squareKey[x2][y1];
            }
        }
    copyArray(newMessage, size, message);
}


