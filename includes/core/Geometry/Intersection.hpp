#pragma once
#include "Point.hpp"
#include "../Core.hpp"
#include "../Vectors/Vector2.hpp"
#include "../Vectors/Vector3.hpp"
#include "../Vectors/VectorBase.hpp"
#include "includes/core/Geometry/GeoUtils.hpp"

typedef RELATIVE_POSITION Position;

template<typename T>
bool intersection(const Point2D<T>& a, const Point2D<T>& b, const Point2D<T>& c, const Point2D<T>& d) {
    Position AB_C = relativePosition2D(a, b, c);
    Position AB_D = relativePosition2D(a, b, d);
    Position CD_A = relativePosition2D(c, d, a);
    Position CD_B = relativePosition2D(c, d, b);

    if(AB_C == Position::ORIGIN || AB_C == Position::DESTINATION || AB_C == Position::BETWEEN)
        return true;

    if(AB_D == Position::ORIGIN || AB_D == Position::DESTINATION || AB_D == Position::BETWEEN)
        return true;

    if(CD_A == Position::ORIGIN || CD_A == Position::DESTINATION || CD_A == Position::BETWEEN)
        return true;

    if(CD_B == Position::ORIGIN || CD_B == Position::DESTINATION || CD_B == Position::BETWEEN)
        return true;

    return xor(AB_C == Position::LEFT, AB_D == Position::LEFT) && xor(CD_A == Position::LEFT, CD_B == Position::LEFT);
}

template<typename T>
Point3D<T> intersection(const Point3D<T>& a, const Point3D<T>& b, const Point3D<T>& c, const Point3D<T>& d) {

    return Point3D<T>(0,0,0);
}
