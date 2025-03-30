// Copyright 2024 New Developer
#include "circle.h"
#include <cmath>
#include <stdexcept>

Circle::Circle(double radius) {
    setRadius(radius);
}

void Circle::computeCircumference() {
    m_circumference = 2 * M_PI * m_radius;
}

void Circle::computeArea() {
    m_area = M_PI * m_radius * m_radius;
}

void Circle::setRadius(double radius) {
    if (radius < 0) throw std::invalid_argument("Radius must be non-negative");
    m_radius = radius;
    computeCircumference();
    computeArea();
}

void Circle::setCircumference(double circumference) {
    if (circumference < 0)
        throw std::invalid_argument("Circumference must be non-negative");
    m_circumference = circumference;
    m_radius = circumference / (2 * M_PI);
    computeArea();
}

void Circle::setArea(double area) {
    if (area < 0) throw std::invalid_argument("Area must be non-negative");
    m_area = area;
    m_radius = sqrt(area / M_PI);
    computeCircumference();
}

double Circle::radius() const { return m_radius; }
double Circle::circumference() const { return m_circumference; }
double Circle::area() const { return m_area; }
