#include <iostream>
#include <vector>
#include "matrix.hpp"

int shapes[2][16] = {
    {
        1, 1, 1, 1,
        0, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0,
    },
    {
        1, 0, 0, 0,
        1, 0, 0, 0,
        1, 1, 0, 0,
        0, 0, 0, 0,
    }
};
std::vector<Matrix> pieces;

int main()
{
    pieces.reserve(2);
    for(int* piece : shapes) {
        pieces.push_back(Matrix(4, 4, piece));
    }
}
