#ifndef AST_H;
#define AST_H
#include <string>

enum NodeType {
    VAR_DECL, ASSIGN_STMT, IF_STMT, BIN_EXPR, NUM, VAR
};
 struct ASTNode {
    NodeType type;
    std::string name;
    int value;
    ASTNode* left;
    ASTNode* right;
 };

#endif 
