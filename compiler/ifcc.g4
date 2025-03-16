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

// ADDED: Expression rules with bitwise operations
expr : expr '&' expr    # BitwiseAndExpr  // ADDED: Bitwise AND
     | expr '|' expr    # BitwiseOrExpr   // ADDED: Bitwise OR
     | expr '^' expr    # BitwiseXorExpr  // ADDED: Bitwise XOR
     | '(' expr ')'     # ParenthesizedExpr
     | ID              # IdentifierExpr
     | CONST           # ConstantExpr
     ;

RETURN : 'return' ;
ID     : [a-zA-Z_][a-zA-Z_0-9]* ; // Match identifiers (e.g., variable names)
CONST  : [0-9]+ ;                 // Match integer constants
COMMENT : '/*' .*? '*/' -> skip ;  // Skip comments
DIRECTIVE : '#' .*? '\n' -> skip ; // Skip preprocessor directives
WS     : [ \t\r\n]+ -> channel(HIDDEN) ; // Skip whitespace
