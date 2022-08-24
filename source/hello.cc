//
// Created by ByLCY on 8/24/22.
//

#include "cpp_template/hello.h"

namespace start {
    std::string Hello::hello() { return "Hello " + this->name; }

    int Hello::factorial(int number) {
        int result = 1;
        while (number > 1) {
            result *= number;
            number--;
        }
        return result;
    }
}// namespace start