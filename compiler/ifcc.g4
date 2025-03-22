grammar ifcc;

axiom : prog EOF ;

prog : 'int' 'main' '(' ')' '{' stmt* '}' ;

stmt : decl_stmt
     | assign_stmt
     | return_stmt
     ;

decl_stmt : 'int' ID ('=' expr)? ';'|'char' ID ('=' expr)? ';' ;

assign_stmt : ID '=' expr ';' ;

return_stmt : RETURN expr ';' ;

expr
    : expr op=('==' | '!=' | '>' | '<' | '>=' | '<=') expr
    | ID
    | CONST
    | exprc
    ;

exprc : xor_expr
        | xor_expr OR exprc
        ;

xor_expr : and_expr
        | and_expr XOR xor_expr
        ;

and_expr : add_expr
        | add_expr AND and_expr
        ;

add_expr : mult_expr
      | mult_expr OPA add_expr
      ;

mult_expr : primary_expr
          | primary_expr OPM mult_expr
          ;

primary_expr : CONST
             | ID
             | '(' exprc ')'
             ;

RETURN : 'return' ;
ID     : [a-zA-Z_][a-zA-Z_0-9]* ; // Match identifiers (e.g., variable names)
CONST  : [0-9]+|'\'' . '\'' ;                 // Match integer constants
COMMENT : '/*' .*? '*/' -> skip ;  // Skip comments
DIRECTIVE : '#' .*? '\n' -> skip ; // Skip preprocessor directives
WS     : [ \t\r\n]+ -> channel(HIDDEN) ; // Skip whitespace
OR : '|';
AND : '&';
XOR : '^';
OPA : '+' | '-';
OPM : '*' | '/' | '%';
