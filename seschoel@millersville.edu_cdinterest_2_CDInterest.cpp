/*
    Filename    : CDinterest.cpp
    Author      : Simon Schoelkopf
    Course      : CSCI 362-01
    Assignment  : (Re)writing a CSCI 161 Lab in C++
    Description : Displays the amount of interest gained on a CD
*/

/************************************************************/
//System includes

#include <iostream>
#include <string>
#include <cstdlib>

/************************************************************/
//Local Includes

#include <stdio.h>
#include <locale.h>

/************************************************************/
//Using declarations

using std::cout;
using std::cin;
using std::endl;

/************************************************************/
// Function prototypes/global vars/typedefs

void
printIntro ();

void
printTable (int numRows, double balance, double rate);

void
printRow (int currentRowNum, double currentBalance, double interestGained);

double
getBalance ();

double
getRate ();

int
getYears ();

double
calcInterest (double balance, double rate);

/************************************************************/

int
main (int argc, char* argv[])
{
    setlocale (LC_NUMERIC, "");

    printIntro ();

    double startingBalance = getBalance ();
    double enteredRate = getRate ();
    int years = getYears ();

    printTable (years, startingBalance, enteredRate);

    return EXIT_SUCCESS;
}

/************************************************************/

void
printIntro ()
{
    cout << "This program will calculate the interest earned" << endl;
    cout << "  on a CD over a period of several years." << endl;
    cout << endl;
}

/************************************************************/

void
printTable (int numRows, double balance, double rate)
{


    double totalBalance = balance;

    //Sets up the headers of the table
    printf ("%-4s%12s%13s%16s\n", "Year", "Balance", "Interest", "New Balance");
    printf ("%-4s%12s%13s%16s\n", "----", "-------", "--------", "-----------");

    //Prints the rest of the data into the table
    for (int year = 1; year <= numRows; year++)
    {
        double currentInterest = calcInterest(totalBalance, rate);
        double newBalance = totalBalance + currentInterest;

        printRow (year, totalBalance, currentInterest);
        totalBalance = newBalance;
    }
}

/************************************************************/

void
printRow (int currentRowNum, double currentBalance, double interestGained)
{
    printf ("%'-4d%'12.2f%'13.2f%'16.2f\n", currentRowNum, currentBalance, interestGained, (currentBalance + interestGained));
}

/************************************************************/

double
calcInterest (double balance, double rate)
{

    double interest = (balance * (rate / 100));

    return interest;

}

/************************************************************/

double
getBalance ()
{
    cout << "Please enter the initial balance: ";
    double initialBalance;
    cin >> initialBalance;

    return initialBalance;
}

/************************************************************/

double
getRate ()
{
    cout << "Please enter the interest rate  : ";
    double rate;
    cin >> rate;

    return rate;
}

/************************************************************/

int
getYears ()
{
    cout << "Please enter the number of years: ";
    int years;
    cin >> years;
    cout << endl;

    return years;
}
