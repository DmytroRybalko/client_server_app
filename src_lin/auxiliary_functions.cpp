#include <vector>
#include <algorithm>
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
