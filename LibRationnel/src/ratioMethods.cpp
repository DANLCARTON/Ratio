#include "../include/ratio.hpp"

// - - - M E T H O D S - - -

template <typename T> Ratio<T> Ratio<T>::sqrt() {
    if (((double)this->m_num / (double)this->m_den) < 0) {
        std::cerr << *this << std::endl;
        throw std::domain_error("must be positive");
    }
    
    
    Ratio THIS = -(*this)+1;
    if (THIS.m_num/THIS.m_den == 1) {
        return Ratio(1, 1);
    }
    Ratio ratio(1, 1);
    Ratio ratio2(1, 2);
    Ratio ratio3(1, 8);
    Ratio ratio4(1, 16);
    Ratio ratio5(5, 126);
    Ratio ratio6(7, 256);
    return (ratio + ratio2*THIS - ratio3*THIS*THIS + ratio4*THIS*THIS*THIS - ratio5*THIS*THIS*THIS*THIS /*+ ratio6*THIS*THIS*THIS*THIS*THIS*/).make_irreductible();
    // sqrt(1+x) = 1 + 1/2*x - 1/8*x² + 1/16*x³ - 5/126*x⁴ + 7/256*x⁵
}

template class Ratio<int>;