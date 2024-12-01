#include "my_math.h"
#include <thread>
#include <iostream>
#include <chrono>

// Function to calculate sin(x) in parallel
void sinWorker(const std::vector<double>& input, std::vector<double>& output, int start, int end) {
    for (int i = start; i < end; ++i) {
        output[i] = std::sin(input[i]);
    }
}

std::vector<double> parallelSinCalculation(const std::vector<double>& input) {
    int numThreads = std::thread::hardware_concurrency();
    std::vector<std::thread> threads;
    std::vector<double> output(input.size());

    int chunkSize = input.size() / numThreads;
    int start = 0;

    for (int i = 0; i < numThreads; ++i) {
        int end = (i == numThreads - 1) ? input.size() : start + chunkSize;
        threads.emplace_back(sinWorker, std::ref(input), std::ref(output), start, end);
        start = end;
    }

    for (auto& t : threads) {
        t.join();
    }

    return output;
}

// Function to calculate sin(x) without parallelization
std::vector<double> nonParallelSinCalculation(const std::vector<double>& input) {
    std::vector<double> output(input.size());
    for (size_t i = 0; i < input.size(); ++i) {
        output[i] = std::sin(input[i]);
    }
    return output;
}

// Function to calculate a sequence of sin(x) values
std::vector<double> calculateSinSequence(double start, double end, double step) {
    std::vector<double> sequence;
    for (double x = start; x <= end; x += step) {
        sequence.push_back(std::sin(x));
    }
    return sequence;
}

// Function to measure execution time of a given function
void measureExecutionTime(void (*func)(const std::vector<double>&), const std::vector<double>& input) {
    auto start = std::chrono::high_resolution_clock::now();

    // Call the function to be measured
    func(input);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    std::cout << "Execution time: " << duration.count() << " seconds" << std::endl;
}
