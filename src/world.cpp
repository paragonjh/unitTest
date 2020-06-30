#include "world.h"
#include "shape.h"

World::World()
    : m_numShapes(0)
{
}

void World::add(Shape *shape)
{
    m_shapes[m_numShapes++] = shape;
}

int World::getAllArea() const
{
    double sum = 0;
    for(int i = 0; i < m_numShapes; ++i)
        sum += m_shapes[i]->getArea();
    return sum;
}

