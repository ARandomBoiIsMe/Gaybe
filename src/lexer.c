#include <stdio.h>

// Define Token Types
enum TokenType {
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
};

// Define Token
struct Token
{
    char* value;
    enum TokenType type;
};

// Define Tokenize function, which returns a list of Tokens
