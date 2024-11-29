// C++ For Loop with 87 exercises from https://www.w3resource.com/cpp-exercises/for-loop/index.php
#include <iostream>
#include <vector>
#include <cstdlib> // For EXIT_SUCCESS
#include <cmath>   // For sqrt
#include "cpp_for_loop.h"

int inputNumber()
{
    // Function to input a number from the user
    int n;
    std::cout << "Input number: ";
    std::cin >> n;
    return n;
}

std::vector<int> generateFirstNNaturalNumbers(int n)
/**
 * Function to generate the first N natural numbers.
 *
 * This function returns a vector containing the first N natural numbers.
 *
 * Parameters:
 * n (int): The number of natural numbers to generate.
 *
 * Returns:
 * std::vector<int>: A vector containing the first N natural numbers.
 */
{
    std::vector<int> vec;
    for (int i = 0; i < n; i++)
    {
        vec.push_back(i);
    }
    return vec;
}

int sumOfNNaturalNumbers(const std::vector<int> &vec)
{
    /**
     * Function to calculate sum of the N natural numbers in vector.
     *
     * This function returns a integer containing the sum of N natural numbers.
     *
     * Parameters:
     * vec (vector<int>): A vector number of natural numbers to calculate the sum.
     *
     * Returns:
     * int: Sum of elements in the vector.
     */
    int sum = 0;
    for (const auto &i : vec)
    {
        sum += i;
    }
    return sum;
}

bool isPrimeNumber(int n)
/**
 * Function to check whether a number is prime or not.
 *
 * Parameters:
 * n (int): An integer number to check.
 *
 * Returns:
 * bool: A number N is primer or not.
 */
{
    if (n <= 1)
        return false;
    int count = 0;
    for (int i = 1; i < sqrt(n); i++)
    {
        if (n % i == 0)
            ++count;
    }
    return (count == 1) ? true : false;
}