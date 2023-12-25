#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "include/lexer.h"
#include "include/general_util.h"
#include "include/lexer_util.h"

Token* tokenize(char* source) {
    Token* tokens = NULL;
    int tokenCount = 0;

    while (*source != '\0') {
        // Whitespace
        if (isspace(*source)) {
            skipWhitespace(&source);
            continue;
        }

        // Keywords and identifiers
        if (isalpha(*source) || *source == '_') {
            Token token = generateIdentifierOrKeywordToken(&source);
            insertToken(&tokens, &token, &tokenCount);

            continue;
        }

        // Strings
        if (*source == '\"') {
            Token token = generateStringLiteralToken(&source);
            insertToken(&tokens, &token, &tokenCount);

            continue;
        }

        // Integers
        if (isdigit(*source)) {
            Token token = generateIntegerLiteralToken(&source);
            insertToken(&tokens, &token, &tokenCount);

            continue;
        }

        // Arithmetic and logical operators
        // --------------------------------
        if (*source == '+') {
            if (peek(&source) == '=') {
                Token token = generateOperatorToken(&source, "+=", PLUS_EQUAL);
                insertToken(&tokens, &token, &tokenCount);
            }
            else {
                Token token = generateOperatorToken(&source, "+", PLUS);
                insertToken(&tokens, &token, &tokenCount);
            }

            continue;
        }

        if (*source == '-') {
            if (peek(&source) == '=') {
                Token token = generateOperatorToken(&source, "-=", MINUS_EQUAL);
                insertToken(&tokens, &token, &tokenCount);
            }
            else if (peek(&source) == '>') {
                Token token = generateOperatorToken(&source, "->", ARROW);
                insertToken(&tokens, &token, &tokenCount);
            }
            else {
                Token token = generateOperatorToken(&source, "-", MINUS);
                insertToken(&tokens, &token, &tokenCount);
            }

            continue;
        }

        if (*source == '*') {
            if (peek(&source) == '=') {
                Token token = generateOperatorToken(&source, "*=", STAR_EQUAL);
                insertToken(&tokens, &token, &tokenCount);
            }
            else {
                Token token = generateOperatorToken(&source, "*", STAR);
                insertToken(&tokens, &token, &tokenCount);
            }

            continue;
        }

        if (*source == '/') {
            if (peek(&source) == '=') {
                Token token = generateOperatorToken(&source, "/=", SLASH_EQUAL);
                insertToken(&tokens, &token, &tokenCount);
            }
            else {
                Token token = generateOperatorToken(&source, "/", SLASH);
                insertToken(&tokens, &token, &tokenCount);
            }

            continue;
        }

        if (*source == '=') {
            if (peek(&source) == '=') {
                Token token = generateOperatorToken(&source, "==", EQUAL_EQUAL);
                insertToken(&tokens, &token, &tokenCount);
            }
            else {
                Token token = generateOperatorToken(&source, "=", EQUAL);
                insertToken(&tokens, &token, &tokenCount);
            }

            continue;
        }

        if (*source == '!') {
            if (peek(&source) == '=') {
                Token token = generateOperatorToken(&source, "!=", BANG_EQUAL);
                insertToken(&tokens, &token, &tokenCount);
            }
            else {
                Token token = generateOperatorToken(&source, "!", BANG);
                insertToken(&tokens, &token, &tokenCount);
            }

            continue;
        }

        if (*source == '<') {
            if (peek(&source) == '=') {
                Token token = generateOperatorToken(&source, "<=", LESS_EQUAL);
                insertToken(&tokens, &token, &tokenCount);
            }
            else {
                Token token = generateOperatorToken(&source, "<", LESS_THAN);
                insertToken(&tokens, &token, &tokenCount);
            }

            continue;
        }

        if (*source == '>') {
            if (peek(&source) == '=') {
                Token token = generateOperatorToken(&source, ">=", GREATER_EQUAL);
                insertToken(&tokens, &token, &tokenCount);
            }
            else {
                Token token = generateOperatorToken(&source, ">", GREATER_THAN);
                insertToken(&tokens, &token, &tokenCount);
            }

            continue;
        }
        // --------------------------------

        // Symbols
        // --------------------------------
        if (*source == '{') {
            Token token = generateSymbolToken(&source, "{", LEFT_CURLY_BRACE);
            insertToken(&tokens, &token, &tokenCount);

            continue;
        }

        if (*source == '}') {
            Token token = generateSymbolToken(&source, "}", RIGHT_CURLY_BRACE);
            insertToken(&tokens, &token, &tokenCount);

            continue;
        }

        if (*source == '[') {
            Token token = generateSymbolToken(&source, "[", LEFT_SQUARE_BRACE);
            insertToken(&tokens, &token, &tokenCount);

            continue;
        }

        if (*source == ']') {
            Token token = generateSymbolToken(&source, "]", RIGHT_SQUARE_BRACE);
            insertToken(&tokens, &token, &tokenCount);

            continue;
        }

        if (*source == '(') {
            Token token = generateSymbolToken(&source, "(", LEFT_PAREN);
            insertToken(&tokens, &token, &tokenCount);

            continue;
        }

        if (*source == ')') {
            Token token = generateSymbolToken(&source, ")", RIGHT_PAREN);
            insertToken(&tokens, &token, &tokenCount);

            continue;
        }

        if (*source == ':') {
            Token token = generateSymbolToken(&source, ":", COLON);
            insertToken(&tokens, &token, &tokenCount);

            continue;
        }

        if (*source == '.') {
            Token token = generateSymbolToken(&source, ".", PERIOD);
            insertToken(&tokens, &token, &tokenCount);

            continue;
        }

        if (*source == ',') {
            Token token = generateSymbolToken(&source, ",", COMMA);
            insertToken(&tokens, &token, &tokenCount);

            continue;
        }
        // --------------------------------

        else {
            source++;
            insertToken(&tokens, &(Token){"", INVALID}, &tokenCount);

            continue;
        }
    }

    Token token = {"", END_OF_FILE};
    insertToken(&tokens, &token, &tokenCount);

    return tokens;
}