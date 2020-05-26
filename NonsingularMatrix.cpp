//
// Created by yakir on 5/24/20.
//

#include "NonsingularMatrix.h"

NonsingularMatrix::NonsingularMatrix(int numRows, int numCols) : Matrix(numRows, numCols) {
    if ( numRows != numCols || numRows == 0 )
        throw -1;

    for (auto row = 0; row < this->getNumRows(); ++row)
        this->setEntry(row, row, 1);
}
