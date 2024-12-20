#include "utils.h"

void printCurrentTime(std::ostream& os)
{
    // Get the current time point
    auto now = std::chrono::system_clock::now();
    // Convert the time point to a time_t object for formatting
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
    // Format the time and print it
    os << "Current time: " << std::ctime(&currentTime);
}
