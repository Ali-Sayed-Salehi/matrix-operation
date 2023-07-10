//
// Created by Ali Sayed Salehi on 2023-07-06.
//

#include <iostream>
#include <iomanip>
#include "inc/Mat2x2.h"


Mat2x2::Mat2x2(): matrix(array< array<double, 2>, 2>()) {
}

Mat2x2::Mat2x2(const double& a00, const double& a01, const double& a10, const double& a11):
    matrix(array< array<double, 2>, 2>({a00, a01, a10, a11})) {
}

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
        os << "|  ";
        for (auto& element : row) {
            os << std::left << " " << std::setw(8) << element;
        }
        os << "|" << std::endl;
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

Mat2x2 Mat2x2::addScalar(const double& s, const Mat2x2 &a) {
    Mat2x2 result{};
    for (int i = 0; i < a.matrix.size(); ++i) {
        for (int j = 0; j < a.matrix[i].size(); ++j) {
            result.matrix[i][j] = a.matrix[i][j] + s;
        }
    }
    return result;
}

Mat2x2 Mat2x2::subtractScalar(const double& s, const Mat2x2 &a) {
    Mat2x2 result{};
    for (int i = 0; i < a.matrix.size(); ++i) {
        for (int j = 0; j < a.matrix[i].size(); ++j) {
            result.matrix[i][j] = s - a.matrix[i][j];
        }
    }
    return result;
}

Mat2x2 Mat2x2::subtractScalar(const Mat2x2 &a, const double& s) {
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

const double &Mat2x2::operator[](const int& index) const {
    switch (index) {
        case 0:
            return matrix[0][0];
        case 1:
            return matrix[0][1];
        case 2:
            return matrix[1][0];
        case 3:
            return matrix[1][1];
        default:
            throw std::invalid_argument("index out of bounds");
    }
}

double &Mat2x2::operator[](const int& index) {
    switch (index) {
        case 0:
            return matrix[0][0];
        case 1:
            return matrix[0][1];
        case 2:
            return matrix[1][0];
        case 3:
            return matrix[1][1];
        default:
            throw std::invalid_argument("index out of bounds");
    }
}

bool operator==(const Mat2x2 &lhs, const Mat2x2& rhs) {
    auto lhsMatrix = lhs.getMatrix();
    auto rhsMatrix = rhs.getMatrix();

    for (int i = 0; i < lhsMatrix.size(); ++i) {
        for (int j = 0; j < lhsMatrix[i].size(); ++j) {
            if (isNotAlmostEqual(lhsMatrix[i][j], rhsMatrix[i][j])) return false;
        }
    }

    return true;
}

bool operator!=(const Mat2x2 &lhs, const Mat2x2& rhs) {
    return !(lhs == rhs);
}

Mat2x2 Mat2x2::operator+() {
    return *this;
}

Mat2x2 Mat2x2::operator-() {
    Mat2x2 result{};
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            result.matrix[i][j] = - matrix[i][j];
        }
    }
    return result;
}

Mat2x2 operator+(const Mat2x2& matrix1, const Mat2x2& matrix2){
    Mat2x2 temp{matrix1};
    temp += matrix2;
    return temp;
}
Mat2x2 operator+(const Mat2x2& matrix1, const double& scalar){
    Mat2x2 temp{matrix1};
    temp += scalar;
    return temp;
}

Mat2x2 operator+(const double& scalar, const Mat2x2& matrix1){
    Mat2x2 temp{matrix1};
    temp += scalar;
    return temp;
}

Mat2x2 &Mat2x2::operator+=(const Mat2x2 &rhs) {
    *this = Mat2x2::add(*this, rhs);
    return *this;
}

Mat2x2 operator-(const Mat2x2& matrix1, const Mat2x2& matrix2){
    Mat2x2 temp{matrix1};
    temp -= matrix2;
    return temp;
}

Mat2x2 operator-(const Mat2x2& matrix1, const double& scalar){
    Mat2x2 temp{matrix1};
    temp -= scalar;
    return temp;
}

Mat2x2 operator-(const double& scalar, const Mat2x2& matrix1){
    return Mat2x2::subtractScalar(scalar, matrix1);
}

Mat2x2 &Mat2x2::operator-=(const Mat2x2 &rhs) {
    *this = Mat2x2::subtract(*this, rhs);
    return *this;
}

Mat2x2 &Mat2x2::operator*=(const double& scalar) {
    *this = Mat2x2::multiplyByScalar(*this, scalar);
    return *this;
}

Mat2x2 Mat2x2::multiplyByScalar(const double& s, const Mat2x2 &a) {
    Mat2x2 result{};
    for (int i = 0; i < a.matrix.size(); ++i) {
        for (int j = 0; j < a.matrix[i].size(); ++j) {
            result.matrix[i][j] = s * a.matrix[i][j];
        }
    }
    return result;
}

Mat2x2 Mat2x2::multiplyByScalar(const Mat2x2 &a, const double& s) {
    return multiplyByScalar(s, a);
}

Mat2x2 &Mat2x2::operator*=(const Mat2x2 &rhs) {
    *this = Mat2x2::multiply(*this, rhs);
    return *this;
}

Mat2x2 &Mat2x2::operator+=(const double& scalar) {
    *this = Mat2x2::addScalar(*this, scalar);
    return *this;
}

Mat2x2 Mat2x2::addScalar(const Mat2x2 &a, const double &s) {
    return Mat2x2::addScalar(s, a);
}

Mat2x2 &Mat2x2::operator-=(const double &scalar) {
    *this = Mat2x2::subtractScalar(*this, scalar);
    return *this;
}

Mat2x2 &Mat2x2::operator++() {
    *this = Mat2x2::addScalar(*this, 1);
    return *this;
}

Mat2x2 Mat2x2::operator++(int) {
    Mat2x2 temp(*this);
    operator++(); // pre-increment this instance
    return temp;
}

Mat2x2 &Mat2x2::operator--() {
    *this = Mat2x2::subtractScalar(*this, 1);
    return *this;
}

Mat2x2 Mat2x2::operator--(int) {
    Mat2x2 temp(*this);
    operator--(); // pre-increment this instance
    return temp;
}

double Mat2x2::determinant() const {
    return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
}

double Mat2x2::trace() const {
    return matrix[0][0] + matrix[1][1];
}

Mat2x2 Mat2x2::transpose() const {
    Mat2x2 temp{matrix[0][0], matrix[1][0], matrix[0][1], matrix[1][1]};
    return temp;
}

bool Mat2x2::isSymmetric() const {
    return matrix[0][1] == matrix[1][0];
}

bool Mat2x2::isSimilar(const Mat2x2& other) const {
    auto detA = this -> determinant();
    auto detB = other.determinant();
    auto traceA = this -> trace();
    auto traceB = other.trace();
    return (isAlmostEqual(detA, detB) && isAlmostEqual(traceA, traceB));

}

bool Mat2x2::isInvertible() const {
    auto detA = this -> determinant();
    isNotAlmostEqual(detA, 0);
    return isNotAlmostEqual(detA, 0);
}

Mat2x2 Mat2x2::inverse() const {
    if (!(this -> isInvertible())) throw std::overflow_error("Inverse undefined");
    Mat2x2 temp{matrix[1][1], -matrix[0][1], -matrix[1][0], matrix[1][1]};
    auto determinant = this -> determinant();
    return Mat2x2::multiplyByScalar(1/determinant, temp);
}

bool Mat2x2::operator!() const {
    return !(this -> isInvertible());
}

double Mat2x2::operator()() const {
    return this -> determinant();
}

Mat2x2::operator bool() const {
    return this -> isInvertible();
}

Mat2x2 Mat2x2::divide(const Mat2x2 &matrix1, const Mat2x2 &matrix2) {
    // A * bˆ-1
    if (!matrix2.isInvertible()) {
        throw std::overflow_error("cannot divide: Inverse undefined");
    }
    return Mat2x2::multiply(matrix1, matrix2.inverse());
}

Mat2x2 Mat2x2::divideScalar(const double &scalar, const Mat2x2 &matrix1) {
    //s * aˆ-1
    if (!matrix1.isInvertible()) {
        throw std::overflow_error("cannot divide: Inverse undefined");
    }
    return multiplyByScalar(scalar, matrix1.inverse());
}

Mat2x2 Mat2x2::divideScalar(const Mat2x2 &matrix1, const double &scalar) {
    // a * 1/x
    if (isAlmostEqual(scalar, 0)) {
        throw std::overflow_error("cannot divide: scalar is almost zero");
    }
    return multiplyByScalar(matrix1, 1 / scalar);
}

Mat2x2 &Mat2x2::operator/=(const double &scalar) {
    *this = Mat2x2::divideScalar(*this, scalar);
    return *this;
}

Mat2x2 &Mat2x2::operator/=(const Mat2x2 &rhs) {
    *this = Mat2x2::divide(*this, rhs);
    return *this;
}

std::istream& operator>>(std::istream& is, Mat2x2 &target){
    target.read(is);
    return is;
}

std::ostream& operator<<(std::ostream& os, const Mat2x2 &target){
    target.write(os);
    return os;
}

Mat2x2 operator*(const Mat2x2& matrix1, const Mat2x2& matrix2){
    Mat2x2 temp{matrix1};
    temp *= matrix2;
    return temp;
}

Mat2x2 operator*(const Mat2x2& matrix1, const double& scalar){
    Mat2x2 temp{matrix1};
    temp *= scalar;
    return temp;
}

Mat2x2 operator*(const double& scalar, const Mat2x2& matrix1){
    Mat2x2 temp{matrix1};
    temp *= scalar;
    return temp;
}

Mat2x2 operator/(const Mat2x2& matrix1, const Mat2x2& matrix2){
    Mat2x2 temp{matrix1};
    temp /= matrix2;
    return temp;
}

Mat2x2 operator/(const Mat2x2& matrix1, const double& scalar){
    Mat2x2 temp{matrix1};
    temp /= scalar;
    return temp;
}

Mat2x2 operator/(const double& scalar, const Mat2x2& matrix1){
    return Mat2x2::divideScalar(scalar, matrix1);
}
