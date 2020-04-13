//
// Created by xaero on 08.04.2020.
//

#ifndef UNTITLED_VECTOR2D_H
#define UNTITLED_VECTOR2D_H

#include <iostream>

class Vector2D {
private:
    double x, y;
public:
    Vector2D(); // дефолтный конструктор
    Vector2D(double x, double y); // конструктор с координатами

    ~Vector2D(); // деструктор

    double getX() const; // задать координаты вектора по х и у
    double getY() const;

    void setX(double x); // получить координаты вектора по х и у
    void setY(double y);

    bool operator==(const Vector2D &v2) const; // оператор сравнения

    bool operator!=(const Vector2D &v2) const; // оператор сравнения (вдруг захочется)

    Vector2D operator= (const Vector2D& v2); // оператор присваивания

    Vector2D operator+(const Vector2D &v2) const; // оператор сложения векторов
    Vector2D operator+=(const Vector2D &v2) const;

    Vector2D operator-(const Vector2D &v2) const; // оператор вычитания векторов
    Vector2D operator-=(const Vector2D &v2) const;

    Vector2D operator*(double a) const; //оператор умножения вектора на константу
    Vector2D operator*=(double a) const;

    Vector2D operator/ (double a) const; // оператор деления вектора на константу
    Vector2D operator/= (double a) const;

    double get_module() const; // получить модуль вектора

    double scalar_product(const Vector2D &v2) const; // получить скалярное произведение

    double module_vector_product(const Vector2D &v2) const; // получить модуль векторного произведения

    double get_the_angel_in_degree(const Vector2D &v2) const; // получить угол между векторами в углах или радианах
    double get_the_angel_in_radian(const Vector2D &v2) const;
};

    std::ostream& operator<< (std::ostream& os, const Vector2D& v); // перегруженые операторы ввода и вывода векторов
    std::istream& operator>>(std::istream& is, Vector2D& v);



#endif //UNTITLED_VECTOR2D_H
