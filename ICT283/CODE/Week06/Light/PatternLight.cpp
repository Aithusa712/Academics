#include "PatternLight.h"


PatternLight::PatternLight()
{
    m_shape = NO_SHAPE;
}
int PatternLight::GetShape() const
{
    return m_shape;
}

bool PatternLight::SetShape(int shape)
{
    if(shape >= NO_SHAPE && shape <= MAX_SHAPE)
    {
        m_shape = shape;
        return true;
    }
    else
    {
        return false;
    }
}

ostream& operator << (ostream& ostr, const PatternLight& patternLight)
{
    ostr << static_cast<Light> (patternLight);
    if(patternLight.m_on && patternLight.m_shape != NO_SHAPE)
    {
        ostr << ", showing ";
        switch(patternLight.m_shape)
        {
            case LEFT_ARROW:
            ostr << " Left Arrow";
            break;
            case RIGHT_ARROW:
            ostr<< "Right Arrow";
            break;
        }
    }
    return ostr;
}


