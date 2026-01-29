#ifndef AST_H
#define AST_H

#include <string>
#include <memory>

enum class ASTNodeType {
    VAR_DECL,
    ASSIGN,
    BIN_OP,
    NUMBER,
    IDENTIFIER
};

struct ASTNode {
    ASTNodeType type;
    std::string value;
    std::unique_ptr<ASTNode> left;
    std::unique_ptr<ASTNode> right;

    ASTNode(ASTNodeType t, const std::string& v = "")
        : type(t), value(v) {}
};

#endif // AST_H
