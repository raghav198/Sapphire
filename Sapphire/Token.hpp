//
//  Token.hpp
//  Sapphire
//
//  Created by Owner on 6/19/17.
//  Copyright © 2017 Owner. All rights reserved.
//

#ifndef Token_hpp
#define Token_hpp

#include <vector>
#include <string>

enum TokenType {
    NUMBER,
    PLUS,
    MINUS,
    MUL,
    DIV,
    LPAREN,
    RPAREN,
    _EOF
};


struct Token {
    TokenType type = TokenType::_EOF;
    float value;
};

extern std::string names[7];
extern std::vector<TokenType> plusOrMinus;
extern std::vector<TokenType> mulOrDiv;

Token makeNum(float);
Token makeOperator(char);
Token makeBlank();
#endif /* Token_hpp */
