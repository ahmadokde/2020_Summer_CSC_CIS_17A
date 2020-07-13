/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Date:   October 3rd, 2019
 * Purpose:Step 0 in creating a Table Structure with a Record Structure
 * Create a single static row/record object, fill, print, cleanup all in main
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
    Record row;
    
    //Initialize Variables
    row.nCol=10;
    row.colData=new int[row.nCol];
    
    //Process inputs to outputs/map
    for(int col=0;col<row.nCol;col++){
        row.colData[col]=rand()%90+10;//2 Digit Number
    }
    
    //Display the results
    cout<<"Record Data"<<endl;
    for(int col=0;col<row.nCol;col++){
        cout<<row.colData[col]<<" ";
    }
    cout<<endl;
    
    //Clean up memory
    delete []row.colData;

    //Clean up and exit stage right
    return 0;
}