//
//  AST.cpp
//  Sapphire
//
//  Created by Owner on 6/19/17.
//  Copyright © 2017 Owner. All rights reserved.
//

#include "AST.hpp"

AST::AST(Token val) {
    this->left = nullptr;
    this->right = nullptr;
    this->val = val;
}

AST::AST(Token val, AST * right) {
    this->left = nullptr;
    this->right = right;
    this->val = val;
}

AST::AST(Token val, AST * left, AST * right) {
    this->left = left;
    this->right = right;
    this->val = val;
}

float AST::evaluate() {
    if (this->left == nullptr && this->right == nullptr)
        return this->val.value;
    switch(this->val.type) {
        case TokenType::MUL:
            return this->left->evaluate() * this->right->evaluate();
        case TokenType::DIV:
            return this->left->evaluate() / this->right->evaluate();
        case TokenType::PLUS:
            if (this->left == nullptr)
                return this->right->evaluate();
            return this->left->evaluate() + this->right->evaluate();
        case TokenType::MINUS:
            if (this->left == nullptr)
                return -1 * this->right->evaluate();
            return this->left->evaluate() - this->right->evaluate();
        default:
            return -1.0;
    }
}
