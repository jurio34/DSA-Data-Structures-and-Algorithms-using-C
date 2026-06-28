//
// Created by gtgmaster on 08/06/2026.
//
#include <stdlib.h>
#include <stdio.h>
typedef struct Stack {
    int data;
    struct Stack *next;
}Stack;
void push(Stack **head, int data) {
    Stack *newNode = (Stack *)malloc(sizeof(Stack));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        printf("Stack is empty\n");
    }else {
        //a lista ligada eh assim: x -> y -> z, pra adicionar eh pra fazer newnode->next virar o head e atualizar o head pra newnode
        newNode->next = *head;
        *head = newNode;
    }
}
int pop(Stack **head) {
    int poppedValue = (*head)->data;
    if (*head == NULL) {
        printf("Stack is empty\n");
    } else {
        //pra remover eh pra fazer o root a
        Stack *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    return poppedValue;
}

int main() {
    printf("Hello World!\n");
    return 0;
}