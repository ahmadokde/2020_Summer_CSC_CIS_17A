/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Date:   October 3rd, 2019
 * Purpose:Step 3 in creating a Table Structure with a Record Structure
 * Go back to Step 1 and now create an array of records! like in a table
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <iostream>
using namespace std;

//User Libraries
#include "Record.h"

//Global Constants

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed here
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int nRecords=5;
    Record *rec=new Record[nRecords];
    
    //Initialize Variables
    for(int row=0;row<nRecords;row++){
        rec[row].nCol=10;
        rec[row].colData=new int[rec[row].nCol];
    }
    
    //Process inputs to outputs/map
    for(int row=0;row<nRecords;row++){
        for(int col=0;col<rec[row].nCol;col++){
            rec[row].colData[col]=rand()%90+10;//2 Digit Number
        }
    }
    
    //Display the results
    cout<<"Record Data"<<endl;
    for(int row=0;row<nRecords;row++){
        for(int col=0;col<rec[row].nCol;col++){
            cout<<rec[row].colData[col]<<" ";//2 Digit Number
        }
        cout<<endl;
    }
    cout<<endl;
    
    //Clean up memory
    for(int row=0;row<nRecords;row++){
        delete []rec[row].colData;
    }
    delete []rec;

    //Clean up and exit stage right
    return 0;
}