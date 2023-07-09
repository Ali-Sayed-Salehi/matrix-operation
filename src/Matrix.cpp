//
// Created by Ali Sayed Salehi on 2023-07-06.
//

#include <cstdlib>
#include "../inc/Matrix.h"

bool Matrix::isAlmostEqual(double first,
                           double second, double epsilon) {
    if (abs(first - second) < epsilon) return true;
    return false;
}

bool Matrix::isNotAlmostEqual(double first,
                              double second, double epsilon) {
    return !isAlmostEqual(first, second, epsilon);
}
