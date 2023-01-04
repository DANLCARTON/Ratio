#include "../include/ratio.hpp"

// - - - - -   C O M P A R I S O N   O P E R A T O R S   - - - - -

template <typename T> bool Ratio<T>::operator==(const Ratio &rn) {
    Ratio ratio1 = this->make_irreductible();
    Ratio ratio2 = rn;
    ratio2 = ratio2.make_irreductible();
    if (ratio1.m_num == ratio2.m_num && ratio1.m_den == ratio2.m_den) return true;
    else return false;
}

template <typename T> bool Ratio<T>::operator!=(const Ratio &rn) {
    Ratio ratio1 = this->make_irreductible();
    Ratio ratio2 = rn;
    ratio2 = ratio2.make_irreductible();
    if (ratio1.m_num != ratio2.m_num || ratio1.m_den != ratio2.m_den) return true;
    else return false;
}

template <typename T> bool Ratio<T>::operator<=(const Ratio &rn) {
    Ratio ratio1 = this->make_irreductible();
    Ratio ratio2 = rn;
    ratio2 = ratio2.make_irreductible();
    if ((double)ratio1.m_num/(double)ratio1.m_den <= (double)ratio2.m_num/(double)ratio2.m_den) return true;
    else return false;
}

template <typename T> bool Ratio<T>::operator<(const Ratio &rn) {
    Ratio ratio1 = this->make_irreductible();
    Ratio ratio2 = rn;
    ratio2 = ratio2.make_irreductible();
    if ((double)ratio1.m_num/(double)ratio1.m_den < (double)ratio2.m_num/(double)ratio2.m_den) return true;
    else return false;
}

template <typename T> bool Ratio<T>::operator>=(const Ratio &rn) {
    Ratio ratio1 = this->make_irreductible();
    Ratio ratio2 = rn;
    ratio2 = ratio2.make_irreductible();
    if ((double)ratio1.m_num/(double)ratio1.m_den >= (double)ratio2.m_num/(double)ratio2.m_den) return true;
    else return false;
}

template <typename T> bool Ratio<T>::operator>(const Ratio &rn) {
    Ratio ratio1 = this->make_irreductible();
    Ratio ratio2 = rn;
    ratio2 = ratio2.make_irreductible();
    if ((double)ratio1.m_num/(double)ratio1.m_den > (double)ratio2.m_num/(double)ratio2.m_den) return true;
    else return false;
}

template class Ratio<int>;
template class Ratio<long>;
template class Ratio<long long>;