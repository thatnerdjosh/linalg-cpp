#include <iostream>
#include "matrix.hpp"

Matrix::Matrix(){}
Matrix::Matrix(int rows, int cols): rows(rows), cols(cols) {
    data = new int[rows*cols];
}

Matrix::Matrix(int rows, int cols, int* arr) : rows(rows), cols(cols) {
    _build(arr);
}

void Matrix::_build(int* arr) {
    data = new int[rows*cols];
    for(int row = 0; row < rows; row++) {
        for(int col = 0; col < cols; col++) {
            data[row*cols+col] = arr[row*cols+col];
        }
    }
}

Matrix Matrix::operator*(const Matrix& other) {
    Matrix temp(rows, cols);

    for(int i=0; i < rows; i++) {
        for(int j=0; j < cols; j++) {
            int sum = 0;
            for (int k=0; k < rows; k++) {
               sum += data[i*cols+k] * other.data[k*cols+j];
            }
            temp.data[i*cols+j] = sum;
        }
    }

    return temp;
}

std::ostream& operator<<(std::ostream& os, const Matrix& m) {
    for(int i=0; i < m.rows; i++) {
        for (int j=0; j < m.cols; j++)
            os << m.ItemAt(i, j);
        os << std::endl;
    }
}

Matrix Matrix::Transpose() const {
    int *B = new int[rows*cols];

    // TODO: Implement cache blocking
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            B[i*cols+j] = data[j*cols+i];
        }
    }
    
    Matrix t(4,4,B);
    delete []B;
    return t;
}

Matrix::Matrix(const Matrix& other): rows(other.rows), cols(other.cols) {
    _build(other.data);
}

int Matrix::ItemAt(int row, int col) const {
    return data[row*cols+col];
}

Matrix::~Matrix() {
    delete []data;
}
