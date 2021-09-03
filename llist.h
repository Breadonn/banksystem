/*****************************************************************
//
//  NAME:        Braydon Nagasako
//
//  HOMEWORK:    project 2
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        April 12, 2021
//
//  FILE:        llist.h
//
//  DESCRIPTION:
//   Class definition for llist
//
****************************************************************/

#include "record.h"

#ifndef llist_h
#define llist_h

class llist
{
private:
    record *    start;
    char        filename[16];
    int         readfile();
    int         writefile();
    void        cleanup();

public:
    llist();
    llist(char[]);
    ~llist();
    int addRecord(int, char [ ],char [ ]);
    int findRecord(int);
    void printAllRecords();
    int deleteRecord(int);
};

#endif
