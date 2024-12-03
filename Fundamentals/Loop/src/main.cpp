#include <iostream>
#include "cpp_for_loop.h"

int main()
{
    int n = inputNumber();
    // for (const auto &i : generateFirstNNaturalNumbers(n))
    // {
    //     std::cout << i << " ";
    // }
    // std::cout << "\n";
    // std::cout << sumOfNNaturalNumbers(generateFirstNNaturalNumbers(n)) << std::endl;
    // std::cout << isPrimeNumber(n) << std::endl;
    std::vector<int> vec = generateFirstNNaturalNumbers(n);
    // std::vector<int> res = findPerfectNumbers(vec);
    // for (const auto &i : res)
    // {
    //     std::cout << i << " ";
    // }
    // std::cout << "\n";
    std::cout << "The total number of prime numbers in vector is: " << countPrimeNumber(vec) << std::endl;
    return EXIT_SUCCESS;
}
