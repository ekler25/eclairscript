#pragma once

#include <algorithm>
#include <regex>
#include <types.hpp>

template<typename T>
bool IsInVector(T Value, Vec<T> Vector) {
    if (std::find(Vector.begin(), Vector.end(), Value) != Vector.end()) return true;
    return false;
}

bool IsANumber(String Value) {
    if (Value.empty()) return false;

    for (auto& C : Value) {
        if (!std::isdigit(C)) return false;
    }
    return true;
}

bool IsValidSymbolName(String Value) {
    std::regex pattern("^[A-Za-z_][A-Za-z0-9_]*$");
    return std::regex_match(Value, pattern);
}
