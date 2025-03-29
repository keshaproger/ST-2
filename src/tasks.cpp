// Copyright 2024 New Developer
#include "tasks.h"
#include "circle.h"

namespace {
    constexpr double EARTH_RADIUS_KM = 6378.1;
    constexpr double ROPE_ADDITION_M = 0.001;
    constexpr double POOL_RADIUS = 3.0;
    constexpr double PATH_WIDTH = 1.0;
    constexpr double CONCRETE_PRICE = 1000.0;
    constexpr double FENCE_PRICE = 2000.0;
}

// Задача "Верёвка"
double calculateGap() {
    Circle earth(EARTH_RADIUS_KM);
    earth.setCircumference(earth.getCircumference() + ROPE_ADDITION_M);
    return earth.getRadius() - EARTH_RADIUS_KM;
}

// Задача "Бассейн"
double calculatePoolCost() {
    Circle pool(POOL_RADIUS);
    Circle poolWithPath(POOL_RADIUS + PATH_WIDTH);
    
    double concreteCost = (poolWithPath.getArea() - pool.getArea()) * CONCRETE_PRICE;
    double fenceCost = poolWithPath.getCircumference() * FENCE_PRICE;
    
    return concreteCost + fenceCost;
}
