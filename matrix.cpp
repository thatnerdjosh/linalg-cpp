#include <iostream>
#include "matrix.hpp"

Matrix::Matrix(){}
Matrix::Matrix(int rows, int cols): rows(rows), cols(cols) {
    this->data = new int[rows*cols];
}

Matrix::Matrix(int rows, int cols, int* arr) : rows(rows), cols(cols) {
    _build(arr);
}

void Matrix::_build(int* arr) {
    this->data = new int[this->rows*this->cols];
    for(int row = 0; row < rows; row++) {
        for(int col = 0; col < cols; col++) {
            this->data[row*cols+col] = arr[row*cols+col];
        }
    }
}

Matrix Matrix::operator*(const Matrix& other) {
    Matrix temp(this->rows, this->cols);

    for(int i=0; i < this->rows; i++) {
        for(int j=0; j < this->cols; j++) {
            int sum = 0;
            for (int k=0; k < this->rows; k++) {
               sum += this->data[i*this->cols+k] * other.data[k*this->cols+j];
            }
            temp.data[i*this->cols+j] = sum;
        }
    }

    return temp;
}

Matrix Matrix::Transpose() {
    int *B = new int[this->rows*this->cols];

    // TODO: Implement cache blocking
    for(int i = 0; i < this->rows; i++) {
        for(int j = 0; j < this->cols; j++) {
            B[i*this->cols+j] = data[j*this->cols+i];
        }
    }
    
    Matrix t(this->rows,this->cols,B);
    delete []B;
    return t;
}

Matrix::Matrix(const Matrix& other): rows(other.rows), cols(other.cols) {
    _build(other.data);
}

int Matrix::ItemAt(int row, int col) {
    return data[row*this->cols+col];
}

Matrix::~Matrix() {
    delete []data;
}
