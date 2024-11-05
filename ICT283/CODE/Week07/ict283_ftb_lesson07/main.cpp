#include <iostream>
#include <set>
#include <algorithm> // use the union or intersection
#include <vector>

using std::cout;
using std::endl;
using std::set;
using std::vector;  // store the results

int main()
{
    set<int> numberSet1;
    numberSet1.insert(5);
    numberSet1.insert(13);
    numberSet1.insert(7);
    numberSet1.insert(11);
    numberSet1.insert(4);
    numberSet1.insert(5);
    numberSet1.insert(8);
    /*
    cout << "{ ";
    for(int number:numberSet1)
    {
        cout << number << " ";

    }
    cout << "}" <<endl;
    */
    set<int> numberSet2 { 6,7,8,5,10,20,29,7,4};
    /*
    cout << "{ ";
    for(int number:numberSet2)
    {
        cout << number << " ";

    }
    cout << "}" <<endl;
    */
    vector<int> resultSet(numberSet1.size() + numberSet2.size());
    set_union( numberSet1.begin(),numberSet1.end(),
                numberSet2.begin(), numberSet2.end(),
                resultSet.begin());

    cout << "{ ";
    for(int number:resultSet)
    {
        cout << number << " ";

    }
    cout << "}" <<endl;
    return 0;
}
