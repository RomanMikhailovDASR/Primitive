//
// Created by xaero on 08.04.2020.
//

#include "Vector2D.h"

#include <cmath>

Vector2D::Vector2D(double x, double y) {
    this->x = x;
    this->y = y;
};

Vector2D::Vector2D() {};

Vector2D::~Vector2D() {
    this->x = 0;
    this->y = 0;
};

double Vector2D::getX() const { return x; };

double Vector2D::getY() const {return y; };

void Vector2D::setX(double x) { this->x = x; };

void Vector2D::setY(double y) { this->y = y; };

Vector2D Vector2D::operator= (const Vector2D& v2) {
    this->x = v2.getX();
    this->y = v2.getY();
    return Vector2D(v2.getX(), v2.getY());
};

bool Vector2D::operator== (const Vector2D& v2) const {
    return(getX() == v2.getX()) && (getY() == v2.getY());
};

bool Vector2D::operator!= (const Vector2D& v2) const {
    return !operator==(v2);
};

Vector2D Vector2D::operator+ (const Vector2D& v2) const {
    return Vector2D(getX() + v2.getX(), getY() + v2.getY());
};

Vector2D Vector2D::operator+= (const Vector2D& v2) const {
    return Vector2D(getX() + v2.getX(), getY() + v2.getY());
};

Vector2D Vector2D::operator- (const Vector2D& v2) const {
    return Vector2D(getX() - v2.getX(), getY() - v2.getY());
};

Vector2D Vector2D::operator-= (const Vector2D& v2) const {
    return Vector2D(getX() - v2.getX(), getY() - v2.getY());
};

Vector2D Vector2D::operator* (const double a) const {
    return Vector2D(getX()*a, getY()*a);
};

Vector2D Vector2D::operator*= (const double a) const {
    return Vector2D(getX()*a, getY()*a);
};

Vector2D Vector2D::operator/ (const double a) const {
    return Vector2D(getX()/a, getY()/a);
};

Vector2D Vector2D::operator/= (const double a) const {
    return Vector2D(getX()/a, getY()/a);
};

double Vector2D::get_module() const {
    return sqrt(this->x * this->x + this->y * this->y);
};

double Vector2D::scalar_product(const Vector2D& v2) const {
    return (this->x * v2.getX() + this->y * v2.getY());
};

double Vector2D::module_vector_product(const Vector2D& v2) const {
    return sqrt(this->x * this->x + this->y * this->y)*v2.get_module()*sin(get_the_angel_in_radian(v2));
};

double Vector2D::get_the_angel_in_degree(const Vector2D& v2) const {
    if (this->x/v2.getX() == this->y/v2.getY()) {
        if (this->x * v2.getX() < 0)
            return 180;
        else
            return 0;
    }
    return acos(abs(this->x * v2.getX() + this->y * v2.getY())/(sqrt(this->x * this->x + this->y * this->y)*sqrt(v2.getX()*v2.getX() + v2.getY()*v2.getY())))*180/3.141592653589793;
};

double Vector2D::get_the_angel_in_radian(const Vector2D& v2) const {
    if (this->x/v2.getX() == this->y/v2.getY()) {
        if (this->x * v2.getX() < 0)
            return 3.1416;
        else
            return 0;
    }
    return acos(abs(this->x * v2.getX() + this->y * v2.getY())/(sqrt(this->x * this->x + this->y * this->y)*sqrt(v2.getX()*v2.getX() + v2.getY()*v2.getY())));
};

std::ostream& operator<<(std::ostream& os, const Vector2D& v) {
    os << "(" << v.getX() << "; " << v.getY() << ")";
    return os;
};

std::istream& operator>>(std::istream& is, Vector2D& v) {
    int x, y;
    is >> x >> y;
    v.setX(x);
    v.setY(y);
    return is;
};
