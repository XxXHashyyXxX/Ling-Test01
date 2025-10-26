#pragma once

#include "Token.hpp"
#include <string_view>
#include <vector>
#include <unordered_map>

using Tokens = std::vector<Token>;

class Lexer {
public:
    static Tokens tokenize(const std::string_view& expression);

private:
    inline static std::unordered_map<char, Token::Type> operators = {
        {'+', Token::Type::OperatorPlus},
        {'-', Token::Type::OperatorMinus},
        {'*', Token::Type::OperatorStar},
        {'/', Token::Type::OperatorSlash},
        {'(', Token::Type::ParenthesisLeft},
        {')', Token::Type::ParenthesisRight}
    };
};