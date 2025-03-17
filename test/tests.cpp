// Copyright 2025 Коньков И.

#include <gtest/gtest.h>
#include <cmath>

#include "circle.h"
#include "tasks.h"

TEST(CircleTest, RadiusUpdatesCorrectly) {
    Circle c(10);
    ASSERT_DOUBLE_EQ(c.getRadius(), 10);
    ASSERT_NEAR(c.getFerence(), 62.8319, 1e-4);
    ASSERT_NEAR(c.getArea(), 314.159, 1e-3);
}

TEST(CircleTest, FerenceUpdatesCorrectly) {
    Circle c(10);
    c.setFerence(100);
    ASSERT_NEAR(c.getRadius(), 100 / (2 * M_PI), 1e-4);
}

TEST(CircleTest, AreaUpdatesCorrectly) {
    Circle c(10);
    c.setArea(100);
    ASSERT_NEAR(c.getRadius(), sqrt(100 / M_PI), 1e-4);
}

TEST(TaskTest, EarthGap) {
    double gap = calculateGap();
    ASSERT_NEAR(gap, 0.159, 1e-3);
}

TEST(TaskTest, PoolCost) {
    double cost = calculatePoolCost();
    ASSERT_NEAR(cost, 72256.631, 1);
}

TEST(CircleTest, DefaultConstructor) {
    Circle c;
    ASSERT_DOUBLE_EQ(c.getRadius(), 0);
}

TEST(CircleTest, NegativeRadius) {
    Circle c(-5);
    ASSERT_DOUBLE_EQ(c.getRadius(), 0);
}

TEST(CircleTest, SetNegativeFerence) {
    Circle c(10);
    c.setFerence(-50);
    ASSERT_GE(c.getRadius(), 0);
}

TEST(CircleTest, SetNegativeArea) {
    Circle c(10);
    c.setArea(-100);
    ASSERT_GE(c.getRadius(), 0);
}

TEST(TaskTest, SmallEarthGap) {
    double gap = calculateGap(1);
    ASSERT_NEAR(gap, 0.00159, 1e-5);
}

TEST(TaskTest, LargeEarthGap) {
    double gap = calculateGap(1000);
    ASSERT_NEAR(gap, 159, 1);
}

TEST(TaskTest, PoolCostZero) {
    double cost = calculatePoolCost(0);
    ASSERT_DOUBLE_EQ(cost, 0);
}

TEST(TaskTest, PoolCostNegative) {
    double cost = calculatePoolCost(-10);
    ASSERT_GE(cost, 0);
}

TEST(TaskTest, PoolCostLarge) {
    double cost = calculatePoolCost(10000);
    ASSERT_NEAR(cost, 7.2256631e6, 1);
}

TEST(CircleTest, RadiusChangeAffectsFerence) {
    Circle c(10);
    c.setRadius(20);
    ASSERT_NEAR(c.getFerence(), 2 * M_PI * 20, 1e-4);
}

TEST(CircleTest, RadiusChangeAffectsArea) {
    Circle c(10);
    c.setRadius(20);
    ASSERT_NEAR(c.getArea(), M_PI * 400, 1e-4);
}

TEST(CircleTest, FerenceChangeAffectsRadius) {
    Circle c(10);
    c.setFerence(50);
    ASSERT_NEAR(c.getRadius(), 50 / (2 * M_PI), 1e-4);
}

TEST(CircleTest, AreaChangeAffectsRadius) {
    Circle c(10);
    c.setArea(200);
    ASSERT_NEAR(c.getRadius(), sqrt(200 / M_PI), 1e-4);
}

TEST(TaskTest, EarthGapWithZeroRadius) {
    double gap = calculateGap(0);
    ASSERT_DOUBLE_EQ(gap, 0);
}

TEST(TaskTest, EarthGapWithNegativeRadius) {
    double gap = calculateGap(-100);
    ASSERT_GE(gap, 0);
}

TEST(TaskTest, PoolCostExtremeCase) {
    double cost = calculatePoolCost(1e6);
    ASSERT_NEAR(cost, 7.2256631e10, 1e5);
}
