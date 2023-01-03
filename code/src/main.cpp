#include "ratio.hpp"
#include <iostream>
#include <random>
#include <string>
#include <algorithm>
#include <limits>
#include <gtest/gtest.h>

long int long_gcd(long int a, long int b) {
    if (b == 0) return a;
    return long_gcd(b, a%b);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// C O N S T R U C T E U R S 

TEST (RatioConstructor, defaultConstructor) {
    Ratio<int> ratio;
    EXPECT_EQ(ratio.num(), 0);
    EXPECT_EQ(ratio.den(), 1);
}

TEST (RatioConstructor, copyConstructor) {
    const unsigned int maxVal = 100;
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

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// O P E R A T E U R S

// Somme
TEST (RatioArithmetic, plus) {
    const unsigned int maxVal = 100;
    std::default_random_engine generator(0);
    std::uniform_int_distribution<int> uniformDistributionValue(-int(maxVal), maxVal);
    auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};
    for (size_t run = 0; run < 100; ++run) {
        Ratio<int> ratio1(gen(), gen());
        Ratio<int> ratio2(gen(), gen());
        Ratio<int> ratio3;
        ratio3 = ratio1 + ratio2;
        int gcd = std::gcd(ratio1.num()*ratio2.den()+ratio1.den()*ratio2.num(), ratio2.den()*ratio1.den());
        if (ratio2.den()*ratio1.den() < 0) gcd = -gcd;
        ASSERT_EQ(ratio3.num(), (ratio1.num()*ratio2.den()+ratio1.den()*ratio2.num())/gcd);
        ASSERT_EQ(ratio3.den(), (ratio2.den()*ratio1.den())/gcd);
    }
}

// Commutativité de l'somme
TEST (RatioArithmetic, plusComutativity) {
    const unsigned int maxVal = 100;
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
    const unsigned int maxVal = 100;
    std::default_random_engine generator(0);
    std::uniform_int_distribution<int> uniformDistributionValue(-int(maxVal), maxVal);
    auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};
    for (size_t run = 0; run < 100; ++run) {
        Ratio<int> ratio1(gen(), gen());
        Ratio<int> ratio2(gen(), gen());
        Ratio<int> ratio3;
        ratio3 = ratio1 - ratio2;
        int gcd = std::gcd(ratio1.num()*ratio2.den()-ratio1.den()*ratio2.num(), ratio2.den()*ratio1.den());
        if (ratio2.den()*ratio1.den() < 0) gcd = -gcd;
        ASSERT_EQ(ratio3.num(), (ratio1.num()*ratio2.den()-ratio1.den()*ratio2.num())/gcd);
        ASSERT_EQ(ratio3.den(), (ratio2.den()*ratio1.den())/gcd);
    }
}

// Produit
TEST (RatioArithmetic, multiply) {
    const unsigned int maxVal = 100;
    std::default_random_engine generator(0);
    std::uniform_int_distribution<int> uniformDistributionValue(-int(maxVal), maxVal);
    auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};
    for (size_t run = 0; run < 100; ++run) {
        Ratio<int> ratio1(gen(), gen());
        Ratio<int> ratio2(gen(), gen());
        Ratio<int> ratio3;
        ratio3 = ratio1 * ratio2;
        int gcd = std::gcd(ratio1.num()*ratio2.num(), ratio1.den()*ratio2.den());
        if (ratio1.den()*ratio2.den() < 0) gcd = -gcd;
        ASSERT_EQ(ratio3.num(), (ratio1.num()*ratio2.num())/gcd);
        ASSERT_EQ(ratio3.den(), (ratio1.den()*ratio2.den())/gcd);
    }
}

// Comutativité du produit
TEST (RatioArithmetic, multiplyComutativity) {
    const unsigned int maxVal = 100;
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
    const unsigned int maxVal = 100;
    std::default_random_engine generator(0);
    std::uniform_int_distribution<int> uniformDistributionValue(-int(maxVal), maxVal);
    auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};
    for (size_t run = 0; run < 100; ++run) {
        Ratio<int> ratio1(gen(), gen());
        Ratio<int> ratio2(gen(), gen());
        Ratio<int> ratio3;
        ratio3 = ratio1 / ratio2;
        int gcd = std::gcd(ratio1.num()*ratio2.den(), ratio1.den()*ratio2.num());
        if (ratio1.den()*ratio2.num() < 0) gcd = -gcd;
        ASSERT_EQ(ratio3.num(), (ratio1.num()*ratio2.den())/gcd);
        ASSERT_EQ(ratio3.den(), (ratio1.den()*ratio2.num())/gcd);
    }
}

// ++
TEST (RatioArithmetic, itrationPlus) {
    const unsigned int maxVal = 100;
    std::default_random_engine generator(0);
    std::uniform_int_distribution<int> uniformDistributionValue(-int(maxVal), maxVal);
    auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};
    for (size_t run = 0; run < 100; ++run) {
        Ratio<int> ratio(gen(), gen());
        while(!(ratio.den() != 0)) {
            ratio = Ratio(gen(), gen());
        }
        Ratio<int> ratio2(++ratio);
        int gcd = std::gcd(ratio.num()*ratio.den()+ratio.den()*ratio.den(), ratio.den()*ratio.den()); // a/b + b/b = (a*b+b*b)/(b*b)
        if (ratio.den()*ratio.den() < 0) gcd = -gcd;
        ASSERT_EQ(ratio2.num(), (ratio.num()*ratio.den()+ratio.den()*ratio.den())/gcd);
        ASSERT_EQ(ratio2.den(), (ratio.den()*ratio.den())/gcd);
    }
}

// --
TEST (RatioArithmetic, iterationMinus) {
    const unsigned int maxVal = 100;
    std::default_random_engine generator(0);
    std::uniform_int_distribution<int> uniformDistributionValue(-int(maxVal), maxVal);
    auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};
    for (size_t run = 0; run < 100; ++run) {
        Ratio<int> ratio(gen(), gen());
        while(!(ratio.den() != 0)) {
            ratio = Ratio(gen(), gen());
        }
        Ratio<int> ratio2(--ratio);
        int gcd = std::gcd(ratio.num()*ratio.den()-ratio.den()*ratio.den(), ratio.den()*ratio.den()); // a/b - b/b = (a*b-b*b)/(b*b)
        if (ratio.den()*ratio.den() < 0) gcd = -gcd;
        ASSERT_EQ(ratio2.num(), (ratio.num()*ratio.den()-ratio.den()*ratio.den())/gcd);
        ASSERT_EQ(ratio2.den(), (ratio.den()*ratio.den())/gcd);
    }
}

// moins unaire
TEST (RatioArithmetic, unaryMinus) {
    const unsigned int maxVal = 100;
    std::default_random_engine generator(0);
    std::uniform_int_distribution<int> uniformDistributionValue(-int(maxVal), maxVal);
    auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};
    for (size_t run = 0; run < 100; ++run) {
        Ratio<int> ratio(gen(), gen());
        Ratio<int> ratio2(-ratio);
        int gcd = std::gcd(-ratio.num(), ratio.den());
        if (ratio.den() < 0) gcd = -gcd;
        ASSERT_EQ(ratio2.num(), -ratio.num()/gcd);
        ASSERT_EQ(ratio2.den(), ratio.den()/gcd);
    }
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// C O M P A R A I S O N S

// égalité
TEST (RatioLogic, equality) {
    const unsigned int maxVal = 5;
    std::default_random_engine generator(0);
    std::uniform_int_distribution<int> uniformDistributionValue(-int(maxVal), maxVal);
    auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};
    for (size_t run = 0; run < 100; ++run) {
        Ratio<int> ratio(gen(), gen());
        while(!(ratio.den() != 0)) {
            ratio = Ratio(gen(), gen());
        }
        Ratio<int> ratio2(gen(), gen());
        while(!(ratio2.den() != 0)) {
            ratio2 = Ratio(gen(), gen());
        }
        int gcd1 = std::gcd(ratio.num(), ratio.den());
        int gcd2 = std::gcd(ratio2.num(), ratio2.den());
        if (ratio.den() < 0) gcd1 = -gcd1;
        if (ratio2.den() < 0) gcd2 = -gcd2;
        if (ratio == ratio2) {
            ASSERT_EQ(ratio.num()/gcd1, ratio2.num()/gcd2);
            ASSERT_EQ(ratio.den()/gcd1, ratio2.den()/gcd2);
        }        
    }
}

//inégalité
TEST (RatioLogic, nonequality) {
    const unsigned int maxVal = 5;
    std::default_random_engine generator(0);
    std::uniform_int_distribution<int> uniformDistributionValue(-int(maxVal), maxVal);
    auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};
    for (size_t run = 0; run < 100; ++run) {
        Ratio<int> ratio(gen(), gen());
        while(!(ratio.den() != 0)) {
            ratio = Ratio(gen(), gen());
        }
        Ratio<int> ratio2(gen(), gen());
        while(!(ratio2.den() != 0)) {
            ratio2 = Ratio(gen(), gen());
        }
        double gcd1 = std::gcd(ratio.num(), ratio.den());
        double gcd2 = std::gcd(ratio2.num(), ratio2.den());
        if (ratio.den() < 0) gcd1 = -gcd1;
        if (ratio2.den() < 0) gcd2 = -gcd2;
        if (ratio != ratio2) {
            ASSERT_NE(((double)ratio.num()/gcd1)/((double)ratio.den()/gcd1), ((double)ratio2.num()/gcd2)/((double)ratio2.den()/gcd2));
        }
    }
}

//plus petit que
TEST (RatioLogic, lowerThan) {
    const unsigned int maxVal = 5;
    std::default_random_engine generator(0);
    std::uniform_int_distribution<int> uniformDistributionValue(-int(maxVal), maxVal);
    auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};
    for (size_t run = 0; run < 100; ++run) {
        Ratio<int> ratio(gen(), gen());
        while(!(ratio.den() != 0)) {
            ratio = Ratio(gen(), gen());
        }
        Ratio<int> ratio2(gen(), gen());
        while(!(ratio2.den() != 0)) {
            ratio2 = Ratio(gen(), gen());
        }
        double gcd1 = std::gcd(ratio.num(), ratio.den());
        double gcd2 = std::gcd(ratio2.num(), ratio2.den());
        if (ratio.den() < 0) gcd1 = -gcd1;
        if (ratio2.den() < 0) gcd2 = -gcd2;
        if (ratio < ratio2) {
            ASSERT_LT(((double)ratio.num()/gcd1)/((double)ratio.den()/gcd1), ((double)ratio2.num()/gcd2)/((double)ratio2.den()/gcd2));
        }
    }
}

// plus petit ou egal à
TEST (RatioLogic, lowerEqual) {
    const unsigned int maxVal = 5;
    std::default_random_engine generator(0);
    std::uniform_int_distribution<int> uniformDistributionValue(-int(maxVal), maxVal);
    auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};
    for (size_t run = 0; run < 100; ++run) {
        Ratio<int> ratio(gen(), gen());
        while(!(ratio.den() != 0)) {
            ratio = Ratio(gen(), gen());
        }
        Ratio<int> ratio2(gen(), gen());
        while(!(ratio2.den() != 0)) {
            ratio2 = Ratio(gen(), gen());
        }
        double gcd1 = std::gcd(ratio.num(), ratio.den());
        double gcd2 = std::gcd(ratio2.num(), ratio2.den());
        if (ratio.den() < 0) gcd1 = -gcd1;
        if (ratio2.den() < 0) gcd2 = -gcd2;
        if (ratio <= ratio2) {
            ASSERT_LE(((double)ratio.num()/gcd1)/((double)ratio.den()/gcd1), ((double)ratio2.num()/gcd2)/((double)ratio2.den()/gcd2));
        }
    }
}

// plus grand que
TEST (RatioLogic, greaterThan) {
    const unsigned int maxVal = 5;
    std::default_random_engine generator(0);
    std::uniform_int_distribution<int> uniformDistributionValue(-int(maxVal), maxVal);
    auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};
    for (size_t run = 0; run < 100; ++run) {
        Ratio<int> ratio(gen(), gen());
        while(!(ratio.den() != 0)) {
            ratio = Ratio(gen(), gen());
        }
        Ratio<int> ratio2(gen(), gen());
        while(!(ratio2.den() != 0)) {
            ratio2 = Ratio(gen(), gen());
        }
        double gcd1 = std::gcd(ratio.num(), ratio.den());
        double gcd2 = std::gcd(ratio2.num(), ratio2.den());
        if (ratio.den() < 0) gcd1 = -gcd1;
        if (ratio2.den() < 0) gcd2 = -gcd2;
        if (ratio > ratio2) {
            ASSERT_GT(((double)ratio.num()/gcd1)/((double)ratio.den()/gcd1), ((double)ratio2.num()/gcd2)/((double)ratio2.den()/gcd2));
        }
    }
}

// plus grand ou égal à
TEST (RatioLogic, greaterEqual) {
    const unsigned int maxVal = 5;
    std::default_random_engine generator(0);
    std::uniform_int_distribution<int> uniformDistributionValue(-int(maxVal), maxVal);
    auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};
    for (size_t run = 0; run < 100; ++run) {
        Ratio<int> ratio(gen(), gen());
        while(!(ratio.den() != 0)) {
            ratio = Ratio(gen(), gen());
        }
        Ratio<int> ratio2(gen(), gen());
        while(!(ratio2.den() != 0)) {
            ratio2 = Ratio(gen(), gen());
        }
        double gcd1 = std::gcd(ratio.num(), ratio.den());
        double gcd2 = std::gcd(ratio2.num(), ratio2.den());
        if (ratio.den() < 0) gcd1 = -gcd1;
        if (ratio2.den() < 0) gcd2 = -gcd2;
        if (ratio >= ratio2) {
            ASSERT_GE(((double)ratio.num()/gcd1)/((double)ratio.den()/gcd1), ((double)ratio2.num()/gcd2)/((double)ratio2.den()/gcd2));
        }
    }
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// M E T H O D E S 

TEST (RatioMethods, invert) {
    const unsigned int maxVal = 100;
    std::default_random_engine generator(0);
    std::uniform_int_distribution<int> uniformDistributionValue(-int(maxVal), maxVal);
    auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};
    for (size_t run = 0; run < 100; ++run) {
        Ratio<int> ratio(gen(), gen());
        Ratio<int> ratio2 = ratio.inverse();
        int gcd = std::gcd(ratio.den(), ratio.num());
        if (ratio.num() < 0) gcd = -gcd;
        ASSERT_EQ(ratio2.num(), ratio.den()/gcd);
        ASSERT_EQ(ratio2.den(), ratio.num()/gcd);
    }
}

// rendre irreductible
TEST (RatioMethods, makeIrreductible) {
    const unsigned int maxVal = 100;
    std::default_random_engine generator(0);
    std::uniform_int_distribution<int> uniformDistributionValue(-int(maxVal), maxVal);
    auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};
    for (size_t run = 0; run < 100; ++run) {
        Ratio<int> ratio(gen(), gen());
        Ratio<int> ratio2 = ratio.make_irreductible();
        int gcd = std::gcd(ratio.num(), ratio.den());
        if (ratio.den() < 0) gcd = -gcd;
        ASSERT_EQ(ratio2.num(), ratio.num()/gcd);
        ASSERT_EQ(ratio2.den(), ratio.den()/gcd);
    }
}

// racine carrée
TEST(RatioMethods, squareRoot) {
    const unsigned int maxVal = 50;
    std::default_random_engine generator(0);
    std::uniform_int_distribution<int> uniformDistributionValue(1, maxVal);
    auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};
    for (size_t run = 0; run < 100; ++run) {
        Ratio<int> ratio(gen(), gen());
        while(!(ratio.den() != 0)) {
            ratio = Ratio(gen(), gen());
        }
        Ratio<int> sqrt = ratio.sqrt();
        int gcd = std::gcd((int)std::sqrt(ratio.num()), (int)std::sqrt(ratio.den()));
        if (std::sqrt(ratio.den()) < 0) gcd = -gcd;
        ASSERT_DOUBLE_EQ((double)sqrt.num()/(double)sqrt.den(), std::sqrt((double)ratio.num()/(double)ratio.den()));
    }
}

// cosinus
TEST(RatioMethods, cosinus) {
    const unsigned int maxVal = 50;
    std::default_random_engine generator(0);
    std::uniform_int_distribution<int> uniformDistributionValue(-int(maxVal), maxVal);
    auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};
    for (size_t run = 0; run < 100; ++run) {
        Ratio<int> ratio(gen(), gen());
        Ratio<int> cos = ratio.cos();
        ASSERT_DOUBLE_EQ((double)cos.num()/(double)cos.den(), std::cos((double)ratio.num()/(double)ratio.den()));
    }
}

// sinus
TEST(RatioMethods, sinus) {
    const unsigned int maxVal = 50;
    std::default_random_engine generator(0);
    std::uniform_int_distribution<int> uniformDistributionValue(-int(maxVal), maxVal);
    auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};
    for (size_t run = 0; run < 100; ++run) {
        Ratio<int> ratio(gen(), gen());
        Ratio<int> sin = ratio.sin();
        ASSERT_DOUBLE_EQ((double)sin.num()/(double)sin.den(), std::sin((double)ratio.num()/(double)ratio.den()));
    }
}

// tangente
TEST(RatioMethods, tangent) {
    const unsigned int maxVal = 50;
    std::default_random_engine generator(0);
    std::uniform_int_distribution<int> uniformDistributionValue(-int(maxVal), maxVal);
    auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};
    for (size_t run = 0; run < 100; ++run) {
        Ratio<int> ratio(gen(), gen());
        Ratio<int> tan = ratio.tan();
        ASSERT_DOUBLE_EQ((double)tan.num()/(double)tan.den(), std::tan((double)ratio.num()/(double)ratio.den()));
    }
}

// puissance
TEST(RatioMethods, power) {
    const unsigned int maxVal = 10;
    std::default_random_engine generator(0);
    std::uniform_int_distribution<int> uniformDistributionValue(0, maxVal);
    auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};
    for (size_t run = 0; run < 100; ++run) {
        Ratio<long int> ratio(gen(), gen());
        int power = gen();
        Ratio<long int> pow = ratio.pow(power);
        long int gcd = long_gcd(std::pow(ratio.num(), power), std::pow(ratio.den(), power));
        if (std::pow(ratio.num(), power) < 0) gcd = -gcd;
        ASSERT_EQ(pow.num(), std::pow(ratio.num(), power)/gcd);
        ASSERT_EQ(pow.den(), std::pow(ratio.den(), power)/gcd);
    }
}

// exponentielle
TEST (RatioMethods, exp) {
    const unsigned int maxVal = 10;
    std::default_random_engine generator(0);
    std::uniform_int_distribution<int> uniformDistributionValue(-int(maxVal), maxVal);
    auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};
    for (size_t run = 0; run < 100; ++run) {
        Ratio<int> ratio(gen(), gen());
        Ratio<int> exp = ratio.exp();
        ASSERT_DOUBLE_EQ((double)exp.num()/(double)exp.den(), std::exp((double)ratio.num()/(double)ratio.den()));
    }
}

// logarithme
TEST (RatioMethods, logarithm) {
    const unsigned int maxVal = 10;
    std::default_random_engine generator(0);
    std::uniform_int_distribution<int> uniformDistributionValue(1, maxVal);
    auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};
    for (size_t run = 0; run < 100; ++run) {
        Ratio<int> ratio(gen(), gen());
        double log = ratio.log();
        ASSERT_DOUBLE_EQ(log, std::log((double)ratio.num()) - std::log((double)ratio.den()));
    }
}

// partie entière
TEST (RatioMethods, integerPart) {
    const unsigned int maxVal = 10;
    std::default_random_engine generator(0);
    std::uniform_int_distribution<int> uniformDistributionValue(-(int)maxVal, maxVal);
    auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};
    for (size_t run = 0; run < 100; ++run) {
        Ratio<int> ratio(gen(), gen());
        while(!(ratio.den() != 0)) {
            ratio = Ratio(gen(), gen());
        }
        int intPart = ratio.int_part();
        int neg = 0;
        if ((double)ratio.num()/(double)ratio.den() < 0) neg = 1;
        ASSERT_EQ(intPart, (int)((double)ratio.num()/(double)ratio.den())-neg);
    }
}

// valeur absolue
TEST (RatioMethods, absoluteValue) {
    const unsigned int maxVal = 10;
    std::default_random_engine generator(0);
    std::uniform_int_distribution<int> uniformDistributionValue(-(int)maxVal, maxVal);
    auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};
    for (size_t run = 0; run < 100; ++run) {
        Ratio<int> ratio(gen(), gen());
        ratio = ratio.make_irreductible();
        Ratio<int> abs = ratio.abs();
        if (ratio.num() < 0) ASSERT_EQ (abs.num(), -ratio.num());
        else ASSERT_EQ(abs.num(), ratio.num());
    }
}

int main(int argc, char **argv) {
    /*
    Ratio<int> a(4, 9);
    Ratio<int> b(5, 10);
    Ratio<int> c = a;
    Ratio<int> d = a.sqrt();
    Ratio<int> e(3, 10);
    Ratio<int> f = e.sqrt();
    Ratio<int> g(-34, 10);
    Ratio<int> h(34, -10);
    Ratio<int> i(-34, -10);
    Ratio<long int> j(4000000000000, 4123456789123);
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
    std::cout << "//////////////" << std::endl;
    std::cout << d << std::endl;
    std::cout << f << std::endl;
    std::cout << e.pow(4) << std::endl;
    std::cout << g.abs() << std::endl;
    std::cout << g.int_part() << std::endl;
    std::cout << a.int_part() << std::endl;
    std::cout << "//////////////" << std::endl;
    std::cout << a.log() << std::endl;
    std::cout << g.log() << std::endl;
    std::cout << "cos : " << a.cos() << std::endl;
    std::cout << "cos : " << g.cos() << std::endl;
    std::cout << "//////////////" << std::endl;
    std::cout << convert_float_to_ratio(M_PI, 20) << std::endl;
    std::cout << convert_float_to_ratio(-M_PI, 20) << std::endl;
    std::cout << convert_float_to_ratio(14852.958645, 20) << std::endl;
    std::cout << 2+a << std::endl;
    std::cout << 2-a << std::endl;
    std::cout << 2*a << std::endl;
    std::cout << 2/a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a-- << std::endl;
    Ratio aa = convert_float_to_ratio(2.5, 10);
    std::cout << "test normal : " << convert_float_to_ratio(14852.958645, 47) << std::endl; // je crois qu'on ne pourra pas régler ça :/
    std::cout << "test normal : " << convert_float_to_ratio(148.52,53) << std::endl;
    std::cout << "aa : " << aa <<  std::endl;
    std::cout << "test normal : " << convert_float_to_ratio(0.738469,53) << std::endl;
    std::cout << g.sqrt() << std::endl;
    std::cout << Ratio<int>(-3628800, -132710400).make_irreductible() << std::endl;
    */

    //Tests unitaires
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}  