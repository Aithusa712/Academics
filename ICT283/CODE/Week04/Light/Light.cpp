#include "Light.h"




Light::Light()
{
    m_colour = "white";
    m_radius = 0;
    m_on = false;
}


string Light::GetColour() const // allowable if string is small
{
    return m_colour; // reminder not to do this for obects or large strings
}
float Light::GetRadius() const
{
    return m_radius;
}
bool Light::isOn() const
{
    return m_on;
}

void Light::SetColour(const string& colour)
{
    m_colour = colour;
}


bool Light::SetRadius(float radius)
{
    if(radius>0)
    {
        m_radius = radius;
        return true;
    }
    else
    {
        return false;
    }
}

void Light::Switch()
{
    m_on=!m_on;
}
ostream& operator << (ostream& ostr, const Light& light)
{
    // 15 cm red light is off
    string state = (light.m_on ? "on" : "off");
    ostr << light.m_radius << " cm " << light.m_colour << " light is " << state;
    return ostr;
}