grammar ifcc;

axiom : progs EOF ;

progs : prog* ;
prog : 'int' ID '(' ')' '{' stmt* '}'
     | 'void' ID '(' ')' '{' stmt* '}';

stmt : decl_stmt           #decl
     | assign_stmt         #assign
     | return_stmt         #ret
     | '{' stmt* '}'       #block
     ;

decl_stmt : 'int' equalexpr_stmt (',' equalexpr_stmt )* ';' | 'char' equalexpr_stmt (',' equalexpr_stmt )* ';';
equalexpr_stmt : ID ('=' expr)? ;
assign_stmt : ID '=' expr ';' ;
return_stmt : RETURN expr ';' ;

expr : UNARY expr # unary
     | OPA expr # moin
     | expr OPM expr # mul   
     | expr OPA expr # plus
     | expr AND expr # and
     | expr XOR expr # xor
     | expr OR expr # or
     | expr COMP expr # comp
     | CONST # const
     | ID OPENPARENT CLOSEPARENT # funct
     | ID # id
     | OPENPARENT expr CLOSEPARENT # parent
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
OPENPARENT : '(';
CLOSEPARENT: ')';
