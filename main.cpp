#include <iostream>
#include "Matrix.h"
#include "InvalidDimensionException.h"
#include "NonsingularMatrix.h"
//#include "NonsingularMatrix.h"
//#include "NonsingularMatrix.cpp"

/*
 * TODO:
 * rewrite scrambling procedure
 */

int main() {

    try {

        NonsingularMatrix m {5, 5};

        std::cout << m << std::endl;

//        m.setEntry(2, 3, 5);
//        m.addScale(2, 0, -402.33);
//        m.swapRow(0, 1);
//        m.scaleRow(2, 2.25);

    } catch (const InvalidDimensionException& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
