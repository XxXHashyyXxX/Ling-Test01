#pragma once

#include <variant>
#include <ostream>

struct Token {
    enum class Type {
        Invalid,
        IntLiteral, DoubleLiteral,
        OperatorPlus, OperatorMinus, OperatorStar, OperatorSlash,
        ParenthesisLeft, ParenthesisRight
    } type;

    std::variant<std::monostate, int, double> value;

    Token(int value) : type(Type::IntLiteral), value(value) {}
    Token(double value) : type(Type::DoubleLiteral), value(value) {}
    Token(Type type = Type::Invalid) : type(type), value(std::monostate()) {}

    friend std::ostream& operator<<(std::ostream& os, const Token& token);
};