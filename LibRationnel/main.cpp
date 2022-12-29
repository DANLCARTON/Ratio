#include "include/ratio.hpp"
#include <iostream>

int main() {
    Ratio<int> a(4, 9);
    Ratio<int> b(5, 10);
    Ratio<int> c = a;
    Ratio<int> d = a.sqrt();
    Ratio<int> e(3, 10);
    Ratio<int> f = e.sqrt();
    Ratio<int> g(-34, 10);
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << a+b << std::endl;
    std::cout << a+2 << std::endl;
    std::cout << a-b << std::endl;
    std::cout << a-2 << std::endl;
    std::cout << a*b << std::endl;
    std::cout << a.inverse() << std::endl;
    std::cout << a/b << std::endl;
    std::cout << a/2 << std::endl;
    std::cout << a*2 << std::endl;
    std::cout << ++a << std::endl;
    std::cout << --a << std::endl;
    std::cout << -a << std::endl;
    std::cout << (a == b) << std::endl;
    std::cout << (a == c) << std::endl;
    std::cout << (a != b) << std::endl;
    std::cout << (a != c) << std::endl;
    std::cout << (a <= b) << std::endl;
    std::cout << (a <= c) << std::endl;
    std::cout << (a < b) << std::endl;
    std::cout << (a < c) << std::endl;
    std::cout << (a >= b) << std::endl;
    std::cout << (a >= c) << std::endl;
    std::cout << (a > b) << std::endl;
    std::cout << (a > c) << std::endl;
    std::cout << b.make_irreductible() << std::endl;
    std::cout << d << std::endl;
    std::cout << f << std::endl;
    std::cout << e.pow(4) << std::endl;
    std::cout << g.abs() << std::endl;
    std::cout << g.int_part() << std::endl;
    std::cout << a.int_part() << std::endl;

}  