#pragma once
#include <cmath>
#include "../core/Vectors/Vector2.hpp"
#include "../core/Vectors/Vector3.hpp"

template<typename T, std::size_t N>
T norm(const VectorBase<T, N>& v) {
    T result{};

    for(std::size_t i = 0; i < v.size(); i++) {
        result += v[i] * v[i];
    }

    return std::sqrt(result);
}

template<typename T, std::size_t N>
T dotProduct(const VectorBase<T, N>& v, const VectorBase<T, N>& w) {
    T result{};

    for(std::size_t i = 0; i < N; i++) {
        result += v[i] * w[i];
    }

    return result;
}

template<typename T, std::size_t N>
inline bool isPerpendicular(const VectorBase<T, N>& v, const VectorBase<T, N>& w) {
    return (dotProduct(v, w) == 0) ? true : false;
}

template<typename T, std::size_t N>
VectorBase<T, N> normalize(const VectorBase<T, N>& v) {
    T magnitude = norm(v);

    assert(magnitude > 0 && "Cannot normalize a zero-length vector");

    return v/magnitude;
}

/// @brief It's a crossproduct between two vector
/// @return The area of a non-absolute parallelogram
template<typename T>
T determinant(const Vector2<T>& v, const Vector2<T>& w) {
    T result = v.X() * w.Y() - v.Y() * w.X();

    return result;
}

template<typename T>
Vector3<T> crossProduct(const Vector3<T>& v, const Vector3<T>& w) {
    T x = (v.Y() * w.Z()) - (v.Z() * w.Y());
    T y = (v.Z() * w.X()) - (v.X() * w.Z());
    T z = (v.X() * w.Y()) - (v.Y() * w.X());

    return Vector3<T>(x, y, x);
}