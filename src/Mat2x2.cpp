//
// Created by Ali Sayed Salehi on 2023-07-06.
//

#include "inc/Mat2x2.h"


Mat2x2::Mat2x2(): matrix(array< array<double, 2>, 2>()) {
}

Mat2x2::Mat2x2(double a00, double a01, double a10, double a11):
    matrix(array< array<double, 2>, 2>({a00, a01, a10, a11})) {
}

std::istream &Mat2x2::operator>>(std::istream &is) {
    for (auto& row : matrix) {
        for (auto& element : row) {
            is >> element;
        }
    }
    return is;
}

std::ostream &Mat2x2::operator<<(std::ostream &os) const {
    for (auto& row : matrix) {
        for (auto& element : row) {
            os << element << " ";
        }
        os << std::endl;
    }
    return os;
}

Mat2x2 &Mat2x2::operator+(const Matrix &other) const {
    const auto& otherMat = dynamic_cast<const Mat2x2&>(other);

    Mat2x2 sumMatrix;
    for ( int i; i < matrix.size(); ++i) {
        sumMatrix.matrix[i] = matrix[i] + otherMat.matrix[i];
    }

    return sumMatrix;
}

const array<array<double, 2>, 2> &Mat2x2::getMatrix() const {
    return matrix;
}
