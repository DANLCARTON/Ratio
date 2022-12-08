#include "../include/ratio.hpp"

Ratio::Ratio() {
    this->n_num = 0;
    this->m_den = 1;
}

Ratio::Ratio(const T &num, const T &den) {
    this->n_num = num;
    this->n_den = den;
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

std::ostream &operator<<(std::ostream &stream, const Ratio<T> &rn) {
    //...
    return 42;
}