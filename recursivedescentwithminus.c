/*

BEFORE REMOVING LEFT RECURSION
E –> E + J | J
J -> J - T  | T
T –> T * F | F
F –> ( E ) | id	

AFTER REMOVING LEFT RECURSION
E –> J E’
E’ –> + J E’ | e
J  -> T J'   
J' -> - T J' | e
T –> F T’
T’ –> * F T’ | e
F –> ( E ) | id
*/
#include<stdio.h>
#include<ctype.h>
#include<string.h>
char expression[10];
void E();
int count=0,flag=0;
void F(){
    if(expression[count]=='('){
        count++;
        E();
        if(expression[count]==')'){
            count++;
        }else{
            flag=1;
        }
    }else  if(isalnum(expression[count])){
        count++;
    }else{
        flag=1;
    }
}

void Tprime(){
    if(expression[count]=='*'){
        count++;
        F();
        Tprime();
    }
}
void T(){
    
    F();
    Tprime();
}
void Jprime(){
    if(expression[count]=='-'){
        count++;
        T();
        Jprime();
    }
}
void J(){
    T();
    Jprime();
}
void Eprime(){
    if(expression[count]=='+'){
        count++;
        J();
        Eprime();
    }
}
void E(){
    J();
    Eprime();
}
void main(){
    printf("\nEnter an Algebraic Expression:\t");
    scanf("%s", expression);
    E();
    printf("%d \n",count);
    if((count ==strlen(expression)) && flag==0){
        printf("Expression is valid");
    }else{
         printf("Expression is invalid");
    }
}