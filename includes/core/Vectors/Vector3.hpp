#pragma once
#include "VectorBase.hpp"

template<typename T = double>
class Vector3 : public VectorBase<T, 3>
{
    public:
        //using Vector<Type, 3>::Vector; // Import all constructor from Vector
        using VectorBase<T, 3>::operator[];
        using VectorBase<T, 3>::operator+;
        using VectorBase<T, 3>::operator-;
        using VectorBase<T, 3>::operator=;
        using VectorBase<T, 3>::operator*;

        Vector3() : VectorBase<T, 3>() {}

        Vector3(T x, T y, T z) : VectorBase<T, 3>() {
            (*this)[0] = x;
            (*this)[1] = y;
            (*this)[2] = z;
        }

        Vector3(const VectorBase<T, 3>& other) : VectorBase<T, 3>(other) {}

        Vector3(std::initializer_list<T> list) : VectorBase<T, 3>(list) {}

        Vector3(std::array<T, 3>& array) : VectorBase<T, 3>(array) {}

        T& X() {
            return (*this)[0];
        }

        T& Y() {
            return (*this)[1];
        }

        T& Z() {
            return (*this)[2];
        }

        const T& X() const {
            return (*this)[0];
        }

        const T& Y() const {
            return (*this)[1];
        }

        const T& Z() const {
            return (*this)[2];
        }
};
