#pragma once

#include <iostream>

class Math {
public:
    std::string sum(std::string &a, std::string &b);
    std::string difference(std::string &a, std::string &b);
    std::string multiplication(const std::string &a, const std::string &b);
private:
    inline uint64_t trans_to_digit(const char &a);
    inline char trans_to_char(const int &a);
    bool correct_data (const std::string &a);
};