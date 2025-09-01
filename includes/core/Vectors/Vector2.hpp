#pragma once
#include "VectorBase.hpp"

template<typename T = double>
class Vector2 : public VectorBase<T, 2>
{
    public:
        using VectorBase<T, 2>::operator+;
        using VectorBase<T, 2>::operator-;
        using VectorBase<T, 2>::operator*;
        using VectorBase<T, 2>::operator[];
        using VectorBase<T, 2>::operator=;

        Vector2() : VectorBase<T, 2>() {}

        Vector2(T x, T y) : VectorBase<T, 2>() {
            (*this)[0] = x;
            (*this)[1] = y;
        }

        Vector2(const VectorBase<T, 2>& other) : VectorBase<T, 2>(other) {}

        Vector2(std::initializer_list<T> list) : VectorBase<T, 2>(list) {}

        Vector2(std::array<T, 2>& array) : VectorBase<T, 2>(array) {}
        
        const T& X() const {
            return (*this)[0];
        }

        const T& Y() const {
            return (*this)[1];
        }

        T& X() {
            return (*this)[0];
        }

        T& Y() {
            return (*this)[1];
        }
};

