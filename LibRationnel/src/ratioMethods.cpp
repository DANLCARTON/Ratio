#include "../include/ratio.hpp"

// - - - M E T H O D S - - -

template <typename T> constexpr Ratio<T> Ratio<T>::inverse() const {
    Ratio ratio;
    ratio.m_num = this->m_den;
    ratio.m_den = this->m_num;
    ratio = ratio.make_irreductible();
    return ratio;
}

template <typename T> Ratio<T> Ratio<T>::make_irreductible() {
    Ratio ratio;
    T gcd;
    if (this->m_num == 0) {
        gcd = std::abs(this->m_den);
    } else {
        gcd = std::gcd(this->m_num, this->m_den);
    }
    if (this->m_den < 0) gcd = -gcd;
    ratio.m_num = this->m_num/gcd;
    ratio.m_den = this->m_den/gcd;
    return ratio;
}

template <typename T> constexpr Ratio<T> Ratio<T>::sqrt() {
    if (((double)this->m_num / (double)this->m_den) < 0) {
        std::cerr << *this << std::endl;
        throw std::domain_error("L'argument n'est pas dans le domaine de définition de la fonction sqrt ! ");
    }
    
    /*
    Ratio ratio_1 = convert_float_to_ratio(std::sqrt((double)this->m_num), 20);
    Ratio ratio_2 = convert_float_to_ratio(std::sqrt((double)this->m_den), 20);
    Ratio ratio;
    ratio.m_num = ratio_1.m_num * ratio_2.m_den;
    ratio.m_den = ratio_1.m_den * ratio_2.m_num;
    return ratio;
    */


    Ratio THIS = -(*this)+1;
    if (THIS.m_num/THIS.m_den == 1) {
        return Ratio(1, 1);
    }
    /*
    Ratio ratio(1, 1);
    Ratio ratio2(1, 2);
    Ratio ratio3(1, 8);
    Ratio ratio4(1, 16);
    Ratio ratio5(5, 126);
    Ratio ratio6(7, 256);
    return (ratio + ratio2*THIS - ratio3*THIS*THIS + ratio4*THIS*THIS*THIS - ratio5*THIS*THIS*THIS*THIS).make_irreductible();
    */

    Ratio u(1, 1);
    for (unsigned int i = 0; i < 5; ++i) {
        u = u + (*this / u);
        u = u / 2;
        u.make_irreductible();
    }
    return u.make_irreductible();
    // sqrt(1+x) = 1 + 1/2*x - 1/8*x² + 1/16*x³ - 5/126*x⁴ + 7/256*x⁵
}

template <typename T> constexpr Ratio<T> Ratio<T>::cos() {
    // return convert_float_to_ratio(std::cos((double)this->m_num / (double)this->m_den), 20);
    Ratio ratio(1, 1);
    Ratio ratio2(1, 2);
    Ratio ratio3(1, 24);
    return (ratio + ratio2*(*this)*(*this) + ratio3*(*this)*(*this)*(*this)*(*this)).make_irreductible();
}

template <typename T> constexpr Ratio<T> Ratio<T>::sin() {
    // return convert_float_to_ratio(std::sin((double)this->m_num / (double)this->m_den), 20);
    Ratio ratio(1, 1);
    Ratio ratio2(1, 6);
    Ratio ratio3(1, 120);
    return (ratio*(*this) - ratio2*(*this)*(*this)*(*this) + ratio3*(*this)*(*this)*(*this)*(*this)*(*this)).make_irreductible();
}

template <typename T> constexpr Ratio<T> Ratio<T>::tan() {
    // return convert_float_to_ratio(std::tan((double)this->m_num / (double)this->m_den), 20);
    Ratio ratio(1, 1);
    Ratio ratio2(1, 3);
    Ratio ratio3(2, 15);
    Ratio ratio4(17, 315);
    return (ratio*(*this) + ratio2*(*this)*(*this)*(*this) + ratio3*(*this)*(*this)*(*this)*(*this)*(*this) + ratio4*(*this)*(*this)*(*this)*(*this)*(*this)*(*this)*(*this)).make_irreductible();
}

template <typename T> constexpr Ratio<T> Ratio<T>::pow(const unsigned int &k) {
    Ratio ratio(1, 1);
    this->make_irreductible();
    return k == 0 ? ratio : *this*pow(k-1);
}

template <typename T> constexpr Ratio<T> Ratio<T>::exp() {
    // return convert_float_to_ratio(std::exp((double)this->m_num / (double)this->m_den), 20);
    Ratio ratio(1, 1);
    Ratio ratio2(1, 1);
    Ratio ratio3(1, 2);
    Ratio ratio4(1, 6);
    Ratio ratio5(1, 24);
    return (ratio + ratio2*(*this) + ratio3*(*this)*(*this) + ratio4*(*this)*(*this)*(*this) + ratio5*(*this)*(*this)*(*this)*(*this));
}

template <typename T> Ratio<T> Ratio<T>::log() {
    if (((double)this->m_num / (double)this->m_den) < 0) {
        std::cerr << *this << std::endl;
        throw std::domain_error("L'argument n'est pas dans le domaine de définition de la fonction log !");
    }
    else return convert_float_to_ratio<T>(std::log(this->m_num), 20) - convert_float_to_ratio<T>(std::log(this->m_den), 20);
}

template <typename T> int Ratio<T>::int_part() {
    Ratio ratio;
    ratio.m_num = this->m_num;
    ratio.m_den = this->m_den;
    if (ratio >= 0) return (double)this->m_num / (double)this->m_den;
    else return (double)this->m_num / (double)this->m_den - 1;
}

template <typename T> Ratio<T> Ratio<T>::abs() {
    Ratio ratio;
    ratio.m_num = this->m_num;
    ratio.m_den = this->m_den;
    ratio = ratio.make_irreductible();
    if (ratio.m_num < 0) ratio.m_num = -ratio.m_num;
    return ratio;
} 

template class Ratio<long long>;
template class Ratio<long>;
template class Ratio<int>;