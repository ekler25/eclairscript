#include <iostream>

#include <classes/lexer.hpp>
#include <classes/tokenmap.hpp>
#include <classes/token.hpp>

#include <types.hpp>
#include <utils.hpp>

void Lexer::FlushCurrentToken() {
    if (!CurrentToken.empty()) {
        ToReturn.push_back(Token{
            IdentifyToken(CurrentToken),
            CurrentToken
        });
        CurrentToken.clear();
    }
}

TokenTypes Lexer::IdentifyToken(String Value) {
    if (TokenMap.find(Value) != TokenMap.end()) return TokenMap.at(Value);
    if (IsInVector(Value, Keywords)) return TokenTypes::Keyword;
    if (IsInVector(Value, Types)) return TokenTypes::Types;
    if (IsValidSymbolName(Value)) return TokenTypes::Symbol;
    if (IsAnInt(Value)) return TokenTypes::Int;
    return TokenTypes::Unknown;  
}

Token Lexer::PushToken(char ShortVariant, Vec<String> LongVariants, String& Data, int& Index) {
    FlushCurrentToken();
    String BestMatch{ShortVariant};
    int BestLength = 1;

    for (auto& Variant : LongVariants) {
        int Length = static_cast<int>(Variant.length());
        if (Index + Length > static_cast<int>(Data.size())) continue;

        bool Match = true;
        for (int i = 0; i < Length; i++) {
            if (Data[Index + i] != Variant[i]) {
                Match = false;
                break;
            }
        }

        if (Match && Length > BestLength) {
            BestMatch = Variant;
            BestLength = Length;
        }
    }

    Index += BestLength - 1;

    this->CurrentToken = "";
    return Token{
        IdentifyToken(BestMatch),
        BestMatch
    };
}

Vec<Token> Lexer::LexicalAnalisys(String Data) {
    for (int i = 0; i < Data.length(); i++) {
        switch (this->Mode) {
            case LexerModes::Default:
                if (isspace(Data[i])) {
                    FlushCurrentToken();
                    continue;
                } else if (Data[i] == ';') {
                    ToReturn.push_back(PushToken(';', {}, Data, i)); break;
                } else {
                    switch (Data[i]) {
                        case '+': ToReturn.push_back(PushToken('+', {"++", "+="}, Data, i)); break;
                        case '-': ToReturn.push_back(PushToken('-', {"--", "-=", "->"}, Data, i)); break;
                        case '*': ToReturn.push_back(PushToken('*', {"**", "*="}, Data, i)); break;
                        case '/': ToReturn.push_back(PushToken('/', {"/="}, Data, i)); break;
                        case '=': ToReturn.push_back(PushToken('=', {"=>", "=="}, Data, i)); break;
                        case '(': ToReturn.push_back(PushToken('(', {}, Data, i)); break;
                        case ')': ToReturn.push_back(PushToken(')', {}, Data, i)); break;
                        default: CurrentToken += Data[i];
                    }
                }
                break;
            case LexerModes::StringLiteral:
                break;
            default: break;
        }
    }

    FlushCurrentToken();
    for (auto& T : ToReturn) {
        std::cout << "TOKEN: (Value: \x1b[92m" << T.Value << "\x1b[0m, Type: \x1b[92m" << (int)T.Type << "\x1b[0m)\n";
    }
    return ToReturn;
}

