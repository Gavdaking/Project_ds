// Scanner.cpp
#include "Scanner.h"
#include <cctype>
using namespace std;


// Constructor initializes input string and starting position
Scanner::Scanner(const string& text)
    : input(text), pos(0) {}

// Retrieves the next token from the input string
Token Scanner::getNextToken() {
    // Skip whitespace
    while (pos < input.size() && isspace(input[pos])) {
        pos++;
    }

    if (pos >= input.size()) {
        return Token(END_OF_INPUT, "");
    }

    char current = input[pos];

    // Handle signed numbers like -10 or +5
    if ((current == '-' || current == '+') && pos + 1 < input.size() && isdigit(input[pos + 1])) {
        string number(1, current);
        pos++;
        while (pos < input.size() && isdigit(input[pos])) {
            number += input[pos++];
        }
        return Token(NUMBER, number);
    }

    // Handle regular numbers
    if (isdigit(current)) {
        string number;
        while (pos < input.size() && isdigit(input[pos])) {
            number += input[pos++];
        }
        return Token(NUMBER, number);
    }

    // Handle identifiers (like variable names)
    if (isalpha(current)) {
        string identifier;
        while (pos < input.size() && isalpha(input[pos])) {
            identifier += input[pos++];
        }
        return Token(IDENTIFIER, identifier);
    }

    // Handle single-character operators and symbols
    switch (current) {
        case '+': pos++; return Token(PLUS, "+");
        case '-': pos++; return Token(MINUS, "-");
        case '*': pos++; return Token(MULTIPLY, "*");
        case '/': pos++; return Token(DIVIDE, "/");
        case '=': pos++; return Token(ASSIGN, "=");
        case '(': pos++; return Token(LPAREN, "(");
        case ')': pos++; return Token(RPAREN, ")");
        case '{': pos++; return Token(LBRACE, "{");
        case '}': pos++; return Token(RBRACE, "}");
        case ',': pos++; return Token(COMMA, ",");
    }

    // Fallback for unrecognized characters
    string unknown(1, input[pos++]);
    return Token(UNKNOWN, unknown);
}
