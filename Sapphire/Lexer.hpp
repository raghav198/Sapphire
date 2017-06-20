//
//  Lexer.hpp
//  Sapphire
//
//  Created by Owner on 6/19/17.
//  Copyright © 2017 Owner. All rights reserved.
//

#ifndef Lexer_hpp
#define Lexer_hpp


#include "AST.hpp"


class Lexer {
    TokenStream * stream;
public:
    Lexer(std::string expression);
    bool hasNext(std::vector<TokenType>);
    Token eat(std::vector<TokenType>);
    
    // Currently implemented syntax rules
    AST * factor(); // one thing being multiplied
    AST * term(); // one thing being added
    AST * expression(); // any mathematical expression
    
};

#endif /* Lexer_hpp */
