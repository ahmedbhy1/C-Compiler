grammar ifcc;

axiom : progs EOF ;

progs : prog* ;
prog : 'int' ID '(' ')' '{' stmt* '}'
     | 'void' ID '(' ')' '{' stmt* '}';

stmt : decl_stmt
     | assign_stmt
     | return_stmt
     | putchar_stmt
     | getchar_stmt
     ;

decl_stmt : 'int' ID (',' ID)* ('=' expr)? ';' | 'char' ID (',' ID)* ('=' expr)? ';';

assign_stmt : ID '=' expr ';' ;

return_stmt : RETURN expr ';' ;

putchar_stmt : 'putchar' '(' expr ')' ';' ;

getchar_stmt : 'getchar' ';' ;

expr:  exprc 
    |  exprc COMP expr
    |  CONST
    |  ID
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

mult_expr : unary_expr
          | unary_expr OPM mult_expr
          ;

unary_expr : primary_expr
           | UNARY unary_expr
           | OPA unary_expr 
           ;

primary_expr : CONST
             | ID
             | '(' expr ')'
             ;

RETURN : 'return' ;
ID     : [a-zA-Z_][a-zA-Z_0-9]* ; // Match identifiers (e.g., variable names)
CONST  : [0-9]+|'\'' . '\'' ;                 // Match integer constants
COMMENT : '/*' .*? '*/' -> skip ;  // Skip comments
DIRECTIVE : '#' .*? '\n' -> skip ; // Skip preprocessor directives
WS     : [ \t\r\n]+ -> channel(HIDDEN) ; // Skip whitespace

COMP: '==' | '!=' | '>' | '<' | '>=' | '<=';
UNARY :  '!';
OR : '|';
AND : '&';
XOR : '^';
OPA : '+' | '-';
OPM : '*' | '/' | '%';
