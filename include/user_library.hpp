#ifndef USER_LIBRARY_HPP
#define USER_LIBRARY_HPP

#include <string>
#include "auxiliary_functions.hpp"  

namespace user_library {

    // A sample user function that prints a message.
    void printMessage(const std::string &msg);

    // You can add more shared functions here...
    std::string createMessage(int a, int b);
}

#endif // USER_LIBRARY_HPP
