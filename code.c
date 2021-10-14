#include <stdio.h>
#include <stdio.h>
#define MAX_NUM 30
int top=-1;   
int stack[MAX_NUM];
int isFull(){
    if(top==MAX_NUM-1)
        return 1;
    return 0;
}
int isNull(){
     if(top==-1)
       return 1;
     return 0;
}
void push(int value){
    if(isFull()==1)
        printf("Over flow");
    else
      stack[++top]=value;
}
void pop(){
    if(isNull()==1)
        printf("Underflow");
    else
        top--;
}
void view(){
    int i;
    printf("\nStack \n");
    if(isNull()==1)
        printf("Stack Empty");
    else 
        for(i=0;i<=top;i++)
            printf("%d\n",stack[i]);
    printf("\n");
}


int matrix[5][5];


void puzzle(int num){

    view();
    static int n = 0;
    ++num;
    if(num == 10000)
        return;
    if(top == 24)
        return;
    for(int i = 0;i < 5;i++)
        for(int j = 0;j < 5;j++)
            if(matrix[i][j] == num)
                push(matrix[i][j]);
    for(int i = 0;i < 5;i++)
        for(int j = 0;j < 5;j++){
            if(matrix[i][j] == num + 5 || matrix[i][j] == num - 5 || matrix[i][j] == num + 1 || matrix[i][j] == num - 1){
                puzzle(matrix[i][j]);
            
            }
        }

    pop();    
            
        
    
}

void main(){
    int n = 0;
    for(int i = 0;i < 5;i++)
        for(int j = 0;j < 5;j++){
            matrix[i][j] = n++;
        }

    puzzle(1);

    view();

}
