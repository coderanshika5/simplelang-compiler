#include "lexer.h"
#include <cctype>

Lexer::Lexer(const std::string& src) : source(src), pos(0) {}
Token Lexer::getNextToken() {
    while (pos<source.size() && isspace(source[pos]))
    pos++;

    if(pos>=source.size())
    return {END, ""};

    char c=source[pos];

    if(isalpha(c)){
        std::string word;
        while (isalnum(source[pos]))
        word+=source[pos++];

        if(word=="int") return {INT, word};
        if(word=="if") return {IF, word};
        return {IDENT, word};
    }

    if (isdigit(c)) {
        std::string num;
        while(isdigit(source[pos]))
        num+=source[pos++];
        return {NUMBER, num};
    }

    pos++;
    switch (c) {
        case '=':
        if(source[pos]=='=') {pos++; return {EQEQ, "=="};}
        return {ASSIGN, "="};
        case '+': return {PLUS, "+"};
        case '-': return {MINUS, "-"};
        case '(': return {LPAREN, "("};
        case ')': return {RPAREN, ")"};
        case '{': return {LBRACE, "{"};
        case '}': return {RBRACE, "}"};
        case ';': return {SEMICOLON, ";"};
    }
    return {END, ""};
}