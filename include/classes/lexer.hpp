#pragma once

#include <classes/token.hpp>
#include <types.hpp>

enum class LexerModes {
    Default = 0,
    StringLiteral = 1
};

struct Lexer {
    LexerModes Mode = LexerModes::Default;

    Vec<Token*> LexicalAnalisys(String Data);
};