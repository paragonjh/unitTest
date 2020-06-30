#ifndef POLYGON_H
#define POLYGON_H

#include "shape.h"
#include "point.h"

struct PolygonAreaGeneral
{
    int operator()(int numPoints, const Point *points) const
    {
        int sum = 0;
        for(int i = 0, j = numPoints - 1; i < numPoints; j=i, ++i)
            sum += ( (points[j].x + points[i].x) * (points[j].y - points[i].y) );
        return static_cast<int>(abs(sum) / 2);
    }
};

struct PolygonCenterGeneral
{
    Point operator()(int numPoints, const Point *points, int area)
    {
        Point center { 0, 0 };
        for(int i = 0, j = numPoints - 1; i < numPoints; j=i, ++i)
        {
            int x = (points[j].x + points[i].x) * (points[j].x * points[i].y - points[i].x * points[j].y);
            int y = (points[j].y + points[i].y) * (points[j].x * points[i].y - points[i].x * points[j].y);
            center.x += x;
            center.y += y;
        }
        center.x /= (area * 6);
        center.y /= (area * 6);
        return center;
    }
};

template <int N,
    typename PolygonArea=PolygonAreaGeneral,
    typename PolygonCenter=PolygonCenterGeneral>
class Polygon : public Shape
{
public:
    Polygon(Point *points)
    : Shape()
    , m_center({ 0, 0 })
    {
        for(int i = 0; i < N; ++i)
            m_points[i] = points[i];
        m_center = m_get_center(N, points, m_get_area(N, points));

    }
    virtual ~Polygon() {}
    virtual int getX() const
    {
        return m_center.x;
    }
    virtual int getY() const
    {
        return m_center.y;
    }
    virtual int getArea() const
    {
        return m_get_area(N, m_points);
    }

private:
    Point m_points[N];
    Point m_center;
    PolygonArea m_get_area;
    PolygonCenter m_get_center;
};

#endif

