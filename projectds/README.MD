# Scanner Project

## Overview
This project implements a **Scanner** (also known as a lexer or tokenizer) that reads an arithmetic expression and splits it into meaningful tokens. 

## Features
- Supports arithmetic expressions
- Recognizes signed numbers (e.g., -5, +10)
- Handles parentheses and standard arithmetic operators
- Identifies unknown characters

## Token Types
- `NUMBER` → Digits including positive and negative numbers
- `PLUS`, `MINUS`, `MULTIPLY`, `DIVIDE` → Arithmetic operators
- `ASSIGN` → Equal sign
- `LPAREN`, `RPAREN` → Parentheses
- `UNKNOWN` → Any unrecognized character
- `END_OF_INPUT` → Marks the end of input

## Files
- `Scanner.h` → Token definitions and class interface
- `Scanner.cpp` → Implementation of the Scanner class
- `main.cpp` → Interactive test interface for the Scanner

## Build and Run
```bash
g++ -o scanner main.cpp Scanner.cpp
./scanner
```

## Sample Input and Output
**Input:** `-7(5+7) -2 *7+5`

**Output:**
```
Token(Type: NUMBER, Value: "-7")
Token(Type: LPAREN, Value: "(")
Token(Type: NUMBER, Value: "5")
Token(Type: PLUS, Value: "+")
Token(Type: NUMBER, Value: "7")
Token(Type: RPAREN, Value: ")")
Token(Type: NUMBER, Value: "-2")
Token(Type: MULTIPLY, Value: "*")
Token(Type: NUMBER, Value: "7")
Token(Type: PLUS, Value: "+")
Token(Type: NUMBER, Value: "5")  
```

## Author
Gavin Juarez 
Youtude link: https://youtu.be/NE-UF2Fm8SY
 