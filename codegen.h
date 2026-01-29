#ifndef CODEGEN_H
#define CODEGEN_H

#include "ast.h"
#include <map>
#include <vector>
#include<string>
class CodeGen {
    public:
    void generate(ASTNode* node);
    void writeToFile(const std::string& filename);

    private:
    std::map<std::string, int> memory;
    int addr=16;
    std::vector<std::string> code;

    void emit(const std::string& line);
};

#endif // !CODEGEN_H
