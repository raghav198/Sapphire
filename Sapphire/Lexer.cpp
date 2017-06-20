//
//  Lexer.cpp
//  Sapphire
//
//  Created by Owner on 6/19/17.
//  Copyright © 2017 Owner. All rights reserved.
//

#include "Lexer.hpp"
#include <algorithm>
#include <iterator>
#include <iostream>

Lexer::Lexer(std::string expression) {
    this->stream = new TokenStream(expression);
}

bool Lexer::hasNext(std::vector<TokenType> types) {
    
    Token t = this->stream->peekToken();
    TokenType type = t.type;
    
    return std::find(types.begin(), types.end(), type) != types.end();
    
}

Token Lexer::eat(std::vector<TokenType> types) {
    if (this->hasNext(types))
        return this->stream->getNextToken();
    std::cout << "Expected (";
    for (TokenType t : types)
        std::cout << names[(int)t] << ",";
    Token tok = this->stream->peekToken();
    
    std::cout << "); received " << tok.type << "....." << names[(int)tok.type] << "!" << std::endl;
    return makeBlank();
}

AST * Lexer::factor() {
    AST * res;
    if (this->hasNext(plusOrMinus))
        res = new AST(this->eat(plusOrMinus), this->factor());
    else if (this->hasNext({TokenType::LPAREN})) {
        this->eat({TokenType::LPAREN});
        res = this->expression();
        this->eat({TokenType::RPAREN});
    } else
        res = new AST(this->eat({TokenType::NUMBER}));
    
    
    return res;
}

AST * Lexer::term() {
    AST * res = this->factor();
    while (this->hasNext(mulOrDiv)) {
        Token op = this->eat(mulOrDiv);
        AST * rhs = this->factor();
        res = new AST(op, res, rhs);
    }
    
    return res;
}

AST * Lexer::expression() {
    AST * res = this->term();
    while (this->hasNext(plusOrMinus)) {
        Token op = this->eat(plusOrMinus);
        AST * rhs = this->term();
        res = new AST(op, res, rhs);
    }
    
    return res;
}
