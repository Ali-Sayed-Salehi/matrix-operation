//
// Created by Ali Sayed Salehi on 2023-07-04.
//
#include <iostream>
#include "inc/Matrix.h"
#include "src/Mat2x2.cpp"

int main() {
    Matrix* matrix = new Mat2x2();
    std::cout << (Matrix::isAlmostEqual(1e-6, 1.5e-6)) << std::endl;
    std::cout << (Matrix::isNotAlmostEqual(1e-6, 1.5e-6)) << std::endl;
    return 0;
}
