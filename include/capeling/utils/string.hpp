#pragma once

#include <string>
#include <vector>

namespace capeling::utils::string {
    std::string toLowercase(const std::string_view str);
    std::string toUppercase(const std::string_view str);

    std::vector<std::string_view> split(const std::string_view s, const std::string_view sep);
    std::vector<std::string_view> splitlines(const std::string_view s);
    std::string replace(std::string_view input, std::string_view searched, std::string_view replacement);
}