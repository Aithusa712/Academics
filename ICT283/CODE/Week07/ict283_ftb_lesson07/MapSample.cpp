// Map.cpp
// Simple client program showing STL map use
// See lecture notes for more explanations
//------------------------------------------------------


#include <map>  // the STL map
#include <iostream>
#include <iomanip>
#include <string>

// using namespace std;
// Be careful with what we expose
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::setw;



//------------------------------------------------------
// typedefs make it easier to use the various types.
typedef std::map<string,int> Popularity;
typedef Popularity::iterator PopItr;
typedef Popularity::const_iterator cPopItr; // when is this going to be used?


//------------------------------------------------------
//Forward declarations as main() is at the top of the source code file
void AddData (Popularity &pop);
void Output  (const Popularity &pop); // should Output be the version below?
//void Output  (Popularity &pop);

//------------------------------------------------------

int main ()
{
    Popularity pop;

    AddData (pop);
    Output (pop);

    cout << endl;
    return 0;
}

//------------------------------------------------------

void AddData (Popularity &pop)
{
    string name;

    // Prime the while loop
    cout << "Enter vote name, or 'end' to finish: ";
    getline (cin, name, '\n');

    while (name != "end") // how much processing is needed just to make this comparison?
        // name is std:string and "end" is a C string
    {
        // If this person is not yet in the map
        if (pop.find(name) == pop.end())
        {
            // Add them to the map
            pop[name] = 1;
        }
        else
        {
            // Otherwise just increment the number of votes in the map
            pop[name]++;
        }

        cout << "Enter vote name, or 'end' to finish: ";
        getline (cin, name);
    }
}

//------------------------------------------------------

void Output  (const Popularity &pop)  // should it be the version as in the commented code below? why?
//void Output  (Popularity &pop)   // non const reference version
{
    cPopItr winner = pop.begin();  // should it be the version below? why?
    //PopItr winner = pop.begin();
    string name;
    string voteCount;
    // For each entry in the map
    for (cPopItr itr = pop.begin(); itr != pop.end(); itr++)
        //for (PopItr itr = pop.begin(); itr != pop.end(); itr++)  // why not this one? try it
    {
        name = itr -> first;
        voteCount = itr ->  second;
        // Output the first and second parts of the pair (association)
        cout << setw(20) << name << ": " << voteCount<< endl;

        // Now check if this person should be the winner
        if (winner->second < voteCount)
        {
            winner = itr;
        }
    }

    // Output the winner.
    if (pop.begin() != pop.end()) // why???
    {
        cout << endl << "The new class president is " << winner->first
             << " with " << winner->second << " votes" << endl; // what if the votes are equal?
    }
    else
    {
        cout << "no data" << endl;
    }
}

//---------------------
