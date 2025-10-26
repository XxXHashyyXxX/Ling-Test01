#include "Parser.hpp"

void Parser::determineArityOfOperators(Tokens &tokens)
{
    for(auto it = tokens.begin(); it != tokens.end(); ++it) {
        if(it->type != Token::Type::OperatorPlus && it->type != Token::Type::OperatorMinus) continue;

        if(it == tokens.begin()) {
            switch(it->type) {
                case Token::Type::OperatorMinus:
                    it->type = Token::Type::UnaryMinus;
                    break;
                case Token::Type::OperatorPlus:
                    it->type = Token::Type::UnaryPlus;
                    break;
            }
            continue;
        }

        auto& previous = *(it - 1);
        switch(previous.type) {
            case Token::Type::DoubleLiteral:
            case Token::Type::IntLiteral:
            case Token::Type::ParenthesisRight:
                switch(it->type) {
                    case Token::Type::OperatorMinus:
                        it->type = Token::Type::BinaryMinus;
                        break;
                    case Token::Type::OperatorPlus:
                        it->type = Token::Type::BinaryPlus;
                        break;
                }
            default:
                switch(it->type) {
                    case Token::Type::OperatorMinus:
                        it->type = Token::Type::UnaryMinus;
                        break;
                    case Token::Type::OperatorPlus:
                        it->type = Token::Type::UnaryPlus;
                        break;
                }
        }
    }
}