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


int matrix[10][10],x,sp;

int isElement(int n){

    for(int i = 0;i < top;i++)
        if(n == stack[i])
            return 1;
    return 0;
}

int checkCondition(int ix,int y,int thisx,int thisy){

    if(ix == thisx)
        if(thisy == y + 1 || thisy == y - 1){
            //printf("\n\n%d\n\n",!isElement(matrix[ix][y]));
            if(!isElement(matrix[ix][y]))
                return 1;
        }
            
    if(y == thisy)
        if(ix == thisx + 1 || ix == thisx - 1)
            if(!isElement(matrix[ix][y]))
                return 1;

    return 0;

}

void puzzle(int num){

    int thisx,thisy;

    for(int i = 0;i < x;i++)
        for(int j = 0;j < x;j++)
            if(matrix[i][j] == num){
                printf("\nLoop called\n");
                thisx = i;
                thisy = j;
                push(matrix[i][j]);
                break;
            }

    if(top == x * x - 1)
        return;

    for(int i = 0;i < x;i++)
        for(int j = 0;j < x;j++){
            if(top == x * x - 1)
                return;
            printf("Loop %d %d of %d %d\n",i,j,thisx,thisy);
            if(checkCondition(i,j,thisx,thisy)){

                view();
                puzzle(matrix[i][j]);
                
            }
        }

    if(top == x * x - 1)
        return;
    pop();    
    view();           
        
    
}

void main(){

    int n = 0;

    printf("Enter x value\n");
    scanf("%d",&x);

    printf("Enter starting point\n");
    scanf("%d",&sp);

    for(int i = 0;i < x;i++)
        for(int j = 0;j < x;j++){
            matrix[i][j] = n++;
        }

    puzzle(sp);

    view();

}
