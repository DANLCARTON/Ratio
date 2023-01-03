#include "ratio.hpp"
#include <math.h>

Ratio<int> convert_float_to_ratio(const double &real, const unsigned int &nbIter) {

    if (real < 0) {
        double absReal = std::abs(real);
        Ratio ratio = convert_float_to_ratio(absReal, nbIter).make_irreductible();
        return -ratio;
    }

    if (real == 0) return Ratio (0, 1);

    if (nbIter == 0) return Ratio(0, 1);

    if (real < 1.0) {
        Ratio ratio = convert_float_to_ratio(1.0/real, nbIter);
        return ratio.inverse().make_irreductible();
    }
    if (real >= 1.0) {
        int q = (int)real;
        Ratio ratio(q, 1);
        Ratio ratio2 = convert_float_to_ratio(real-(double)q, nbIter-1).make_irreductible();
        return ratio+ratio2;
    }
    return Ratio(0,1); // Pour éviter un warning.
}

