#ifndef USER_LIBRARY_HPP
#define USER_LIBRARY_HPP

#include <string>
#include <vector>
#include "auxiliary_functions.hpp"  

namespace user_library {

    // A sample user function that prints a message.
    void printMessage(const std::string &msg);

    // You can add more shared functions here...
    std::string createMessage(int a, int b);

    // Server's function that get string from client and insert own string before clients one
    void server_insert_name(std::vector<char> &clientBuff, std::vector<char> &servBuff);
}

#endif // USER_LIBRARY_HPP
