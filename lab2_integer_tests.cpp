#include <gtest/gtest.h>

// Integer9: первая цифра трехзначного числа (сотни).
int Integer9(int n) {
    return n / 100;
}

// Integer19: количество полных минут с начала суток.
int Integer19(int n) {
    return n / 60;
}

// Integer21: секунды, прошедшие с начала последней минуты.
int Integer21(int n) {
    return n % 60;
}

// Integer9
TEST(Integer9Test, MinimumNumber) {
    // Arrange
    int n = 100;
    // Act
    int result = Integer9(n);
    // Assert
    EXPECT_EQ(result, 1);
}

TEST(Integer9Test, NormalNumber) {
    // Arrange
    int n = 567;
    // Act
    int result = Integer9(n);
    // Assert
    EXPECT_EQ(result, 5);
}

TEST(Integer9Test, MaximumNumber) {
    // Arrange
    int n = 999;
    // Act
    int result = Integer9(n);
    // Assert
    EXPECT_EQ(result, 9);
}

// Integer19
TEST(Integer19Test, LessThanMinute) {
    // Arrange
    int n = 59;
    // Act
    int result = Integer19(n);
    // Assert
    EXPECT_EQ(result, 0);
}

TEST(Integer19Test, SeveralMinutes) {
    // Arrange
    int n = 125;
    // Act
    int result = Integer19(n);
    // Assert
    EXPECT_EQ(result, 2);
}

TEST(Integer19Test, EndOfDay) {
    // Arrange
    int n = 86399;
    // Act
    int result = Integer19(n);
    // Assert
    EXPECT_EQ(result, 1439);
}

// Integer21
TEST(Integer21Test, ExactMinute) {
    // Arrange
    int n = 120;
    // Act
    int result = Integer21(n);
    // Assert
    EXPECT_EQ(result, 0);
}

TEST(Integer21Test, SeveralSeconds) {
    // Arrange
    int n = 125;
    // Act
    int result = Integer21(n);
    // Assert
    EXPECT_EQ(result, 5);
}

TEST(Integer21Test, LastSecondOfDay) {
    // Arrange
    int n = 86399;
    // Act
    int result = Integer21(n);
    // Assert
    EXPECT_EQ(result, 59);
}
