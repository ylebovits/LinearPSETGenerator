#ifndef LINEARPSETGENERATOR_MATRIX_H
#define LINEARPSETGENERATOR_MATRIX_H

#include <vector>
#include <ostream>

class Matrix {

private:
    double **matrix;

protected:
    int numRows;
    int numCols;

public:
    Matrix(int numRows, int numCols);

   // virtual ~Matrix();

    int getNumRows() const;
    int getNumCols() const;
    void setEntry(int row, int col, double value);
    double getEntry(int row, int col);
    void swapRow(int src, int dest);
    void scaleRow(int row, double alpha);
    void addScale(int src, int dest, double alpha);
    Matrix copy();

    friend std::ostream &operator<<(std::ostream &os, const Matrix &matrix);
};

#endif //LINEARPSETGENERATOR_MATRIX_H
