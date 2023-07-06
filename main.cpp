//
// Created by Ali Sayed Salehi on 2023-07-04.
//
#include <iostream>
#include "inc/Matrix.h"
#include "src/Mat2x2.cpp"

int main() {
    Matrix* matrix = new Mat2x2();
    std::cout << (matrix->isAlmostEqual(0, 0)) << std::endl;
    return 0;
}
