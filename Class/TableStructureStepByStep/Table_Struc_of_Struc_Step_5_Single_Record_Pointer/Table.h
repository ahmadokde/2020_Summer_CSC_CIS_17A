/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Date:   October 3rd, 2019
 * Purpose:Specification for the Table Structure
 * Note:  Naming clearly reduces ambiguity and promotes clarity
 */

#ifndef TABLE_H
#define TABLE_H

#include "Record.h"

struct Table{
    int nFields;   //Number of Fields in the Table
    int nRecords;  //Number of Records in the Table
    Record *record;//Array of Records
};

#endif /* TABLE_H */