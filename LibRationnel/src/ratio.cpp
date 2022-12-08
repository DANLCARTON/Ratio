#include "./include/ratio.hpp"

Ratio::Ratio() {
    n_num = 0;
    m_den = 1;
}

Ratio::Ratio(const T &den, const T &num) {
    n_num = num;
    n_den = den;
}

Ratio convert_float_to_ratio(const T &real) {
    //...
    return 42;
}

Ratio operator+(const Ratio &rn) const {
    //...
    return 42;
}

Ratio operator-(const Ratio &rn) const {
    //...
    return 42;
}

Ratio operator*(const Ratio &rn) const {
    //...
    return 42;
}

Ratio inverse() const {
    //...
    return 42;
} 

Ratio operator/(const Ratio &rn) const {
    //...
    return 42;
}

Ratio operator++() {
    //...
    return 42;
}

Ratio operator--() {
    //...
    return 42;
}