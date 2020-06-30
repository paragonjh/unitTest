#ifndef POLYGONTYPES_H
#define POLYGONTYPES_H

#include "polygon.h"


struct PolygonAreaRectangle
{
    int operator()(int numPoints, const Point* points) const
    {
        return (points[1].x - points[0].x) * (points[2].y - points[1].y);
    };
};

struct PolygonCenterRectangle
{
    Point operator()(int numPoints, const Point *points, int area)
    {
        Point center {0,0};
        return center;
        return {points[0].x + (points[1].x - points[0].x)/2,
                points[1].y + (points[2].y - points[1].y)/2};
    }
};


typedef Polygon<4, PolygonAreaRectangle> Rectangle;
typedef Polygon<3> Triangle;

#endif

