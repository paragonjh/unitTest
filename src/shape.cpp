#include "shape.h"

#include <cstring>

Shape::Shape()
    : m_color(0)
{
}

Shape::~Shape()
{
}

int Shape::getColor() const
{
    return m_color;
}

void Shape::setColor(int r, int g, int b)
{
    m_color = ((r & 0xFF) << 16) | ((g & 0xFF) << 8) | (b & 0xFF);
}

void Shape::setText(const char *text)
{
    m_text = text;
}

String Shape::getText() const
{
    return m_text;
}

