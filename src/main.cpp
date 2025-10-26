#include <iostream>
#include <fstream>
#include "Frontend/Token.hpp"
#include "Frontend/Lexer.hpp"
#include <string>

int main() {
    std::ifstream tests("test.txt");
    std::string line;

    while(std::getline(tests, line)) {
        auto pos = line.find(';');

        auto name = line.substr(0, pos);
        auto expression = line.substr(pos + 1);

        std::cout << "Test " << name << ": " << expression << std::endl;
        for(auto& token : Lexer::tokenize(expression)) {
            std::cout << "\t" << token << std::endl;
        }
    }

    return 0;
}