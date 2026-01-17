#pragma once

#include <classes/token.hpp>
#include <types.hpp>

enum class LexerModes {
    Default = 0,
    StringLiteral = 1
};

struct Lexer {
    LexerModes Mode = LexerModes::Default;
    String CurrentToken = "";
    Vec<Token> ToReturn = {};

    void FlushCurrentToken();
    Token PushToken(char ShortVariant, Vec<String> LongVariants, String& Data, int& Index);
    TokenTypes IdentifyToken(String Value);
    Vec<Token> LexicalAnalisys(String Data);
};
