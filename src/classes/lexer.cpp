#include <iostream>

#include <classes/lexer.hpp>
#include <classes/token.hpp>

#include <types.hpp>

Vec<Token*> Lexer::LexicalAnalisys(String Data) {
    Vec<Token*> ToReturn = {};
    String CurrentToken = "";

    for (auto& C : Data) {
        switch (this->Mode) {
            case LexerModes::Default:
                break;
            case LexerModes::StringLiteral:
                break;
        }
    }

    return ToReturn;
}