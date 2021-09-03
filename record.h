/***************************************************************** 
// 
// NAME: Ravi Narayan 
// 
// HOMEWORK: project1 
// 
// CLASS: ICS 212 
// 
// INSTRUCTOR: Ravi Narayan 
// 
// DATE: March 13, 2021 
// 
// FILE: record.h 
// 
// DESCRIPTION: 
// Represents a record 
// ****************************************************************/

#ifndef WHATEVER_H_INCLUDED 
#define WHATEVER_H_INCLUDED
int f(int a); 

struct record 
{
    int accountno;
    char name[25];
    char address[50];
    struct record* next;
};

#endif
