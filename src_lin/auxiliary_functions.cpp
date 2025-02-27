#include <vector>
#include <algorithm>
#include <cmath>
#include "auxiliary_functions.hpp"

// Implementation of the auxiliary functions
int addNumbers(int a, int b) {
    return a + b;
}

// find position of the last character in buffer
int last_position(const std::vector<char>& buffer, const char symbol) 
{
	return distance(buffer.begin(), find(buffer.begin(), buffer.end(), symbol));
}

// parse digit from char buffer
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

