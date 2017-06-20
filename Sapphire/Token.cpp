//
//  Token.cpp
//  Sapphire
//
//  Created by Owner on 6/19/17.
//  Copyright © 2017 Owner. All rights reserved.
//

#include "Token.hpp"
#include <stdlib.h>

Token makeNum(float value) {
    Token c;
    c.type = TokenType::NUMBER;
    c.value = value;
    return c;
}

Token makeOperator(char op) {
    Token c;
    switch(op) {
        case '+':
            c.type = TokenType::PLUS;
            break;
        case '-':
            c.type = TokenType::MINUS;
            break;
        case '*':
            c.type = TokenType::MUL;
            break;
        case '/':
            c.type = TokenType::DIV;
            break;
        case '(':
            c.type = TokenType::LPAREN;
            break;
        case ')':
            c.type = TokenType::RPAREN;
            break;
        default:
            break;
    }
    
    return c;
}

Token makeBlank() {
    Token c;
    c.type = _EOF;
    return c;
}

std::string names[7] = {
    "value",
    "+",
    "-",
    "*",
    "/",
    "(",
    ")"
};
std::vector<TokenType> plusOrMinus = { TokenType::PLUS, TokenType::MINUS };
std::vector<TokenType> mulOrDiv = { TokenType::MUL, TokenType::DIV };


