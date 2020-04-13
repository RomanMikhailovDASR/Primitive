//
// Created by david on 13.04.2020.
//

#include "Circle.h"
#include <GL/glut.h>
#include <cmath>

Circle::Circle() {
    a = Vector2D(0,0);
    rad = 0.3;
    r = 0;
    g = 0;
    b = 0;
}

Circle::Circle(Vector2D a, double rad) {
    this->a = a;
    this->rad = rad;
    r = 0;
    g = 0;
    b = 0;
}

Circle::Circle(Vector2D a, double r, double g, double b) {
    this->a = a;
    this->rad = rad;
    this->r = r;
    this->g = g;
    this->b = b;
}

Circle::~Circle() {
    a = Vector2D();
    rad = 0;
    r = 0;
    g = 0;
    b = 0;
}

void Circle::setColor(double r, double g, double b) {
    this->r = r;
    this->g = g;
    this->b = b;
}

void Circle::setRadius(double rad) {
    this->rad = rad;
}

void Circle::multipleRadius(double n) {
    rad *= n;
}

double Circle::getRadius() {
    return rad;
}

void Circle::moveRight(double x) {
    a.setX(a.getX() + x);
}

void Circle::moveLeft(double x) {
    a.setX(a.getX() - x);
}

void Circle::moveUp(double x) {
    a.setY(a.getY() + x);
}

void Circle::moveDown(double x) {
    a.setY(a.getY() - x);
}

void Circle::paintLine() {
    glBegin(GL_LINES);
    for (unsigned int i=0; i<100; i++) {
        glColor3d(r, g, b);
        glVertex2d(a.getX() + rad * cos(i * 0.12566), a.getY() + rad * sin(i * 0.12566));
        glVertex2d(a.getX() + rad * cos((i+1) * 0.12566), a.getY() + rad * sin((i+1) * 0.12566));
    };
    glEnd();
}

void Circle::paintPolygon() {
    glBegin(GL_POLYGON);
    for (unsigned int i=0; i<100; i++) {
        glColor3d(r, g, b);
        glVertex2d(a.getX() + rad * cos(i * 0.12566), a.getY() + rad * sin(i * 0.12566));
    };
    glEnd();
}