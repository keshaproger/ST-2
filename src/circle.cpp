// Copyright 2024 New Developer
#include "circle.h"
#include <cmath>

constexpr double PI = acos(-1.0); // Использована константа через acos

Circle::Circle(double radius) {
    setRadius(radius);
}

void Circle::updateFromRadius() {
    m_circumference = 2 * PI * m_radius;
    m_area = PI * m_radius * m_radius;
}

void Circle::updateFromCircumference() {
    m_radius = m_circumference / (2 * PI);
    m_area = PI * m_radius * m_radius;
}

void Circle::updateFromArea() {
    m_radius = sqrt(m_area / PI);
    m_circumference = 2 * PI * m_radius;
}

// Дополнительные проверки в сеттерах
void Circle::setRadius(double radius) {
    if (radius < 0) throw std::invalid_argument("Invalid radius");
    m_radius = radius;
    updateFromRadius();
}

void Circle::setCircumference(double circumference) {
    if (circumference < 0) throw std::invalid_argument("Invalid length");
    m_circumference = circumference;
    updateFromCircumference();
}

void Circle::setArea(double area) {
    if (area < 0) throw std::invalid_argument("Invalid area");
    m_area = area;
    updateFromArea();
}

// Геттеры
double Circle::getRadius() const { return m_radius; }
double Circle::getCircumference() const { return m_circumference; }
double Circle::getArea() const { return m_area; }
