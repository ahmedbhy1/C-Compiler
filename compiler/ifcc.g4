grammar ifcc;

axiom : progs EOF ;

progs : prog* ;
prog : 'int' ID '(' ')' '{' stmt* '}'
     | 'void' ID '(' ')' '{' stmt* '}';

stmt : decl_stmt
     | assign_stmt
     | return_stmt
     ;

decl_stmt : 'int' ID (',' ID)* ('=' expr)? ';' | 'char' ID (',' ID)* ('=' expr)? ';';
assign_stmt : ID '=' expr ';' ;
return_stmt : RETURN expr ';' ;

expr : expr COMP expr #Comparaison
     | expr OR expr #Or
     | expr XOR expr #Comparaison
     | expr AND expr #Comparaison
     | expr OPA expr #Comparaison
     | expr OPM expr #Comparaison
     | UNARY expr #Comparaison
     | CONST
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
