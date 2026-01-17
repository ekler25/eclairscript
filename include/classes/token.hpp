#pragma once

#include <types.hpp>

enum class TokenTypes {
    Unknown, Keyword, Types, Symbol,
    Int, Float, Bool, StringLiteral,
    Add, Sub, Mul, Div, Pow, Assign,
    Inc, Dec, AddA, SubA, MulA, DivA,
    Eq, Neq, Gtr, Geq, Lss, Leq,
    Not, And, Or,
    LParam, RParam, LBracket, RBracket, LBrace, RBrace,
    Period, Comma,

    Eol = 255
};

struct Token {
    TokenTypes Type;
    String Value;

    Token(TokenTypes T, String V) : Type(T), Value(V) {}
};
