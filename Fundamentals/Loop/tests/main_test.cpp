#include <gtest/gtest.h>
#include <sstream>
#include "cpp_for_loop.h"
#include "utils.h"

// Unit test for inputNumber function
TEST(GenerateFirstNNaturalNumbersTest, HandlesPositiveInput)
{
    std::vector<int> result = generateFirstNNaturalNumbers(10);
    std::vector<int> expected{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    EXPECT_EQ(result, expected);
}

TEST(GenerateFirstNNaturalNumbersTest, HandlesZeroInput)
{
    std::vector<int> result = generateFirstNNaturalNumbers(0);
    std::vector<int> expected{};
    EXPECT_EQ(result, expected);
}

TEST(GenerateFirstNNaturalNumbersTest, HandlesNegativeInput)
{
    std::vector<int> result = generateFirstNNaturalNumbers(-3);
    std::vector<int> expected{};
    EXPECT_EQ(result, expected);
}

// Unit test for sumOfNNaturalNumbers()
TEST(SumOfNNaturalNumbersTest, HandlesPositiveInput)
{
    std::vector<int> vec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    EXPECT_EQ(sumOfNNaturalNumbers(vec), 55);
}

TEST(SumOfNNaturalNumbersTest, HandlesNegativeInput)
{
    std::vector<int> vec{0, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10};
    EXPECT_EQ(sumOfNNaturalNumbers(vec), -55);
}

// Unit test for isPrimeNumber()
TEST(IsPrimeNumberTest, PrimeNumbers)
{
    EXPECT_TRUE(isPrimeNumber(2));
    EXPECT_TRUE(isPrimeNumber(3));
    EXPECT_TRUE(isPrimeNumber(5));
    EXPECT_TRUE(isPrimeNumber(11));
}

TEST(IsPrimeNumberTest, NonPrimeNumbers)
{
    EXPECT_FALSE(isPrimeNumber(0));
    EXPECT_FALSE(isPrimeNumber(-1));
    EXPECT_FALSE(isPrimeNumber(1));
    EXPECT_FALSE(isPrimeNumber(4));
    EXPECT_FALSE(isPrimeNumber(9));
}

// Unit test for isPerfectNumber()
TEST(IsPerfectNumberTest, PerfectNumbers)
{
    EXPECT_TRUE(isPerfectNumber(6));
    EXPECT_TRUE(isPerfectNumber(28));
    EXPECT_TRUE(isPerfectNumber(496));
}

TEST(IsPerfectNumberTest, NonPerfectNumbers)
{
    EXPECT_FALSE(isPerfectNumber(0));
    EXPECT_FALSE(isPerfectNumber(-1));
    EXPECT_FALSE(isPerfectNumber(1));
    EXPECT_FALSE(isPerfectNumber(4));
    EXPECT_FALSE(isPerfectNumber(500));
}

// Unit test for findPerfectNumbers()
TEST(FindPerfectNumbersTest, HandlesEmptyVector)
{
    std::vector<int> input = findPerfectNumbers({});
    std::vector<int> expected {};
    EXPECT_EQ(input, expected);
}

TEST(FindPerfectNumbersTest, HandlesNoPerfectNumbers)
{
    std::vector<int> input = findPerfectNumbers({1, 2, 3, 5, 7, 11});
    std::vector<int> expected {};
    EXPECT_EQ(input, expected);
}

TEST(FindPerfectNumbersTest, HandlesPerfectNumbers)
{
    std::vector<int> input = findPerfectNumbers({6, 28, 496});
    std::vector<int> expected {6, 28, 496};
    EXPECT_EQ(input, expected);
}

TEST(FindPerfectNumbersTest, HandlesMixedNumbers)
{
    std::vector<int> input = findPerfectNumbers({1, 6, 2, 28, 3, 496, 10});
    std::vector<int> expected {{6, 28, 496}};
    EXPECT_EQ(input, expected);
}

// Unit test for countPrimeNumber function
TEST(CountPrimeNumberTest, HandlesEmptyVector) {
    std::vector<int> input = {};
    int expected = 0;
    EXPECT_EQ(countPrimeNumber(input), expected);
}

TEST(CountPrimeNumberTest, HandlesNoPrimeNumbers) {
    std::vector<int> input = {1, 4, 6, 8, 9, 10, 12};
    int expected = 0;
    EXPECT_EQ(countPrimeNumber(input), expected);
}

TEST(CountPrimeNumberTest, HandlesPrimeNumbersOnly) {
    std::vector<int> input = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    int expected = 10;
    EXPECT_EQ(countPrimeNumber(input), expected);
}

TEST(CountPrimeNumberTest, HandlesMixedNumbers) {
    std::vector<int> input = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
    int expected = 7;
    EXPECT_EQ(countPrimeNumber(input), expected);
}

// Unit test for printCurrentTime() in utils.h
TEST(PrintCurrentTimeTest, OutputsCurrentTime)
{
    // Capture the output
    std::ostringstream capturedOut;
    printCurrentTime(capturedOut);

    // Get the current time for comparison
    auto now = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
    std::string expectedOutput = "Current time: " + std::string(std::ctime(&currentTime));

    // Compare the captured output with the expected output format
    std::string capturedStr = capturedOut.str();

    EXPECT_EQ(capturedStr.substr(0, 14), "Current time: ");
}

// Main function for running tests
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
