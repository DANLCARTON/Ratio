#include "ratio.hpp"
#include <math.h>

Ratio<int> convert_float_to_ratio(const double &real, const unsigned int &nbIter) {
    
    if (real == 0) return Ratio<int> (0, 1);
    if (nbIter == 0) return Ratio<int> (0, 1);
    
    if (real < 0){
        int x = std::abs(real);
        if (x < 1.0) return convert_float_to_ratio(1.0/x, nbIter-1).inverse();
        if (x >= 1.0) {
            int q = (int)x;
            return Ratio<int>(q, 1)+convert_float_to_ratio(x-(double)q, nbIter-1);
        }        

    }
    if (real > 0 ){
        if (real < 1.0) return convert_float_to_ratio(1.0/real, nbIter-1).inverse();
        if (real >= 1.0) {
            int q = (int)real;
            return Ratio<int>(q, 1)+convert_float_to_ratio(real-(double)q, nbIter-1);
        }
    }
    return Ratio<int> (0,1);
}