#include <iostream>
#include "Frontend/Token.hpp"

int main() {
    auto tokens = { Token(5), Token(Token::Type::BinaryPlus), Token(3.5) };
    for(auto& token : tokens) {
        std::cout << token << std::endl;
    }

    return 0;
}