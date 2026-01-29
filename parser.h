#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"
#include "ast.h"

class Parser {
    public:
    Parser(Lexer& lexer);
    ASTNode* parseStatement();

    private:
    Lexer& lexer;
    Token current;

    void next();
    ASTNode* parseExpression();
};



#endif 


