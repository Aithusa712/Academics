#include "Unit.h"     // Unit class declaration/interface
#include "Result.h"   // Result class declaration/interface
#include "Date.h"     // Date class declaration/interface
#include "Regist.h"   // Registration class declaration/interface
#include <iostream>
#include <fstream>

using namespace std;



int main()
{
    ifstream infile( "rinput.txt" );
    if( !infile )
    {
        cout << "File not found" << endl;
        return -1;
    }
    Registration R;

    infile >> R;
    infile.close();
    ofstream ofile( "routput.txt" );

    ofile << R
          << "Number of courses = " << R.GetCount() << '\n'
          << "Total credits     = " << R.GetCredits() << '\n';

    return 0;
}

