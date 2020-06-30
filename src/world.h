#ifndef WORLD_H
#define WORLD_H

class Shape;
class World
{
public:
    World();

    void add(Shape *shape);

    int getAllArea() const;

private:
    int m_numShapes;
    Shape* m_shapes[10];
};

#endif

