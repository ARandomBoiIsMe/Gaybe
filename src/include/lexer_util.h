#ifndef LEXER_UTIL_H
#define LEXER_UTIL_H

typedef enum {
    KEYWORD,
    IDENTIFIER,
    INTEGER_LITERAL,
    STRING_LITERAL,
    DOUBLE_STAR,
    PLUS,
    STAR,
    MINUS,
    SLASH,
    DOUBLE_SLASH,
    PERCENT,
    PLUS_EQUAL,
    MINUS_EQUAL,
    SLASH_EQUAL,
    DOUBLE_SLASH_EQUAL,
    PERCENT_EQUAL,
    STAR_EQUAL,
    EXCLAMATION,
    LESS_THAN,
    GREATER_THAN,
    LESS_EQUAL,
    GREATER_EQUAL,
    NOT_EQUAL,
    EQUAL_EQUAL,
    EQUAL,
    LEFT_PAREN,
    RIGHT_PAREN,
    LEFT_SQUARE_BRACE,
    RIGHT_SQUARE_BRACE,
    COLON,
    COMMA,
    INVALID,
    DOUBLE_STAR_EQUAL,
    LEFT_CURLY_BRACE,
    RIGHT_CURLY_BRACE,
    PERIOD,
    FLOAT,
    END_OF_FILE
} TokenType;

typedef struct
{
    char* value;
    TokenType type;
} Token;

int isKeyword(char* word);
char* custom_strndup(char* string, int size);

#endif