grammar ifcc;

axiom : prog EOF ;

prog : 'int' 'main' '(' ')' '{' stmt* '}' ;

stmt : decl_stmt
     | assign_stmt
     | return_stmt
     ;

decl_stmt : 'int' ID ('=' expr)? ';' ;

assign_stmt : ID '=' expr ';' ;

return_stmt : RETURN expr ';' ;

expr
    : expr op=('==' | '!=' | '>' | '<' | '>=' | '<=') expr
    | ID
    | CONST
    ;

RETURN : 'return' ;
ID     : [a-zA-Z_][a-zA-Z_0-9]* ;
CONST  : [0-9]+ ;
COMMENT : '/*' .*? '*/' -> skip ;
DIRECTIVE : '#' .*? '\n' -> skip ;
WS     : [ \t\r\n]+ -> channel(HIDDEN) ;
