/*
  Filename   : Sieve.cpp
  Author     : Simon Schoelkopf
  Course     : CSCI 362
  Assignment : The Sieve of Eratosthenes
  Description: 
*/   

/************************************************************/
// System includes

#include <iostream>
#include <iterator>
#include <algorithm>
#include <string>
#include <chrono>
#include <set>
#include <vector>
#include <cstdlib>


/************************************************************/
// Local includes

#include "Timer.hpp"

/************************************************************/
// Using declarations

using std::cout;
using std::endl;
using std::cerr;
using std::stoul;
using std::string;
using std::set;
using std::vector;

/************************************************************/
// Function prototypes/global vars/typedefs

set<unsigned>
sieveSet (unsigned N);

set<unsigned>
sieveVector (unsigned N);

/************************************************************/
//replace every unsigned with unsigned int?
int
main (int argc, char* argv[])
{
    if (argc != 3)
    {
        cerr << "Usage: <NAME> <NUMBER>" << endl;
        exit (EXIT_FAILURE);
    }

    string type (argv[1]);

    string numb (argv[2]);
    unsigned long N = stoul (numb);

    set<unsigned> oSet;

    Timer<> t;

    if (type == "set")
    {
        for (int i = 0; i < 3; ++i)
        {
            t.start();
            oSet = sieveSet (N);
            t.stop();
        }
    }

    else if (type == "vector")
    {
        for (int i = 0; i < 3; ++i)
        {
            t.start();
            oSet = sieveVector(N);
            t.stop();
        }
    }

    double aveTime = (t.getElapsedMs() /3) *10;

    cout << "Pi[" << N << "] = " << oSet.size() 
    << " (using a " << type << ")" << endl;

    printf ("Time: %.2f ms\n", aveTime);

    return EXIT_SUCCESS;
}

// Return the set of primes between 2 and N.
// Use a set to implement the sieve.
set<unsigned>
sieveSet (unsigned N)
{
    set<unsigned> s;
    set<unsigned>::iterator pos = s.begin();

    s.insert(2);

    for (auto i = 3; i <= N; i+=2)
    {
        s.insert(i);
    }

    for (auto m = 3; m * m <= N; m+=2)
    {
        for (auto e = m; m * e <= N; e+=2)
        {
            s.erase(m * e);
        }
    }

    return s;

}

// Return the set of primes between 2 and N.
// Use a vector to implement the sieve.
// After filtering out the composites, put the primes in a set
//   to return to the caller. 
set<unsigned>
sieveVector (unsigned N)
{
    vector<bool> v (N, true);
    set<unsigned> s;

    v[0] = false;
    v[1] = false;

    for (auto i = 4; i <= N; i+=2)
    {
        v[i] = false;
    }

    for (auto m = 3; m * m <= N; m+=2)
    {
        for (auto e = m; m * e <= N; e+=2)
        {
            v[m * e] = false;
        }
    }

    for (auto t = 0; t <= N; ++t)
    {
        if(v[t] == true)
            s.insert(t);
    }

    return s;
}