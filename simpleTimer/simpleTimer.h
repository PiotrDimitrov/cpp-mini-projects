#ifndef SIMPLETIMER_SIMPLETIMER_H
#define SIMPLETIMER_SIMPLETIMER_H
#include <chrono>
#include <iostream>

class timer
{
public:
    timer();
    ~timer();
private:
    std::chrono::system_clock::time_point start, end;

};

#endif //SIMPLETIMER_SIMPLETIMER_H
