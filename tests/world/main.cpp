#include "cpptest.h"

#include "polygontypes.h"
#include "circle.h"
#include "world.h"

#include <iostream>

void testWorldGetAllArea()
{
    Point points[4] = { { 5, 0 }, { 15, 0 }, { 15, 20 }, { 5, 20 } };
    Rectangle rect(points);
    Circle circle( 5, 5, 15);
    World world;

    world.add(&rect);
    world.add(&circle);
    EXPECT_EQ(world.getAllArea(), 906);
}

void testWorldAddMany()
{
    // TODO: enable tc
    return;

    Point points[4] = { { 5, 0 }, { 15, 0 }, { 15, 20 }, { 5, 20 } };
    Rectangle rect(points);
    World world;

    for(int i = 0; i < 100; ++i)
        world.add(&rect);
    EXPECT_EQ(world.getAllArea(), 20000);
}

void testWorldAddCopy()
{
    // TODO: enable tc
    return;

    Point points[4] = { { 5, 0 }, { 15, 0 }, { 15, 20 }, { 5, 20 } };
    Rectangle rect1(points);
    World world;

    world.add(&rect1);
    {
        Rectangle rect2(points);
        world.add(&rect2);
    }
    EXPECT_EQ(world.getAllArea(), 400);
}

int main()
{
    cpptest::init({
        testWorldGetAllArea,
        testWorldAddMany,
        testWorldAddCopy
    });

    return cpptest::runAllTests();
}

