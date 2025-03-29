// Copyright 2024 New Developer
#ifndef CIRCLE_H
#define CIRCLE_H

#include <stdexcept>

class Circle {
private:
    double m_radius;
    double m_circumference;
    double m_area;

    void updateFromRadius();
    void updateFromCircumference();
    void updateFromArea();

public:
    explicit Circle(double radius);
    
    void setRadius(double radius);
    void setCircumference(double circumference);
    void setArea(double area);
    
    double getRadius() const;
    double getCircumference() const;
    double getArea() const;
};

#endif // CIRCLE_H
