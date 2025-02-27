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

    // Server's function that get string of numbers with math operation and return result
    void sum_two_numbers(std::vector<char> &clientBuff, std::vector<char> &servBuff)
    {
        // Get last position of the buffer
        const int last_pos = last_position(servBuff);

        // Check if the character before the last position is a newline character
        (servBuff[last_pos - 1] == '\n') ? servBuff[last_pos - 1] = '\0' : servBuff[last_pos] = '\0';

        // Get position of the math operation
        const int posMathOperation = last_position(servBuff, '+');

        // Save characters for the first number (before the math operation)
        std::vector<char> firstNumberChar(posMathOperation);
        copy(
            servBuff.begin(),
            servBuff.begin() + posMathOperation,
            firstNumberChar.begin()
            );

        // Save characters for the second number (after the math operation)
        std::vector<char> secondNumberChar(last_pos - posMathOperation - 2);
        copy(
            servBuff.begin() + posMathOperation + 1,
            servBuff.begin() + last_pos,
            secondNumberChar.begin()
            );
        
        // Get result of adding two numbers
        int result = parse_digit_from_char(firstNumberChar) + parse_digit_from_char(secondNumberChar);
        std::string str = std::to_string(result); // convert integer to string
        fill(clientBuff.begin(), clientBuff.end(), '\0'); // clear client buffer
        copy(str.begin(), str.end(), clientBuff.begin()); // copy result to client buffer
        std::cout << "Sum of first and second number: " << clientBuff.data() << std::endl;

    }

    // Server's function that get string of numbers and return result due to math operation
    void do_math_operation(std::vector<char> &clientBuff, std::vector<char> &servBuff)
    {
        // Get last position of the buffer
        const int last_pos = last_position(servBuff);

        // Check if the character before the last position is a newline character
        (servBuff[last_pos - 1] == '\n') ? servBuff[last_pos - 1] = '\0' : servBuff[last_pos] = '\0';

        // Recognize math operation in char vector (+, -, *, /)
        const std::vector <char> mathOperands {'+', '-', '*', '/'};
        const char symbol = *find_first_of(servBuff.begin(), servBuff.end(), mathOperands.begin(), mathOperands.end());

        // Get position of the math operation
        const int posMathOperation = last_position(servBuff, symbol);

        // Save characters for the first number (before the math operation)
        std::vector<char> firstNumberChar(posMathOperation);
        copy(
            servBuff.begin(),
            servBuff.begin() + posMathOperation,
            firstNumberChar.begin()
            );

        // Save characters for the second number (after the math operation)
        std::vector<char> secondNumberChar(last_pos - posMathOperation - 2);
        copy(
            servBuff.begin() + posMathOperation + 1,
            servBuff.begin() + last_pos,
            secondNumberChar.begin()
            );
        
        // Apply math operation
        auto firstNumber = parse_digit_from_char(firstNumberChar);
        auto secondNumber = parse_digit_from_char(secondNumberChar);
        //std::cout << "Result of switch math operation: " << apply_math_operation(firstNumber, secondNumber, symbol) << endl;
        
        // Copy result to client buffer
        auto result = apply_math_operation(firstNumber, secondNumber, symbol);
        
        std::string str = std::to_string(result); // convert integer to string
        
        fill(clientBuff.begin(), clientBuff.end(), '\0'); // clear client buffer
        
        copy(str.begin(), str.end(), clientBuff.begin()); // copy result to client buffer
        
        std::cout << "Sum of first and second number: " << clientBuff.data() << std::endl;

    }
        // Additional function implementations...
}
