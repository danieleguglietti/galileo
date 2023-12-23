#ifndef GALILEO_CONCEPTS_H
#define GALILEO_CONCEPTS_H

#include <concepts>
#include <type_traits>

namespace galileo {
    template <typename T>
    concept arithmetic = std::is_arithmetic_v<T>;
}

#endif //GALILEO_CONCEPTS_H
