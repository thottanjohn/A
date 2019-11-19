%{
#include<stdio.h>
int valid=1;
%}
%token num id op  type strct
%%
start : strct ' ' id '{' declarations '}' ;
declarations :  type  ' ' E ';' declarations |;
E : id ; | id '=' num;

%%

int main()
{
printf("\nEnter the expression:\n");
yyparse();
if(valid)
{printf("\nValid expression!\n");}
}


int yyerror()
{
valid=0;
printf("\nInvalid expression!\n");
return 0;
}