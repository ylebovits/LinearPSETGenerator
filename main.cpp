#include <iostream>
#include "Matrix.h"
#include "InvalidDimensionException.h"
#include "NonsingularMatrix.h"
//#include "NonsingularMatrix.h"
//#include "NonsingularMatrix.cpp"

/*
 * TODO:
 * segfault when scrambling matrices, probably needs to be fixed
 */

int main() {

    try {

        NonsingularMatrix m {5, 5};

//        m.setEntry(2, 3, 5);
//        m.addScale(2, 0, -402.33);
//        m.swapRow(0, 1);
//        m.scaleRow(2, 2.25);

        std::cout << m << std::endl;

    } catch (const InvalidDimensionException& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
