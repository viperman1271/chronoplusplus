#pragma once

#include <chrono>

namespace chronoplusplus
{
    const std::string default_timeformat = "%Y-%m-%d %H:%M:%S";

    static std::string output_local_time(const std::chrono::system_clock::time_point time_point, const std::string& time_format)
    {
        std::time_t time_t_format = std::chrono::system_clock::to_time_t(time_point);
        std::tm* time_tm_format = std::localtime(&time_t_format);
        return std::put_time(time_tm_format, time_format);
    }

    static std::string output_local_time(const std::chrono::system_clock::time_point time_point)
    {
        return output_local_time(time_point, default_timeformat);
    }
}