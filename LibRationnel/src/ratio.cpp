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
    Ratio ratio;
    ratio.m_num = (this->m_num*rn.m_den)+(this->m_den*rn.m_num);
    ratio.m_den = this->m_den*rn.m_den;
    return ratio;
}

Ratio operator-(const Ratio &rn) const {
    Ratio ratio;
    ratio.m_num = (this->m_num*rn.m_den)-(this->m_den*rn.m_num);
    ratio.m_den = this->m_den*rn.m_den;
    return ratio;
}

Ratio operator*(const Ratio &rn) const {
    Ratio ratio;
    ratio.m_num = (this->m_num*rn.m_num);
    ratio.m_den = (this->m_den*rn.m_den);
    return ratio;
}

Ratio inverse() const {
    Ratio ratio;
    ratio.m_num = this->m_den;
    ratio.m_den = this->m_num;
} 

Ratio operator/(const Ratio &rn) const {
    Ratio ratio;
    rn = rn.inverse();
    ratio.m_num = (this->m_num*rn.m_num);
    ratio.m_den = (this->m_den*rn.m_den);
    return ratio;
}

std::ostream &operator<<(std::ostream &stream, const Ratio<T> &rn) {
    //...
    return 42;
}