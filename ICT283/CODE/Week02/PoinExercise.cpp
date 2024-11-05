#include <iostream>
using namespace std;


int main(){
/*

Mark the following statements as valid or invalid. 
If a statement is invalid, explain why:

a.     p =  q; //valid, addr = addr
b.    *p = 56; //valid, assigning int to int type(*p) 
c.     p =  x; //invalid, assigning int to addr type
d.    *p = *q; //valid, int=int
e.     q = &x; //valid, *x is an addr
f.    *p =  q; //invalid, *p is an int, q is an addr
*/

    int x;
    int y;
    int *p = &x;
    int *q = &y;
    x = 35;
    y = 46;
    p = q;
    *p = 18;


    cout << x << " "<< y << endl;
    cout <<*p << " "<< *q <<endl;
    return 0;
    

}