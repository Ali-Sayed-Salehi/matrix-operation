//
// Created by Ali Sayed Salehi on 2023-07-06.
//

#ifndef MATRIX_OPERATION_MAT2X2_H
#define MATRIX_OPERATION_MAT2X2_H


#include <array>
#include "../inc/Matrix.h"
using std::array;

class Mat2x2 : public Matrix {
private:
    array< array<double, 2>, 2> matrix {};
public:
    Mat2x2();
    Mat2x2(double a00, double a01, double a10, double a11);
    Mat2x2(const Mat2x2& other) = default;
    Mat2x2(Mat2x2&& other) = default;
    ~Mat2x2() = default;
    const array< array<double, 2>, 2>& getMatrix() const;

    std::istream& operator>>(std::istream& is) override;
    std::ostream& operator<<(std::ostream& os) const override;

    Matrix operator+(const Matrix& other) const override;

};



#endif //MATRIX_OPERATION_MAT2X2_H
