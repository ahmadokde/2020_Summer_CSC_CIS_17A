/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr
 * Created on March 26th, 2020, 1:10 PM
 * Purpose:  A Dynamic Array of 1D Dynamic Array Structure
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries
#include "Struc1DArray.h"

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
int *fill1D(int);
DynAry1 *filStrc(int,int);
void prnStrc(DynAry1 *,int,int);
void destroy(DynAry1 *,int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables and Initialize
    int size=100;
    int nArrays=5;
    DynAry1 *array1D=filStrc(size,nArrays);
    
    //Initialize Variables
    prnStrc(array1D,nArrays,10);
    
    //Deallocate memory
    destroy(array1D,nArrays);
    
    //Exit stage right!
    return 0;
}

int *fill1D(int n){
    int *a=new int[n];
    for(int i=0;i<n;i++){
        a[i]=rand()%90+10;//Random 2 Digit numbers
    }
    return a;
}

DynAry1 *filStrc(int n,int nArrays){
    DynAry1 *d1=new DynAry1[nArrays];
    for(int i=0;i<nArrays;i++){
        d1[i].size=n;
        d1[i].array=fill1D(n);
    }
    return d1;
}

void prnStrc(DynAry1 *d1,int nArrays,int perLine){
    cout<<endl;
    for(int j=0;j<nArrays;j++){
        for(int i=0;i<d1[j].size;i++){
            cout<<d1[j].array[i]<<" ";
            if(i%perLine==(perLine-1))cout<<endl;
        }
        cout<<endl;
    }
}

void destroy(DynAry1 *d1,int nArray){
    for(int i=0;i<nArray;i++){
        delete []d1[i].array;
    }
    delete []d1;
}