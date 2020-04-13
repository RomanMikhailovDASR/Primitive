//
// Created by xaero on 08.04.2020.
//

#ifndef UNTITLED_MATRIX_H
#define UNTITLED_MATRIX_H


class Matrix {
private:
    int n; // вертикальный размер
    int m;  // горизонтальный размер
    double cell[101][101];
public:
    Matrix(int n, int m); // конструктор: в случае n == m создаем единичную матрицу n*n, иначе - пустую

    ~Matrix(); // деструктор

    void print_Matrix() const; // вывод матрицы на экран

    void set_cell(int x, int y, double value); // задать значение ячейки матрицы с индексами х и у

    double get_cell(int x, int y) const; // получить значение ячейки матрицы с индексами х и у

    int get_vertical_size() const; // получить вертикальный или оризонтальный размеры матрицы
    int get_horizontal_size() const;

    void transpose(); // транспонировать матрицу

    Matrix operator=(const Matrix &matrix); // оператор присваивания

    Matrix operator+(const Matrix &matrix); // операторы сложения матриц
    Matrix operator+=(const Matrix &matrix);

    Matrix operator-(const Matrix &matrix); // операторы вычитания матриц
    Matrix operator-=(const Matrix &matrix);

    Matrix operator*(double a); // операторы умножения матрицы на константу
    Matrix operator*=(double a);

    Matrix operator/(double a); // операторы деления матрицы на константу
    Matrix operator/=(double a);

    Matrix operator*(const Matrix& matrix); // операторы умножения матриц
    Matrix operator*=(const Matrix& matrix);

};


#endif //UNTITLED_MATRIX_H
