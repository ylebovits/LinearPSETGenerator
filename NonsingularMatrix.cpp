#include <random>
#include "NonsingularMatrix.h"
#include "InvalidDimensionException.h"

#define MAX_SOLUTION_VALUE 8
#define MIN_SOLUTION_VALUE -8

NonsingularMatrix::NonsingularMatrix(int numRows, int numCols) : Matrix(numRows, numCols + 1) { // addl column for solutions
    if ( numRows != numCols || numRows == 0 )
        throw InvalidDimensionException();

    for (auto row = 0; row < this->getNumRows(); ++row)
        this->setEntry(row, row, 1);


    std::default_random_engine engine(std::random_device{}());
    std::normal_distribution<double> dis(0, 7);

    int rand_pick = INT32_MIN;

    for (auto x = 0; x < this->getNumRows(); ++x) {

        do {
            rand_pick = (int)dis(engine);
        } while ( (rand_pick < MIN_SOLUTION_VALUE) || (rand_pick > MAX_SOLUTION_VALUE) );

        this->setEntry(x, this->getNumCols()-1, rand_pick);
    }
}
