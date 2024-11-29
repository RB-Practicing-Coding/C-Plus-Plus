#include <iostream>
#include "cpp_for_loop.h"

int main()
{
    int n = inputNumber();
    for (const auto &i : generateFirstNNaturalNumbers(n))
    {
        std::cout << i << " ";
    }
    std::cout << "\n";
    std::cout << sumOfNNaturalNumbers(generateFirstNNaturalNumbers(n)) << std::endl;
    std::cout << isPrimeNumber(n) << std::endl;
    return EXIT_SUCCESS;
}
