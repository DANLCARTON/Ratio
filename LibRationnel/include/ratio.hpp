#ifndef RATIO
#define RATIO

#include <iostream>
#include <numeric>
#include <algorithm>
#include <math.h>

template <typename T> class Ratio{

    private :

    int m_num;
    int m_den;

    public :

    Ratio(const int &num = 0, const int &den = 1) : m_num(num), m_den(den) {};
    ~Ratio() = default;


    //opérateurs
    
    Ratio operator+(const Ratio &rn) const;
    Ratio operator-(const Ratio &rn) const;
    Ratio operator*(const Ratio &rn) const;
    Ratio operator/(const Ratio &rn) const;

    Ratio operator/(const T &real) const;
    Ratio operator*(const T &real) const;
    Ratio operator-(const T &real) const;
    Ratio operator+(const T &real) const;

    Ratio operator++(); // marche qu'avec ++a mais pas avec a++
    Ratio operator--(); // marche qu'avec --a mais pas avec a--

	Ratio operator-(); // moins unaire

    bool operator==(const Ratio &rn);
    bool operator!=(const Ratio &rn);
    bool operator<(const Ratio &rn);
    bool operator<=(const Ratio &rn);
    bool operator>(const Ratio &rn);
    bool operator>=(const Ratio &rn);

    // getters
    inline int num() const {return m_num;};
    inline int den() const {return m_den;};

    //applications
    Ratio inverse() const;
    Ratio make_irreductible();
    Ratio sqrt(); // racine carrée
    Ratio cos(); // cosinus
    Ratio sin(); // sinus
    Ratio tan(); // tangeante
    Ratio pow(const int &k); // puissance k
    Ratio exp(); // exponentielle
    T log(); // logarithme népérien
    int int_part(); // partie entière
    Ratio abs(); // valeur absolue
};

// - - - P R I N T   W I T H   S T D : : C O U T - - -

template <typename T> std::ostream &operator<< (std::ostream &stream, const Ratio<T> &rn) { 
 	stream << rn.num() << "/" << rn.den();
	return stream;
}

// - - - F U N C T I O N S   P R O T O T Y P E S - - -

Ratio<int> convert_float_to_ratio(const double &real, const unsigned int &nbIter);

// - - - M E T H O D S - - -

template <typename T> Ratio<T> Ratio<T>::inverse() const {
    Ratio ratio;
    ratio.m_num = this->m_den;
    ratio.m_den = this->m_num;
    // rendre irreductible
    return ratio;
}

template <typename T> Ratio<T> Ratio<T>::make_irreductible() {
    Ratio ratio;
    int gcd = std::gcd(this->m_num, this->m_den);
    ratio.m_num = this->m_num/gcd;
    ratio.m_den = this->m_den/gcd;
    return ratio;
}

// - - - O P E R A T O R S - - -

template <typename T> Ratio<T> Ratio<T>::operator+(const Ratio &rn) const {
    Ratio ratio;
    ratio.m_num = this->m_num*rn.m_den + this->m_den*rn.m_num;
    ratio.m_den = this->m_den*rn.m_den;
    ratio = ratio.make_irreductible();
    return ratio;
}

template <typename T> Ratio<T> Ratio<T>::operator+(const T &real) const {
    Ratio ratio;
    Ratio ratio2 = convert_float_to_ratio(real, 10);
    ratio.m_num = this->m_num*ratio2.m_den + this->m_den*ratio2.m_num;
    ratio.m_den = this->m_den*ratio2.m_den;
    ratio = ratio.make_irreductible();
    return ratio;
}

template <typename T> Ratio<T> Ratio<T>::operator-(const Ratio &rn) const {
    Ratio ratio;
    ratio.m_num = this->m_num*rn.m_den - this->m_den*rn.m_num;
    ratio.m_den = this->m_den*rn.m_den;
    ratio = ratio.make_irreductible();
    return ratio;
}

template <typename T> Ratio<T> Ratio<T>::operator-(const T &real) const {
    Ratio ratio;
    Ratio ratio2 = convert_float_to_ratio(real, 10);
    ratio.m_num = this->m_num*ratio2.m_den - this->m_den*ratio2.m_num;
    ratio.m_den = this->m_den*ratio2.m_den;
    ratio = ratio.make_irreductible();
    return ratio;
}

template <typename T> Ratio<T> Ratio<T>::operator*(const Ratio &rn) const {
    Ratio ratio;
    ratio.m_num = (this->m_num*rn.m_num);
    ratio.m_den = (this->m_den*rn.m_den);
    ratio = ratio.make_irreductible();
    return ratio;
}

template <typename T> Ratio<T> Ratio<T>::operator*(const T &real) const {
    Ratio ratio;
    Ratio ratio2 = convert_float_to_ratio(real, 10);
    ratio.m_num = this->m_num * ratio2.m_num;
    ratio.m_den = this->m_den * ratio2.m_den;
    ratio = ratio.make_irreductible();
    return ratio;
}

template <typename T> Ratio<T> Ratio<T>::operator/(const Ratio &rn) const {
    Ratio ratio;
    ratio.m_num = this->m_num * rn.inverse().m_num;
    ratio.m_den = this->m_den * rn.inverse().m_den;
    ratio = ratio.make_irreductible();
    return ratio;
}

template <typename T> Ratio<T> Ratio<T>::operator/(const T &real) const {
    Ratio ratio;
    Ratio ratio2 = convert_float_to_ratio(real, 10);
    ratio.m_num = this->m_num * ratio2.inverse().m_num;
    ratio.m_den = this->m_den * ratio2.inverse().m_den;
    ratio = ratio.make_irreductible();
    return ratio;
}

template <typename T> Ratio<T> Ratio<T>::operator++() {
    Ratio ratio;
    ratio.m_num = this->m_num + this->m_den;
    ratio.m_den = this->m_den;
    ratio = ratio.make_irreductible();
    return ratio;
}

template <typename T> Ratio<T> Ratio<T>::operator--() {
    Ratio ratio;
    ratio.m_num = this->m_num - this->m_den;
    ratio.m_den = this->m_den;
    ratio = ratio.make_irreductible();
    return ratio;
}

template <typename T> Ratio<T> Ratio<T>::operator-() {
    Ratio ratio;
    ratio.m_num = -this->m_num;
    ratio.m_den = this->m_den;
    ratio = ratio.make_irreductible();
    return ratio;
}

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

// OPERATOR APPLICATIONS


template <typename T> Ratio<T> Ratio<T>::sqrt() {
    Ratio ratio_1 = convert_float_to_ratio(std::sqrt((double)this->m_num), 20);
    Ratio ratio_2 = convert_float_to_ratio(std::sqrt((double)this->m_den), 20);
    Ratio ratio;
    ratio.m_num = ratio_1.m_num * ratio_2.m_den;
    ratio.m_den = ratio_1.m_den * ratio_2.m_num;
    return ratio;
}

template <typename T> Ratio<T> Ratio<T>::cos() {
    return convert_float_to_ratio(std::cos((double)this->m_num / (double)this->m_den), 20);
}

template <typename T> Ratio<T> Ratio<T>::sin() {
    return convert_float_to_ratio(std::sin((double)this->m_num / (double)this->m_den), 20);
}

template <typename T> Ratio<T> Ratio<T>::tan() {
    return convert_float_to_ratio(std::tan((double)this->m_num / (double)this->m_den), 20);
}

template <typename T> Ratio<T> Ratio<T>::pow(const int &k) {
    Ratio ratio;
    ratio.m_num = 1;
    ratio.m_den = 1;
    for (int i = 0; i < k; i++)
    {
        ratio.m_num *= (this->m_num);
        ratio.m_den *= (this->m_den);
    }

    return ratio;
}

template <typename T> Ratio<T> Ratio<T>::exp() {
    return convert_float_to_ratio(std::exp((double)this->m_num / (double)this->m_den), 20);
}

template <typename T> T Ratio<T>::log() {
    return std::log((double)this->m_num) - std::log((double)this->m_den);
}
// ne marche pas 

template <typename T> int Ratio<T>::int_part() {
    Ratio ratio;
    ratio.m_num = this->m_num;
    ratio.m_den = this->m_den;
    if (ratio > 0) return this->m_num / this->m_den;
    else return this->m_num / this->m_den - 1;
}

template <typename T> Ratio<T> Ratio<T>::abs() {
    Ratio ratio;
    ratio.m_num = this->m_num;
    ratio.m_den = this->m_den;
    if ((ratio.m_den >= 0 && ratio.m_num >= 0) || (ratio.m_den <= 0 && ratio.m_num <= 0)) return ratio;
    else{
        ratio.m_den = -this->m_den;
        return ratio;
    }
}

#endif