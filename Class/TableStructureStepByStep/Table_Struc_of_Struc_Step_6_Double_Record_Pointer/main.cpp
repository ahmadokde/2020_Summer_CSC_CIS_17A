/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Date:   October 3rd, 2019
 * Purpose:Step 6 in creating a Table Structure with a Record Structure
 * Simple modification.  Instead of using an array of Records, use an array
 * of pointers to each individual record.  This will be useful when we get
 * to Classes, where the constructor is how we build each record.
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <iostream>
using namespace std;

//User Libraries
#include "Table.h"

//Global Constants

//Function Prototypes
Table *fillTable(int,int);
void printTable(const Table *);
void destroyTable(Table *);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed here
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int nFields=10;
    int nRecords=5;
    Table *table;
    
    //Initialize Variables
    table=fillTable(nRecords,nFields);
    
    //Display the results
    printTable(table);
    
    //Clean up memory
    destroyTable(table);

    //Clean up and exit stage right
    return 0;
}

Table *fillTable(int nRecords,int nColumns){
    Table *table=new Table;
    table->nRecords=nRecords;
    table->nFields=nColumns;
    table->record=new Record*[table->nRecords];
    
    //Initialize Variables
    for(int row=0;row<table->nRecords;row++){
        table->record[row]=new Record;
        table->record[row]->nColumns=table->nFields;
        table->record[row]->colData=new int[table->record[row]->nColumns];
    }
    
    //Process inputs to outputs/map
    for(int row=0;row<table->nRecords;row++){
        for(int col=0;col<table->record[row]->nColumns;col++){
            table->record[row]->colData[col]=rand()%90+10;//2 Digit Number
        }
    }
    return table;
}

void printTable(const Table *table){
    //Display the results
    cout<<"Record Data"<<endl;
    for(int row=0;row<table->nRecords;row++){
        for(int col=0;col<table->record[row]->nColumns;col++){
            cout<<table->record[row]->colData[col]<<" ";//2 Digit Number
        }
        cout<<endl;
    }
    cout<<endl;
}

void destroyTable(Table *table){
    //Clean up memory
    for(int row=0;row<table->nRecords;row++){
        delete []table->record[row]->colData;
        delete table->record[row];
    }
    delete []table->record;
    delete table;
}