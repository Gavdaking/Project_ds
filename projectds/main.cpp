#include "Scanner.h"
#include <iostream>
using namespace std;

int main() {
    string input;
    cout << "Enter expression: ";
    getline(cin, input);

    Scanner scanner(input);
    Token token = scanner.getNextToken();

    while (token.type != END_OF_INPUT) {
        cout << "Token(Type: ";

        switch (token.type) {
            case NUMBER: cout << "NUMBER"; break;
            case IDENTIFIER: cout << "IDENTIFIER"; break;
            case PLUS: cout << "PLUS"; break;
            case MINUS: cout << "MINUS"; break;
            case MULTIPLY: cout << "MULTIPLY"; break;
            case DIVIDE: cout << "DIVIDE"; break;
            case ASSIGN: cout << "ASSIGN"; break;
            case LPAREN: cout << "LPAREN"; break;
            case RPAREN: cout << "RPAREN"; break;
            case LBRACE: cout << "LBRACE"; break;
            case RBRACE: cout << "RBRACE"; break;
            case COMMA: cout << "COMMA"; break;
            case UNKNOWN: cout << "UNKNOWN"; break;
            default: cout << "OTHER"; break;
        }

        cout << ", Value: \"" << token.value << "\")" << endl;
        token = scanner.getNextToken();
    }

    return 0;
}
