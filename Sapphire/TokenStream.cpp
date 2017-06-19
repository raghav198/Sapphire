//
//  TokenStream.cpp
//  Sapphire
//
//  Created by Owner on 6/19/17.
//  Copyright © 2017 Owner. All rights reserved.
//

#include "TokenStream.hpp"

#include<ctype.h>

TokenStream::TokenStream(std::string expr) {
    this->expression = expr;
    this->pos = 0;
}
char TokenStream::read() {
    return this->expression[this->pos++];
}

char TokenStream::peek() {
    return this->expression[this->pos];
}

int TokenStream::getInt() {
    int result = 0;
    while (isdigit(this->peek())) {
        result *= 10;
        result += (this->read() - '0');
    }
    return result;
}

Token TokenStream::getNextToken() {
    while (isspace(this->peek()))
        this->read();
    if (isdigit(this->peek()))
        return makeNum((float)this->getInt());
    
    return makeOperator(this->read());
}

Token TokenStream::peekToken() {
    int pos = this->pos;
    Token t = this->getNextToken();
    this->pos = pos;
    return t;
}
