
#pragma once
#include <type_traits>
#include "Point.hpp"
#include "../Vectors/Vector2.hpp"
#include "../Vectors/Vector3.hpp"
#include "../Vectors/VectorBase.hpp"

template<typename T = double, std::size_t DIM = 2>
class Line
{
    private:
        using Vec = std::conditional_t<DIM == 2, Vector2<T>, Vector3<T>>;
        Vec m_origin;
        Vec m_destination;
        Vec m_direction;

    public:
        Line(const Point2D<T>& p1, const Point2D<T>& p2)
        {
            m_direction = Vec(p2.x, p2.y) - Vec(p1.x, p1.y);
            m_origin = Vec(p1.x, p1.y);
            m_destination = Vec(p2.x, p2.y);
        }

        Line(const Point3D<T>& p1, const Point3D<T>& p2)
        {
            m_direction = Vec(p2.x, p2.y, p2.z) - Vec(p1.x, p1.y, p1.z);
            m_origin = Vec(p1.x, p1.y, p1.z);
            m_destination = Vec(p2.x, p2.y, p2.z);
        }

        const Vec& getDirection() const {
            return m_direction;
        }

        const Vec& getOrigin() const {
            return m_origin;
        }

        const Vec& getDestination() const {
            return m_destination;
        }
};
