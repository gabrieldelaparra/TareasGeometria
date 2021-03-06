//
// Definición y operaciones de vectores:
// https://es.wikipedia.org/wiki/Vector
// https://es.wikipedia.org/wiki/Producto_vectorial
// https://es.wikipedia.org/wiki/Producto_escalar
//
// Created by wororo on 06-04-17.
//

#ifndef TAREA1_VECTOR_H
#define TAREA1_VECTOR_H

#include <iostream>
#include <cmath>
#include "Point.h"

template<class T>
class Vector {
private:
    Point<T> Point1 = Point<T>(0, 0, 0);
public:

    Point<T> Point2;

    Vector() : Point1(), Point2() {};

    Vector(T x, T y) : Point2(x, y) {};

    Vector(T x, T y, T z) : Point2(x, y, z) {};

    Vector(Point<T> p) : Point2(p) {};

    Vector<T> UnitVector() {
        Vector<T> newVector(0, 0, 0);
        double mag = Length();
        if (mag != 0) {
            newVector.Point2.X = Point2.X / mag;
            newVector.Point2.Y = Point2.Y / mag;
            newVector.Point2.Z = Point2.Z / mag;
        }

        return newVector;
    }

    double Length() {
        return std::sqrt(std::pow(Point2.X - Point1.X, 2)
                         + std::pow(Point2.Y - Point1.Y, 2)
                         + std::pow(Point2.Z - Point1.Z, 2));
    }

    template<class T2>
    Vector<T> Cross(Vector<T2> &v2) {
        Vector<T> newVector(0, 0, 0);
        double len = Length();
        if (len != 0) {
            newVector.Point2.X = Point2.Y * T(v2.Point2.Z) - Point2.Z * T(v2.Point2.Y);
            newVector.Point2.Y = Point2.Z * T(v2.Point2.X) - Point2.X * T(v2.Point2.Z);
            newVector.Point2.Z = Point2.X * T(v2.Point2.Y) - Point2.Y * T(v2.Point2.X);
        }

        return newVector;
    }

    template<class T2>
    double Dot(Vector<T2> &v2) {
        return Point2.X * T(v2.Point2.X)
               + Point2.Y * T(v2.Point2.Y)
               + Point2.Z * T(v2.Point2.Z);

    }

    template<class T2>
    bool operator==(Vector<T2> &v2) {
        return Point1.X == T(v2.Point1.X)
               && Point1.Y == T(v2.Point1.Y)
               && Point1.Z == T(v2.Point1.Z)
               && Point2.X == T(v2.Point2.X)
               && Point2.Y == T(v2.Point2.Y)
               && Point2.Z == T(v2.Point2.Z);
    }


    template<class T2>
    Vector<T> operator+(Vector<T2> &v2) {
        Vector<T> newVector(Point2.X + T(v2.Point2.X),
                            Point2.Y + T(v2.Point2.Y),
                            Point2.Z + T(v2.Point2.Z));

        return newVector;
    }

    template<class T2>
    Vector<T> operator-(Vector<T2> &v2) {
        Vector<T> newVector(Point2.X - T(v2.Point2.X),
                            Point2.Y - T(v2.Point2.Y),
                            Point2.Z - T(v2.Point2.Z));

        return newVector;
    }

    void ToString() const {
        std::cout << "(" << Point2.X
                  << ", " << Point2.Y
                  << ", " << Point2.Z
                  << ")"
                  << std::endl;
    }

};


#endif //TAREA1_VECTOR_H
