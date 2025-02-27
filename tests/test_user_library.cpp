#include <iostream>
#include <cassert>
#include "user_library.hpp"
#include "auxiliary_functions.hpp"

/*
In your test source file (for example, tests/test_user_library.cpp), include both my_library.hpp
(if it depends on helper functions) and helper_functions.hpp directly if you want to test them separately. 
*/

int main() {
    
    // Test sum_two_numbers function
    std::vector<char> clientBuff(100), servBuff(100);
    
    std::cout << "Enter string like 123+23: " << std::endl;
    fgets(servBuff.data(), servBuff.size(), stdin);
    
    user_library::do_math_operation(clientBuff, servBuff);
    
    return 0;
}

// ========== Insert this code into main() for testing ==========

/*  
// Test sum_two_numbers function
    std::vector<char> clientBuff(100), servBuff(100);
    
    std::cout << "Enter string like 123+23: " << std::endl;
    fgets(servBuff.data(), servBuff.size(), stdin);
    
    user_library::sum_two_numbers(clientBuff, servBuff);
 */

/* Base working code
// Test a function from my_library that uses helper functions.
    std::string msg = user_library::createMessage(5, 7);
    std::cout << "User library test message: " << msg << std::endl;
    assert(msg.find("12") != std::string::npos);

    // Test the helper function directly.
    int result = addNumbers(3, 4);
    std::cout << "Helper function addNumbers(3,4) returned: " << result << std::endl;
    assert(result == 7);

    std::cout << "All tests passed." << std::endl;
*/