#include "Token.hpp"
#include <unordered_map>
#include <functional>

std::ostream &operator<<(std::ostream &os, const Token &token)
{
    const std::unordered_map<Token::Type, std::function<void(void)>> functions = {
        {Token::Type::IntLiteral, [&]() { os << std::get<int>(token.value); }},
        {Token::Type::DoubleLiteral, [&]() { os << std::get<double>(token.value); }},
        {Token::Type::Invalid, [&]() { os << "Invalid token"; }},
        {Token::Type::BinaryMinus, [&]() { os << "Binary -"; }},
        {Token::Type::BinaryPlus, [&]() { os << "Binary +"; }},
        {Token::Type::BinarySlash, [&]() { os << "Binary /"; }},
        {Token::Type::BinaryStar, [&]() { os << "Binary *"; }},
        {Token::Type::UnaryMinus, [&]() { os << "Unary -"; }},
        {Token::Type::UnaryPlus, [&]() { os << "Unary +"; }}
    };

    if(!functions.contains(token.type)) throw std::runtime_error("Unrecognized token type");
    functions.at(token.type)();
    return os;
}