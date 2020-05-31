#ifndef LINEARPSETGENERATOR_MATRIX_H
#define LINEARPSETGENERATOR_MATRIX_H

#include <vector>
#include <ostream>

class Matrix {

private:
    double **matrix;
    double **row_reduction; // original matrix before scramble

protected:
    int numRows;
    int numCols;
    void save_row_reduction();

public:
    Matrix(int numRows, int numCols);
    int getNumRows() const;
    int getNumCols() const;
    void setEntry(int row, int col, double value);
    double getEntry(int row, int col);
    void swapRow(int src, int dest);
    void scaleRow(int row, double alpha);
    void addScale(int src, int dest, double alpha);
    void scramble();
    Matrix copy();

    virtual ~Matrix();

    friend std::ostream &operator<<(std::ostream &os, const Matrix &matrix);
};

#endif //LINEARPSETGENERATOR_MATRIX_H
