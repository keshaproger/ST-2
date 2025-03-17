#include "tasks.h"
#include "circle.h"

#include <cmath>
#include <gtest/gtest.h>

TEST(CircleTest, RadiusUpdatesCorrectly) {
    Circle c(10);
    ASSERT_DOUBLE_EQ(c.getRadius(), 10);
    ASSERT_NEAR(c.getFerence(), 62.8319, 1e-4);
    ASSERT_NEAR(c.getArea(), 314.159, 1e-3);
}

TEST(CircleTest, FerenceUpdatesCorrectly) {
    Circle c(10);
    c.setFerence(100);
    ASSERT_NEAR(c.getRadius(), 100 / (2 * 3.14159), 1e-4);
}

TEST(CircleTest, AreaUpdatesCorrectly) {
    Circle c(10);
    c.setArea(100);
    ASSERT_NEAR(c.getRadius(), sqrt(100 / 3.14159), 1e-4);
}

TEST(TaskTest, EarthGap) {
    double gap = calculateGap();
    ASSERT_NEAR(gap, 0.159, 1e-3);
}

TEST(TaskTest, PoolCost) {
    double cost = calculatePoolCost();
    ASSERT_NEAR(cost, 44000, 1);
}
