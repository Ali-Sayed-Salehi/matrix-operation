//
// Created by Ali Sayed Salehi on 2023-07-06.
//

#include <iostream>
#include "inc/Mat2x2.h"


Mat2x2::Mat2x2(): matrix(array< array<double, 2>, 2>()) {
}

Mat2x2::Mat2x2(double a00, double a01, double a10, double a11):
    matrix(array< array<double, 2>, 2>({a00, a01, a10, a11})) {
}
/*

std::istream &Mat2x2::operator>>(std::istream &is) {
    for (auto& row : matrix) {
        for (auto& element : row) {
            is >> element;
        }
    }
    return is;
}
*/

/*

std::ostream &Mat2x2::operator<<(std::ostream &os, const Mat2x2 &target) const {
    for (auto& row : target.matrix) {
        for (auto& element : row) {
            os << element << " ";
        }
        os << std::endl;
    }
    return os;
}
*/

/*

Mat2x2 Mat2x2::operator+(const Mat2x2 &other) const {

    Mat2x2 sumMatrix{};
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            sumMatrix.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
        }
    }

    return sumMatrix;
}
*/

const array<array<double, 2>, 2> &Mat2x2::getMatrix() const {
    return matrix;
}


bool isAlmostEqual(double first,
                           double second, double epsilon) {
    if (abs(first - second) < epsilon) return true;
    return false;
}

bool isNotAlmostEqual(double first,
                              double second, double epsilon) {
    return !isAlmostEqual(first, second, epsilon);
}

void Mat2x2::write(std::ostream &os) const {
    for (auto& row : matrix) {
        for (auto& element : row) {
            os << element << " ";
        }
        os << std::endl;
    }
}

void Mat2x2::read(std::istream &sin) {
    for (auto& row : matrix) {
        for (auto& element : row) {
            sin >> element;
        }
    }
}

Mat2x2 Mat2x2::add(const Mat2x2 &a, const Mat2x2 &b) {
    Mat2x2 sum{};
    for (int i = 0; i < a.matrix.size(); ++i) {
        for (int j = 0; j < a.matrix[i].size(); ++j) {
            sum.matrix[i][j] = a.matrix[i][j] + b.matrix[i][j];
        }
    }
    return sum;
}

Mat2x2 Mat2x2::subtract(const Mat2x2 &a, const Mat2x2 &b) {
    Mat2x2 result{};
    for (int i = 0; i < a.matrix.size(); ++i) {
        for (int j = 0; j < a.matrix[i].size(); ++j) {
            result.matrix[i][j] = a.matrix[i][j] - b.matrix[i][j];
        }
    }
    return result;
}

Mat2x2 Mat2x2::addScalar(double s, const Mat2x2 &a) {
    Mat2x2 result{};
    for (int i = 0; i < a.matrix.size(); ++i) {
        for (int j = 0; j < a.matrix[i].size(); ++j) {
            result.matrix[i][j] = a.matrix[i][j] + s;
        }
    }
    return result;
}

Mat2x2 Mat2x2::subtractScalar(double s, const Mat2x2 &a) {
    Mat2x2 result{};
    for (int i = 0; i < a.matrix.size(); ++i) {
        for (int j = 0; j < a.matrix[i].size(); ++j) {
            result.matrix[i][j] = s - a.matrix[i][j];
        }
    }
    return result;
}

Mat2x2 Mat2x2::subtractScalar(const Mat2x2 &a, double s) {
    Mat2x2 result{};
    for (int i = 0; i < a.matrix.size(); ++i) {
        for (int j = 0; j < a.matrix[i].size(); ++j) {
            result.matrix[i][j] = a.matrix[i][j] - s;
        }
    }
    return result;
}

Mat2x2 Mat2x2::multiply(const Mat2x2 &a, const Mat2x2 &b) {
    Mat2x2 result{};

    size_t aRows = a.matrix.size();
    size_t aCols = a.matrix[0].size();
    size_t bCols = b.matrix[0].size();

    for (size_t i = 0; i < aRows; ++i) {
        for (size_t j = 0; j < bCols; ++j) {
            for (size_t k = 0; k < aCols; ++k) {
                result.matrix[i][j] += a.matrix[i][k] * b.matrix[k][j];
            }
        }
    }
    return result;
}
