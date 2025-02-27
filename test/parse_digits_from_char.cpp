#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int parse_digit_from_char(const std::vector<char>& buffer) 
{
    int power = buffer.size() - 1;
    int result = 0;

    for (auto digit : buffer)
    {
        //result += (digit == '0' ? 0 : (digit - '0')) * pow(10, power);
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
    // Test reverse iterator in vector
    
    //std::vector<char> test {'1', '2', '3', '4', '+', '6', '7', '8', '9', '\0', '\0'};
    //std::vector<char> test {'4', '+', '6', '\0', '\0'};
    //std::vector<char> test {'4', '5', '+', '0', '\0', '\0'};
    
    // Test from terminal
    std::vector<char> test(100);
    std::cout << "Enter string like 123+23: " << std::endl;
    fgets(test.data(), test.size(), stdin); 
    
    cout << "Test vector: " << test.data() << endl;
    
    // Get last position of the buffer
    const int lpos = last_position(test);
    cout << "Last symbol: " << test[lpos - 1] << " at position " << lpos - 1 << endl;

    // Check if the character before the last position is a newline character
    (test[lpos - 1] == '\n') ? test[lpos - 1] = '\0' : test[lpos] = '\0';
    
    // Get position of the math operation
    const int posMathOperation = last_position(test, '+');
    cout << "Math symbol: " << test[posMathOperation] << " at position " << posMathOperation << endl;

    // Save characters for the first number (before the math operation)
    std::vector<char> firstNumberChar(posMathOperation);
    copy(test.begin(), test.begin() + posMathOperation, firstNumberChar.begin());
    cout << "Character's vector for the first number: " << firstNumberChar.data() << endl;

    // Save characters for the second number (after the math operation)
    std::vector<char> secondNumberChar(lpos - posMathOperation - 2);
    copy(test.begin() + posMathOperation + 1, test.begin() + lpos, secondNumberChar.begin());
    cout << "Character's vector for the second number: " << secondNumberChar.data() << endl;             

    /* cout << "Get characters in reverse order before sign + (=4321): " << endl; 
    for_each(test.rend() - posMathOperation, test.rend(), [](char c) { cout << c; }); cout << endl;
    
    cout << "Get characters in reverse order after sign + (=9876): " << endl;
    for_each(test.rend() - lpos, test.rend() - (posMathOperation + 1), [](char c) { cout << c; }); cout << endl; */

    
    // Convert char to gidits and process 

    cout << "First number: " << parse_digit_from_char(firstNumberChar) << endl;
    cout << "Second number: " << parse_digit_from_char(secondNumberChar) << endl;
    int result = parse_digit_from_char(firstNumberChar) + parse_digit_from_char(secondNumberChar);
    cout << "Sum of first and second number: " << result << endl;
    
    // Conver integer to string
    std::string str = std::to_string(result);
    // clear client buffer
    fill(test.begin(), test.end(), '\0');
    copy(str.begin(), str.end(), test.begin());
    cout << "Client buffer result: " << test.data() << endl;
    
    return 0;
}