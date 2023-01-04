#include "../include/ratio.hpp"
#include <math.h>

// - - - - - C O N V E R T   F L O A T   T O   R A T I O - - - - -

template <typename T> Ratio<T> convert_float_to_ratio(const double &real, const unsigned int &nbIter) {

    if (real < 0) {
        double absReal = std::abs(real);
        Ratio ratio = convert_float_to_ratio<T>(absReal, nbIter).make_irreductible();
        return -ratio;
    }

    if (real == 0) return Ratio<T> (0, 1);

    if (nbIter == 0) return Ratio<T> (0, 1);

    if (real < 1.0) {
        Ratio<T> ratio = convert_float_to_ratio<T>(1.0/real, nbIter);
        return ratio.inverse().make_irreductible();
    }
    if (real >= 1.0) {
        int q = (int)real;
        Ratio<T> ratio(q, 1);
        Ratio<T> ratio2 = convert_float_to_ratio<T>(real-(double)q, nbIter-1).make_irreductible();
        return ratio+ratio2;
    }
    return Ratio<T>(0,1); // Pour éviter un warning.
}

template class Ratio<int>;
template class Ratio<long>;
template class Ratio<long long>;