#include "../include/ratio.hpp"

// - - - - - O P E R A T O R S - - - - - -

template <typename T> constexpr Ratio<T> Ratio<T>::operator+(const Ratio &rn) const {
    Ratio ratio;
    ratio.m_num = this->m_num*rn.m_den + this->m_den*rn.m_num;
    ratio.m_den = this->m_den*rn.m_den;
    ratio = ratio.make_irreductible();
    return ratio;
}

template <typename T> constexpr Ratio<T> Ratio<T>::operator+(const T &real) const {
    Ratio ratio;
    Ratio ratio2 = convert_float_to_ratio<T>(real, 10);
    ratio.m_num = this->m_num*ratio2.num() + this->m_den*ratio2.num();
    ratio.m_den = this->m_den*ratio2.num();
    ratio = ratio.make_irreductible();
    return ratio;
}

template <typename T> constexpr Ratio<T> Ratio<T>::operator-(const Ratio &rn) const {
    Ratio ratio;
    ratio.m_num = this->m_num*rn.m_den - this->m_den*rn.m_num;
    ratio.m_den = this->m_den*rn.m_den;
    ratio = ratio.make_irreductible();
    return ratio;
}

template <typename T> constexpr Ratio<T> Ratio<T>::operator-(const T &real) const {
    Ratio ratio;
    Ratio ratio2 = convert_float_to_ratio<T>(real, 10);
    ratio.m_num = this->m_num*ratio2.den() - this->m_den*ratio2.num();
    ratio.m_den = this->m_den*ratio2.den();
    ratio = ratio.make_irreductible();
    return ratio;
}

template <typename T> constexpr Ratio<T> Ratio<T>::operator*(const Ratio &rn) const {
    Ratio ratio;
    ratio.m_num = (this->m_num*rn.m_num);
    ratio.m_den = (this->m_den*rn.m_den);
    ratio = ratio.make_irreductible();
    return ratio;
}

template <typename T> constexpr Ratio<T> Ratio<T>::operator*(const T &real) const {
    Ratio ratio;
    Ratio ratio2 = convert_float_to_ratio<T>(real, 10);
    ratio.m_num = this->m_num * ratio2.m_num;
    ratio.m_den = this->m_den * ratio2.m_den;
    ratio = ratio.make_irreductible();
    return ratio;
}

template <typename T> constexpr Ratio<T> Ratio<T>::operator/(const Ratio &rn) const {
    Ratio ratio;
    ratio.m_num = this->m_num * rn.inverse().m_num;
    ratio.m_den = this->m_den * rn.inverse().m_den;
    ratio = ratio.make_irreductible();
    return ratio;
}

/*template <typename T> constexpr Ratio<T> Ratio<T>::operator/(const T &real) const {
    Ratio ratio;
    Ratio ratio2 = convert_float_to_ratio<T>(real, 10);
    ratio.m_num = this->m_num * ratio2.inverse().m_num;
    ratio.m_den = this->m_den * ratio2.inverse().m_den;
    ratio = ratio.make_irreductible();
    return ratio;
}*/

template <typename T> constexpr Ratio<T> Ratio<T>::operator++() {
    Ratio ratio;
    ratio.m_num = this->m_num + this->m_den;
    ratio.m_den = this->m_den;
    ratio = ratio.make_irreductible();
    return ratio;
}

template <typename T> constexpr Ratio<T> Ratio<T>::operator--() {
    Ratio ratio;
    ratio.m_num = this->m_num - this->m_den;
    ratio.m_den = this->m_den;
    ratio = ratio.make_irreductible();
    return ratio;
}

template <typename T> constexpr Ratio<T> Ratio<T>::operator++(int one) {
    Ratio ratio;
    ratio.m_num = this->m_num + this->m_den;
    ratio.m_den = this->m_den;
    ratio = ratio.make_irreductible();
    return ratio;
}

template <typename T> constexpr Ratio<T> Ratio<T>::operator--(int one) {
    Ratio ratio;
    ratio.m_num = this->m_num - this->m_den;
    ratio.m_den = this->m_den;
    ratio = ratio.make_irreductible();
    return ratio;
}

template <typename T> constexpr Ratio<T> Ratio<T>::operator-() {
    Ratio ratio;
    ratio.m_num = -this->m_num;
    ratio.m_den = this->m_den;
    ratio = ratio.make_irreductible();
    return ratio;
}

template class Ratio<long long>;
template class Ratio<long>;
template class Ratio<int>;