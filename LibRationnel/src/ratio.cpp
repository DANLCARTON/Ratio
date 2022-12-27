#include "../include/ratio.hpp"
#include <iostream>

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
    return ratio;
} 

template <typename T> Ratio<T> Ratio<T>::operator/(const Ratio &rn) const {
    Ratio ratio;
    ratio.m_num = this->m_num * rn.inverse().m_num;
    ratio.m_den = this->m_den * rn.inverse().m_den;
}