#include <capeling/utils/string.hpp>

namespace capeling::utils::string {
    std::string toLowercase(const std::string_view str) {
        std::string result;
        for (char c : str) {
            result += std::tolower(c);
        }

        return result;
    }

    std::string toUppercase(const std::string_view str) {
        std::string result;
        for (char c : str) {
            result += std::toupper(c);
        }

        return result;
    }

    std::vector<std::string_view> split(const std::string_view s, const std::string_view sep) {
        std::vector<std::string_view> out;
        size_t start = 0;
        size_t end;

        while ((end = s.find(sep, start)) != std::string_view::npos) {
            out.emplace_back(s.substr(start, end - start));
            start = end + sep.size();
        }

        out.emplace_back(s.substr(start));

        return out;
    }

    std::vector<std::string_view> splitlines(const std::string_view s) {
        std::vector<std::string_view> lines;
        std::size_t start = 0;
        while (start < s.size()) {
            std::size_t end = s.find_first_of("\r\n", start);

            if (end == std::string_view::npos) {
                lines.emplace_back(s.substr(start));
                break;
            }

            lines.emplace_back(s.substr(start, end - start));
            if (s[end] == '\r' && end + 1 < s.size() && s[end + 1] == '\n') {
                end += 1;
            }

            start = end + 1;
        }

        return lines;
    }

        std::string replace(std::string_view input, std::string_view searched, std::string_view replacement) {
        std::string out;
        out.reserve(input.size());

        // input = 5 = abcde
        // searched = 2 = bc
        // i = 0 through 3 s

        for (size_t i = 0; i < input.size();) {
            // if does not match, simply append
            if (input.substr(i, searched.size()) != searched) {
                out += input[i];
                i++;
            } else {
                // if matches, increment i by size of searched and append the replacement
                out += replacement;
                i += searched.size();
            }
        }

        return out;
    }
}