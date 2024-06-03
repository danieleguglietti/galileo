#ifndef GALILEO_UTILS_H
#define GALILEO_UTILS_H

#pragma once

#include <concepts>
#include <type_traits>

// Namespace Declaration
#define GALILEO_BEGIN namespace galileo {
#define GALILEO_END }

// Utility macro
#define INLINE inline

GALILEO_BEGIN

// Concepts
namespace concepts {
    template<typename T>
    concept arithmetic = std::is_arithmetic_v<T>;

    template<size_t N>
    constexpr bool two_dimesional = (N == 2);

    template<size_t N>
    constexpr bool three_dimensional = (N == 3);

    template<size_t N>
    concept real_object = three_dimensional<N> || two_dimesional<N>;
}

GALILEO_END


#endif //GALILEO_UTILS_H
