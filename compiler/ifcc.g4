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
    | exprc
    ;

exprc : mult_expr
      | mult_expr OPA exprc
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
CONST  : [0-9]+ ;                 // Match integer constants
COMMENT : '/*' .*? '*/' -> skip ;  // Skip comments
DIRECTIVE : '#' .*? '\n' -> skip ; // Skip preprocessor directives
WS     : [ \t\r\n]+ -> channel(HIDDEN) ; // Skip whitespace
OPA : '+' | '-';
OPM : '*' | '/';