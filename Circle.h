//
// Created by david on 13.04.2020.
//

#ifndef LINAL_CIRCLE_H
#define LINAL_CIRCLE_H
#include <GL/glut.h>
#include "Vector2D.h"

class Circle
{
protected:
    Vector2D a;     // Координаты вектора - центр круга
    double rad;     // Радиус - дробное число
    double r;       // Красный
    double g;       // Зелёный
    double b;       // Синий
public:
    Circle();       // Конструктор по умолчанию
    Circle(Vector2D a, double rad);     // Конструктор с заданными центром и радиусом
    Circle(Vector2D a, double r, double g, double b);   // Конструктор со всеми параметрами
    ~Circle();      // Деструктор

    void setRadius(double rad);     // Меняет радиус на заданный
    double getRadius();             // Возвращает значение радиуса
    void multipleRadius(double n);  // Меняет радиус в n раз
    void setColor(double r, double g, double b);    // Меняет цвет на заданный

    void moveUp(double x);      // Двигать вверх
    void moveDown(double x);    // Двигать вниз
    void moveLeft(double x);    // Двигать влево
    void moveRight(double x);   // Двигать вправо

    void paintLine();           // Нарисовать контур
    void paintPolygon();        // Нарисовать закрашенный круг
};


#endif //LINAL_CIRCLE_H
