%{
    #include "y.tab.h"
%}

%%

int|float|double|char return type;
if return  iff;
else return  ellse;
[a-zA-Z_][a-zA-Z_0-9]* return id;
[0-9]+  return num;
\+|\-|\\|\* return op;
"<"|">"|">="|"<="|"=="|"!=" {return relop;}
. return yytext[0];
\n return 0;
%%

int yywrap(){
    return 1;
}