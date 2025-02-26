#ifndef AUXILIARY_FUNCTIONS_HPP
#define AUXILIARY_FUNCTIONS_HPP

// A simple helper function declaration.
int addNumbers(int a, int b);

// find position of the last character in buffer
int last_position(const std::vector<char>& buffer, const char symbol = '\0');

// parse digit from char buffer
int parse_digit_from_char(const std::vector<char>& buffer);
 
#endif // AUXILIARY_FUNCTIONS_HPP