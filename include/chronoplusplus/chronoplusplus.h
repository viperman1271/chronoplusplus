#pragma once

#include <chrono>
#include <ctime>
#include <iomanip>
#include <string>
#include <sstream>

namespace chronoplusplus
{
    const std::string default_timeformat = "%Y-%m-%d %H:%M:%S";

    static std::string output_local_time(const std::chrono::system_clock::time_point time_point, const std::string& time_format)
    {
        std::time_t time_t_format = std::chrono::system_clock::to_time_t(time_point);
#if defined(_MSC_VER) && !defined(_CRT_SECURE_NO_WARNINGS)
        std::tm tm_local;
        localtime_s(&tm_local, &time_t_format);
        std::tm* time_tm_format = &tm_local;
#else
        std::tm* time_tm_format = std::localtime(&time_t_format);
#endif // _MSC_VER

        std::stringstream ss;
        ss << std::put_time(time_tm_format, time_format.c_str());
        return ss.str();
    }

    static std::string output_local_time(const std::chrono::system_clock::time_point time_point)
    {
        return output_local_time(time_point, default_timeformat);
    }
}