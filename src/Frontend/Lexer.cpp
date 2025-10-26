#include "Lexer.hpp"
#include <cctype>

Tokens Lexer::tokenize(const std::string_view &expression)
{
    Tokens outTokens;

    for(auto it = expression.begin(); it != expression.end(); ++it) {
        if(std::isspace(*it)) continue;

        if(std::isdigit(*it) || *it == '.') {
            auto start = it;
            bool isDouble = false;
            while(it != expression.end() && std::isdigit(*it)) ++it;
            if(*it == '.') {
                isDouble = true;
                ++it;
                while(it != expression.end() && std::isdigit(*it)) ++it;
            }
            auto end = it;
            auto valueString = std::string(start, end);

            if(isDouble) {
                auto value = std::stod(valueString);
                outTokens.push_back(Token(value));
            } else {
                auto value = std::stoi(valueString);
                outTokens.push_back(Token(value));
            }

            --it;
            continue;
        }

        if(operators.contains(*it)) {
            outTokens.push_back(Token(operators.at(*it)));
            continue;
        }

        while(it != expression.end() && !std::isspace(*it)) ++it;
        outTokens.push_back(Token());

        --it;
        continue;
    }

    return outTokens;
}