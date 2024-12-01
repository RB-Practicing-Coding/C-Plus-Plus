#include "my_math.h"
#include <iostream>

// Wrapper functions for the measureExecutionTime function
void parallelWrapper(const std::vector<double> &input)
{
    parallelSinCalculation(input);
}

void nonParallelWrapper(const std::vector<double> &input)
{
    nonParallelSinCalculation(input);
}

int main()
{
    // Sample input for sin calculation
    std::vector<double> input(1'000'000);
    for (size_t i = 0; i < input.size(); ++i)
    {
        input[i] = i * 0.0001;
    }

    // Measure time for parallel sin calculation
    std::cout << "Parallel computation:" << std::endl;
    measureExecutionTime(parallelWrapper, input);

    // Measure time for non-parallel sin calculation
    std::cout << "Non-parallel computation:" << std::endl;
    measureExecutionTime(nonParallelWrapper, input);

    // // Calculate sin(x) sequence from 0 to 2π with a step of 0.1
    // std::vector<double> sinSequence = calculateSinSequence(0, 2 * M_PI, 0.1);

    // // Print the sin(x) sequence
    // for (const auto& value : sinSequence) {
    //     std::cout << value << " ";
    // }
    // std::cout << std::endl;

    return 0;
}
