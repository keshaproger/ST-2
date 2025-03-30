// Copyright 2025 UNN-CS Team
#include <gtest/gtest.h>
#include <cmath>
#include "circle.h"
#include "tasks.h"

// Тесты класса Circle
TEST(CircleTest, ConstructorInitializesCorrectly) {
    Circle c(5.0);
    EXPECT_DOUBLE_EQ(c.radius(), 5.0);
    EXPECT_DOUBLE_EQ(c.circumference(), 10 * M_PI);
    EXPECT_DOUBLE_EQ(c.area(), 25 * M_PI);
}

TEST(CircleTest, ZeroRadiusInitialization) {
    Circle c(0.0);
    EXPECT_EQ(c.radius(), 0.0);
    EXPECT_EQ(c.circumference(), 0.0);
    EXPECT_EQ(c.area(), 0.0);
}

TEST(CircleTest, NegativeRadiusThrowsException) {
    EXPECT_THROW(Circle(-2.5), std::invalid_argument);
}

TEST(CircleTest, SetRadiusUpdatesAllFields) {
    Circle c(2.0);
    c.setRadius(4.0);
    EXPECT_DOUBLE_EQ(c.radius(), 4.0);
    EXPECT_DOUBLE_EQ(c.circumference(), 8 * M_PI);
    EXPECT_DOUBLE_EQ(c.area(), 16 * M_PI);
}

TEST(CircleTest, SetCircumferenceCalculatesRadius) {
    Circle c(1.0);
    c.setCircumference(20 * M_PI);
    EXPECT_NEAR(c.radius(), 10.0, 1e-6);
    EXPECT_NEAR(c.area(), 100 * M_PI, 1e-6);
}

TEST(CircleTest, SetAreaUpdatesCircumference) {
    Circle c(3.0);
    c.setArea(50 * M_PI);
    EXPECT_NEAR(c.radius(), sqrt(50), 1e-6);
    EXPECT_NEAR(c.circumference(), 2 * M_PI * sqrt(50), 1e-6);
}

TEST(CircleTest, SetZeroCircumferenceResetsAll) {
    Circle c(5.0);
    c.setCircumference(0.0);
    EXPECT_EQ(c.radius(), 0.0);
    EXPECT_EQ(c.area(), 0.0);
}

TEST(CircleTest, SetNegativeCircumferenceThrows) {
    Circle c(2.0);
    EXPECT_THROW(c.setCircumference(-1.0), std::invalid_argument);
}

TEST(CircleTest, SetNegativeAreaThrows) {
    Circle c(2.0);
    EXPECT_THROW(c.setArea(-10.0), std::invalid_argument);
}

TEST(CircleTest, MultipleFieldUpdatesConsistency) {
    Circle c(2.0);
    c.setRadius(5.0);
    c.setArea(100 * M_PI);
    c.setCircumference(10 * M_PI);
    EXPECT_DOUBLE_EQ(c.radius(), 5.0);
    EXPECT_DOUBLE_EQ(c.circumference(), 10 * M_PI);
}

// Тесты для задачи "Верёвка"
TEST(RopeTaskTest, GapIsCorrect) {
    double gap = calculateRopeGap();
    double expectedGap = 0.001 / (2 * M_PI);
    EXPECT_NEAR(gap, expectedGap, 1e-6);
}

TEST(RopeTaskTest, EarthRadiusUnchanged) {
    Circle earth(6378.1);
    calculateRopeGap();
    EXPECT_DOUBLE_EQ(earth.radius(), 6378.1);
}

// Тесты для задачи "Бассейн"
TEST(PoolTaskTest, ConcreteAreaCalculation) {
    Circle inner(3.0);
    Circle outer(4.0);
    double area = outer.area() - inner.area();
    EXPECT_DOUBLE_EQ(area, 7 * M_PI);
}

TEST(PoolTaskTest, TotalCostCalculation) {
    double cost = calculatePoolCost();
    double expectedCost = (7 * M_PI) * 1000 + (8 * M_PI) * 2000;
    EXPECT_NEAR(cost, expectedCost, 1e-2);
}

TEST(PoolTaskTest, ZeroPathWidthCost) {
    Circle pool(3.0);
    Circle sameAsPool(3.0);
    double cost = (sameAsPool.area() - pool.area()) * 1000 + sameAsPool.circumference() * 2000;
    EXPECT_DOUBLE_EQ(cost, 6 * M_PI * 2000);
}

// Граничные случаи
TEST(EdgeCases, MaxDoubleRadius) {
    Circle c(DBL_MAX);
    EXPECT_DOUBLE_EQ(c.circumference(), 2 * M_PI * DBL_MAX);
}

TEST(EdgeCases, TinyRadius) {
    Circle c(1e-10);
    EXPECT_NEAR(c.area(), M_PI * 1e-20, 1e-30);
}

TEST(EdgeCases, SetAreaToZero) {
    Circle c(5.0);
    c.setArea(0.0);
    EXPECT_EQ(c.radius(), 0.0);
    EXPECT_EQ(c.circumference(), 0.0);
}

TEST(EdgeCases, SetCircumferenceToZero) {
    Circle c(5.0);
    c.setCircumference(0.0);
    EXPECT_EQ(c.radius(), 0.0);
    EXPECT_EQ(c.area(), 0.0);
}

TEST(EdgeCases, NegativeInputInTasks) {
    EXPECT_NO_THROW(calculateRopeGap());
}
