//
//  Token.hpp
//  Sapphire
//
//  Created by Owner on 6/19/17.
//  Copyright © 2017 Owner. All rights reserved.
//

#ifndef Token_hpp
#define Token_hpp

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

Token makeNum(float);
Token makeOperator(char);
#endif /* Token_hpp */
