/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on July 6th,2020 7:25 PM
 * Purpose:  Dynamic 1 and 2 D Arrays using Structures
 */

//System Libraries Here
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries Here
#include "Array1D.h"
#include "Array2D.h"

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
Array1D *filAray(int);
Array2D *filAray(int,int);
void prntAry(Array1D *,int);
void prntAry(Array2D *);
void destroy(Array1D *);
void destroy(Array2D *);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));

    //Declare all Variables Here
    int row,col,perLine;
    Array1D *a1D, *b1D;
    Array2D *a2D, *b2D;
    
    //Input or initialize values Here
    row=10,perLine=col=20;
    a1D=filAray(row*col);
    b1D=filAray(row*col);
    a2D=filAray(row,col);
    b2D=filAray(row,col);
    
    //Process/Calculations Here
    
    //Output Located Here
    prntAry(a1D,perLine);
    prntAry(a2D);
    prntAry(b1D,perLine);
    prntAry(b2D);
    
    //Clean up
    destroy(a1D);
    destroy(a2D);
    destroy(b1D);
    destroy(b2D);

    //Exit
    return 0;
}

void destroy(Array2D *array){
    for(int r=0;r<array->rows;r++){
        delete []array->data[r];
    }
    delete []array->data;
    delete array;
}

void destroy(Array1D *a){
    delete []a->data;
    delete a;
}

void prntAry(Array2D *a){
    cout<<endl;
    for(int r=0;r<a->rows;r++){
        for(int c=0;c<a->cols;c++){
            cout<<a->data[r][c]<<" ";//2 digit numbers
        }
        cout<<endl;
    }
    cout<<endl;
}

void prntAry(Array1D *a,int perLine){
    cout<<endl;
    for(int i=0;i<a->size;i++){
        cout<<a->data[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

Array2D *filAray(int row,int col){
    row=row<2?2:
      row>1000?1000:row;
    col=col<2?2:
      col>1000?1000:col;
    Array2D *array=new Array2D;
    array->cols=col;
    array->rows=row;
    array->data=new int*[row];
    for(int r=0;r<row;r++){
        array->data[r]=new int[col];
        for(int c=0;c<col;c++){
            array->data[r][c]=rand()%90+10;//2 digit numbers
        }
    }
    return array;
}

Array1D *filAray(int n){
    n=n<2?2:
      n>1000?1000:n;
    Array1D *array=new Array1D;
    array->size=n;
    array->data=new int[n];
    for(int i=0;i<n;i++){
        //array->data[i]=rand()%90+10;//2 digit numbers
        (*array).data[i]=rand()%90+10;//2 digit numbers
    }
    return array;
}