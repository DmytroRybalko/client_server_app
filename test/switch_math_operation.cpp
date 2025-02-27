#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
//#include "auxiliary_functions.hpp"

using namespace std;

template <typename T>
T apply_math_operation(T a, T b, char operation) {
    switch (operation) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return b != 0 ? a / b : 0; // handle division by zero
        default: return 0;
    }
}

// TODO: Think about parsing and return float type 
int parse_digit_from_char(const std::vector<char>& buffer) 
{
    int power = buffer.size() - 1;
    int result = 0;

    for (auto digit : buffer)
    {
        result += (digit - '0') * pow(10, power);
        --power;
    }
    return result;
}

int last_position(const std::vector<char>& buffer, const char symbol = '\0') 
{
    return distance(buffer.begin(), find(buffer.begin(), buffer.end(), symbol));
}

int main(void)
{   
    //std::vector<char> test {'1', '2', '3', '4', '+', '6', '7', '8', '9', '\0', '\0'};
    
    // Test from terminal
    std::vector<char> test(100);
    std::cout << "Enter string like 123+23: " << std::endl;
    fgets(test.data(), test.size(), stdin); 
    cout << "Test vector: " << test.data() << endl;
    
    // Get last position of the buffer
    const int lpos = last_position(test);

    // Recognize math operation in char vector (+, -, *, /)
    const vector <char> mathOperands {'+', '-', '*', '/'};
    const char symbol = *find_first_of(test.begin(), test.end(), mathOperands.begin(), mathOperands.end());
    
    // Get position of the math operation
    const int posMathOperation = last_position(test, symbol);
    cout << "Math symbol: " << test[posMathOperation] << " at position " << posMathOperation << endl;

    // Save characters for the first number (before the math operation)
    std::vector<char> firstNumberChar(posMathOperation);
    copy(test.begin(), test.begin() + posMathOperation, firstNumberChar.begin());

    // Save characters for the second number (after the math operation)
    std::vector<char> secondNumberChar(lpos - posMathOperation - 2);
    copy(test.begin() + posMathOperation + 1, test.begin() + lpos, secondNumberChar.begin());

    // Apply math operation
    auto firstNumber = parse_digit_from_char(firstNumberChar);
    auto secondNumber = parse_digit_from_char(secondNumberChar);
    cout << "Result of switch math operation: " << apply_math_operation(firstNumber, secondNumber, symbol) << endl;
    
    return 0;
}
