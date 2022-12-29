#include "include/ratio.hpp"
#include <iostream>

int main() {
    Ratio<int> a(4, 9);
    Ratio<int> b(5, 10);
    Ratio<int> c = a;
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

}  