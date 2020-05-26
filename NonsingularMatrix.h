//
// Created by yakir on 5/24/20.
//

#ifndef LINEARPSETGENERATOR_NONSINGULARMATRIX_H
#define LINEARPSETGENERATOR_NONSINGULARMATRIX_H


#include "Matrix.h"

class NonsingularMatrix: public Matrix {
public:
    NonsingularMatrix(int numRows, int numCols);
};


#endif //LINEARPSETGENERATOR_NONSINGULARMATRIX_H
