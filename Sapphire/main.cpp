//
//  main.cpp
//  Sapphire
//
//  Created by Owner on 6/19/17.
//  Copyright © 2017 Owner. All rights reserved.
//

#include <iostream>
#include "Lexer.hpp"

int main(int argc, const char * argv[]) {
    std::string command;
    while(true) {
        std::cout << "calc> ";
        getline(std::cin, command);
        if (command == "quit")
            break;
        Lexer * lex = new Lexer(command);
        std::cout << lex->expression()->evaluate() << std::endl;
        
    }
    return 0;
}
