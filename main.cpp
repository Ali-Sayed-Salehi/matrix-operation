//
// Created by Ali Sayed Salehi on 2023-07-04.
//
#include <iostream>
#include "src/Mat2x2.cpp"

int main() {
    Mat2x2 matrix1{1, 1, 1, 1};
    Mat2x2 matrix2{0, 0, 0, 0};
    std::cout << (Mat2x2::isAlmostEqual(1e-6, 1.5e-6)) << std::endl;
    std::cout << (Mat2x2::isNotAlmostEqual(1e-6, 1.5e-6)) << std::endl;

    Mat2x2 sum = matrix1 + matrix2;

    std::cout << sum << std::endl;
    return 0;
}
