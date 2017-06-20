//
//  TokenStream.hpp
//  Sapphire
//
//  Created by Owner on 6/19/17.
//  Copyright © 2017 Owner. All rights reserved.
//

#ifndef TokenStream_hpp
#define TokenStream_hpp


#include "Token.hpp"

class TokenStream {
    std::string expression;
    int pos;
public:
    TokenStream(std::string);
    char peek();
    char read();
    int getInt();
    float getFloat();
    Token peekToken();
    Token getNextToken();
};

#endif /* TokenStream_hpp */
