#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    int size;
    int top;
    char *arr;
}stack;

int isEmpty(stack *s){

    if(s->top == -1)
        return 1;

    return 0;
}

int isFull(stack *s) {

    if(s->top == s->size - 1)
        return 1;

    return 0;
}

void push(stack *s, char d) {

    if(isFull(s)){
        printf("Stack Overflow!\n");
        return;
    }

    s->top++;
    s->arr[s->top] = d;
}

char pop(stack *s) {

    if(isEmpty(s)){
        printf("Stack Underflow! Cannot pop more\n");
        return -1;
    }

    char val = s->arr[s->top];
    s->top--;
    return val;
}

char peek(stack *s) {
    return s->arr[s->top];
}

int precedence(char ch) {

    if(ch == '*' || ch == '/')
        return 3;
    else if(ch == '+' || ch == '-')
        return 2;
    else
        return 0;
}

int isOperator(char ch) {

    if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return 1;

    return 0;
}

char* infixToPostfix(char* infix) {

    stack *s = (stack *)malloc(sizeof(stack));
    s->size = 100;
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char));

    char* postfix = (char *)malloc((strlen(infix)+1) * sizeof(char));

    int i = 0;// Track infix traversal
    int j = 0;// Track Postfix addition

    while(infix[i] != '\0') {
        if(!isOperator(infix[i])){
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else{
            if(precedence(infix[i])>precedence(peek(s))){
                push(s, infix[i]);
                i++;
            }
            else{
                postfix[j] = pop(s);
                j++;
            }
        }
    }

    while(!isEmpty(s)){

        postfix[j] = pop(s);
        j++;
    }

    postfix[j] = '\0';
    return postfix;
}

int main() {

    char* infix = "x-y/z-k*d";

    printf("Postfix: %s\n", infixToPostfix(infix));

    // push(s, 10);
    // push(s, 20);
    // push(s, 30);
    // push(s, 40);
    // push(s, 50);
    // push(s, 60);// Stack overflow occurs here

    // printf("Popped %d\n", pop(s));
    // printf("Popped %d\n", pop(s));
    // printf("Popped %d\n", pop(s));
    // printf("Popped %d\n", pop(s));
    // printf("Popped %d\n", pop(s));
    // printf("Popped %d\n", pop(s));// Stack underflow occurs here



    return 0;
}
