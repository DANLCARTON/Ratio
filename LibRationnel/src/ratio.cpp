#include "../include/ratio.hpp"
#include <iostream>

template <typename T> Ratio<T>::Ratio() {
    this->n_num = 0;
    this->m_den = 1;
}

template <typename T> Ratio<T>::Ratio(const T &num, const T &den) {
    this->n_num = num;
    this->n_den = den;
}

template <typename T> Ratio<T> convert_float_to_ratio(const T &real) {
    //...
    return 42;
}

template <typename T> Ratio<T> Ratio<T>::operator+(const Ratio &rn) const {
    Ratio ratio;
    ratio.m_num = (this->m_num*rn.m_den)+(this->m_den*rn.m_num);
    ratio.m_den = this->m_den*rn.m_den;
    return ratio;
}

template <typename T> Ratio<T> Ratio<T>::operator-(const Ratio &rn) const {
    Ratio ratio;
    ratio.m_num = (this->m_num*rn.m_den)-(this->m_den*rn.m_num);
    ratio.m_den = this->m_den*rn.m_den;
    return ratio;
}

template <typename T> Ratio<T> Ratio<T>::operator*(const Ratio &rn) const {
    Ratio ratio;
    ratio.m_num = (this->m_num*rn.m_num);
    ratio.m_den = (this->m_den*rn.m_den);
    return ratio;
}

template <typename T> Ratio<T> Ratio<T>::inverse() const {
    Ratio ratio;
    ratio.m_num = this->m_den;
    ratio.m_den = this->m_num;
} 

template <typename T> std::ostream &operator<<(std::ostream &stream, const Ratio<T> &rn) {
    stream << rn.m_num << "/" << rn.m_den;
    return stream;
}