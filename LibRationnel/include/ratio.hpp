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
    constexpr Ratio operator+(const Ratio &rn) const;
    /**
     * @brief Soustraction de deux Ratio : a/b - c/d
     * 
     * @param rn 
     * @return Ratio 
     */
    constexpr Ratio operator-(const Ratio &rn) const;
    /**
     * @brief Produit de deux Ratio : a/b * c/d
     * 
     * @param rn 
     * @return Ratio 
     */
    constexpr Ratio operator*(const Ratio &rn) const;
    /**
     * @brief Division de deux Ratio : a/b / c/d
     * 
     * @param rn 
     * @return Ratio 
     */
    constexpr Ratio operator/(const Ratio &rn) const;

    /**
     * @brief Division d'un Ratio avec un scalaire : a/b / scalaire
     * 
     * @param real 
     * @return Ratio 
     */
    constexpr Ratio operator/(const T &real) const;
    /**
     * @brief Produit d'un Ratio avec un scalaire : a/b * scalaire
     * 
     * @param real 
     * @return Ratio 
     */
    constexpr Ratio operator*(const T &real) const;
    /**
     * @brief Soustraction d'un Ratio avec un scalaire : a/b - scalaire
     * 
     * @param real 
     * @return Ratio 
     */
    constexpr Ratio operator-(const T &real) const;
    /**
     * @brief Somme d'un Ratio avec un scalaire : a/b + scalaire
     * 
     * @param real 
     * @return Ratio 
     */
    constexpr Ratio operator+(const T &real) const;

    // template <typename U> friend Ratio operator+(U real, const Ratio<U> &rn);

    /**
     * @brief Opérateur ++ préfixé
     * 
     * @return Ratio 
     */
    constexpr Ratio operator++(); 
    /**
     * @brief Opéréateur -- préfixé
     * 
     * @return Ratio 
     */
    constexpr Ratio operator--(); 
    /**
     * @brief Opérateur ++ postfixé
     * 
     * @param one 
     * @return constexpr Ratio 
     */
    constexpr Ratio operator++(int one);
    /**
     * @brief Opérateur -- postfixé
     * 
     * @param one 
     * @return constexpr Ratio 
     */
    constexpr Ratio operator--(int one);

    /**
     * @brief Moins unaire : a/b = -a/b
     * 
     * @return Ratio 
     */
	constexpr Ratio operator-(); // moins unaire

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

    /**
     * @brief Setter numérateur du Ratio
     * 
     * @param v 
     * @return T 
     */
    inline T num(const T &v) {this->m_num = v;};
    /**
     * @brief Setter dénominateur du Ratio
     * 
     * @param v 
     * @return T 
     */
    inline T den(const T &v) {this->m_den = v;};

    //applications
    /**
     * @brief Inverse du Ratio : (a/b).inverse() -> b/a
     * 
     * @return Ratio 
     */
    constexpr Ratio inverse() const;
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
    constexpr Ratio sqrt(); // racine carrée
    /**
     * @brief Cosinus d'un Ratio : (a/b).cos() -> cos(a/b)
     * 
     * @return Ratio 
     */
    constexpr Ratio cos(); // cosinus
    /**
     * @brief Sinus d'un Ratio : (a/b).sin() -> sin(a/b)
     * 
     * @return Ratio 
     */
    constexpr Ratio sin(); // sinus
    /**
     * @brief Tengente d'un Ratio : (a/b).tan() -> tan(a/b)
     * 
     * @return Ratio 
     */
    constexpr Ratio tan(); // tangeante
    /**
     * @brief Ratio à la puissance k -> (a/b).pow(k) -> (a/b)^k
     * 
     * @param k 
     * @return Ratio 
     */
    constexpr Ratio pow(const unsigned int &k); // puissance k
    /**
     * @brief Exponentielle d'un Ratio : (a/b).exp() -> exp(a/b)
     * 
     * @return Ratio 
     */
    constexpr Ratio exp(); // exponentielle
    /**
     * @brief Logarithme d'un Ratio : (a/b).log() -> log(a/b)
     * 
     * @return double 
     */
    Ratio log(); // logarithme népérien 
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
template <typename T> Ratio<T> convert_float_to_ratio(const double &real, const unsigned int &nbIter);

template <typename T> constexpr Ratio<T> Ratio<T>::operator/(const T &real) const {
    Ratio ratio;
    Ratio ratio2 = convert_float_to_ratio<T>(real, 10);
    ratio.m_num = this->m_num * ratio2.inverse().m_num;
    ratio.m_den = this->m_den * ratio2.inverse().m_den;
    ratio = ratio.make_irreductible();
    return ratio;
} // Lui seul rend une "référence indéfinie" vers convert_float_to_ratio<int> convert_float_to_ratio<long> et convert_float_to_ratio<long long> si je le définis dans ratioOperators.cpp

// - - - - - OPERATEURS AVEC LE RATIO COMME OPERANTE DE DROITE - - - - -

/**
 * @brief Somme d'un scalaire avec un Ratio : real + a/b
 * 
 * @tparam T 
 * @param real 
 * @param rn 
 * @return Ratio<T> 
 */
template <typename T> Ratio<T> operator+(T real, const Ratio<T> &rn) {
    Ratio<T> ratio;
    ratio = rn + real;
    return ratio;
}

/**
 * @brief Soustraction d'un scalaire avec un Ratio : real - a/b
 * 
 * @tparam T 
 * @param real 
 * @param rn 
 * @return Ratio<T> 
 */
template <typename T> Ratio<T> operator-(T real, const Ratio<T> &rn) {
    Ratio<T> ratio;
    ratio = rn - real;
    return ratio;
}

/**
 * @brief Produit d'un scalaire avec un Ratio : real * a/b
 * 
 * @tparam T 
 * @param real 
 * @param rn 
 * @return Ratio<T> 
 */
template <typename T> Ratio<T> operator*(T real, const Ratio<T> &rn) {
    Ratio<T> ratio;
    ratio = rn * real;
    return ratio;
}

/**
 * @brief Division d'un scalaire avec un Ratio : real / a/b
 * 
 * @tparam T 
 * @param real 
 * @param rn 
 * @return Ratio<T> 
 */
template <typename T> Ratio<T> operator/(T real, const Ratio<T> &rn) {
    Ratio<T> ratio;
    ratio = rn / real;
    return ratio;
}

#endif