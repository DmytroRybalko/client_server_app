#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include "user_library.hpp"

namespace user_library {

    void printMessage(const std::string &msg) {
        std::cout << "[UserLibrary] " << msg << std::endl;
    }

std::string createMessage(int a, int b) {
    // Use the helper function to compute a value.
    int sum = addNumbers(a, b);
    std::ostringstream oss;
    oss << "The sum of " << a << " and " << b << " is " << sum;
    return oss.str();
}

void server_insert_name(std::vector<char> &clientBuff, std::vector<char> &servBuff)
{   
    // Server's function that get string from client and insert own string before clients one

    // swap data between buffers
    clientBuff.swap(servBuff);

    std::cout << "Your (host) message: ";
    fgets(servBuff.data(), servBuff.size(), stdin);
    
    // Find the position of the last character in the client buffer
    int lpos = last_position(clientBuff, '\0');

    // Check if the character before the last position is a newline character
    if (clientBuff[lpos - 1] == '\n')
    {
        // If it is a newline, replace it with a space
        clientBuff[lpos - 1] = ' ';
    } 
    else 
    {
        // Otherwise, insert a space at the last position
        clientBuff[lpos] = ' ';
    }

    // copy data from client buffer into server buffer to the position after space symbol
    copy(
        servBuff.begin(),
        servBuff.begin() + last_position(servBuff),
        clientBuff.begin() + last_position(clientBuff));

    std::cout << "Full message: " << clientBuff.data() << std::endl;
}

    // Additional function implementations...
}
