// Copyright 2025 UNN-CS Team
#include "tasks.h"
#include "circle.h"

double calculateRopeGap() {
    const double earthRadius = 6378100.0; // В метрах
    Circle earth(earthRadius);
    earth.setFerence(earth.getFerence() + 1.0);
    return earth.getRadius() - earthRadius;
}

double calculatePoolCost() {
    const double poolRadius = 3.0;
    const double width = 1.0;
    const double outerRadius = poolRadius + width;

    Circle pool(poolRadius);
    Circle outer(outerRadius);

    double concreteArea = outer.getArea() - pool.getArea();
    double fenceLength = outer.getFerence();

    return concreteArea * 1000.0 + fenceLength * 2000.0;
}
