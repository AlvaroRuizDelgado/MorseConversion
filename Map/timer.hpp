#include <iostream>
#include <chrono>

struct Timer
{
    std::chrono::high_resolution_clock::time_point start;
    std::chrono::high_resolution_clock::time_point end;
    std::chrono::duration<float> duration;

    Timer(std::string description = "Timer")
    {
        description_ = description;
        start = std::chrono::high_resolution_clock::now();
    }

    ~Timer()
    {
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;

        float ms = duration.count() * 1000.f;
        std::cout << description_ << " took " << ms << " ms" << std::endl;
    }

private:
    std::string description_;
};