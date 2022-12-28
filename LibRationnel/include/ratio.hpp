#ifndef RATIO
#define RATIO

#include <iostream>

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
    Ratio inverse() const;
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
    Ratio make_irreductible();
    Ratio sqrt(); // racine carrée
    Ratio cos(); // cosinus
    Ratio sin(); // sinus
    Ratio tan(); // tangeante
    Ratio pow(const int &k); // puissance k
    Ratio exp(); // exponentielle
    Ratio log(); // logarithme (népérien ?)
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

// - - - O P E R A T O R S - - -

template <typename T> Ratio<T> Ratio<T>::operator+(const Ratio &rn) const {
    Ratio ratio;
    ratio.m_num = this->m_num*rn.m_den + this->m_den*rn.m_num;
    ratio.m_den = this->m_den*rn.m_den;
    // rendre irreductible
    return ratio;
}

template <typename T> Ratio<T> Ratio<T>::operator+(const T &real) const {
    Ratio ratio;
    Ratio ratio2 = convert_float_to_ratio(real, 10);
    ratio.m_num = this->m_num*ratio2.m_den + this->m_den*ratio2.m_num;
    ratio.m_den = this->m_den*ratio2.m_den;
    // rendre irreductible
    return ratio;
}

template <typename T> Ratio<T> Ratio<T>::operator-(const Ratio &rn) const {
    Ratio ratio;
    ratio.m_num = this->m_num*rn.m_den - this->m_den*rn.m_num;
    ratio.m_den = this->m_den*rn.m_den;
    // rendre irreductible
    return ratio;
}

template <typename T> Ratio<T> Ratio<T>::operator-(const T &real) const {
    Ratio ratio;
    Ratio ratio2 = convert_float_to_ratio(real, 10);
    ratio.m_num = this->m_num*ratio2.m_den - this->m_den*ratio2.m_num;
    ratio.m_den = this->m_den*ratio2.m_den;
    // rendre irreductible
    return ratio;
}

template <typename T> Ratio<T> Ratio<T>::operator*(const Ratio &rn) const {
    Ratio ratio;
    ratio.m_num = (this->m_num*rn.m_num);
    ratio.m_den = (this->m_den*rn.m_den);
    // rendre irreductible
    return ratio;
}

template <typename T> Ratio<T> Ratio<T>::operator*(const T &real) const {
    Ratio ratio;
    Ratio ratio2 = convert_float_to_ratio(real, 10);
    ratio.m_num = this->m_num * ratio2.m_num;
    ratio.m_den = this->m_den * ratio2.m_den;
    // rendre irreductible
    return ratio;
}

template <typename T> Ratio<T> Ratio<T>::operator/(const Ratio &rn) const {
    Ratio ratio;
    ratio.m_num = this->m_num * rn.inverse().m_num;
    ratio.m_den = this->m_den * rn.inverse().m_den;
    // rendre irreductible
    return ratio;
}

template <typename T> Ratio<T> Ratio<T>::operator/(const T &real) const {
    Ratio ratio;
    Ratio ratio2 = convert_float_to_ratio(real, 10);
    ratio.m_num = this->m_num * ratio2.inverse().m_num;
    ratio.m_den = this->m_den * ratio2.inverse().m_den;
    // rendre irreductible
    return ratio;
}

template <typename T> Ratio<T> Ratio<T>::operator++() {
    Ratio ratio;
    Ratio unit(this->m_den, this->m_den);
    ratio = *this + unit;
    // rendre irreductible
    return ratio;
}

template <typename T> Ratio<T> Ratio<T>::operator--() {
    Ratio ratio;
    Ratio unit(this->m_den, this->m_den);
    ratio = *this - unit;
    // rendre irreductible
    return ratio;
}

template <typename T> Ratio<T> Ratio<T>::operator-() {
    Ratio ratio;
    ratio.m_num = -this->m_num;
    ratio.m_den = this->m_den;
    // rendre irreductible
    return ratio;
}

template <typename T> bool Ratio<T>::operator==(const Ratio &rn) {
    // rendre irreductible
    if (this->m_num == rn.m_num && this->m_den == rn.m_den) return true;
    else return false;
}

template <typename T> bool Ratio<T>::operator!=(const Ratio &rn) {
    // rendre irreductible
    if (this->m_num != rn.m_num || this->m_den != rn.m_den) return true;
    else return false;
}

template <typename T> bool Ratio<T>::operator<=(const Ratio &rn) {
    // rendre irreductible
    if ((double)this->m_num/(double)this->m_den <= (double)rn.m_num/(double)rn.m_den) return true;
    else return false;
}

template <typename T> bool Ratio<T>::operator<(const Ratio &rn) {
    // rendre irreductible
    if ((double)this->m_num/(double)this->m_den < (double)rn.m_num/(double)rn.m_den) return true;
    else return false;
}

template <typename T> bool Ratio<T>::operator>=(const Ratio &rn) {
    // rendre irreductible
    if ((double)this->m_num/(double)this->m_den >= (double)rn.m_num/(double)rn.m_den) return true;
    else return false;
}

template <typename T> bool Ratio<T>::operator>(const Ratio &rn) {
    // rendre irreductible
    if ((double)this->m_num/(double)this->m_den > (double)rn.m_num/(double)rn.m_den) return true;
    else return false;
}

#endif