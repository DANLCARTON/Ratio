#ifndef RATIO
#define RATIO

#include <iostream>
#include <numeric>
#include <algorithm>
#include <math.h>
#include <stdexcept>
template <typename T> class Ratio{

    private :

    T m_num; /* Numérateur du Ratio */
    T m_den; /* Dénominateur du Ratio */

    public :
    /**
     * @brief Constructeur de Ratio
     * 
     * @param num 
     * @param den 
     */
    Ratio(const T &num = 0, const T &den = 1) : m_num(num), m_den(den) {};
    /**
     * @brief Destructeur de Ratio
     * 
     */
    ~Ratio() = default;


    //opérateurs
    /**
     * @brief Somme de deux Ratio : a/b + c/d
     * 
     * @param rn 
     * @return Ratio 
     */
    Ratio operator+(const Ratio &rn) const;
    /**
     * @brief Soustraction de deux Ratio : a/b - c/d
     * 
     * @param rn 
     * @return Ratio 
     */
    Ratio operator-(const Ratio &rn) const;
    /**
     * @brief Produit de deux Ratio : a/b * c/d
     * 
     * @param rn 
     * @return Ratio 
     */
    Ratio operator*(const Ratio &rn) const;
    /**
     * @brief Division de deux Ratio : a/b / c/d
     * 
     * @param rn 
     * @return Ratio 
     */
    Ratio operator/(const Ratio &rn) const;

    /**
     * @brief Division d'un Ratio avec un scalaire : a/b / scalaire
     * 
     * @param real 
     * @return Ratio 
     */
    Ratio operator/(const T &real) const;
    /**
     * @brief Produit d'un Ratio avec un scalaire : a/b * scalaire
     * 
     * @param real 
     * @return Ratio 
     */
    Ratio operator*(const T &real) const;
    /**
     * @brief Soustraction d'un Ratio avec un scalaire : a/b - scalaire
     * 
     * @param real 
     * @return Ratio 
     */
    Ratio operator-(const T &real) const;
    /**
     * @brief Somme d'un Ratio avec un scalaire : a/b + scalaire
     * 
     * @param real 
     * @return Ratio 
     */
    Ratio operator+(const T &real) const;

    // template <typename U> friend Ratio operator+(U real, const Ratio<U> &rn);

    /**
     * @brief Ratio +1
     * 
     * @return Ratio 
     */
    Ratio operator++(); 
    /**
     * @brief Ratio -1
     * 
     * @return Ratio 
     */
    Ratio operator--(); 
    Ratio operator++(int one);
    Ratio operator--(int one);

    /**
     * @brief Moins unaire : a/b = -a/b
     * 
     * @return Ratio 
     */
	Ratio operator-(); // moins unaire

    /**
     * @brief Comparaison égalité entre deux Ratio : a/b == c/d ?
     * 
     * @param rn 
     * @return true 
     * @return false 
     */
    bool operator==(const Ratio &rn);
    /**
     * @brief Comparaison inégalité entre deux Ratio : a/b != c/d ?
     * 
     * @param rn 
     * @return true 
     * @return false 
     */
    bool operator!=(const Ratio &rn);
    /**
     * @brief Comparaison plus petit que entre deux Ratio : a/b < c/d ?
     * 
     * @param rn 
     * @return true 
     * @return false 
     */
    bool operator<(const Ratio &rn);
    /**
     * @brief Comparaison plus petit ou égal à entre deux Ratio : a/b <= c/d ?
     * 
     * @param rn 
     * @return true 
     * @return false 
     */
    bool operator<=(const Ratio &rn);
    /**
     * @brief Comparaison plus grand que entre deux Ratio : a/b > c/d ?
     * 
     * @param rn 
     * @return true 
     * @return false 
     */
    bool operator>(const Ratio &rn);
    /**
     * @brief Comparaison plus grand ou égal à entre deux Ratio : a/b >+ c/d
     * 
     * @param rn 
     * @return true 
     * @return false 
     */
    bool operator>=(const Ratio &rn);

    // getters
    /**
     * @brief Getter numérateur du Ratio : (a/b).num() -> a
     * 
     * @return int 
     */
    inline T num() const {return m_num;};
    /**
     * @brief Getter dénominateur du Ratio : (a/b).den()-> b
     * 
     * @return int 
     */
    inline T den() const {return m_den;};

    //applications
    /**
     * @brief Inverse du Ratio : (a/b).inverse() -> b/a
     * 
     * @return Ratio 
     */
    Ratio inverse() const;
    /**
     * @brief Rend un Ratio irreductible : e.g (2a/4b).make_irreductible() -> a/2b
     * 
     * @return Ratio 
     */
    Ratio make_irreductible();
    /**
     * @brief Racine carrée d'un Ratio : (a/b).sqrt() -> sqrt(a/b)
     * 
     * @return Ratio 
     */
    Ratio sqrt(); // racine carrée
    /**
     * @brief Cosinus d'un Ratio : (a/b).cos() -> cos(a/b)
     * 
     * @return Ratio 
     */
    Ratio cos(); // cosinus
    /**
     * @brief Sinus d'un Ratio : (a/b).sin() -> sin(a/b)
     * 
     * @return Ratio 
     */
    Ratio sin(); // sinus
    /**
     * @brief Tengente d'un Ratio : (a/b).tan() -> tan(a/b)
     * 
     * @return Ratio 
     */
    Ratio tan(); // tangeante
    /**
     * @brief Ratio à la puissance k -> (a/b).pow(k) -> (a/b)^k
     * 
     * @param k 
     * @return Ratio 
     */
    Ratio pow(const unsigned int &k); // puissance k
    /**
     * @brief Exponentielle d'un Ratio : (a/b).exp() -> exp(a/b)
     * 
     * @return Ratio 
     */
    Ratio exp(); // exponentielle
    /**
     * @brief Logarithme d'un Ratio : (a/b).log() -> log(a/b)
     * 
     * @return double 
     */
    double log(); // logarithme (népérien ?)
    /**
     * @brief Partie entière d'un Ratio : (a/b).int_part() -> ⌊(a/b)⌋
     * 
     * @return int 
     */
    int int_part(); // partie entière
    /**
     * @brief Valeur abosolue d'un ratio : -a/b -> a/b ; a/b -> a/b
     * 
     * @return Ratio 
     */
    Ratio abs(); // valeur absolue
};

// - - - P R I N T   W I T H   S T D : : C O U T - - -

/**
 * @brief Uitliser std::cout << Ratio << std::endl pour afficher un Ratio dans le terminal sous la forme a/b
 * 
 * @tparam T 
 * @param stream 
 * @param rn 
 * @return std::ostream& 
 */
template <typename T> std::ostream &operator<< (std::ostream &stream, const Ratio<T> &rn) { 
 	stream << rn.num() << " / " << rn.den();
	return stream;
}

// - - - F U N C T I O N S   P R O T O T Y P E S - - -

/**
 * @brief Convertir un scalaire en Ratio : scalaire -> a/b
 * 
 * @param real 
 * @param nbIter 
 * @return Ratio<int> 
 */
Ratio<int> convert_float_to_ratio(const double &real, const unsigned int &nbIter);

// - - - M E T H O D S - - -

template <typename T> Ratio<T> Ratio<T>::inverse() const {
    Ratio ratio;
    ratio.m_num = this->m_den;
    ratio.m_den = this->m_num;
    ratio = ratio.make_irreductible();
    return ratio;
}

template <typename T> Ratio<T> Ratio<T>::make_irreductible() {
    Ratio ratio;
    int gcd;
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
    Ratio<int> ratio2 = convert_float_to_ratio(real, 10);
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
    Ratio<int> ratio2 = convert_float_to_ratio(real, 10);
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

template <typename T> Ratio<T> operator+(T real, const Ratio<T> &rn) {
    Ratio<T> ratio;
    ratio = rn + real;
    return ratio;
}

template <typename T> Ratio<T> operator-(T real, const Ratio<T> &rn) {
    Ratio<T> ratio;
    ratio = rn - real;
    return ratio;
}

template <typename T> Ratio<T> operator*(T real, const Ratio<T> &rn) {
    Ratio<T> ratio;
    ratio = rn * real;
    return ratio;
}

template <typename T> Ratio<T> operator/(T real, const Ratio<T> &rn) {
    Ratio<T> ratio;
    ratio = rn / real;
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

template <typename T> Ratio<T> Ratio<T>::operator++(int one) {
    Ratio ratio;
    ratio.m_num = this->m_num + this->m_den;
    ratio.m_den = this->m_den;
    ratio = ratio.make_irreductible();
    return ratio;
}

template <typename T> Ratio<T> Ratio<T>::operator--(int one) {
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
    if (((double)this->m_num / (double)this->m_den) < 0) {
        std::cerr << *this << std::endl;
        throw std::domain_error("must be positive");
    }
    
    
    Ratio THIS = 1-(*this);
    if (THIS.m_num/THIS.m_den == 1) {
        return Ratio<int>(1, 1);
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

template <typename T> Ratio<T> Ratio<T>::cos() {
    // return convert_float_to_ratio(std::cos((double)this->m_num / (double)this->m_den), 20);
    Ratio ratio(1, 1);
    Ratio ratio2(1, 2);
    Ratio ratio3(1, 24);
    return (ratio + ratio2*(*this)*(*this) + ratio3*(*this)*(*this)*(*this)*(*this)).make_irreductible();
}

template <typename T> Ratio<T> Ratio<T>::sin() {
    // return convert_float_to_ratio(std::sin((double)this->m_num / (double)this->m_den), 20);
    Ratio ratio(1, 1);
    Ratio ratio2(1, 6);
    Ratio ratio3(1, 120);
    return (ratio*(*this) - ratio2*(*this)*(*this)*(*this) + ratio3*(*this)*(*this)*(*this)*(*this)*(*this)).make_irreductible();
}

template <typename T> Ratio<T> Ratio<T>::tan() {
    // return convert_float_to_ratio(std::tan((double)this->m_num / (double)this->m_den), 20);
    Ratio ratio(1, 1);
    Ratio ratio2(1, 3);
    Ratio ratio3(2, 15);
    Ratio ratio4(17, 315);
    return (ratio*(*this) + ratio2*(*this)*(*this)*(*this) + ratio3*(*this)*(*this)*(*this)*(*this)*(*this) + ratio4*(*this)*(*this)*(*this)*(*this)*(*this)*(*this)*(*this)).make_irreductible();
}

template <typename T> Ratio<T> Ratio<T>::pow(const unsigned int &k) {
    Ratio ratio(1, 1);
    if (k == 0) {
        return Ratio(1, 1);
    }
    for (unsigned int i = 0; i < k; i++)
    {
        ratio.m_num *= (this->m_num);
        ratio.m_den *= (this->m_den);
    }
    ratio = ratio.make_irreductible();
    return ratio;
}

template <typename T> Ratio<T> Ratio<T>::exp() {
    // return convert_float_to_ratio(std::exp((double)this->m_num / (double)this->m_den), 20);
    Ratio ratio(1, 1);
    Ratio ratio2(1, 1);
    Ratio ratio3(1, 2);
    Ratio ratio4(1, 6);
    Ratio ratio5(1, 24);
    return (ratio + ratio2*(*this) + ratio3*(*this)*(*this) + ratio4*(*this)*(*this)*(*this) + ratio5*(*this)*(*this)*(*this)*(*this));
}

template <typename T> double Ratio<T>::log() {
    return std::log((double)this->m_num) - std::log((double)this->m_den);
}
// ne marche pas 

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
    /*
    if ((ratio.m_den >= 0 && ratio.m_num >= 0) || (ratio.m_den <= 0 && ratio.m_num <= 0)) return ratio.make_irreductible();
    else{
        ratio.m_den = -this->m_den;
        return ratio.make_irreductible();
    }
    */
    if (ratio.m_num < 0) ratio.m_num = -ratio.m_num;
    return ratio;
}

#endif