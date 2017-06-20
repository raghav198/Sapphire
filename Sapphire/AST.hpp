//
//  AST.hpp
//  Sapphire
//
//  Created by Owner on 6/19/17.
//  Copyright © 2017 Owner. All rights reserved.
//

#ifndef AST_hpp
#define AST_hpp

#include "TokenStream.hpp"

class AST;

class AST {
    Token val;
    AST *left, *right;
public:
    AST(Token);
    AST(Token, AST*);
    AST(Token, AST*, AST*);
    float evaluate();
};

#endif /* AST_hpp */
