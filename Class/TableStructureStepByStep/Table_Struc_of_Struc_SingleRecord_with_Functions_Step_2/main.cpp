/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Date:   October 3rd, 2019
 * Purpose:Step 2 in creating a Table Structure with a Record Structure
 * From step 1, just modify to add functions fill, print, destroy
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
Record *fillRecord(int);
void printRecord(const Record *);
void destroyRecord(Record *);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed here
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare and initialize Variables
    Record *row;
    
    //Initialize Variables
    int nColumns=10;
    row=fillRecord(nColumns);
    
    //Display the results
    printRecord(row);
    
    //Clean up memory
    destroyRecord(row);

    //Clean up and exit stage right
    return 0;
}

Record *fillRecord(int nCol){
    //Dynamically allocate the 1 record
    Record *row=new Record;
    row->nCol=nCol;
    row->colData=new int[row->nCol];
    //Process inputs to outputs/map
    for(int col=0;col<row->nCol;col++){
        row->colData[col]=rand()%90+10;//2 Digit Number
    }
    return row;
}

void printRecord(const Record *row){
    cout<<"Record Data"<<endl;
    for(int col=0;col<row->nCol;col++){
        //cout<<row->colData[col]<<" ";   //Link Notation with Array Notation
        //cout<<*(row->colData+col)<<" "; //Link Notation with Pointer Notation
        cout<<*((*row).colData+col)<<" "; //Dot Notation with Pointer Notation
    }
    cout<<endl;
}

void destroyRecord(Record *row){
    delete []row->colData;
    delete row;
}