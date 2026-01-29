#include "codegen.h"
#include <fstream>

void CodeGen::emit(const std::string& line){
    code.push_back(line);
}
void CodeGen::generate(ASTNode* node){
    if(node->type == VAR_DECL){
        memory[node->name]=addr++;
    }
    if(node->type==ASSIGN_STMT){
        if(node->left->type==NUM) 
        emit("Idi A" + std::to_string(node->left->value));
        else
        emit("mov A M" + std::to_string(memory[node->left->name]));

        emit("mov M A"+ std::to_string(memory[node->name]));
    }
}

void CodeGen::writeToFile(const std::string& filename){
    std::ofstream out(filename);
    for(auto& line : code)
    out<<line<<"\n";
}