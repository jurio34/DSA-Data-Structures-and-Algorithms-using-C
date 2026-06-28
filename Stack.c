//
// Created by gtgmaster on 08/06/2026.
//
#include <stdio.h>
#include <stdlib.h>
typedef struct Stack {
  int data;
  struct Stack *next;
} Stack;
void push(Stack **head, int data) {
  Stack *newNode = (Stack *)malloc(sizeof(Stack));
  newNode->data = data;
  newNode->next = NULL;
  if (*head == NULL) {
    printf("Stack is empty\n");
  } else {
    // a lista ligada eh assim: x -> y -> z, pra adicionar eh pra fazer
    // newnode->next virar o head e atualizar o head pra newnode
    newNode->next = *head;
    *head = newNode;
  }
}
int pop(Stack **head) {
  int poppedValue = (*head)->data;
  if (*head == NULL) {
    printf("Stack is empty\n");
  } else {
    // pra remover eh pra fazer o root a
    Stack *temp = *head;
    *head = (*head)->next;
    free(temp);
  }
  return poppedValue;
}
void print_stack(Stack **head) {
  Stack *currentPtr;
  printf("A pilha é: \n");
  while (currentPtr != NULL) {
    printf("%d ->", currentPtr->data);
    currentPtr = currentPtr->next;
  }
}
int main() {
  Stack **head = NULL;
  int value;
  int options;
  printf("Digite a operação a ser feita na pilha: (1- Empilhar um valor, "
         "2-Desempilhar)\n");
  scanf("%d\n", &options);
  while (options < 3 && options != 0) {
    switch (options) {
    case 1:
      printf("Digite o valor a ser empilhado: \n");
      scanf("%d", &value);
      push(head, value);
      print_stack(head);
      break;
    case 2:
      pop(head);
      break;
    default:
      printf("Opção inválida!\n");
      break;
    }
  }
  return 0;
}
