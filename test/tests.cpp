// Copyright 2025 UNN-CS Team
#include <gtest/gtest.h>
#include <cmath>
#include "circle.h"
#include "tasks.h"

// Тесты для класса Circle
TEST(CircleTest, ConstructorAndGetters) {
    Circle c(5.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 5.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI * 5.0);
    EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 25.0);
}

TEST(CircleTest, SetRadius) {
    Circle c(1.0);
    c.setRadius(2.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 2.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 4 * M_PI);
    EXPECT_DOUBLE_EQ(c.getArea(), 4 * M_PI);
}

TEST(CircleTest, SetFerence) {
    Circle c(0.0);
    c.setFerence(2 * M_PI);
    EXPECT_NEAR(c.getRadius(), 1.0, 1e-6);
    EXPECT_NEAR(c.getArea(), M_PI, 1e-6);
}

TEST(CircleTest, SetArea) {
    Circle c(0.0);
    c.setArea(M_PI);
    EXPECT_NEAR(c.getRadius(), 1.0, 1e-6);
    EXPECT_NEAR(c.getFerence(), 2 * M_PI, 1e-6);
}

TEST(CircleTest, ZeroRadius) {
    Circle c(0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTest, LargeRadius) {
    Circle c(1e6);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI * 1e6);
    EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 1e12);
}

TEST(CircleTest, UpdateRadiusFromArea) {
    Circle c(2.0);
    c.setArea(4 * M_PI);
    EXPECT_NEAR(c.getRadius(), 2.0, 1e-6);
    EXPECT_NEAR(c.getFerence(), 4 * M_PI, 1e-6);
}

TEST(CircleTest, UpdateFerenceFromRadius) {
    Circle c(3.0);
    c.setFerence(6 * M_PI);
    EXPECT_NEAR(c.getRadius(), 3.0, 1e-6);
    EXPECT_NEAR(c.getArea(), 9 * M_PI, 1e-6);
}

TEST(CircleTest, ChainUpdates) {
    Circle c(10.0);
    c.setRadius(5.0);
    c.setFerence(10 * M_PI);
    c.setArea(25 * M_PI);
    EXPECT_NEAR(c.getRadius(), 5.0, 1e-6);
}

TEST(CircleTest, NegativeRadiusHandling) {
    Circle c(-1.0);
    c.setRadius(-1.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), -1.0);
    EXPECT_TRUE(std::isnan(c.getArea()));
}

// Тесты для задачи "Земля и верёвка"
TEST(RopeProblemTest, BasicGapCalculation) {
    double gap = calculateRopeGap();
    double expected = 1.0 / (2 * M_PI);
    EXPECT_NEAR(gap, expected, 1e-6);
}

TEST(RopeProblemTest, LargeEarthRadius) {
    const double earthRadius = 1e9;
    Circle earth(earthRadius);
    earth.setFerence(earth.getFerence() + 1.0);
    double gap = earth.getRadius() - earthRadius;
    EXPECT_NEAR(gap, 1.0 / (2 * M_PI), 1e-6);
}

TEST(RopeProblemTest, ZeroEarthRadius) {
    Circle earth(0.0);
    earth.setFerence(1.0);
    EXPECT_NEAR(earth.getRadius(), 1.0 / (2 * M_PI), 1e-6);
}

// Тесты для задачи "Бассейн"
TEST(PoolProblemTest, BasicCostCalculation) {
    double cost = calculatePoolCost();
    double expectedConcrete = M_PI * (16.0 - 9.0) * 1000.0;
    double expectedFence = 2 * M_PI * 4.0 * 2000.0;
    EXPECT_NEAR(cost, expectedConcrete + expectedFence, 1e-6);
}

TEST(PoolProblemTest, ZeroWidth) {
    Circle pool(3.0);
    Circle outer(3.0);
    double cost = (outer.getArea() - pool.getArea()) * 1000.0 + outer.getFerence() * 2000.0;
    EXPECT_DOUBLE_EQ(cost, 0.0 + 2 * M_PI * 3.0 * 2000.0);
}

TEST(PoolProblemTest, LargePoolRadius) {
    const double poolRadius = 100.0;
    const double width = 1.0;
    Circle pool(poolRadius);
    Circle outer(poolRadius + width);
    double cost = (outer.getArea() - pool.getArea()) * 1000.0 + outer.getFerence() * 2000.0;
    EXPECT_NEAR(cost, (M_PI * (101.0 * 101.0 - 100.0 * 100.0) * 1000.0 + 2 * M_PI * 101.0 * 2000.0, 1e-6);
}

TEST(PoolProblemTest, NegativeWidthHandling) {
    const double poolRadius = 3.0;
    const double width = -1.0;
    Circle outer(poolRadius + width); // Радиус = 2.0
    double cost = (outer.getArea() - M_PI * 9.0) * 1000.0 + outer.getFerence() * 2000.0;
    EXPECT_NEAR(cost, (M_PI * (4.0 - 9.0) * 1000.0 + 2 * M_PI * 2.0 * 2000.0, 1e-6);
}

TEST(PoolProblemTest, ZeroPoolRadius) {
    const double poolRadius = 0.0;
    const double width = 1.0;
    Circle pool(poolRadius);
    Circle outer(width);
    double cost = (outer.getArea() - 0.0) * 1000.0 + outer.getFerence() * 2000.0;
    EXPECT_NEAR(cost, M_PI * 1.0 * 1000.0 + 2 * M_PI * 1.0 * 2000.0, 1e-6);
}
