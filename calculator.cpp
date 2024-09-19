#include "calculator.h"

#include <iostream>
#include <cmath>

using Number = double;

bool ReadNumber(Number& result) {
    // std::cin >> result ? return true : return false;
    if (std::cin >> result) {
        return true;
    }
    else
    {
        std::cerr << "Error: Numeric operand expected" << std::endl;
        return false;
    }
}

bool RunCalculatorCycle() {
    using namespace std::literals;

    Number result = 0;

    if (ReadNumber(result)) {
        Number memory = 0;
        bool empty_memory = true;
        std::string token;
        while (std::cin >> token) {
            Number number = 0;
            if (token == "+"s) {
                if (!ReadNumber(number)) {
                    return false;
                }
                result += number;
            }
            else if (token == "-"s) {
                if (!ReadNumber(number)) {
                    return false;
                }
                result -= number;
            }
            else if (token == "*"s) {
                if (!ReadNumber(number)) {
                    return false;
                }
                result *= number;
            }
            else if (token == "/"s) {
                if (!ReadNumber(number)) {
                    return false;
                }
                result /= number;
            }
            else if (token == "**"s) {
                if (!ReadNumber(number)) {
                    return false;
                }
                result = std::pow(result, number);
            }
            else if (token == "="s) {
                std::cout << result << std::endl;
            }
            else if (token == "c"s) {
                result = 0;
            }
            else if (token == ":"s) {
                if (!ReadNumber(number)) {
                    return false;
                }
                result = number;
            }
            else if (token == "s"s) {
                empty_memory = false;
                memory = result;
            }
            else if (token == "l"s) {
                if (empty_memory) {
                    std::cerr << "Error: Memory is empty "s << std::endl;
                    return false;
                }
                result = memory;
            }
            else if (token == "q"s) {
                return true;
            }
            else {
                std::cerr << "Error: Unknown token "s << token << std::endl;
                return false;
            }
        }
    }
    else {
        return false;
    }
    return true;
}