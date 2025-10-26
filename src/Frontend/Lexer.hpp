#pragma once

#include "Token.hpp"
#include <string_view>
#include <vector>
#include <unordered_map>

using Tokens = std::vector<Token>;

class Lexer {
public:
    static Tokens tokenize(const std::string_view& expression);
};