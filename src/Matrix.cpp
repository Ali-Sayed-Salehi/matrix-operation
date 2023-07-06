//
// Created by Ali Sayed Salehi on 2023-07-06.
//

#include <cstdlib>
#include "../inc/Matrix.h"

bool Matrix::isAlmostEqual(const double &first,
                           const double &second, const double &epsilon) {
    if (abs(first - second) < epsilon) return true;
    return false;
}
