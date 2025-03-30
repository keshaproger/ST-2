// Copyright 2024 New Developer
#include "tasks.h"
#include "circle.h"

double calculateRopeGap() {
    const double EARTH_RADIUS_KM = 6378.1;
    Circle earth(EARTH_RADIUS_KM);
    earth.setCircumference(earth.circumference() + 0.001); // +1 meter in km
    return earth.radius() - EARTH_RADIUS_KM;
}

double calculatePoolCost() {
    const double POOL_RADIUS = 3.0;
    const double PATH_WIDTH = 1.0;
    Circle pool(POOL_RADIUS);
    Circle poolWithPath(POOL_RADIUS + PATH_WIDTH);

    double concreteCost = (poolWithPath.area() - pool.area()) * 1000;
    double fenceCost = poolWithPath.circumference() * 2000;
    
    return concreteCost + fenceCost;
}
