#include <iostream>
#include <sstream>
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
    // Additional function implementations...
}
