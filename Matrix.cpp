#include "Matrix.h"

int Matrix::getNumRows() const {
    return numRows;
}

int Matrix::getNumCols() const {
    return numCols;
}

void Matrix::setEntry(int row, int col, double value) {
    this->matrix[row][col] = value;
}

double Matrix::getEntry(int row, int col) {
    return this->matrix[row][col];
}

void Matrix::swapRow(int src, int dest) {
    double *tmp = this->matrix[src];
    this->matrix[src] = this->matrix[dest];
    this->matrix[dest] = tmp;
}

void Matrix::scaleRow(int row, double alpha) {
    for (auto col = 0; col < this->getNumCols(); ++col)
        this->matrix[row][col] *= alpha;
}

void Matrix::addScale(int src, int dest, double alpha) {
    for (auto col = 0; col < this->getNumCols(); ++col)
        this->matrix[dest][col] += this->matrix[src][col] * alpha;
}

Matrix Matrix::copy() {
    Matrix m {this->getNumRows(), this->getNumCols()};

    for (int row = 0; row < this->getNumRows(); ++row) {
        for (int col = 0; col < this->getNumCols(); ++col) {
            m.setEntry(row, col, this->getEntry(row, col));
        }
    }

    return m;
}

Matrix::Matrix(int numRows, int numCols) : numRows(numRows), numCols(numCols) {
    this->numCols = numCols;
    this->numRows = numRows;

    this->matrix = new double*[numRows];
    for (auto i = 0; i < numCols; ++i)
        this->matrix[i] = new double[numCols];

    for (auto row = 0; row < this->getNumRows(); ++row) {
        for (auto col = 0; col < this->getNumCols(); ++col) {
            this->matrix[row][col] = 0;
        }
    }
}

std::ostream &operator<<(std::ostream &os, const Matrix &matrix) {

    for (auto row = 0; row < matrix.getNumRows(); ++row) {
        for (auto col = 0; col < matrix.getNumCols(); ++col) {
            os << matrix.matrix[row][col] << " ";
        }
        os << std::endl;
    }

    return os;
}
//
//Matrix::~Matrix() {
//
//    for (auto row = 0; row < this->getNumRows(); ++row)
//        free(this->matrix[row]);
//
//}


