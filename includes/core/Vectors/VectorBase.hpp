#pragma once
#include <array>
#include <cassert>
#include <type_traits>
#include <initializer_list>
#include <cmath>

template<typename TYPE = float, std::size_t SIZE = 2>
class VectorBase {
    
        static_assert(SIZE >= 2 && "Vector size must be at least 2");
        static_assert(std::is_arithmetic_v<TYPE> == true && "Vector TYPE must be arithmetic");

        std::array<TYPE, SIZE> m_data;

    public:
        // Constructor by default, set data to 0
        VectorBase() {
            m_data.fill({});
        }

        // Copy Constructor
        VectorBase(const VectorBase<TYPE, SIZE>& other) {
            m_data = other.m_data;
        }

        VectorBase(std::initializer_list<TYPE> list) {
            assert(list.size() == SIZE);

            std::copy(list.begin(), list.end(), m_data.begin());
        }

        VectorBase(std::array<TYPE, SIZE>& array) {
            assert(array.size() == SIZE);

            m_data = array;
        }

        const TYPE& operator[](std::size_t index) const {
            assert(index < SIZE);
            
            return m_data[index];
        }

        TYPE& operator[](std::size_t index) {
            assert(index < SIZE);

            return m_data[index];
        }

        VectorBase& operator=(const VectorBase<TYPE, SIZE>& other) {

            if(&other != this)
                m_data = other.m_data;

            return *this;
        }

        VectorBase& operator=(std::initializer_list<TYPE> list) {
            assert(list.size() == SIZE);

            std::copy(list.begin(), list.end(), m_data.begin());

            return *this;
        }

        template<typename Scalar>
        VectorBase operator*(const Scalar scalar) const {
            static_assert(std::is_arithmetic_v<Scalar> == true);

            std::array<TYPE, SIZE> tmp_data_mult;

            for (int i = 0; i < SIZE; i++) {
                tmp_data_mult[i] = scalar * m_data[i];
            }

            return VectorBase<TYPE, SIZE>(tmp_data_mult);
        }

        template<typename Scalar>
        friend VectorBase operator*(const Scalar scalar, const VectorBase<TYPE, SIZE>& other) {
            static_assert(std::is_arithmetic_v<Scalar> == true);

            std::array<TYPE, SIZE> tmp_data_mult;

            for (int i = 0; i < SIZE; i++) {
                tmp_data_mult[i] = scalar * other.m_data[i];
            }

            return VectorBase<TYPE, SIZE>(tmp_data_mult);
        }

        template<typename Scalar>
        VectorBase operator/(const Scalar scalar) const {
            static_assert(std::is_arithmetic_v<Scalar> == true);

            std::array<TYPE, SIZE> tmp_data_div;

            for (std::size_t i = 0; i < SIZE; i++) {
                tmp_data_div[i] = m_data[i] / scalar;
            }
            
            return VectorBase<TYPE, SIZE>(tmp_data_div);
        }

        template<typename otherType>
        VectorBase operator+(const VectorBase<otherType, SIZE>& other) const {
            static_assert(std::is_arithmetic_v<otherType> == true);

            using resultType = decltype(std::declval<otherType>() + std::declval<TYPE>());

            std::array<resultType, SIZE> tmp_data_sum;

            for(int i = 0; i < SIZE; i++) {
                tmp_data_sum[i] = m_data[i] + other.m_data[i];
            }

            return VectorBase<resultType, SIZE>(tmp_data_sum);
        }

        VectorBase operator-(const VectorBase<TYPE, SIZE>& other) const {
            static_assert(std::is_arithmetic_v<TYPE> == true);

            std::array<TYPE, SIZE> tmp_data_sub;

            for(int i = 0; i < SIZE; i++) {
                tmp_data_sub[i] = m_data[i] - other.m_data[i];
            }

            return VectorBase<TYPE, SIZE>(tmp_data_sub);
        }

        std::size_t size() const {
            return SIZE;
        }
};
