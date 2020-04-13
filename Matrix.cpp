//
// Created by xaero on 08.04.2020.
//

#include "Matrix.h"

#include <iostream>

Matrix::Matrix(int n, int m) { //в случае n == m создаем единичную матрицу n*m, иначе - пустую
    this->n = n + 1;
    this->m = m + 1;
    if (n == m)
        for (int i = 1; i <= n; i++) //индексы элементов проходят с 1, 1 до n, m включительно
            for (int j = 1; j <= n; j++)
                if (i == j)
                    cell[i][j] = 1;
                else
                    cell[i][j] = 0;
} // конструктор

Matrix::~Matrix() {
    n = 0;
    m = 0;
} // деструктор

void Matrix::print_Matrix() const {
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++)
            std::cout << cell[i][j] << ' ';
        std::cout << std::endl;
    }
} // вывод матрицы на экран

void Matrix::set_cell(int x, int y, double value) {
    cell[x][y] = value;
} // задать значение ячейки с индексами х, у

double Matrix::get_cell(int x, int y) const {
    return cell[x][y];
} // получить значение ячейки с индексами х, у

int Matrix::get_vertical_size() const {
    return n - 1;
} // получить вертикальный размер матрицы

int Matrix::get_horizontal_size() const {
    return m - 1;
} // получить горизонтальный размер матрицы

void Matrix::transpose() {
    int a = n;
    double reserve_cell[100][100];

    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            reserve_cell[i][j] = cell[i][j];

    for (int j = 1; j < n; j++)
        for (int i = 1; i < m; i++) {
            cell[i][j] = reserve_cell[j][i];
        }
    n = m;
    m = a;
} // процедура транспонирования матрицы

Matrix Matrix::operator=(const Matrix &matrix) {
    int n = this->n;
    int m = this->m;
    double cell[101][101];
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            this->cell[i][j] = matrix.get_cell(i, j);
    return Matrix(n, m);
} // оператор присваивания

Matrix Matrix::operator+(const Matrix &matrix) {
    int n = this->n;
    int m = this->m;
    double cell[101][101];
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            this->cell[i][j] += matrix.get_cell(i, j);
    return Matrix(n, m);
}; // оператор сложения матриц

Matrix Matrix::operator+=(const Matrix &matrix) {
    int n = this->n;
    int m = this->m;
    double cell[101][101];
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            this->cell[i][j] += matrix.get_cell(i, j);
    return Matrix(n, m);
}; // еще один оператор сложения

Matrix Matrix::operator-(const Matrix &matrix) {
    int n = this->n;
    int m = this->m;
    double cell[101][101];
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            this->cell[i][j] -= matrix.get_cell(i, j);
    return Matrix(n, m);
};  // оператор вычитания матриц

Matrix Matrix::operator-=(const Matrix &matrix) {
    int n = this->n;
    int m = this->m;
    double cell[101][101];
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            this->cell[i][j] -= matrix.get_cell(i, j);
    return Matrix(n, m);
}; // и еще оператор вычитания

Matrix Matrix::operator*(double a) {
    int n = this->n;
    int m = this->m;
    double cell[101][101];
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            this->cell[i][j] *= a;
    return Matrix(n, m);
}; // оператор умножения на константу

Matrix Matrix::operator*=(double a) {
    int n = this->n;
    int m = this->m;
    double cell[101][101];
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            this->cell[i][j] *= a;
    return Matrix(n, m);
}; // и еще оператор умножения матрицы на число

Matrix Matrix::operator/(double a) {
    int n = this->n;
    int m = this->m;
    double cell[101][101];
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            this->cell[i][j] /= a;
    return Matrix(n, m);
}; // оператор деления матрицы на константу

Matrix Matrix::operator/=(double a) {
    int n = this->n;
    int m = this->m;
    double cell[101][101];
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            this->cell[i][j] /= a;
    return Matrix(n, m);
}; // и еще оператор деления матрицы на константу

Matrix Matrix::operator*(const Matrix& matrix) {
    int n = this -> n;
    int m = matrix.get_horizontal_size() + 1;
    double sum = 0;
    double multiply_matrix[n][m];
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++) {
            sum = 0;
            for (int k = 1; k < this -> m + 1; k++)
                sum += this -> cell[i][k] * matrix.get_cell(k, j);
            multiply_matrix[i][j] = sum;
        }
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            this -> cell[i][j] = multiply_matrix[i][j];
    this -> m = matrix.get_horizontal_size() + 1;
    return Matrix(n, m);
};

Matrix Matrix::operator*=(const Matrix& matrix) {
    int n = this -> n;
    int m = matrix.get_horizontal_size() + 1;
    double sum = 0;
    double multiply_matrix[n][m];
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++) {
            sum = 0;
            for (int k = 1; k < this -> m + 1; k++)
                sum += this -> cell[i][k] * matrix.get_cell(k, j);
            multiply_matrix[i][j] = sum;
        }
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            this -> cell[i][j] = multiply_matrix[i][j];
    this -> m = matrix.get_horizontal_size() + 1;
    return Matrix(n, m);
};
