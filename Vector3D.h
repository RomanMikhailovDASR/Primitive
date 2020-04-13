//
// Created by xaero on 08.04.2020.
//

#ifndef UNTITLED_VECTOR3D_H
#define UNTITLED_VECTOR3D_H

#include <iostream>
// описание аналогично описанию Vector2D
class Vector3D {
private:
    double x;
    double y;
    double z;
public:
    Vector3D();

    Vector3D(double x, double y, double z);

    ~Vector3D();

    double getX() const;
    double getY() const;
    double getZ() const;

    void setX(double x);
    void setY(double y);
    void setZ(double z);

    bool operator==(const Vector3D &v3) const;

    bool operator!=(const Vector3D &v3) const;

    Vector3D operator=(const Vector3D &v3);

    Vector3D operator+(const Vector3D &v3) const;
    Vector3D operator+=(const Vector3D &v3) const;

    Vector3D operator-(const Vector3D &v3) const;
    Vector3D operator-=(const Vector3D &v3) const;

    Vector3D operator*(double a) const;
    Vector3D operator*=(double a) const;

    Vector3D operator/(double a) const;
    Vector3D operator/=(double a) const;

    double get_module() const;

    double scalar_product(const Vector3D &v3) const;

    Vector3D vector_product(const Vector3D& v3);

    double module_vector_product(const Vector3D &v3) const;

    double get_the_angel_in_degree(const Vector3D &v3) const;

    double get_the_angel_in_radian(const Vector3D &v3) const;

};

    std::ostream& operator<<(std::ostream& os, const Vector3D& v3);
    std::istream& operator>>(std::istream& is, Vector3D& v3);





#endif //UNTITLED_VECTOR3D_H
