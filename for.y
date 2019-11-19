%{
    #include <stdio.h>
    int valid=1;
%}
%token id num type iff ellse op relop FOR unary arassign

%%
 
start : FOR '(' init ';' exp ';'  incr ')' '{' body '}';
| id '=' num;

init : id '=' num ',' init;
| id '=' num;
|;

exp : exp1 relop exp1;
|id '=' exp1 ;
|;

exp1 : id op exp1; 
|id;
|num;

incr : id unary ',' incr;
|id unary;
|; 

body : exp ';' body;
|start;
|; 

%%
int yyerror(){
    valid=0;
    printf("Expression is invalid");
    return 0;
}
void main(){
    printf("Enter the Expression:\n");
    yyparse();
    if(valid){
        printf("Expression is valid");
    }
}