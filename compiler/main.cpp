#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include "antlr4-runtime.h"
#include "generated/ifccLexer.h"
#include "generated/ifccParser.h"
#include "generated/ifccBaseVisitor.h"

#include "CodeGenVisitor.h"

using namespace antlr4;
using namespace std;

int main(int argn, const char **argv)
{
  stringstream in;
  if (argn==2)
  {
     ifstream lecture(argv[1]);
     if( !lecture.good() )
     {
         cerr<<"error: cannot read file: " << argv[1] << endl ;
         exit(1);
     }
     in << lecture.rdbuf();
  }
  else
  {
      cerr << "usage: ifcc path/to/file.c" << endl ;
      exit(1);
  }
  
  ANTLRInputStream input(in.str());

  ifccLexer lexer(&input);
  CommonTokenStream tokens(&lexer);

  ifccParser parser(&tokens);
  tree::ParseTree* tree = parser.axiom();
  Token* t = parser.getCurrentToken();
  
  #ifdef DEBUG
    //cout << "token list =" << endl;
    //for(int i =0;i<tokens.getTokens().size();i++){
    //  cout << "tocken "<< i << " = " << tokens.get(i)->getText() << endl;
    //}
  #endif
  if(parser.getNumberOfSyntaxErrors() != 0)
  {
      cerr << "error: syntax error during parsing" << endl;
      exit(1);
  }

  
  CodeGenVisitor v;
  v.visit(tree);

  return 0;
}
