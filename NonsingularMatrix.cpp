//
// Created by yakir on 5/24/20.
//

#include <random>
#include "NonsingularMatrix.h"
#include "InvalidDimensionException.h"

NonsingularMatrix::NonsingularMatrix(int numRows, int numCols) : Matrix(numRows, numCols + 1) { // addl column for solutions
    if ( numRows != numCols || numRows == 0 )
        throw InvalidDimensionException();

    for (auto row = 0; row < this->getNumRows(); ++row)
        this->setEntry(row, row, 1);

    srand(time(nullptr));

    std::random_device rnd;
    std::mt19937 gen(rnd());
    std::uniform_int_distribution<> dis(-7, 7);

    for (auto x = 0; x < this->getNumRows(); ++x)
        this->setEntry(x, this->getNumCols()-1, dis(gen));

    this->scramble();
}
