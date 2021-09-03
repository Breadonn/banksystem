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
//  FILE:        user-interface.cpp
//
//  DESCRIPTION:
//   Interface to interact with user
//
//
****************************************************************/

#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include "llist.cpp"
void menu(int);

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   Driver for the user-interface
//
//  Parameters:    argc (int) : number of arguments
//                 argv (char*[]): array of arguments
//
//  Return values:  0 : success
//
****************************************************************/

int main (int argc, char* argv[])
{
    int debugmode = 0;
 
    #ifdef DEBUG
        debugmode = 1;
    #endif        

    if ( 0 == 1)
    {
        debugmode = 1;
    }
    
    menu(debugmode);
    
    return 0;
}

/***************************************************************** 
// 
// Function name: menu 
// 
// DESCRIPTION: User-Interface 
// 
// Parameters: debug (int) : status of debug mode 
// 
// 
// Return values: N/A 
//
****************************************************************/ 

void menu(int debug) 
{
    
    char str[20];
    llist *mylist = new llist();
    int quit = 0;
    int accnum;
    char accname[100];
    char accaddress[100];

    if (debug == 1)
    {
        std::cout << "*** DEBUG *** In menu function\n" << std::endl;
    }
    std::cout << "Welcome to the Bank\n\n" << std::endl;
    
    while (quit == 0)
    {
        std::cout << "Please, select one of the following commands\n\n" << std::endl;
        std::cout << "add: Add a new record in the database\n" << std::endl;
        std::cout << "printall: Print all records in the database\n" << std::endl;
        std::cout << "find: Find record(s) with a specified account#\n" << std::endl;
        std::cout << "delete: Delete existing record(s) from the database using the accout number\n" << std::endl;
        std::cout << "quit: Quit the program\n\n" << std::endl;
        std::cin.get(str, 100);

        //std::cout << strcasecmp("add", str) << std::endl;
        
        if ((strcasecmp("a", str) == 0 || strcasecmp("ad", str) == 0) || strcasecmp("add", str) == 0)
        {
            std::cout << "Type the account number of the record\n\n" << std::endl;
            std::cin >> accnum;
            std::cin.clear();
            std::cin.ignore(20, '\n');
            std::cout << "Enter the name for the account" << std::endl;
            std::cin.get(accname, 100);
            std::cin.clear();
            std::cin.ignore(100, '\n');
            std::cout << "Enter the address of the account" << std::endl;
            std::cin.get(accaddress, 100);
            std::cin.clear();
            std::cin.ignore(100, '\n');
            mylist->addRecord(accnum, accname, accaddress);
        }
        else if (((strcasecmp("p", str) == 0 || strcasecmp("pr", str) == 0) || (strcasecmp("pri", str) == 0 || strcasecmp("prin", str) == 0)) || ((strcasecmp("print", str) 
== 0 || strcasecmp("printa", str) == 0) || (strcasecmp("printal", str) == 0 || strcasecmp("printall", str) == 0)))
        {
            mylist->printAllRecords();
        }
        else if ((strcasecmp("f", str) == 0 || strcasecmp("fi", str) == 0) || (strcasecmp("fin", str) == 0 || strcasecmp("find", str) == 0))
        {
            std::cout << "Type the account number of the record you want to find\n\n" << std::endl;
            std::cin >> accnum;
            std::cin.clear();
            std::cin.ignore(20, '\n');
            mylist->findRecord(accnum);
            
        }
        else if (((strcasecmp("d", str) == 0 || strcasecmp("de", str) == 0) || (strcasecmp("del", str) == 0 || strcasecmp("dele", str) == 0)) || (strcasecmp("delet", str) == 
0 || strcasecmp("delete", str) == 0))
        {
            std::cout << "Type the account number of the record you want to delete\n\n" << std::endl;
            std::cin >> accnum;
            std::cin.clear();
            std::cin.ignore(20, '\n');
            mylist->deleteRecord(accnum);
        }
        else if ((strcasecmp("q", str) == 0 || strcasecmp("qu", str) == 0) || (strcasecmp("qui", str) == 0 || strcasecmp("quit", str) == 0))
        {
            quit = 1;
        }
        else
        {
            std::cout << "Error: Invalid option\n\n" << std::endl;
        }
        std::cin.clear();
        std::cin.ignore(100, '\n');
    }
    delete mylist;
}
