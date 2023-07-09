//
// Created by Ali Sayed Salehi on 2023-07-04.
//

#ifndef MATRIX_OPERATION_MATRIX_H
#define MATRIX_OPERATION_MATRIX_H


#include <istream>

class Matrix {

public:
    static bool isAlmostEqual(
            double first, double second, double epsilon = 1.0e-6) ;

    static bool isNotAlmostEqual(
            double first, double second, double epsilon = 1.0e-6) ;

    virtual std::istream& operator>>(std::istream& is) = 0;
    virtual std::ostream& operator<<(std::ostream& os) const = 0;


    virtual Matrix operator+(const Matrix& other) const = 0;

};




#endif //MATRIX_OPERATION_MATRIX_H
