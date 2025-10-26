#include "Token.hpp"
#include <unordered_map>
#include <functional>

std::ostream &operator<<(std::ostream &os, const Token &token)
{
    const std::unordered_map<Token::Type, std::function<void(void)>> functions = {
        {Token::Type::IntLiteral, [&]() { os << std::get<int>(token.value); }},
        {Token::Type::DoubleLiteral, [&]() { os << std::get<double>(token.value); }},
        {Token::Type::Invalid, [&]() { os << "Invalid token"; }},
        {Token::Type::OperatorMinus, [&]() { os << "Operator -"; }},
        {Token::Type::OperatorPlus, [&]() { os << "Operator +"; }},
        {Token::Type::OperatorSlash, [&]() { os << "Operator /"; }},
        {Token::Type::OperatorStar, [&]() { os << "Operator *"; }},
        {Token::Type::ParenthesisLeft, [&]() { os << "Parenthesis ("; }},
        {Token::Type::ParenthesisRight, [&]() { os << "Parenthesis )"; }}
    };

    if(!functions.contains(token.type)) throw std::runtime_error("Unrecognized token type");
    functions.at(token.type)();
    return os;
}