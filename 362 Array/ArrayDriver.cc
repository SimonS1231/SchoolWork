/*
  Filename   : ArrayDriver.cc
  Author     : Gary M. Zoppetti
  Course     : CSCI 362-01
  Assignment : N/A
  Description: Test some, but NOT ALL, methods of the Array class.
*/

/************************************************************/
// System includes

#include <cstdlib>
#include <iostream>
#include <string>
#include <iterator>
#include <sstream>
#include <cassert>

/************************************************************/
// Local includes

#include "Array.hpp"

/************************************************************/
// Using declarations

using std::cin;
using std::cout;
using std::endl;
using std::ostream_iterator;
using std::string;
using std::ostringstream;

/************************************************************/
// Function prototypes/global vars/typedefs

void
printTestResult (const string& test,
		 const string& expected,
		 const ostringstream& actual);

/************************************************************/

int
main (int argc, char* argv[])
{
  Array<int> A;

  // For holding the actual result
  ostringstream output;
  // Put the actual result into the output stream
  output << A;
  printTestResult ("no-arg ctor", "[ ]", output);

  // Must clear the output stream each time
  output.str ("");
  output << A.empty ();
  // "1" for true, "0" for false
  printTestResult ("empty", "1", output);

  //size ctor
  Array<int> B (3, 9);
  output.str ("");
  output << B;
  printTestResult("Size ctor", "[ 9 9 9 ]", output);

  //Insert
  Array<int> C;
  for (int i = 0; i < 10; ++i){
    C.insert (C.begin (), i);}

  output.str("");
  output << C;
  printTestResult("Insert", "[ 9 8 7 6 5 4 3 2 1 0 ]", output);

  //erase
  Array<int> D (4, 6);

  for (Array<int>::iterator i = D.begin (); i != D.end (); )
    i = D.erase (i);

  Array<int>::iterator i = D.begin();
  output.str ("");
  output << D;
  printTestResult("Erase" , "[ ]", output);

  //Assingment
  B = C;
  output.str("");
  output << B;
  printTestResult ("Assignment", "[ 9 8 7 6 5 4 3 2 1 0 ]", output);


  //Pushback
  A.push_back (5);
  A.push_back (10);
  A.push_back (15);

  output.str ("");
  output << A;
  printTestResult ("push_back", "[ 5 10 15 ]", output);

  output.str ("");
  output << A.size ();
  printTestResult ("size", "3", output);

  A.pop_back ();
  A.pop_back ();

  output.str ("");
  output << A;
  printTestResult ("pop_back", "[ 5 ]", output);


  //Range Ctor
  Array<int> E (B.begin (), B.begin () + 2);
  
  output.str("");
  output << E;
  printTestResult ("Range Ctor", "[ 9 8 ]", output);


  //Resize Down
  B.resize (3);

  output.str("");
  output << B;
  printTestResult ("Resize Down", "[ 9 8 7 ]", output);


  //Resize Up
  B.resize (4, 3);


  output.str("");
  output << B;
  printTestResult ("Resize Up", "[ 9 8 7 3 ]", output);


  Array<int> H;
  Array<int> I (3, 4);

  I = H;

  output.str("");
  output << I;
  printTestResult ("Copy Blank", "[ ]", output);





  /************************************************************/
  // Convert the following tests to use printTestResult
  /************************************************************/
 /* for (int i = 0; i < 10; ++i)
    A.insert (A.begin (), i);

  cout << "Inserted 9 8 ... 0 at beginning\n";
  cout << A << endl;
  cout << endl;

  for (Array<int>::iterator i = A.begin (); i != A.end (); )
    i = A.erase (i);

  cout << "Erased all elements of A\n";
  cout << A << endl;
  cout << endl;


  // Range ctor.
  Array<int> C (B.begin (), B.begin () + 2);
  cout << "C (B.begin (), B.begin () + 2): 9 9\n";
  cout << C << endl;
  cout << endl;

  // Assignment operator.
  B = A;
  cout << "B = A: empty\n";
  cout << B << endl;
  cout << endl;

  cout << "Inserting 0, 1, 2, 3, 4 at beginning of B\n";
  for (int i = 0; i < 5; ++i)
    B.insert (B.begin (), i);
  cout << B << endl;
  cout << endl;

  /************************************************************/
  // START WRITING YOUR TESTS HERE
  /************************************************************/

  // Test range ctor (a different case than I test above)

  // Test copy ctor

  // Test capacity

  // ...

  return EXIT_SUCCESS;
}

/************************************************************/

void
printTestResult (const string& test,
		 const string& expected,
		 const ostringstream& actual)
{
  cout << "Test: " << test << endl;
  cout << "==========================" << endl;
  cout << "Expected: " << expected << endl;
  cout << "Actual  : " << actual.str () << endl;
  cout << "==========================" << endl << endl;

  // Ensure the two results are the same
  assert (expected == actual.str ());
}

/************************************************************/
