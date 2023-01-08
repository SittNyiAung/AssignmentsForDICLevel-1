//
// Created by Saito on 1/7/2023.
//

//LIFO

#include "stdlib.h"
#include "stdio.h"

#define MAXOFSTACK 10       //symbolic constant
int dataCount =0;

struct stack{
    int data[MAXOFSTACK];
    int top;
};

typedef struct stack st;

void create_emptyStack(st *myStack){
    myStack->top = -1;
}

int isStackIsFull(st *myStack){
    if(myStack->top == MAXOFSTACK-1){
        return 1;
    } else{
        return 0;
    }
}
void pushToStack(st *myStack, int value){
    if(isStackIsFull(myStack)){
        printf("Stack is full\n");
    } else{
        myStack->top++;
        myStack->data[myStack->top] = value;
        dataCount++;
    }
}

int isStackIsEmpty(st *myStack){
    if(myStack->top == -1){
        return 1;
    } else{
        return 0;
    }
}
void popFromStack(st *myStack){
    if(isStackIsEmpty(myStack)){
        printf("Stack is empty\n");
    } else{
        printf("Pop from stack data is : %d \n",myStack->data[myStack->top]);
        myStack->top--;
    }
}

void dataPrinting(st *myStack){
    printf("There are %d DATAs in Stack.\n",dataCount);
    for(int i=0; i<dataCount; i++){
        popFromStack(myStack);
    }
    dataCount=0;
}


int main(){

    st *myStack = (st*) malloc(sizeof (st));
    create_emptyStack(myStack);
    pushToStack(myStack, 0);
    pushToStack(myStack, 1);
    pushToStack(myStack, 2);
    pushToStack(myStack, 3);
    pushToStack(myStack, 4);
    pushToStack(myStack, 5);
    pushToStack(myStack, 6);
    pushToStack(myStack, 7);
    pushToStack(myStack, 8);
    pushToStack(myStack, 9);
    pushToStack(myStack, 33);

    dataPrinting(myStack);

    return 0;
}