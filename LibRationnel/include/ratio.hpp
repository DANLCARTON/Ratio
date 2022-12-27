#include <iostream>

template <typename T> class Ratio{

    private :

    T m_num;
    T m_den;

    public :

    Ratio();
    Ratio(const T &num, const T &dem);
    ~Ratio() = default;

    
    Ratio convert_float_to_ratio(const T &real);

    //opérateurs
    
    Ratio operator+(const Ratio &rn) const;
    Ratio operator-(const Ratio &rn) const;
    Ratio operator*(const Ratio &rn) const;
    Ratio inverse() const;
    Ratio operator/(const Ratio &rn) const;

    inline Ratio operator/(const T &value) const {return Ratio(m_num, value * m_den);}
    inline Ratio operator++() {return Ratio(m_den + m_num, m_den);}
    inline Ratio operator--() {return Ratio(m_den - m_num, m_den);}
    inline friend Ratio operator*(const T &value) {return (this->m_num * value, this->m_den);}
    inline friend Ratio operator*(const Ratio &rn) {return (rn.m_num * this, rn.m_den);}
	inline friend Ratio operator/(const T &value, const Ratio &rn) {return Ratio(value)/rn;};
	inline Ratio operator-(const Ratio &rn) {return Ratio(-rn);};

    inline bool operator==(const Ratio &rn);
    inline bool operator!=(const Ratio &rn);
    inline bool operator<(const Ratio &rn);
    inline bool operator<=(const Ratio &rn);
    inline bool operator>(const Ratio &rn);
    inline bool operator>=(const Ratio &rn);

    //applications
    Ratio sqrt(); // racine carrée
    Ratio cos(); // cosinus
    Ratio sin(); // sinus
    Ratio tan(); // tangeante
    Ratio pow(const T &k); // puissance
    Ratio exp(); // exponentielle
    Ratio log(); // logarithme (népérien ?)
    int int_part(); // partie entière
    Ratio abs(); // valeur absolue
};

template <typename T> std::ostream &operator<< (std::ostream &stream, const Ratio<T> &rn) { 
 	stream << rn.m_num << "/" << rn.m_num;
	return stream;
}