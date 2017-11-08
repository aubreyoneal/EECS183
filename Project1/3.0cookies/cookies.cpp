//
//  main.cpp
//  3.0cookies
//
//  Created by Aubrey O'Neal on 1/18/14.
//  Copyright (c) 2014 EECS183. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[])
{
    int servingSize;
    int peopleServed;
    int totalBatches = 0;
    
    cout << "How many cookies is a serving size? ";
    cin >> servingSize;
    
    cout << "How many people do you need to serve? ";
    cin >> peopleServed;
    
    
    cout << "You need to make: " << CalculateBatches(servingSize, peopleServed, totalBatches) << pluralize(" batch" ," batches", totalBatches) << " of cookies" << endl;

}

