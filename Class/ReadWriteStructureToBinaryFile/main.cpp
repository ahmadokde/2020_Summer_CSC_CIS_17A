/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on July 8th, 2020, 9:11 AM
 * Purpose:  Create a simple structure to read and write to 
 * binary file.
 */

//System Libraries Here
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;

//User Libraries Here
#include "Test.h"

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
void wrtTxt(fstream &,Test *,int); //Write a structure to a Text File
void wrtBin(fstream &,Test *);     //Write a structure to a Binary File
Test *rdRecBn(fstream &,int);      //Read a Record from the Binary File
void wrtRcBn(fstream &,Test *,int);//For Lab Write Record to Binary File
void prntTxt(Test *);              //Print the Structure

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Open the Text and binary files
    fstream txtFile,binFile;
    txtFile.open("data.txt",ios::in|ios::out);
    binFile.open("data.bin",ios::in|ios::out|ios::binary);
    
    //Declare all Variables Here and Loop
    int nRecords=100;//Number of records 
    
    //Fill a binary and text file with a bunch of regular size structures
    cout<<"The size of the structure is "<<sizeof(Test)<<endl;
    for(int record=0;record<nRecords;record++){
        //Create the Structure and Fill it
        Test *test=new Test;
        test->c=rand()%26+65;
        test->s=rand()%9+record*10;
        test->i=rand()%900+record*1000;
        //Write to binary and text files
        wrtTxt(txtFile,test,record);
        wrtBin(binFile,test);
        delete test;
    }
    
    //Read back in the array, then print out
    int randRec=rand()%nRecords;
    cout<<"Random record to find = "<<randRec<<endl;
    Test *test=rdRecBn(binFile,randRec);
    prntTxt(test);
    
    //Delete the array
    delete test;
    
    //Test out your writing to a Binary File Here
    
    //Close the files
    txtFile.close();
    binFile.close();
    
    //Exit
    return 0;
}

//Function Stub for you to complete and test
void wrtRcBn(fstream &,Test *,int){
    
}

Test *rdRecBn(fstream &in,int record){
    //Declare and initialize variables
    long cursor=0L;    //Where to place the cursor
    Test *a=new Test;//Declare the array to return
    
    //Find the record
    cursor=record*sizeof(Test);
    
    //Fill the structure
    in.seekg(cursor,ios::beg);
    in.read(reinterpret_cast<char *>(a),sizeof(Test));
    return a;
}

void wrtBin(fstream &out,Test *a){
    out.write(reinterpret_cast<char *>(a),sizeof(Test));
}

void wrtTxt(fstream &out,Test *a,int record){
    out<<endl;
    out<<"Structure Contents Record = "<<record<<endl;
    out<<setw(6)<<a->c<<endl;
    out<<setw(6)<<a->s<<endl;
    out<<setw(6)<<a->i<<endl;
    out<<endl;
}

void prntTxt(Test *a){
    cout<<endl;
    cout<<"Structure Contents "<<endl;
    cout<<setw(6)<<a->c<<endl;
    cout<<setw(6)<<a->s<<endl;
    cout<<setw(6)<<a->i<<endl;
    cout<<endl;
}