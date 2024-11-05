#include "Shape.h"

Shape::Shape()
{
    m_height = 0;
    m_description = "Shape";
}
int Shape::GetHeight() const
{
    return m_height;
}
void Shape::GetDescription (string& description)
{   
    description = m_description;
}

void Shape::SetHeight(int height)
{
    m_height = height;
}
void Shape::SetDescription (const string& description)
{
    m_description = description;
}