//
// Created by Kalin on 22.04.2020.
//

#ifndef ZAD_6_MATRIX_H
#define ZAD_6_MATRIX_H
#include <array>
#include <cmath>
#include <iostream>
#include "figure.h"



template<class T>
class Matrix
{
public:
    Matrix() { setIdentity(); }
    Matrix(const Matrix& other) { copyMx(other); }

    static Matrix scaleMx(T scaleX, T scaleY)
    {
        Matrix ans;

        //values from scale matrix formula
        ans.mx.at(0).at(0) = scaleX;
        ans.mx.at(1).at(1) = scaleY;

        return ans;
    }
    static Matrix translateMx(T offsetX, T offsetY)
    {
        Matrix ans;

        //values from translate matrix formula
        ans.mx.at(2).at(0) = offsetX;
        ans.mx.at(2).at(1) = offsetY;

        return ans;
    }
    static Matrix rotateMx(T angle)
    {
        Matrix ans;

        //values from rotate matrix formula
        ans.mx.at(0).at(0) = cos(angle);
        ans.mx.at(0).at(1) = sin(angle);
        ans.mx.at(1).at(0) = -sin(angle);
        ans.mx.at(1).at(1) = cos(angle);

        return ans;
    }
    template<typename Type>
    friend std::ostream& operator<<(std::ostream& os, const Matrix<Type>& rhs)
    {
        for(int row = 0; row < size; ++row)
        {
            for(int rowElem = 0; rowElem < size; ++rowElem)
                os << rhs.mx.at(row).at(rowElem) << ' '; //prints a whole row
            os << endl;
        }
        return os;
    }
    Matrix& operator = (const Matrix& rhm) { copyMx(rhm); return *this; }
    template<typename Type>
    friend Matrix operator*(const Matrix& lhm, const Matrix<Type>& rhm)
    {
        //Matrix is in this implementation a cube-format so I dont have to check dimensions
        //The simplest way
        Matrix ans;
        
        for(int row = 0; row < lhm.size; ++row)
        {
            for(int rowElem = 0; rowElem < lhm.size; ++rowElem)
            {
                if(row == rowElem)
                    ans.mx.at(row).at(rowElem) = 0; //set all Matrix to 0, because of setIdentity

                for(int iterator = 0; iterator < rhm.size; ++iterator)
                    ans.mx.at(row).at(rowElem) += lhm.mx.at(row).at(iterator) *
                            rhm.mx.at(iterator).at(rowElem); //by iterator you can get whole col of Matrix
                                                            //Simply what you get is ans 1,1 = l1,1 * r1,1 + l1,2 * r2,1 + l1,3 * r3,1 etc.
            }
        }

        return ans;
    }
    Matrix& operator *= (const Matrix& rhm) { return *this = *this * rhm;}
    FPoint transform(const FPoint& pt) const
    {
        return FPoint(pt.x * mx.at(0).at(0) + pt.y * mx.at(1).at(0) + mx.at(2).at(0),
                pt.x * mx.at(0).at(1) + pt.y * mx.at(1).at(1) + mx.at(2).at(1));
    }
    std::array<std::array<T, 3>, 3> getArr() { return mx; }
private:
    static const int size = 3; //task required this
    std::array<std::array<T, size>, size> mx;
    void setIdentity() //set mx to Identity matrix
    {
        for(int row = 0; row < size; ++row)
        {
            for(int rowElem = 0; rowElem < size; ++rowElem)
                mx.at(row).at(rowElem) = (rowElem == row) ? T(1) : T(0);
        }
    }

    void copyMx(const Matrix& rhm)
    {
        for(int row = 0; row < size; ++row)
        {
            for(int rowElem = 0; rowElem < size; ++rowElem)
                mx.at(row).at(rowElem) = rhm.mx.at(row).at(rowElem);
        }
    }
};



#endif //ZAD_6_MATRIX_H
