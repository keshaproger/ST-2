// Copyright 2025 Коньков И.

#include "tasks.h"
#include "circle.h"

double calculateGap(double delta) {
    const double EARTH_RADIUS = 6378.1 * 1000;
    Circle earth(EARTH_RADIUS);

    double newFerence = earth.getFerence() + 1;
    earth.setFerence(newFerence);

    return earth.getRadius() - EARTH_RADIUS;
}

double calculatePoolCost(int value) {
    if (value <= 0) return 0;

    double poolRadius = 3.0;
    double roadWidth = 1.0;

    Circle pool(poolRadius);
    Circle outer(poolRadius + roadWidth);

    double roadArea = outer.getArea() - pool.getArea();
    double fenceLength = outer.getFerence();

    double cost = (roadArea * 1000 + fenceLength * 2000) * value;
    return cost;
}
