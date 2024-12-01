#ifndef MY_MATH_H
#define MY_MATH_H

#include <vector>
#include <cmath>

// Function declarations
std::vector<double> parallelSinCalculation(const std::vector<double>& input);
std::vector<double> nonParallelSinCalculation(const std::vector<double>& input);
std::vector<double> calculateSinSequence(double start, double end, double step);
void measureExecutionTime(void (*func)(const std::vector<double>&), const std::vector<double>& input);

#endif // MY_MATH_H
