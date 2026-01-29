#include<fstream>
#include<sstream>
#include "lexer.h"
#include "parser.h"
#include "codegen.h"

int main() {
    std::ifstream file("input.sl");
    std::stringstream buffer;
    buffer << file.rdbuf();

    Lexer lexer(buffer.str());
    Parser parser(lexer);
    CodeGen gen;

    while(ASTNode* stmt=parser.parseStatement()) {
        gen.generate(stmt);
    }
    gen.writeToFile("output.asm");
    return 0;
}