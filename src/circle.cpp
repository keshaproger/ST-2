// Copyright 2022 UNN-CS Team
#include "circle.h"
#include <cmath>

Circle::Circle(double r) {
    setRadius(r);
}

void Circle::setRadius(double r) {
    radius = r;
    ference = 2 * M_PI * r;
    area = M_PI * r * r;
}

void Circle::setFerence(double f) {
    ference = f;
    radius = f / (2 * M_PI);
    area = M_PI * radius * radius;
}

void Circle::setArea(double a) {
    area = a;
    radius = std::sqrt(a / M_PI);
    ference = 2 * M_PI * radius;
}

double Circle::getRadius() const { return radius; }
double Circle::getFerence() const { return ference; }
double Circle::getArea() const { return area; }
