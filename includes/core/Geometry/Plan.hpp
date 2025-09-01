#pragma once
#include "Point.hpp"
#include "../Vectors/Vector3.hpp"
#include "../../operations/Vector.hpp"

template<typename T = double>
class Plan
{
    private:
        // n = (a, b, c)
        // d = n*q
        // Equation : Ax+By+Cz = D
        T m_d{};
        Vector3<T> m_normal;    

    public:
        Plan(const Vector3<T>& normal, T d) : m_normal(normal), m_d(d) {}

        Plan(const Point3<T>& p1, const Point3D<T>& p2, const Point3D<T>& p3)
        {
            Vector3<T> v1(p1.x, p1.y, p1.z);
            Vector3<T> v21(p2.x - p1.x, p2.y - p1.y, p2.z - p1.z);
            Vector3<T> v31(p3.x - p1.x, p3.y - p1.y, p3.z - p1.z);

            m_normal = crossProduct(v21, v31);
            m_d = -dotProduct(m_normal, v1); // d = -dotP(n, p0)
        }

        Plan(const Vector3<T>& normal, const Vector3<T>& q) 
        {
            m_normal = normal;
            m_d = -dotProduct(normal, q);
        }
};


