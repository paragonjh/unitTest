#ifndef SHAPE_H
#define SHAPE_H

#include "mystring.h"

class Shape
{
public:
    Shape();
    virtual ~Shape();

    int getColor() const;
    void setColor(int r, int g, int b);

    void setText(const char *text);
    String getText() const;

    virtual int getX() const = 0;
    virtual int getY() const = 0;
    virtual int getArea() const = 0;

private:
    int m_color;
    String m_text;
};

#endif

