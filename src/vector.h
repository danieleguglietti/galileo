#ifndef VECTOR_H
#define VECTOR_H

#pragma once

#include "utils.h"

GALILEO_BEGIN
    template<concepts::arithmetic T, size_t N>
    struct vector {
    };

    // Int Vectors
    using vec2i = vector<int, 2>;
    using vec3i = vector<int, 3>;
    using vec4i = vector<int, 4>;

    // Float Vectors
    using vec2f = vector<float, 2>;
    using vec3f = vector<float, 3>;
    using vec4f = vector<float, 4>;

    // Double Vectors
    using vec2d = vector<double, 2>;
    using vec3d = vector<double, 3>;
    using vec4d = vector<double, 4>;

    //
    // STRUCT SPECIALIZATIONS
    //

    template<concepts::arithmetic T>
    struct vector<T, 2> {
    public:
        using value_type = T;
        using vec = vector;

        using ref = T &;
        using cref = T const &;
        using ptr = T *;

    public:
        T x;
        T y;

        explicit vector(): x{0}, y{0} {
        }

        vector(value_type x, value_type y): x{x}, y{y} {
        }

        // Copy constructor
        vector(vec const &rhs): x{rhs.x}, y{rhs.y} {
        }

        // Move constructor
        vector(vec &&rhs) noexcept: x{std::move(rhs.x)}, y{std::move(rhs.y)} {
        }

        // Copy assignment
        vec &operator=(vec const &rhs) {
            x = rhs.x;
            y = rhs.y;

            return *this;
        }

        // Move assignment
        vec &operator=(vec &&rhs) noexcept {
            x = std::move(rhs.x);
            y = std::move(rhs.y);

            return *this;
        }

        // Vector Algebra
        vec &operator+=(vec const &rhs) {
            x += rhs.x;
            y += rhs.y;

            return *this;
        }

        vec &operator-=(vec const &rhs) {
            x -= rhs.x;
            y -= rhs.y;

            return *this;
        }

        vec &operator*=(value_type rhs) {
            x *= rhs;
            y *= rhs;

            return *this;
        }

        vec &operator/=(value_type rhs) {
            x /= rhs;
            y /= rhs;

            return *this;
        }

        vec &operator+(vec const &rhs) const {
            return vec{x + rhs.x, y + rhs.y};
        }

        vec &operator-(vec const &rhs) const {
            return vec{x - rhs.x, y - rhs.y};
        }

        vec &operator*(value_type rhs) const {
            return vec{x * rhs, y * rhs};
        }

        vec &operator/(value_type rhs) const {
            return vec{x / rhs, y / rhs};
        }

        value_type operator*(vec const &rhs) const {
            return x * rhs.x + y * rhs.y;
        }

        // Magnitude
        _NODISCARD double magnitude() const {
            return std::sqrt(x * x + y * y);
        }

        // Casting
        explicit operator Vector2() const {
            return Vector2{static_cast<float>(x), static_cast<float>(y)};
        }
    };

    template<concepts::arithmetic T>
    struct vector<T, 3> {
    public:
        using value_type = T;
        using vec = vector;

        using ref = T &;
        using cref = T const &;
        using ptr = T *;

    public:
        T x;
        T y;
        T z;

        explicit vector(): x{0}, y{0}, z{0} {
        }

        vector(value_type x, value_type y, value_type z): x{x}, y{y}, z{z} {
        }

        // Copy constructor
        vector(vec const &rhs): x{rhs.x}, y{rhs.y}, z{rhs.z} {
        }

        // Move constructor
        vector(vec &&rhs) noexcept: x{std::move(x)}, y{std::move(y)}, z{std::move(z)} {
        }

        // Copy assignment
        vec &operator=(vec const &rhs) {
            x = rhs.x;
            y = rhs.y;
            z = rhs.z;

            return *this;
        }

        // Move assignment
        vec &operator=(vec &&rhs) noexcept {
            x = std::move(rhs.x);
            y = std::move(rhs.y);
            z = std::move(rhs.z);

            return *this;
        }

        // Vector Algebra
        vec &operator+=(vec const &rhs) {
            x += rhs.x;
            y += rhs.y;
            z += rhs.z;

            return *this;
        }

        vec &operator+(vec const &rhs) const {
            return vec(x + rhs.x, y + rhs.y, z + rhs.z);
        }

        vec &operator-=(vec const &rhs) {
            x -= rhs.x;
            y -= rhs.y;
            z -= rhs.z;

            return *this;
        }

        vec &operator-(vec const &rhs) const {
            return vec(x - rhs.x, y - rhs.y, z - rhs.z);
        }

        vec &operator*=(value_type rhs) {
            x *= rhs;
            y *= rhs;
            z *= rhs;

            return *this;
        }

        vec &operator*(value_type rhs) const {
            return vec(x * rhs, y * rhs, z * rhs);
        }

        vec &operator/=(value_type rhs) {
            x /= rhs;
            y /= rhs;
            z /= rhs;

            return *this;
        }

        vec &operator/(value_type rhs) const {
            return vec(x / rhs, y / rhs, z / rhs);
        }

        value_type operator*(vec const &rhs) const {
            return x * rhs.x + y * rhs.y + z * rhs.z;
        }

        // Magnitude
        _NODISCARD double magnitude() const {
            return std::sqrt(x * x + y * y + z * z);
        }

        // Casting
        explicit operator Vector3() const {
            return Vector3{static_cast<float>(x), static_cast<float>(y), static_cast<float>(z)};
        }
    };

    template<concepts::arithmetic T>
    struct vector<T, 4> {
    public:
        using value_type = T;
        using vec = vector;

        using ref = T &;
        using cref = T const &;
        using ptr = T *;

    public:
        T x;
        T y;
        T z;
        T w;

        explicit vector(): x{0}, y{0}, z{0}, w{0} {
        }

        vector(value_type x, value_type y, value_type z, value_type w): x{x}, y{y}, z{z}, w{w} {
        }

        // Copy constructor
        vector(vec const &rhs): x{rhs.x}, y{rhs.y}, z{rhs.z}, w{rhs.w} {
        }

        // Move constructor
        vector(vec &&rhs) noexcept: x{std::move(x)}, y{std::move(y)}, z{std::move(z)}, w{std::move(w)} {
        }

        // Copy assignment
        vec &operator=(vec const &rhs) {
            x = rhs.x;
            y = rhs.y;
            z = rhs.z;
            w = rhs.w;

            return *this;
        }

        // Move assignment
        vec &operator=(vec &&rhs) noexcept {
            x = std::move(rhs.x);
            y = std::move(rhs.y);
            z = std::move(rhs.z);
            w = std::move(rhs.w);

            return *this;
        }

        // Vector Algebra
        vec &operator+=(vec const &rhs) {
            x += rhs.x;
            y += rhs.y;
            z += rhs.z;
            w += rhs.w;

            return *this;
        }

        vec &operator+(vec const &rhs) const {
            return vec(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w);
        }

        vec &operator-=(vec const &rhs) {
            x -= rhs.x;
            y -= rhs.y;
            z -= rhs.z;
            w -= rhs.w;

            return *this;
        }

        vec &operator-(vec const &rhs) const {
            return vec(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w);
        }

        vec &operator*=(value_type rhs) {
            x *= rhs;
            y *= rhs;
            z *= rhs;
            w *= rhs;

            return *this;
        }

        vec &operator*(value_type rhs) const {
            return vec(x * rhs, y * rhs, z * rhs, w * rhs);
        }

        vec &operator/=(value_type rhs) {
            x /= rhs;
            y /= rhs;
            z /= rhs;
            w /= rhs;

            return *this;
        }

        vec &operator/(value_type rhs) const {
            return vec(x / rhs, y / rhs, z / rhs, w / rhs);
        }

        value_type operator*(vec const &rhs) const {
            return x * rhs.x + y * rhs.y + z * rhs.z + w * rhs.w;
        }

        // Magnitude
        _NODISCARD double magnitude() const {
            return std::sqrt(x * x + y * y + z * z + w * w);
        }

        // Casting
        explicit operator Vector4() const {
            return Vector4{static_cast<float>(x), static_cast<float>(y), static_cast<float>(z), static_cast<float>(w)};
        }
    };

    //
    // Cross Product
    //

    template<concepts::arithmetic T>
    vector<T, 3> operator^(vector<T, 3> const &v, vector<T, 3> const &w) {
        return vector<T, 3>(
            v.y * w.z - v.z * w.y,
            v.z * w.x - v.x * w.z,
            v.x * w.y - v.y * w.x
        );
    }

    template<concepts::arithmetic T>
    vector<T, 3> operator^(vector<T, 2> const &v, vector<T, 2> const &w) {
        return vector<T, 3>(
            0,
            0,
            v.x * w.y - v.y * w.x
        );
    }

    template<concepts::arithmetic T>
    vector<T, 3> operator^(vector<T, 3> const &v, vector<T, 2> const &w) {
        return vector<T, 3>(
            0,
            0,
            v.x * w.y - v.y * w.x
        );
    }

    template<concepts::arithmetic T>
    vector<T, 3> operator^(vector<T, 2> const &v, vector<T, 3> const &w) {
        return vector<T, 3>(
            0,
            0,
            v.x * w.y - v.y * w.x
        );
    }

GALILEO_END

#endif //VECTOR_H
