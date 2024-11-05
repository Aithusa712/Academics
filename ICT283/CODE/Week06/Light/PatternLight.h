#ifndef PATTERNLIGHT_H_INCLUDED
#define PATTERNLIGHT_H_INCLUDED
#include <iostream>
#include "Light.h"

const int NO_SHAPE = 0;
const int LEFT_ARROW = 1;

const int RIGHT_ARROW = 2;

const int MAX_SHAPE = 2;

class PatternLight: public Light
{
    public:
    PatternLight();
    ~PatternLight(){}
    int GetShape() const;
    bool SetShape(int shape);
    friend ostream& operator << (ostream& ostr, const PatternLight& patternLight);

    private:
    int m_shape;
};
#endif // PATTERNLIGHT_H_INCLUDED