// Scanner.h
#ifndef SCANNER_H
#define SCANNER_H

#include <string>
#include <vector>
using namespace std;

// Enum for token types
enum TokenType {
    NUMBER,
    PLUS,
    MINUS,
    MULTIPLY,
    DIVIDE,
    ASSIGN,
    LPAREN,
    RPAREN,
    LBRACE,
    RBRACE,
    COMMA,
    IDENTIFIER,
    UNKNOWN,
    END_OF_INPUT
};

// Token structure
struct Token {
    TokenType type;
    string value;

    Token(TokenType type, const std::string& value)
        : type(type), value(value) {}
};

// Scanner class declaration
class Scanner {
public:
    Scanner(const std::string& text);
    Token getNextToken();

private:
    string input;
    size_t pos;
};

#endif // SCANNER_H
