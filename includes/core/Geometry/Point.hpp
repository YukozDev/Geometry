#pragma once 

template<typename T = double>
struct Point2D
{
    T x{};
    T y{};

    Point2D(T x, T y) : x(x), y(y) {}

    Point2D(const Point2D& pt) : x(pt.x), y(pt.y) {}
};


template<typename T = double>
struct Point3D
{
    T x{};
    T y{};
    T z{};

    Point3D(T x, T y, T z) : x(x), y(y), z(z) {}

    Point3D(const Point3D& pt) : x(pt.x), y(pt.y), z(pt.z) {}
};

