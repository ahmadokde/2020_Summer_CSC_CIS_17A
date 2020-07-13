/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Date:   October 3rd, 2019
 * Purpose:Step 4 in creating a Table Structure with a Record Structure
 * Just like in Step 2 create functions for the array of Records! from Step 3
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
Record *fillRecords(int,int);
void printRecords(const Record *,int);
void destroyRecords(Record *,int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed here
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int nColumns=10;
    int nRecords=5;
    Record *rec;
    
    //Initialize Variables
    rec=fillRecords(nRecords,nColumns);
    
    //Display the results
    printRecords(rec,nRecords);
    
    //Clean up memory
    destroyRecords(rec,nRecords);

    //Clean up and exit stage right
    return 0;
}

Record *fillRecords(int nRecords,int nColumns){
    Record *rec=new Record[nRecords];
    
    //Initialize Variables
    for(int row=0;row<nRecords;row++){
        rec[row].nCol=nColumns;
        rec[row].colData=new int[rec[row].nCol];
    }
    
    //Process inputs to outputs/map
    for(int row=0;row<nRecords;row++){
        for(int col=0;col<rec[row].nCol;col++){
            rec[row].colData[col]=rand()%90+10;//2 Digit Number
        }
    }
    return rec;
}

void printRecords(const Record *rec,int nRecords){
    //Display the results
    cout<<"Record Data"<<endl;
    for(int row=0;row<nRecords;row++){
        for(int col=0;col<rec[row].nCol;col++){
            cout<<rec[row].colData[col]<<" ";//2 Digit Number
        }
        cout<<endl;
    }
    cout<<endl;
}

void destroyRecords(Record *rec,int nRecords){
    //Clean up memory
    for(int row=0;row<nRecords;row++){
        delete []rec[row].colData;
    }
    delete []rec;
}