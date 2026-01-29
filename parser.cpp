#include "parser.h"
#include <cstdlib>

Parser::Parser(Lexer& l) : lexer(l) {
    next();
}

void Parser::next() {
    current = lexer.getNextToken();
}

ASTNode* Parser::parseExpression() {
    ASTNode* left;

    if(current.type == NUMBER) {
        left=new ASTNode{NUM, "", stoi(current.text), nullptr};
        next();
    }else{
        left=new ASTNode{VAR, current.text, 0, nullptr, nullptr};
        next();
    }

    if(current.type==PLUS||current.type==MINUS) {
        TokenType op=current.type;
        next();
        ASTNode* right=parseExpression();
        return new ASTNode{BIN_EXPR, op==PLUS ? "+" : "-", 0, left, right};

    }
    return left;
}
ASTNode* Parser::parseStatement() {
    if(current.type==INT) {
        next();
        std::string name=current.text;
        next();
         next();
         ASTNode* expr=parseExpression();
         return new ASTNode{ASSIGN_STMT, name, 0, expr, nullptr};
    }
    return nullptr;
}