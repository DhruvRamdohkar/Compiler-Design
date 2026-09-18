#include <stdio.h>


enum {
    KEYWORD = 1,
    PRINT,
    IDENTIFIER,
    INT_LIT,
    FLOAT_LIT,
    STRING_LIT,
    OPERATOR,
    SEMI,
    LPAREN,
    RPAREN,
    UNKNOWN
};


extern int yylex(void);
extern char *yytext;
extern FILE *yyin;


const char *tokenName(int t) {
    switch (t) {
        case KEYWORD:    return "KEYWORD";
        case PRINT:      return "PRINT";
        case IDENTIFIER: return "IDENTIFIER";
        case INT_LIT:    return "INT_LIT";
        case FLOAT_LIT:  return "FLOAT_LIT";
        case STRING_LIT: return "STRING_LIT";
        case OPERATOR:   return "OPERATOR";
        case SEMI:       return "SEMI";
        case LPAREN:     return "LPAREN";
        case RPAREN:     return "RPAREN";
        case UNKNOWN:    return "UNKNOWN";
        default:         return "?";
    }
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        FILE *f = fopen(argv[1], "r");
        if (!f) {
            printf("Could not open file: %s\n", argv[1]);
            return 1;
        }
        yyin = f;
    }

    printf("=== Type Check Lexer - Token Stream ===\n\n");

    int tok;
    int count = 0;
    while ((tok = yylex()) != 0) {
        switch (tok) {
            case SEMI:   printf("SEMI\n"); break;
            case LPAREN: printf("LPAREN\n"); break;
            case RPAREN: printf("RPAREN\n"); break;
            default:     printf("%s(%s)\n", tokenName(tok), yytext); break;
        }
        count++;
    }

    printf("\nTotal tokens recognized: %d\n", count);
    return 0;
}
