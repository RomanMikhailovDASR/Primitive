//
// Created by xaero on 08.04.2020.
//

#include "Vector3D.h"

#include <cmath>

Vector3D::Vector3D () {
    this->x = 0;
    this->y = 0;
    this->z = 0;
}
Vector3D::Vector3D (double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector3D::~Vector3D () {
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

double Vector3D::getX() const { return x; };
double Vector3D::getY() const {return y; };
double Vector3D::getZ() const {return z; };

void Vector3D::setX(double x) { this->x = x; };
void Vector3D::setY(double y) { this->y = y; };
void Vector3D::setZ(double z) { this->z = z; };

Vector3D Vector3D::operator= (const Vector3D& v3) {
    this->x = v3.getX();
    this->y = v3.getY();
    this->z = v3.getZ();
    return Vector3D(v3.getX(), v3.getY(), v3.getZ());
}

bool Vector3D::operator== (const Vector3D& v3) const {
    return((this->x == v3.getX()) && (this->y == v3.getY()) && (this->z == v3.getZ()));
};

bool Vector3D::operator!= (const Vector3D& v3) const {
    return !operator==(v3);
};

Vector3D Vector3D::operator+ (const Vector3D& v3) const {
    return Vector3D(this->x + v3.getX(), this->y + v3.getY(), this->z + v3.getZ());
};

Vector3D Vector3D::operator+= (const Vector3D& v3) const {
    return Vector3D(this->x + v3.getX(), this->y + v3.getY(), this->z + v3.getZ());
};

Vector3D Vector3D::operator- (const Vector3D& v3) const {
    return Vector3D(this->x - v3.getX(), this->y - v3.getY(), this->z - v3.getZ());
};

Vector3D Vector3D::operator-= (const Vector3D& v3) const {
    return Vector3D(this->x - v3.getX(), this->y - v3.getY(), this->z - v3.getZ());
};

Vector3D Vector3D::operator* (const double a) const {
    return Vector3D(this->x * a, this->y *a, this->z *a);
};

Vector3D Vector3D::operator*= (const double a) const {
    return Vector3D(this->x * a, this->y *a, this->z *a);
};

Vector3D Vector3D::operator/ (const double a) const {
    return Vector3D(this->x / a, this->y / a, this->z / a);
};

Vector3D Vector3D::operator/= (const double a) const {
    return Vector3D(this->x / a, this->y / a, this->z / a);
};

double Vector3D::get_module() const {
    return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
};

double Vector3D::scalar_product(const Vector3D& v3) const {
    return (this->x * v3.getX() + this->y * v3.getY() + this->z * v3.getZ());
};

Vector3D Vector3D::vector_product(const Vector3D& v3) {
    double a, b, c;
    a = this->y * v3.getZ() - this->z * v3.getY();
    b = -this->x * v3.getZ() + this->z * v3.getX();
    c = this->x * v3.getY() - this->y * v3.getX();
    this->x = a;
    this->y = b;
    this->z = c;
    return Vector3D(this->x, this->y, this->z);
}

double Vector3D::module_vector_product(const Vector3D& v3) const {
    return sqrt((this->y * v3.getZ() - this->z * v3.getY()) * (this->y * v3.getZ() - this->z * v3.getY()) +
                   (this->x * v3.getZ() - this->z * v3.getX()) * (this->x * v3.getZ() - this->z * v3.getX()) +
                   (this->x * v3.getY() - this->y * v3.getX()) * (this->x * v3.getY() - this->y * v3.getX()));
};

double Vector3D::get_the_angel_in_degree(const Vector3D& v3) const {
    return acos(abs(this->x * v3.getX() + this->y * v3.getY() + this->z * v3.getZ())/
                (sqrt(this->x * this->x + this->y * this->y + this->z * this->z)*sqrt(v3.getX()*v3.getX() + v3.getY()*v3.getY() + v3.getZ()*v3.getZ())))
           *180/3.141592653589793;
};

double Vector3D::get_the_angel_in_radian(const Vector3D& v3) const {
    return acos(abs(this->x * v3.getX() + this->y * v3.getY() + this->z * v3.getZ())/
                (sqrt(this->x * this->x + this->y * this->y + this->z * this->z)*sqrt(v3.getX()*v3.getX() + v3.getY()*v3.getY() + v3.getZ()*v3.getZ())));
};

std::ostream& operator<<(std::ostream& os, const Vector3D& v3) {
    os << "(" << v3.getX() << "; " << v3.getY() << "; " << v3.getZ() << ")";
    return os;
};

std::istream& operator>>(std::istream& is, Vector3D& v3) {
    double x, y, z;
    is >> x >> y >> z;
    v3.setX(x);
    v3.setY(y);
    v3.setZ(z);
    return is;
};
