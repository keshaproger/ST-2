// Copyright 2024 New Developer
#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_

class Circle {
 private:
    double m_radius;
    double m_circumference;
    double m_area;

    void computeCircumference();
    void computeArea();

 public:
    explicit Circle(double radius);

    void setRadius(double radius);
    void setCircumference(double circumference);
    void setArea(double area);

    double radius() const;
    double circumference() const;
    double area() const;
};

#endif // INCLUDE_CIRCLE_H_
