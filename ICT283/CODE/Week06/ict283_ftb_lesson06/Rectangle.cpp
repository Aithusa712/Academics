#include "Rectangle.h"

Rectangle::Rectangle()
{
    m_height = 6;
    m_length = 7;
    m_description = "Rectangle";
}
int Rectangle::GetLength() const
{
    return m_length;
}
void Rectangle::SetLength(int length)
{
    m_length = length;
}
int Rectangle::area() const
{
    return m_length * m_height;
}