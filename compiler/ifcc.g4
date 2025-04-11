grammar ifcc;

axiom : progs ;


progs: def_func+;

def_func: TYPE ID '(' param_list? ')' '{' stmt* '}';


stmt : decl_stmt
     | assign_stmt
     | return_stmt
     | putchar_stmt
     | getchar_stmt
     | break_stmt
     | continue_stmt
     | if_stmt
     | block
     ;

if_stmt : 'if' '(' expr ')' '{' stmt* '}' else_stmt? ;
else_stmt : 'else' ( '{' stmt* '}' | if_stmt ) ;
continue_stmt : 'continue' ';' ;
break_stmt : 'break' ';' ;
getchar_stmt : 'getchar' '(' ID ')' ';' ;
putchar_stmt : 'putchar' '(' expr ')' ';' ;
decl_stmt : 'int' equalexpr_stmt (',' equalexpr_stmt )* ';' | 'char' equalexpr_stmt (',' equalexpr_stmt )* ';';
equalexpr_stmt : ID ('=' expr)? ;
assign_stmt : ID '=' expr ';' ;
return_stmt : RETURN expr ';' ;
block: '{' stmt* '}';

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
     |'getchar' '(' ')' # getchar_expr
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
