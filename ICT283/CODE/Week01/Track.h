#ifndef TRACK_H_INCLUDED
#define TRACK_H_INCLUDED
#include <string>           // part of the STL

using namespace std;

class Track
{
    public:
        Track();            // default constructor
        virtual ~Track() {} // no implemntation, therefroe {}
        // string
        operator string() const;
    private:
        string m_title;
        string m_composer;
    
};

#endif