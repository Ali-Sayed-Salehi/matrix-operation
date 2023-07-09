//
// Created by Ali Sayed Salehi on 2023-07-06.
//

#ifndef MATRIX_OPERATION_MAT2X2_H
#define MATRIX_OPERATION_MAT2X2_H


#include <array>
using std::array;

class Mat2x2 {
private:
    array< array<double, 2>, 2> matrix {};
public:
    // special member functions
    Mat2x2();
    Mat2x2(const Mat2x2& other) = default;
    Mat2x2(Mat2x2&& other) = default;
    Mat2x2& operator=(const Mat2x2& rhs) = default;
    Mat2x2& operator=(Mat2x2&& rhs) = default;
    ~Mat2x2() = default;

    // custom constructor
    Mat2x2(double a00, double a01, double a10, double a11);

    // accessors
    const array< array<double, 2>, 2>& getMatrix() const;

    // facilitator functions
    void write(std::ostream& os)const;
    void read(std::istream& sin);
    static Mat2x2 add(const Mat2x2& a, const Mat2x2& b) ; // a - b
    static Mat2x2 subtract(const Mat2x2& a, const Mat2x2& b) ; // b - a
    static Mat2x2 addScalar(double s, const Mat2x2& a); // a + s
    static Mat2x2 subtractScalar(double s, const Mat2x2& a); // s - a
    static Mat2x2 subtractScalar(const Mat2x2& a, double s); // a - s
    static Mat2x2 multiply(const Mat2x2& a, const Mat2x2& b); // a * b


};
/*

Mat2x2 operator+(const Mat2x2& other) const;

std::istream& operator>>(std::istream& is);
std::ostream& operator<<(std::ostream& os, const Mat2x2 &target) const;
*/

bool isAlmostEqual(
        double first, double second, double epsilon = 1.0e-6) ;

bool isNotAlmostEqual(
        double first, double second, double epsilon = 1.0e-6) ;

#endif //MATRIX_OPERATION_MAT2X2_H
