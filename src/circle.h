#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"
#include "point.h"

class Circle : public Shape
{
public:
    Circle(int x, int y, int radius);

    virtual int getX() const;
    virtual int getY() const;
    virtual int getArea() const;

private:
    int m_radius;
    Point m_center;
};

#endif

