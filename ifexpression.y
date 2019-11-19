%{
    #include <stdio.h>
    int valid=1;
%}
%token id num type iff ellse op relop

%%
 
start : iff  ifexp;
| iff  ifexp  ellse  '{' body '}'  ;
| iff  ifexp   ellse ' ' iff ifexp ellse  '{' body '}'  ;


ifexp : '(' exp ')' '{' body  '}' ;

exp : exp1 relop exp1;
|id '=' exp1;

exp1 : id op id;
|id;
|num;


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