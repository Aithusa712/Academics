void Output(int size, const IntArray& numbers)
{

    cout << "Address of numbers: " << &numbers << endl;
    cout << "Contents of numbers: " << numbers << endl;
    for(int i = 0; i<size; i++)
    {
        cout << "Address and contents of element " << i << " = >"
        << &numbers[i]  << " : " << numbers[i] <<endl;
    }
}