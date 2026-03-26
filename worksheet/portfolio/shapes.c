// Elizabeth Perry
// Student ID: 201952237


#include <stdbool.h>
#include <math.h>

#include "shapes.h"
#define EPSILON 1.0e-6  // small value so we can compare floats safely cuz youknow

Point makePoint( float x, float y ) {
    Point new;
    // implementation
    new.x = x;  // set x coord
    new.y = y;  // set y coord
    return new; // return the point we just made
}

Line makeLine(Point p1, Point p2) {
    Line l;
    l.p[0] = p1; //first end point
    l.p[1] = p2; //second end point
    return l;
}

Triangle makeTriangle(Point p1, Point p2, Point p3) {
    Triangle t;
    t.p[0] = p1; //frixt corner
    t.p[1] = p2; //second corner
    t.p[2] = p3; //third corner
    return t;
}


// complete other functions below
// - start with stubs as above
// - compile regularly to test syntax
// - test functions by calling them from main()

//STURCTURE CALCULATIONS
float lineLength(Line l) {
    float dx = l.p[0].x - l.p[1].x; // using distance formula
    float dy = l.p[0].y - l.p[1].y;
    return sqrt(dx * dx + dy * dy);
}

float triangleArea(Triangle t) {
    // using shoelace formula
    float x1 = t.p[0].x, y1 = t.p[0].y;
    float x2 = t.p[1].x, y2 = t.p[1].y;
    float x3 = t.p[2].x, y3 = t.p[2].y;

    float area = 0.5f * fabs( //fabs makes positive cuz its a shape not a negative shape
        x1*(y2 - y3) +
        x2*(y3 - y1) +
        x3*(y1 - y2)
    );

    return area;
}

//FOR COMPARING THE STRUCTUYRES
bool samePoint(Point p1, Point p2) {
    // can't compare floats directly so check if they close enough
    return (fabs(p1.x - p2.x) < EPSILON) &&
           (fabs(p1.y - p2.y) < EPSILON);
}

bool pointInLine(Point p, Line l) {
    // just check if point matches either end of the line
    return samePoint(p, l.p[0]) || samePoint(p, l.p[1]);
}

bool pointInTriangle(Point p, Triangle t) {
    // same idea as line but with 3 points
    return samePoint(p, t.p[0]) ||
           samePoint(p, t.p[1]) ||
           samePoint(p, t.p[2]);
}