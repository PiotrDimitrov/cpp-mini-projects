#include "simpleTimer.h"
#include <iostream>
#include <chrono>

timer::timer()
{
    start = std::chrono::high_resolution_clock::now();
}

timer::~timer()
{
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "duration: " << duration.count() << " seconds" << std::endl;
}