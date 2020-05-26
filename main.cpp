#include <iostream>
#include "Matrix.h"
//#include "NonsingularMatrix.h"
//#include "NonsingularMatrix.cpp"

/*
 * TODO:
 * deal with memory leaks
 * properly create an InvalidDimensionException and throw it
 */

int main() {

//    try {
        Matrix m {3, 4};

        m.setEntry(2, 3, 5);
        m.addScale(2, 0, -2.33);
        m.swapRow(0, 1);
        m.scaleRow(2, 2.25);

        // Matrix c = m.copy();

        // std::cout << c << std::endl;


//    } catch (InvalidDimensionException *exception) {
//        std::cout << "working\n";
//    }

    return 0;
}
