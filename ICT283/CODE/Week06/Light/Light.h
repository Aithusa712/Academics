#ifndef LIGHT_H_INCLUDED
#define LIGHT_H_INCLUDED
#include <iostream>
#include <string>

using namespace std;

class Light
{
    public:
        Light ();
	    virtual ~Light () {}; // automatically called by child

	    void Clear (); // destructor has no implementation now
        string GetColour() const; // allowable if string is small
        float GetRadius() const;
        bool SetRadius(float Radius);
        bool isOn() const;
        void Switch();
        void SetColour(const string& colour);
        friend ostream& operator << (ostream& ostr, const Light& light);

    protected:
        string m_colour;
        float m_radius;
        bool m_on;
};

#endif// Light_H_INCLUDED