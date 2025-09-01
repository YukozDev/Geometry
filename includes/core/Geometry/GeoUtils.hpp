#pragma once
#include <cmath>
#include "Point.hpp"
#include "../Core.hpp"
#include "../../operations/Vector.hpp"

template<typename T>
T areaOfTriangle(const Point2D<T>& a, const Point2D<T>& b, const Point2D<T>& c) {
    Vector2 AB = Vector2(b.x, b.y) - Vector2(a.x, a.y);
    Vector2 AC = Vector2(c.x, c.y) - Vector2(a.x, a.y);

    return std::abs(determinant(AB, AC)/2);
}

template<typename T>
/***
 * @brief Return the relative position of point C with respect to segment AB
 * @return L
 */
RELATIVE_POSITION relativePosition2D(const Point2D<T>& a, const Point2D<T>& b, const Point2D<T>& c) {

    if(a.x == c.x && a.y == c.y)
        return RELATIVE_POSITION::ORIGIN;

    else if(b.x == c.x && b.y == c.y)
        return RELATIVE_POSITION::DESTINATION;

    Vector2 AB = Vector2(b.x - a.x, b.y - a.y);
    Vector2 AC = Vector2(c.x - a.x, c.y - a.y);
    
    T area = determinant(AB, AC);
    
    if(area > TOLERENCE)
        return RELATIVE_POSITION::RIGHT;

    else if(area < 0)
        return RELATIVE_POSITION::LEFT;

    // Now we know the point is collinear to the segment

    else if(AB.X() * AC.X() < 0 && AB.Y() * AC.Y() < 0)
        return RELATIVE_POSITION::BEHIND;

    else if(norm(AC) > norm(AB))
        return RELATIVE_POSITION::BEYOND;
    
    else
        return RELATIVE_POSITION::BETWEEN;
}

std::ostream& operator<<(std::ostream& os, RELATIVE_POSITION pos) {
    switch (pos) {
        case RELATIVE_POSITION::LEFT: return os << "LEFT";
        case RELATIVE_POSITION::RIGHT: return os << "RIGHT";
        case RELATIVE_POSITION::BEHIND: return os << "BEHIND";
        case RELATIVE_POSITION::BEYOND: return os << "BEYOND";
        case RELATIVE_POSITION::BETWEEN: return os << "BETWEEN";
        case RELATIVE_POSITION::ORIGIN: return os << "ORIGIN";
        case RELATIVE_POSITION::DESTINATION: return os << "DESTINATION";
    }
    return os;
}
