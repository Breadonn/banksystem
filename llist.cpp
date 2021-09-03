/*****************************************************************
//
//  NAME:        Braydon Nagasako
//
//  HOMEWORK:    Project 2
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        April 12, 2021
//
//  FILE:        llist.cpp
//
//  DESCRIPTION:
//   A list of objects
//
//
****************************************************************/

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include "llist.h"
using namespace std;

llist::llist()
{
    start = NULL;
    strcpy(filename, "data.txt");
    readfile();
}

llist::llist(char list[])
{
    start = NULL;
    strcpy(filename, list);
    readfile();
}

llist::~llist()
{
    writefile();
    cleanup();
}

int llist::readfile()
{
    string read;
    int num = 1;
    int accnum;
    char accname[50];
    char accaddress[50];
    std::ifstream file;
    file.open(filename);
    if ( file )
    {
        while ( getline(file, read) )
        {
            if ( (num % 3) == 0 )
            {
                strcpy(accaddress, read.c_str());
                addRecord(accnum, accname, accaddress);
            }
            else if ( (num % 2) == 0 )
            {
                strcpy(accname, read.c_str());
            }
            else
            {
                accnum = std::atoi(read.c_str());
            }
            num++;
        }
        file.close();
    }
    return 0;
}

int llist::writefile()
{
    int valid = 0;
    std::ofstream file;
    file.open(filename);
    if ( start )
    {
        record *temp = start;
        while ( valid == 0 )
        {
            file << temp->accountno << std::endl;
            file << temp->name << std::endl;
            file << temp->address << std::endl;

            if ( !(temp->next) )
            {
                valid = 1;
            }
            else
            {
                temp = temp->next;
            }
        }
    }
    file.close();
    return 0;
}

int llist::addRecord(int accno, char accname[], char accaddress[])
{
    int debug = 0;

    #ifdef DEBUG
        debug = 1;
    #endif

    if ( debug == 1 )
    {
        std::cout << "DEBUG: In addRecord function. accno: " << accno << " accname: " << accname << " accaddress: " << accaddress << "\n" << std::endl;
    }
    int valid = 0;
    int proc = 0;
    record *account = new record();
    account->accountno = accno;
    strcpy(account->name, accname);
    strcpy(account->address, accaddress);
    account->next = NULL;

    if ( start == NULL )
    {
        start = account;
    }
    else if ( start->accountno > accno )
    {
        account->next = start;
        start = account;
    }
    else
    {
        record *current = start;
        if ( !(current->next) )
        {
            valid = 1;
        }

        while (valid == 0)
        {
            if ( accno < current->next->accountno)
            {
                account->next = current->next;
                current->next = account;
                proc = 1;
            }
            if ( !(current->next) )
            {
                valid = 1;
            }
            else
            {
                current = current->next;
            }
        }
        if ( proc == 0 )
        {
            current->next = account;
        }
    }
    return 0;
}

int llist::findRecord(int accno)
{
    int debug = 0;

    #ifdef DEBUG
        debug = 1;
    #endif

    if ( debug == 1 )
    {
        std::cout << "DEBUG: In findRecord function. accno: " << accno << "\n" << std::endl;
    }
    int valid = 0;
    if ( !start )
    {
        std::cout << "The account is not in the list\n" << std::endl;
    }
    else
    {
        record *current = start;
        while ( valid == 0 )
        {
            if ( current->accountno == accno )
            {
                std::cout << "Account has been found\n" << std::endl;
                std::cout << "Account name: " << current->name << "\n" << std::endl;
                std::cout << "Account address: " << current->address << "\n" << std::endl;
                valid = 1;
            }
            else if ( !(current->next) )
            {
                valid = 1;
                std::cout << "The account is not in the list\n" << std::endl;
            }
            else
            {
                current = current->next;
            }
        }
    }
    return 0;
}

void llist::printAllRecords()
{
    int debug = 0;

    #ifdef DEBUG
        debug = 1;
    #endif

    if ( debug == 1 )
    {
        std::cout << "DEBUG: In printAllRecords function.\n" << std::endl;
    }
    int valid = 0;
    if ( start == NULL )
    {
        std::cout << "There are no records in the list\n" << std::endl;
    }
    else
    {
        record *current = start;
        while ( valid == 0 )
        {
            std::cout << "Account number: " << current->accountno << "\n" << std::endl;
            std::cout << "Account name: " << current->name << "\n" << std::endl;
            std::cout << "Account address: " << current->address << "\n\n" << std::endl;
            if ( !(current->next) )
            {
                valid = 1;
            }
            else
            {
                current = current->next;
            }
        }
    }
}

int llist::deleteRecord(int accno)
{
    int debug = 0;

    #ifdef DEBUG
        debug = 1;
    #endif

    if ( debug == 1 )
    {
        std::cout << "DEBUG: In deleteRecord function. accno: " << accno << "\n" << std::endl;
    }
    int valid = 0;
    int proc = 0;
    if ( start == NULL )
    {
        std::cout << "The account is not in the list\n" << std::endl;
    }
    else if ( accno == start->accountno && !(start->next) )
    {
        start = NULL;
    }
    else
    {
        record *previous;
        record *current = start;
        while ( valid == 0 )
        {
            if ( accno == current->accountno )
            {
                previous->next = current->next;
                valid = 1;
                proc = 1;
            }
            else if ( !(current->next) )
            {
                valid = 1;
            }
            else
            {
                previous = current;
                current = current->next;
            }
        }

        if ( proc == 0 )
        {
            std::cout << "The account is not in the list\n" << std::endl;
        }
    }
    return 0;
}

void llist::cleanup()
{
    start = NULL;
}
