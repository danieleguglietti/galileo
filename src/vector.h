#ifndef GALILEO_VECTOR_H
#define GALILEO_VECTOR_H

#include "concepts.h"

namespace galileo {
    using galileo::arithmetic;

    template<size_t N, arithmetic T>
    struct vector;

    using vec2i = vector<2, int>;
    using vec3i = vector<3, int>;
    using vec4i = vector<4, int>;

    using vec2f = vector<2, float>;
    using vec3f = vector<3, float>;
    using vec4f = vector<4, float>;

    using vec2d = vector<2, double>;
    using vec3d = vector<3, double>;
    using vec4d = vector<4, double>;

    template<arithmetic T>
    struct vector<2, T> {
    public:
        using value_type = T;
        using size_type = size_t;
        using reference = value_type &;
        using const_reference = const value_type &;
        using vec = vector<2, value_type>;
        using vec_reference = vec &;
        using vec_const_reference = const vec &;
    public:
        value_type x;
        value_type y;

        const size_type size = 2;
    public:
        explicit vector() = default;

        explicit vector(const_reference xy) :
                x{xy}, y{xy} {}

        explicit vector(const_reference x, const_reference y) :
                x{x}, y{y} {}

        // Copy Semantics
        vector(vec_reference rhs) {
            x = rhs.x;
            y = rhs.y;
        };

        vec_reference operator=(vec_const_reference rhs) {
            x = rhs.x;
            y = rhs.y;

            return *this;
        };

        // Move Semantics
        vector(vec &&rhs) noexcept {
            x = std::move(rhs.x);
            y = std::move(rhs.y);
        };

        vec_reference operator=(vec &&rhs) noexcept {
            x = std::move(rhs.x);
            y = std::move(rhs.y);

            return *this;
        };

        // Vector Operations
        vec_reference operator+=(vec_const_reference rhs) {
            x += rhs.x;
            y += rhs.y;

            return *this;
        }

        vec_reference operator-=(vec_const_reference rhs) {
            x -= rhs.x;
            y -= rhs.y;

            return *this;
        }

        vec_reference operator*=(const_reference scalar) {
            x *= scalar;
            y *= scalar;

            return *this;
        }

        vec_reference operator/(const_reference scalar) {
            x /= scalar;
            y /= scalar;

            return *this;
        }

        _NODISCARD _CONSTEXPR20 vec operator-() const {
            return vec{-x, -y};
        }

        _NODISCARD _CONSTEXPR20 vec operator+() const {
            return vec{x, y};
        }

        _NODISCARD _CONSTEXPR20 vec operator+(vec_const_reference rhs) const {
            return vec{x + rhs.x, y + rhs.y};
        }

        _NODISCARD _CONSTEXPR20 vec operator-(vec_const_reference rhs) const {
            return vec{x - rhs.x, y - rhs.y};
        }

        _NODISCARD _CONSTEXPR20 vec operator*(const_reference scalar) const {
            return vec{x * scalar, y * scalar};
        }

        _NODISCARD _CONSTEXPR20 vec operator/(const_reference scalar) const {
            return vec{x / scalar, y / scalar};
        }

        _NODISCARD _CONSTEXPR20 value_type operator*(vec_const_reference rhs) const {
            return x * rhs.x + y * rhs.y;
        }

        _NODISCARD _CONSTEXPR20 double magnitude() const {
            return std::sqrt(x * x + y * y);
        }

        _NODISCARD _CONSTEXPR20 vec normalize() const {
            return *this / magnitude();
        }

        // Cast Overload
        explicit operator Vector2() const {
            return Vector2{static_cast<float>(x), static_cast<float>(y)};
        }

        explicit operator Vector3() const {
            return Vector3{static_cast<float>(x), static_cast<float>(y), 0};
        }

        explicit operator Vector4() const {
            return Vector4{static_cast<float>(x), static_cast<float>(y), 0, 0};
        }
    };

    template<arithmetic T>
    struct vector<3, T> {
    public:
        using value_type = T;
        using size_type = size_t;
        using reference = value_type &;
        using const_reference = const value_type &;
        using vec = vector<3, value_type>;
        using vec_reference = vec &;
        using vec_const_reference = const vec &;
    public:
        value_type x;
        value_type y;
        value_type z;

        const size_type size = 3;
    public:
        explicit vector() = default;

        explicit vector(const_reference xyz) :
                x{xyz}, y{xyz}, z{xyz} {}

        explicit vector(const_reference x, const_reference y, const_reference z) :
                x{x}, y{y}, z{z} {}

        // Copy Semantics
        vector(vec_reference rhs) {
            x = rhs.x;
            y = rhs.y;
            z = rhs.z;
        };

        vec_reference operator=(vec_const_reference rhs) {
            x = rhs.x;
            y = rhs.y;
            z = rhs.z;

            return *this;
        };

        // Move Semantics
        vector(vec &&rhs) noexcept {
            x = std::move(rhs.x);
            y = std::move(rhs.y);
            z = std::move(rhs.z);
        };

        vec_reference operator=(vec &&rhs) noexcept {
            x = std::move(rhs.x);
            y = std::move(rhs.y);
            z = std::move(rhs.z);

            return *this;
        };

        // Vector Operations
        vec_reference operator+=(vec_const_reference rhs) {
            x += rhs.x;
            y += rhs.y;
            z += rhs.z;

            return *this;
        }

        vec_reference operator-=(vec_const_reference rhs) {
            x -= rhs.x;
            y -= rhs.y;
            z -= rhs.z;

            return *this;
        }

        vec_reference operator*=(const_reference scalar) {
            x *= scalar;
            y *= scalar;
            z *= scalar;

            return *this;
        }

        vec_reference operator/(const_reference scalar) {
            x /= scalar;
            y /= scalar;
            z /= scalar;

            return *this;
        }

        _NODISCARD _CONSTEXPR20 vec operator-() const {
            return vec{-x, -y, -z};
        }

        _NODISCARD _CONSTEXPR20 vec operator+() const {
            return vec{x, y, z};
        }

        _NODISCARD _CONSTEXPR20 vec operator+(vec_const_reference rhs) const {
            return vec{x + rhs.x, y + rhs.y, z + rhs.z};
        }

        _NODISCARD _CONSTEXPR20 vec operator-(vec_const_reference rhs) const {
            return vec{x - rhs.x, y - rhs.y, z - rhs.z};
        }

        _NODISCARD _CONSTEXPR20 vec operator*(const_reference scalar) const {
            return vec{x * scalar, y * scalar, z * scalar};
        }

        _NODISCARD _CONSTEXPR20 vec operator/(const_reference scalar) const {
            return vec{x / scalar, y / scalar, z / scalar};
        }

        _NODISCARD _CONSTEXPR20 value_type operator*(vec_const_reference rhs) const {
            return x * rhs.x + y * rhs.y + z * rhs.z;
        }

        _NODISCARD _CONSTEXPR20 double magnitude() const {
            return std::sqrt(x * x + y * y + z * z);
        }

        _NODISCARD _CONSTEXPR20 vec normalize() const {
            return *this / magnitude();
        }

        // Cast Overload
        explicit operator Vector2() const {
            return Vector2{static_cast<float>(x), static_cast<float>(y)};
        }

        explicit operator Vector3() const {
            return Vector3{static_cast<float>(x), static_cast<float>(y), static_cast<float>(z)};
        }

        explicit operator Vector4() const {
            return Vector4{static_cast<float>(x), static_cast<float>(y), static_cast<float>(y), 0};
        }
    };

    template<arithmetic T>
    struct vector<4, T> {
    public:
        using value_type = T;
        using size_type = size_t;
        using reference = value_type &;
        using const_reference = const value_type &;
        using vec = vector<4, value_type>;
        using vec_reference = vec &;
        using vec_const_reference = const vec &;
    public:
        value_type x;
        value_type y;
        value_type z;
        value_type w;

        const size_type size = 4;
    public:
        explicit vector() = default;

        explicit vector(const_reference xyzw) :
                x{xyzw}, y{xyzw}, z{xyzw} {}

        explicit vector(const_reference x, const_reference y, const_reference z, const_reference w) :
                x{x}, y{y}, z{z}, w{w} {}

        // Copy Semantics
        vector(vec_reference rhs) {
            x = rhs.x;
            y = rhs.y;
            z = rhs.z;
            w = rhs.w;
        };

        vec_reference operator=(vec_const_reference rhs) {
            x = rhs.x;
            y = rhs.y;
            z = rhs.z;
            w = rhs.w;

            return *this;
        };

        // Move Semantics
        vector(vec &&rhs) noexcept {
            x = std::move(rhs.x);
            y = std::move(rhs.y);
            z = std::move(rhs.z);
            w = std::move(rhs.w);
        };

        vec_reference operator=(vec &&rhs) noexcept {
            x = std::move(rhs.x);
            y = std::move(rhs.y);
            z = std::move(rhs.z);
            w = std::move(rhs.w);

            return *this;
        };

        // Vector Operations
        vec_reference operator+=(vec_const_reference rhs) {
            x += rhs.x;
            y += rhs.y;
            z += rhs.z;
            w += rhs.w;

            return *this;
        }

        vec_reference operator-=(vec_const_reference rhs) {
            x -= rhs.x;
            y -= rhs.y;
            z -= rhs.z;
            w -= rhs.w;

            return *this;
        }

        vec_reference operator*=(const_reference scalar) {
            x *= scalar;
            y *= scalar;
            z *= scalar;
            w *= scalar;

            return *this;
        }

        vec_reference operator/(const_reference scalar) {
            x /= scalar;
            y /= scalar;
            z /= scalar;
            w /= scalar;

            return *this;
        }

        _NODISCARD _CONSTEXPR20 vec operator-() const {
            return vec{-x, -y, -z, -w};
        }

        _NODISCARD _CONSTEXPR20 vec operator+() const {
            return vec{x, y, z, w};
        }

        _NODISCARD _CONSTEXPR20 vec operator+(vec_const_reference rhs) const {
            return vec{x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w};
        }

        _NODISCARD _CONSTEXPR20 vec operator-(vec_const_reference rhs) const {
            return vec{x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w};
        }

        _NODISCARD _CONSTEXPR20 vec operator*(const_reference scalar) const {
            return vec{x * scalar, y * scalar, z * scalar, w * scalar};
        }

        _NODISCARD _CONSTEXPR20 vec operator/(const_reference scalar) const {
            return vec{x / scalar, y / scalar, z / scalar, w / scalar};
        }

        _NODISCARD _CONSTEXPR20 value_type operator*(vec_const_reference rhs) const {
            return x * rhs.x + y * rhs.y + z * rhs.z + w * rhs.w;
        }

        _NODISCARD _CONSTEXPR20 double magnitude() const {
            return std::sqrt(x * x + y * y + z * z + w * w);
        }

        _NODISCARD _CONSTEXPR20 vec normalize() const {
            return *this / magnitude();
        }

        // Cast Overload
        explicit operator Vector2() const {
            return Vector2{static_cast<float>(x), static_cast<float>(y)};
        }

        explicit operator Vector3() const {
            return Vector3{static_cast<float>(x), static_cast<float>(y), static_cast<float>(z)};
        }

        explicit operator Vector4() const {
            return Vector4{static_cast<float>(x), static_cast<float>(y), static_cast<float>(y), static_cast<float>(w)};
        }
    };

    // Mixed Operator Overload
    template<arithmetic T>
    _NODISCARD _CONSTEXPR20 vector<3, T> operator+(const vector<3, T> &lhs, const vector<2, T> &rhs) {
        return vector<3, T>{lhs.x + rhs.x, lhs.y + rhs.y, lhs.z};
    }

    template<arithmetic T>
    _NODISCARD _CONSTEXPR20 vector<3, T> operator+(const vector<2, T> &lhs, const vector<3, T> &rhs) {
        return vector<3, T>{rhs.x + lhs.x, rhs.y + lhs.y, rhs.z};
    }

    template<arithmetic T>
    _NODISCARD _CONSTEXPR20 vector<4, T> operator+(const vector<3, T> &lhs, const vector<4, T> &rhs) {
        return vector<3, T>{lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, rhs.w};
    }

    template<arithmetic T>
    _NODISCARD _CONSTEXPR20 vector<4, T> operator+(const vector<4, T> &lhs, const vector<3, T> &rhs) {
        return vector<3, T>{rhs.x + lhs.x, rhs.y + lhs.y, rhs.z + rhs.z, lhs.w};
    }

    template<arithmetic T>
    _NODISCARD _CONSTEXPR20 vector<4, T> operator+(const vector<2, T> &lhs, const vector<4, T> &rhs) {
        return vector<3, T>{lhs.x + rhs.x, lhs.y + rhs.y, rhs.z, rhs.w};
    }

    template<arithmetic T>
    _NODISCARD _CONSTEXPR20 vector<4, T> operator+(const vector<4, T> &lhs, const vector<2, T> &rhs) {
        return vector<3, T>{rhs.x + lhs.x, rhs.y + lhs.y, lhs.z, lhs.w};
    }

    template<arithmetic T>
    _NODISCARD _CONSTEXPR20 vector<3, T> operator-(const vector<3, T> &lhs, const vector<2, T> &rhs) {
        return vector<3, T>{lhs.x + rhs.x, lhs.y + rhs.y, lhs.z};
    }

    template<arithmetic T>
    _NODISCARD _CONSTEXPR20 vector<3, T> operator-(const vector<2, T> &lhs, const vector<3, T> &rhs) {
        return vector<3, T>{rhs.x - lhs.x, rhs.y - lhs.y, -rhs.z};
    }

    template<arithmetic T>
    _NODISCARD _CONSTEXPR20 vector<4, T> operator-(const vector<3, T> &lhs, const vector<4, T> &rhs) {
        return vector<3, T>{lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, -rhs.w};
    }

    template<arithmetic T>
    _NODISCARD _CONSTEXPR20 vector<4, T> operator-(const vector<4, T> &lhs, const vector<3, T> &rhs) {
        return vector<3, T>{rhs.x - lhs.x, rhs.y - lhs.y, rhs.z - rhs.z, lhs.w};
    }

    template<arithmetic T>
    _NODISCARD _CONSTEXPR20 vector<4, T> operator-(const vector<2, T> &lhs, const vector<4, T> &rhs) {
        return vector<3, T>{lhs.x - rhs.x, lhs.y - rhs.y, -rhs.z, -rhs.w};
    }

    template<arithmetic T>
    _NODISCARD _CONSTEXPR20 vector<4, T> operator-(const vector<4, T> &lhs, const vector<2, T> &rhs) {
        return vector<3, T>{rhs.x - lhs.x, rhs.y - lhs.y, lhs.z, lhs.w};
    }

    template<arithmetic T>
    _NODISCARD _CONSTEXPR20 T operator*(const vector<3, T> &lhs, const vector<2, T> &rhs) {
        return lhs.x * rhs.x + lhs.y * rhs.y;
    }

    template<arithmetic T>
    _NODISCARD _CONSTEXPR20 T operator*(const vector<2, T> &lhs, const vector<3, T> &rhs) {
        return lhs.x * rhs.x + lhs.y * rhs.y;
    }

    template<arithmetic T>
    _NODISCARD _CONSTEXPR20 T operator*(const vector<3, T> &lhs, const vector<4, T> &rhs) {
        return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
    }

    template<arithmetic T>
    _NODISCARD _CONSTEXPR20 T operator*(const vector<4, T> &lhs, const vector<3, T> &rhs) {
        return rhs.x * lhs.x + rhs.y * lhs.y + rhs.z * rhs.z;
    }

    template<arithmetic T>
    _NODISCARD _CONSTEXPR20 T operator*(const vector<2, T> &lhs, const vector<4, T> &rhs) {
        return lhs.x * rhs.x + lhs.y * rhs.y;
    }

    template<arithmetic T>
    _NODISCARD _CONSTEXPR20 T operator*(const vector<4, T> &lhs, const vector<2, T> &rhs) {
        return rhs.x * lhs.x + rhs.y * lhs.y;
    }

    // To String Functions

    template<arithmetic T>
    inline std::ostream &operator<<(std::ostream &os, const vector<2, T> &v) {
        os << std::format("{0}", v);
        return os;
    }

    template<arithmetic T>
    struct std::formatter<galileo::vector<2, T>> : std::formatter<std::string_view> {

        auto format(const galileo::vector<2, T> &v, std::format_context &ctx) const {
            return std::formatter<std::string_view>::format(
                    std::format("vec2({0}, {1})", v.x, v.y),
                    ctx
            );
        }
    };

    template<arithmetic T>
    inline std::ostream &operator<<(std::ostream &os, const vector<3, T> &v) {
        os << std::format("{0}", v);
        return os;
    }

    template<arithmetic T>
    struct std::formatter<galileo::vector<3, T>> : std::formatter<std::string_view> {

        auto format(const galileo::vector<3, T> &v, std::format_context &ctx) const {
            return std::formatter<std::string_view>::format(
                    std::format("vec3({0}, {1}, {2})", v.x, v.y, v.z),
                    ctx
            );
        }
    };

    template<arithmetic T>
    inline std::ostream &operator<<(std::ostream &os, const vector<4, T> &v) {
        os << std::format("{0}", v);
        return os;
    }

    template<arithmetic T>
    struct std::formatter<galileo::vector<4, T>> : std::formatter<std::string_view> {

        auto format(const galileo::vector<4, T> &v, std::format_context &ctx) const {
            return std::formatter<std::string_view>::format(
                    std::format("vec3({0}, {1}, {2}, {3})", v.x, v.y, v.z, v.w),
                    ctx
            );
        }
    };
}

#endif //GALILEO_VECTOR_H
