#pragma once

#include <types.hpp>

enum class TokenTypes {
    Unknown, Keyword, 
    Int, Float, Bool, StringLiteral,
    Add, Sub, Mul, Div, Pow,
    Eq, Neq, Gtr, Geq, Lss, Leq,
    LParam, RParam, LBracket, RBracket, LBrace, RBrace,
    Period, Comma,

    Eol = 255

};

struct Token {
    int Type;
    String Value;

    Token(int T, String V) : Type(T), Value(V) {}
};