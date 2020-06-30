#include "cpptest.h"

#include "polygontypes.h"
#include "circle.h"

void testPolygon()
{
    struct TestGetArea
    {
        int operator()(int, const Point*) const
        {
            return 10;
        }
    };

    struct TestGetCenter
    {
        Point operator()(int, const Point*, int) const
        {
            return {100, 100};
        }
    };

    Point points[4] = {{5,0}, {15,0}, {15,20}, {5,20}};
    Polygon<4, TestGetArea, TestGetCenter> rect10(points);
    EXPECT_EQ(rect10.getX(), 100);
    EXPECT_EQ(rect10.getY(), 100);
    EXPECT_EQ(rect10.getArea(), 10);
}


void testRectangle()
{
    Point points[4] = { { 5, 0 }, { 15, 0 }, { 15, 20 }, { 5, 20 } };
    Rectangle rect(points);
    EXPECT_EQ(rect.getX(), 10);
    EXPECT_EQ(rect.getY(), 10);
    EXPECT_EQ(rect.getArea(), 200);
}

void testCircle()
{
    Circle circle( 5, 5, 15);
    EXPECT_EQ(circle.getX(), 5);
    EXPECT_EQ(circle.getY(), 5);
    EXPECT_EQ(circle.getArea(), 706);
}

void testShapeText()
{
    Point points[4] = { { 5, 0 }, { 15, 0 }, { 15, 20 }, { 5, 20 } };
    Rectangle rect(points);
    rect.setText("red box");
    EXPECT_EQ(rect.getText(), "red box");
    rect.setText("blue box");
    EXPECT_EQ(rect.getText(), "blue box");
}

void testShapeCopy()
{
    Point points[4] = { { 5, 0 }, { 15, 0 }, { 15, 20 }, { 5, 20 } };
    Rectangle rect1(points);
    rect1.setText("red box");
    EXPECT_EQ(rect1.getX(), 10);
    EXPECT_EQ(rect1.getY(), 10);
    EXPECT_EQ(rect1.getText(), "red box");

    Rectangle rect2 = rect1;
    EXPECT_EQ(rect2.getX(), 10);
    EXPECT_EQ(rect2.getY(), 10);
    EXPECT_EQ(rect2.getText(), "red box");

    Point points2[4] = { { 0, 0 }, { 1, 0 }, { 1, 1 }, { 0, 1 } };
    Rectangle rect3(points2);
    rect3 = rect1;
    EXPECT_EQ(rect3.getX(), 10);
    EXPECT_EQ(rect3.getY(), 10);
    EXPECT_EQ(rect3.getText(), "red box");
}

int main()
{
    cpptest::init({
        testPolygon,
        testRectangle,
        testCircle,
        testShapeText,
        testShapeCopy
    });

    return cpptest::runAllTests();
}

