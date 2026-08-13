#pragma once

#include <chrono>

class ScopedTimer
{
private:
    std::chrono::high_resolution_clock::time_point m_begin;
    void (*m_callback) (std::chrono::milliseconds duration);

    ScopedTimer(void (*callback) (std::chrono::milliseconds duration));

public:
    ScopedTimer(const ScopedTimer&) = delete;
    
    ~ScopedTimer();

    ScopedTimer& operator = (const ScopedTimer&) = delete;

    static ScopedTimer Begin(void (*callback) (std::chrono::milliseconds duration));
};

ScopedTimer::ScopedTimer(void (*callback) (std::chrono::milliseconds duration))
    : m_begin(std::chrono::high_resolution_clock::now())
    , m_callback(callback)
{
}

ScopedTimer::~ScopedTimer()
{
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - m_begin);
    m_callback(duration);
}

ScopedTimer ScopedTimer::Begin(void (*callback) (std::chrono::milliseconds duration))
{
    return { callback };
}
