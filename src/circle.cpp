#include "circle.h"

Circle::Circle(int x, int y, int radius)
    : Shape()
    , m_radius(radius)
    , m_center( { x, y } )
{
}

int Circle::getX() const
{
    return m_center.x;
}

int Circle::getY() const
{
    return m_center.y;
}

int Circle::getArea() const
{
    return static_cast<int>(3.14 * m_radius * m_radius);
}

