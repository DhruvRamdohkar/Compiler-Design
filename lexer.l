%{
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
%}

%option noyywrap

%%
"int"|"float"|"string"|"bool"                      { return KEYWORD; }
"print"                                             { return PRINT; }
[0-9]+\.[0-9]+                                      { return FLOAT_LIT; }
[0-9]+                                              { return INT_LIT; }
\"[^\"]*\"                                          { return STRING_LIT; }
[a-zA-Z_][a-zA-Z0-9_]*                              { return IDENTIFIER; }
"=="|"!="|"<="|">="|"+"|"-"|"*"|"/"|"="|"<"|">"     { return OPERATOR; }
";"                                                 { return SEMI; }
"("                                                 { return LPAREN; }
")"                                                 { return RPAREN; }
[ \t\r\n]+                                          ; /* skip whitespace */
.                                                   { return UNKNOWN; }
%%
