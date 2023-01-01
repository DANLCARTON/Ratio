#include "ratio.hpp"
#include <iostream>
#include <random>
#include <gtest/gtest.h>

// - - - - - - - - - - - - - - - - - - - - - - - - - - -
// C O N S T R U C T E U R S 

TEST (RatioConstructor, defaultConstructor) {
    Ratio<int> ratio;
    EXPECT_EQ(ratio.num(), 0);
    EXPECT_EQ(ratio.den(), 1);
}

TEST (RatioConstructor, copyConstructor) {
    const unsigned int maxVal = 1000;
    std::default_random_engine generator(0);
    std::uniform_int_distribution<int> uniformDistributionValue(-int(maxVal), maxVal);
    auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};
    
    for (size_t run = 0; run < 100; ++run) {
        Ratio<int> ratio(gen(), gen());
        Ratio<int> ratioCopy(ratio);
        ASSERT_EQ(ratio.num(), ratioCopy.num());
        ASSERT_EQ(ratio.den(), ratioCopy.den());
    }
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - -
// O P E R A T E U R S

// Somme
TEST (RatioArithmetic, plus) {
    const unsigned int maxVal = 1000;
    std::default_random_engine generator(0);
    std::uniform_int_distribution<int> uniformDistributionValue(-int(maxVal), maxVal);
    auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};
    for (size_t run = 0; run < 100; ++run) {
        Ratio<int> ratio1(gen(), gen());
        Ratio<int> ratio2(gen(), gen());
        Ratio<int> ratio3;
        ratio3 = ratio1 + ratio2;
        int gcd = std::gcd(ratio1.num()*ratio2.den()+ratio1.den()*ratio2.num(), ratio2.den()*ratio1.den());
        ASSERT_EQ(ratio3.num(), (ratio1.num()*ratio2.den()+ratio1.den()*ratio2.num())/gcd);
        ASSERT_EQ(ratio3.den(), (ratio2.den()*ratio1.den())/gcd);
    }
}

// Commutativité de l'somme
TEST (RatioArithmetic, plusComutativity) {
    const unsigned int maxVal = 1000;
    std::default_random_engine generator(0);
    std::uniform_int_distribution<int> uniformDistributionValue(-int(maxVal), maxVal);
    auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};
    for (size_t run = 0; run < 100; ++run) {
        Ratio<int> ratio1(gen(), gen());
        Ratio<int> ratio2(gen(), gen());
        Ratio<int> ratio3(ratio1+ratio2);
        Ratio<int> ratio4(ratio2+ratio1);
        ASSERT_EQ(ratio3.num(), ratio4.num());
        ASSERT_EQ(ratio3.den(), ratio4.den());
    }
}

// Soustraction
TEST (RatioArithmetic, minus) {
    const unsigned int maxVal = 1000;
    std::default_random_engine generator(0);
    std::uniform_int_distribution<int> uniformDistributionValue(-int(maxVal), maxVal);
    auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};
    for (size_t run = 0; run < 100; ++run) {
        Ratio<int> ratio1(gen(), gen());
        Ratio<int> ratio2(gen(), gen());
        Ratio<int> ratio3;
        ratio3 = ratio1 - ratio2;
        int gcd = std::gcd(ratio1.num()*ratio2.den()-ratio1.den()*ratio2.num(), ratio2.den()*ratio1.den());
        ASSERT_EQ(ratio3.num(), (ratio1.num()*ratio2.den()+ratio1.den()*ratio2.num())/gcd);
        ASSERT_EQ(ratio3.den(), (ratio2.den()*ratio1.den())/gcd);
    }
}

// Produit
TEST (RatioArithmetic, multiply) {
    const unsigned int maxVal = 1000;
    std::default_random_engine generator(0);
    std::uniform_int_distribution<int> uniformDistributionValue(-int(maxVal), maxVal);
    auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};
    for (size_t run = 0; run < 100; ++run) {
        Ratio<int> ratio1(gen(), gen());
        Ratio<int> ratio2(gen(), gen());
        Ratio<int> ratio3;
        ratio3 = ratio1 * ratio2;
        int gcd = std::gcd(ratio1.num()*ratio2.num(), ratio1.den()*ratio2.den());
        ASSERT_EQ(ratio3.num(), (ratio1.num()*ratio2.num())/gcd);
        ASSERT_EQ(ratio3.den(), (ratio1.den()*ratio2.den())/gcd);
    }
}

// Comutativité du produit
TEST (RatioArithmetic, multiplyComutativity) {
    const unsigned int maxVal = 1000;
    std::default_random_engine generator(0);
    std::uniform_int_distribution<int> uniformDistributionValue(-int(maxVal), maxVal);
    auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};
    for (size_t run = 0; run < 100; ++run) {
        Ratio<int> ratio1(gen(), gen());
        Ratio<int> ratio2(gen(), gen());
        Ratio<int> ratio3(ratio1*ratio2);
        Ratio<int> ratio4(ratio2*ratio1);
        ASSERT_EQ(ratio3.num(), ratio4.num());
        ASSERT_EQ(ratio3.den(), ratio4.den());
    }
}

// Division
TEST (RatioArithmetic, divide) {
    const unsigned int maxVal = 1000;
    std::default_random_engine generator(0);
    std::uniform_int_distribution<int> uniformDistributionValue(-int(maxVal), maxVal);
    auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};
    for (size_t run = 0; run < 100; ++run) {
        Ratio<int> ratio1(gen(), gen());
        Ratio<int> ratio2(gen(), gen());
        Ratio<int> ratio3;
        ratio3 = ratio1 / ratio2;
        int gcd = std::gcd(ratio1.num()/ratio2.num(), ratio1.den()/ratio2.den());
        ASSERT_EQ(ratio3.num(), (ratio1.num()/ratio2.num())/gcd);
        ASSERT_EQ(ratio3.den(), (ratio1.den()/ratio2.den())/gcd);
    }
}

// ++
TEST (RatioArithmetic, itrationPlus) {
    const unsigned int maxVal = 1000;
    std::default_random_engine generator(0);
    std::uniform_int_distribution<int> uniformDistributionValue(-int(maxVal), maxVal);
    auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};
    for (size_t run = 0; run < 100; ++run) {
        Ratio<int> ratio(gen(), gen());
        Ratio<int> ratio2(++ratio);
        int gcd = std::gcd(ratio.num()*ratio.den()+ratio.den()*ratio.den(), ratio.den()*ratio.den()); // a/b + b/b = (a*b+b*b)/(b*b)
        ASSERT_EQ(ratio2.num(), ratio.num()*ratio.den()+ratio.den()*ratio.den());
        ASSERT_EQ(ratio2.den(), ratio.den()*ratio.den());
    }
}

// --
TEST (RatioArithmetic, iterationMinus) {
    const unsigned int maxVal = 1000;
    std::default_random_engine generator(0);
    std::uniform_int_distribution<int> uniformDistributionValue(-int(maxVal), maxVal);
    auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};
    for (size_t run = 0; run < 100; ++run) {
        Ratio<int> ratio(gen(), gen());
        Ratio<int> ratio2(--ratio);
        int gcd = std::gcd(ratio.num()*ratio.den()-ratio.den()*ratio.den(), ratio.den()*ratio.den()); // a/b - b/b = (a*b-b*b)/(b*b)
        ASSERT_EQ(ratio2.num(), ratio.num()*ratio.den()-ratio.den()*ratio.den());
        ASSERT_EQ(ratio2.den(), ratio.den()*ratio.den());
    }
}

// moins unaire
TEST (RatioArithmetic, unaryMinus) {

    const unsigned int maxVal = 1000;
    std::default_random_engine generator(0);
    std::uniform_int_distribution<int> uniformDistributionValue(-int(maxVal), maxVal);
    auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};
    for (size_t run = 0; run < 100; ++run) {
        Ratio<int> ratio(gen(), gen());
        Ratio<int> ratio2(-ratio);
        ASSERT_EQ(ratio2.num(), -ratio.num());
        ASSERT_EQ(ratio2.den(), ratio.den());
    }
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - -
// C O M P A R A I S O N S



int main() {
    Ratio<int> a(4, 9);
    Ratio<int> b(5, 10);
    Ratio<int> c = a;
    Ratio<int> d = a.sqrt();
    Ratio<int> e(3, 10);
    Ratio<int> f = e.sqrt();
    Ratio<int> g(-34, 10);
    Ratio<int> h(34, -10);
    Ratio<int> i(-34, -10);
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
    // std::cout << "//////////////" << std::endl;
    // std::cout << d << std::endl;
    // std::cout << f << std::endl;
    // std::cout << e.pow(4) << std::endl;
    // std::cout << g.abs() << std::endl;
    // std::cout << g.int_part() << std::endl;
    // std::cout << a.int_part() << std::endl;
    // std::cout << "//////////////" << std::endl;
    // std::cout << a.log() << std::endl;
    // std::cout << g.log() << std::endl;
    // std::cout << a.cos() << std::endl;
    // std::cout << g.cos() << std::endl;
    // std::cout << "//////////////" << std::endl;
    // std::cout << convert_float_to_ratio(M_PI, 20) << std::endl;
    // std::cout << convert_float_to_ratio(-M_PI, 20) << std::endl;
    // std::cout << convert_float_to_ratio(14852.958645, 20) << std::endl;
    std::cout << 2+a << std::endl;
    std::cout << 2-a << std::endl;
    std::cout << 2*a << std::endl;
    std::cout << 2/a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a-- << std::endl;
}  