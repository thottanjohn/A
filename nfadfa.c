#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
// number+'0  ='number'  And Similarly  'number' -'0' =number 
/*States are number from 0 to n-1
INput symbols hould be numbered from 0 onwards in proper order
Sample input:
Enter the number of states:3

Enter the number of final states:1

Enter the  final states:2

Enter the number of input symbols:2

Enter the number of transitions:4

Enter the  transitions intialstate inputsymbol finalstate: 
0 0 0
0 1 0
0 1 1
1 1 2
Enter the intial state:
0
/Stack will push new  states and pop them after generating new states
/States char matrix will have all states of DFA
/NFA transition table will 3d integer matrix where 3d dimension denoting final states to be on given input symbol j and ith nfa state
/DFA transition table will 3d character matrix where 3d dimension denoting string of final state.
*/
char stack[100][10];
int top=-1;
void push(char t[]){
top++;
int i;
strcpy(stack[top],t);
}
char *pop(){
int i;
if(top==-1){
    return "-1";
}
char *temp;
temp=(char*)malloc((strlen(stack[top])*1));
for(i=0;i<strlen(stack[top]);i++){
temp[i]=stack[top][i];
}
top--;
return (char *)temp;
}
int main()
{
    int n,m,i,j,k,f_n,f[100],tr,inti,input,fin,count,flag,l,co,dfa_st,finalflag,finalcount=0,in,_j;
    char temp[10];
    char t;
    printf("Enter the number of states:");
    scanf("%d",&n);
    printf("\nEnter the number of final states:");
    scanf("%d",&f_n);
    printf("\nEnter the  final states:");
    for(i=0;i<f_n;i++){
        scanf("%d",&f[i]);
    }
    printf("\nEnter the number of input symbols:");
    scanf("%d",&m);
    printf("\nEnter the number of transitions:");
    scanf("%d",&tr);
    printf("\nEnter the  transitions intialstate inputsymbol finalstate: \n");
    int nfa_transition[n][m][n];
    for(i=0;i<tr;i++){
        scanf("%d%d%d",&inti,&input,&fin);
        nfa_transition[inti][input][fin]=1;
    }
    printf("Enter the intial state:\n");
    scanf("%d",&in);
    char dfa_transition[100][m][n];
    printf("\nNFA TRANSITION TABLE\n");
    for(j=0;j<m;j++){
      printf("\t %d",j);  
    }
    printf("\n");
    for(i=0;i<n;i++){
        printf("%d\t",i);
        for(j=0;j<m;j++){
            temp[0]='\0';
            count=0;
            for(k=0;k<n;k++){
                if(nfa_transition[i][j][k]==1){
                    char c= k+'0';
                    temp[count++]=c;
                    temp[count]='\0';
                }
            }
            printf("%s\t",temp);
        }
        printf("\n");
    }
    printf("NFA final STATES:");
    for(i=0;i<f_n;i++){
         printf("\n%d\t",f[i]);
    }
    //pushing intial state
    temp[0]=in+'0';
    temp[1]='\0';
    push(temp);
    char states[100][10],dfa_finals[10][10];
    for(i=0;i<f_n;i++){
        if(f[i]==in){
            strcpy(dfa_finals[finalcount++],temp);
        }
    }
    strcpy(states[0],temp);
    count=1;
    dfa_st=0;
    printf("\nDFA TRANSITION TABLE:\n");
    for(j=0;j<m;j++){
      printf("\t %d",j);  
    }
    while(1){
        char x[10];
        strcpy(x,pop());
        if(strcmp(x,"-1")==0){
            break;
        }
        printf("\n%s\t",x);
        for(j=0;j<m;j++){
            temp[0]='\0';
            co=0;
            for(i=0;i<strlen(x);i++){
                for(k=0;k<n;k++){
                if(nfa_transition[x[i]-'0'][j][k]==1){
                    char c= k+'0';
                    flag=0;
                    //checking to remve repitive characters
                    for(l=0;l<co;l++){
                        if(temp[l] ==c){
                            flag=1;
                            break;
                        }
                    }
                    if(!flag){
                        temp[co++]=c;
                        temp[co]='\0';
                    }
                }
            }
            }
            
        flag=0;
        if(strlen(temp)==0){
            flag=1;
        } else{
            //Sorting state
        for (i = 0; i <strlen(temp)-1; i++) {
           for (_j = i+1; _j < strlen(temp); _j++) {
                 if (temp[i] > temp[_j]) {
                    t = temp[i];
                    temp[i] = temp[_j];
                    temp[_j] = t;
                }
            }
        }
        
       //Checking this state already defined
        for(i=0;i<count;i++){
            if(strcmp(states[i],temp)==0){
                flag=1;
            }
        }
        }
        strcpy(dfa_transition[dfa_st][j],temp);
        printf("%s\t",dfa_transition[dfa_st][j]);
        if(!flag){
        strcpy(states[count],temp);
        count++;
        push(temp);
        finalflag=0;
        //checking for final states in DFA
        for(i=0;i<f_n;i++){
            for(l=0;l<co;l++){
                if((temp[l]-'0') ==f[i]){
                    finalflag=1;
                    break;
                }
        }
        if(finalflag){
            strcpy(dfa_finals[finalcount++],temp);
            break;
        } 
        }
        }  
        }
       dfa_st++;
    }
  
    printf("\nDFA final STATES:");
    for(i=0;i<finalcount;i++){
         printf("\n%s\t",dfa_finals[i]);
    }
    return 0;
}