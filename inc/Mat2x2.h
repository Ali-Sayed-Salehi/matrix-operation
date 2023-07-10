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
    Mat2x2(const double& a00, const double& a01, const double& a10, const double& a11);

    // accessors
    const array< array<double, 2>, 2>& getMatrix() const;

    // facilitator functions
    void write(std::ostream& os)const;
    void read(std::istream& sin);
    static Mat2x2 add(const Mat2x2& a, const Mat2x2& b) ; // a - b
    static Mat2x2 subtract(const Mat2x2& a, const Mat2x2& b) ; // b - a
    static Mat2x2 addScalar(const double& s, const Mat2x2& a); // s + a
    static Mat2x2 addScalar(const Mat2x2& a, const double& s); // a + s
    static Mat2x2 subtractScalar(const double& s, const Mat2x2& a); // s - a
    static Mat2x2 subtractScalar(const Mat2x2& a, const double& s); // a - s
    static Mat2x2 multiply(const Mat2x2& a, const Mat2x2& b); // a * b
    static Mat2x2 multiplyByScalar(const double& s, const Mat2x2& a); // s * a
    static Mat2x2 multiplyByScalar(const Mat2x2& a, const double& s); // a * s

    // overloading the subscript operator
    const double& operator[] (const int& index) const; // serves const objects
    double& operator[] (const int& index);         // serves non-const objects

    // overloading compound operators
    Mat2x2& operator+= (const Mat2x2& rhs);
    Mat2x2& operator+= (const double& scalar);
    Mat2x2& operator-= (const Mat2x2& rhs);
    Mat2x2& operator-= (const double& scalar);
    Mat2x2& operator*= (const double& scalar);
    Mat2x2& operator*= (const Mat2x2& rhs);

    // unary operators
    Mat2x2& operator++(); // ++Mat2x2
    Mat2x2 operator++(int); // Mat2x2++
    Mat2x2& operator--(); // --Mat2x2
    Mat2x2 operator--(int); // Mat2x2--
    Mat2x2 operator- (); // -Mat2x2
    Mat2x2 operator+ (); // +Mat2x2

};

// overloading relational equality operators
bool operator==(const Mat2x2& lhs, const Mat2x2& rhs);
bool operator!=(const Mat2x2& lhs, const Mat2x2& rhs);

// binary operators
Mat2x2 operator+(const Mat2x2& matrix1, const double& scalar);
Mat2x2 operator+(const double& scalar, const Mat2x2& matrix1);
Mat2x2 operator+(const Mat2x2& matrix1, const Mat2x2& matrix2);

Mat2x2 operator-(const Mat2x2& matrix1, const Mat2x2& matrix2);
Mat2x2 operator-(const Mat2x2& matrix1, const double& scalar);
Mat2x2 operator-(const double& scalar, const Mat2x2& matrix1);

Mat2x2 operator*(const Mat2x2& matrix1, const Mat2x2& matrix2);
Mat2x2 operator*(const Mat2x2& matrix1, const double& scalar);
Mat2x2 operator*(const double& scalar, const Mat2x2& matrix1);

// input/output operators
std::istream& operator>>(std::istream& is, Mat2x2 &target);
std::ostream& operator<<(std::ostream& os, const Mat2x2 &target);

bool isAlmostEqual(
        double first, double second, double epsilon = 1.0e-6) ;

bool isNotAlmostEqual(
        double first, double second, double epsilon = 1.0e-6) ;

#endif //MATRIX_OPERATION_MAT2X2_H
