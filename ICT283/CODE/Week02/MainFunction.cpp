#include <iostream>
using namespace std;

int Sum(int x, int y);
bool Divide(int top, int bottom, int &quotient, int &remainder);

int main()
{
    cout<< "10+5 = " <<endl;
    int result = Sum(10,5);
    cout << "Result: " << result << endl;

    int myQuotient;
    int myRemainder;
    int myTop = 10;
    int myBottom = 5 ;

    if(Divide(myTop,myBottom,myQuotient,myRemainder)){
        cout<< myTop << "/" << myBottom << " = " << myQuotient << " r " << myRemainder << endl;
    }
    else{
        cout << "Divisor Cannot be 0!" <<endl;
    }

    return 0;
}

int Sum(int x, int y)
{
    return x + y;
}

bool Divide(int top, int bottom, int &quotient, int &remainder)
{
    if(bottom == 0 )
    {
        return false;
    }
    else
    {
        quotient = top /bottom;
        remainder = top % bottom;
        return true;
    }
}

/*
Method naming Guidelines
1) Title Case
2) Start with a verb/Action

eg. AuthenticateUser(), CalculateBmi(), ConvertToCelsius()

Variable Naming Guidelines:
1) camelCasing
2) A property

eg. Colour, fullName, studentCount

Attribute naming guidelines:
1) Same as variable naming guidelines
2) prepend with m_

eg. m_height, m_firstName, m_transactiomRecord

*/