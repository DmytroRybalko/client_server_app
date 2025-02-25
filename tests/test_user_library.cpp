#include <iostream>
#include <cassert>
#include "user_library.hpp"
#include "auxiliary_functions.hpp"

/*
In your test source file (for example, tests/test_user_library.cpp), include both my_library.hpp
(if it depends on helper functions) and helper_functions.hpp directly if you want to test them separately. 
*/

int main() {
    // Test a function from my_library that uses helper functions.
    std::string msg = user_library::createMessage(5, 7);
    std::cout << "User library test message: " << msg << std::endl;
    assert(msg.find("12") != std::string::npos);

    // Test the helper function directly.
    int result = addNumbers(3, 4);
    std::cout << "Helper function addNumbers(3,4) returned: " << result << std::endl;
    assert(result == 7);

    std::cout << "All tests passed." << std::endl;
    return 0;
}

// base working code
/* 
int main() {
    // Call a function from your user library to test it.
    std::string msg = user_library::createMessage(5, 7);
    std::cout << "Test message: " << msg << std::endl;

    // You could add checks/assertions here to automatically verify results.
    if (msg.find("12") != std::string::npos) {
        std::cout << "User library test passed." << std::endl;
        return 0;
    } else {
        std::cerr << "User library test failed." << std::endl;
        return 1;
    }
}
 */