#include <iostream>
#include <classes/lexer.hpp>
#include <types.hpp>

int main() {
    String Data = "int test = (10 + 20) * 3;";

    Lexer* LexerInstance = new Lexer();
    LexerInstance->LexicalAnalisys(Data);
}