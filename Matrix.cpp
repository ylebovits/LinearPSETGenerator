#include <iostream>
#include <random>
#include "Matrix.h"

int Matrix::getNumRows() const {
    return this->numRows;
}

int Matrix::getNumCols() const {
    return this->numCols;
}

void Matrix::setEntry(int row, int col, double value) {
    this->matrix[row][col] = value;
}

double Matrix::getEntry(int row, int col) {
    return this->matrix[row][col];
}

void Matrix::swapRow(int src, int dest) {
    if (src == dest) return;
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

    for (auto i = 0; i < this->getNumRows(); ++i)
        this->matrix[i] = new double[numCols];

    for (auto row = 0; row < this->getNumRows(); ++row) {
        for (auto col = 0; col < this->getNumCols(); ++col) {
            this->matrix[row][col] = 0.0;
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

Matrix::~Matrix() {
    for (auto row = 0; row < this->getNumRows(); ++row)
        delete[] this->matrix[row];

    delete[] this->matrix;
}

void Matrix::scramble() {

    std::random_device rnd;
    std::mt19937 gen(rnd());
    std::uniform_int_distribution<> dis(0, 15);

    int loops = dis(gen);
    int choice;

    std::uniform_int_distribution<> dis2(7, 13);
    std::uniform_int_distribution<> alpha(-4, 4);
    std::uniform_int_distribution<> row(0, this->getNumRows()-1);



    for (auto i = 0; i < loops; i++) {
        choice = dis(gen);

        if (choice < 2)
            this->scaleRow(row(gen), alpha(gen));
        else if (choice < 5)
            this->swapRow(row(gen), alpha(gen));
        else
            this->addScale(row(gen), row(gen), alpha(gen));
    }
}



