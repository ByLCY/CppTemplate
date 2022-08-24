//
// Created by ByLCY on 8/24/22.
//

#ifndef CPPTEMPLATE_HELLO_H
#define CPPTEMPLATE_HELLO_H

#include <string>

namespace start {

    class Hello {
    private:
        std::string name;

    public:
        explicit Hello(std::string name) : name(std::move(name)) {}

        std::string hello();
        static int factorial(int number);
    };

}// namespace start

#endif// CPPTEMPLATE_HELLO_H
