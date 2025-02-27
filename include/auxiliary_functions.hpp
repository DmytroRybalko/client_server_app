#ifndef AUXILIARY_FUNCTIONS_HPP
#define AUXILIARY_FUNCTIONS_HPP

// A simple helper function declaration.
int addNumbers(int a, int b);

// find position of the last character in buffer
int last_position(const std::vector<char>& buffer, const char symbol = '\0');

// parse digit from char buffer
int parse_digit_from_char(const std::vector<char>& buffer);

// apply math operation
// Template function declaration and definition
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
 
#endif // AUXILIARY_FUNCTIONS_HPP