%{
#include<stdio.h>
int valid=1;
%}
%token num id op
%%
start : id '=' s ;
s :  id op id;
| num op num;
| '(' s ')';
|num;
|id;

%%
int yyerror()
{
valid=0;
printf("\nInvalid expression!\n");
return 0;
}
int main()
{
printf("\nEnter the expression:\n");
yyparse();
if(valid)
{printf("\nValid expression!\n");}
}