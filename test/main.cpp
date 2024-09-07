#include <cUtils/string.hpp>

#include <iostream>

int main() {
    std::cout << "running cUtils::string tests" << std::endl;
    std::cout << "toUppercase test: " << cUtils::string::toUppercase("hello world") << std::endl;
    std::cout << "toLowercase test: " << cUtils::string::toLowercase("HELLO WORLD") << std::endl;
    std::cout << "split test: " << cUtils::string::split("hello world;goodbye world", ";")[0] << std::endl;
    std::cout << "splitLines test: " << cUtils::string::splitlines("hello world\r\ngoodbye world")[0] << std::endl;
    std::cout << "replace test: " << cUtils::string::replace("hella warld", "a", "o") << std::endl;
    return 0;
}