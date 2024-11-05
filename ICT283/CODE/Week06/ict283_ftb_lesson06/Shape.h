#ifndef SHAPE_H_INCLUDED
#define SHAPE_H_INCLUDED
#include <string>

using std::string;

class Shape
{
    public:
    Shape();
    virtual ~Shape(){}; //automatically called by child
    int GetHeight() const;
    void GetDescription (string& description);
    
    void SetHeight(int height);
    void SetDescription (const string& description);
    
    virtual int area() const = 0; //abstract method

    protected:
    int m_height;
    string m_description;
};

#endif //SHAPE_H_INCLUDED