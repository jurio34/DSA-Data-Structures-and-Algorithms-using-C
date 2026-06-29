//
// Created by gtgmaster on 08/06/2026.
//
#include <stdio.h>
#include <stdlib.h>
typedef struct Stack {
  int data;
  struct Stack *next;
} Stack;
void push(Stack **head, int value) {
  Stack *newNode = (Stack *)malloc(sizeof(Stack));

  if (newNode != NULL) {
    newNode->data = value;
    newNode->next = NULL;
    // a lista ligada eh assim: x -> y -> z, pra adicionar eh pra fazer
    // newnode->next virar o head e atualizar o head pra newnode
    newNode->next = *head;
    *head = newNode;
  } else {
    printf("%d not inserted, Not enough memory\n", value);
  }
}
int pop(Stack **head) {
  int poppedValue = (*head)->data;
  if (*head != NULL) {
    // pra remover eh pra fazer o root a
    Stack *temp = *head;
    *head = (*head)->next;
    free(temp);
    return poppedValue;
  } else {
    printf("Stack empty!\n");
    return -1;
  }
}
void print_stack(Stack **head) {
  Stack *currentPtr = *head;
  printf("A pilha é: \n");
  while (currentPtr != NULL) {
    printf("%d ->", currentPtr->data);
    currentPtr = currentPtr->next;
  }
  printf("NULL\n\n");
}
int main() {
  Stack *head = NULL;
  int value;
  int options;


  printf("Digite a operação a ser feita na pilha: (1- Empilhar, 2- Desempilhar, 3- Sair)\n");
  scanf("%d", &options);

  while (options != 3) {
    switch (options) {
      case 1:
        printf("Digite o valor a ser empilhado: \n");
        scanf("%d", &value);
        push(&head, value);
        print_stack(&head);
        break;
      case 2:
        value = pop(&head);
        if (value != -1) {
          printf("O valor desempilhado eh: %d\n", value);
        }
        print_stack(&head);
        break;
      default:
        printf("Opção inválida!\n");
        break;
    }


    printf("\nDigite a próxima operação: (1- Empilhar, 2- Desempilhar, 3- Sair)\n");
    scanf("%d", &options);
  }

  printf("Programa encerrado.\n");
  return 0;
}
