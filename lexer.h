#ifndef LEXER_H
#define LEXER_h

#include <string>

enum TokenType {
    INT, IF, IDENT, NUMBER,
    ASSIGN, PLUS, MINUS, EQEQ,
    LPAREN, RPAREN, LBRACE, RBRACE,
     SEMICOLON, END
};

struct Token {
    TokenType type;
    std::string text;
};

class Lexer {
    public: 
    Lexer(const std::string& src);
    Token getNextToken();

    private:
    std::string source;
    int pos;
};
#endif
