#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct node {
  int val;
  struct node *next;
  struct node *prev;
} Node;

typedef struct myStack {
  Node *head;
} MyStack;

MyStack* myStackCreate() {
  MyStack *createStack = (MyStack *)malloc(sizeof(MyStack));
  
  if (!createStack) return (NULL);

  createStack->head = NULL;
  return (createStack);
}

void myStackPush(MyStack *obj, int x) {
  Node *newNode = (Node *)malloc(sizeof(Node));

  newNode->val = x;
  newNode->next = newNode;
  newNode->prev = newNode;

  if (!obj->head) obj->head = newNode;
  else
  {
    obj->head->prev->next = newNode;
    newNode->prev = obj->head->prev;
    obj->head->prev = newNode;
    newNode->next = obj->head;
  }
}

int main(void) {
  int n, m, val, less, i = 0;
  Node *help = NULL, *lessP;
  MyStack *stack = myStackCreate();
  
  scanf("%d %d", &n, &m);

  for (int i = 0; i < n; i++)
  {
    scanf("%d", &val);
    myStackPush(stack, val);
  }

  help = stack->head->next;
  less = stack->head->val;
  lessP = stack->head;

  while (i < m)
  {
    while (1)
    {
      if (help->val < less)
      {
        less = help->val;
        lessP = help;
      }
      help = help->next;
      if (help == stack->head) break;
    }

    printf("%d\n", less);
    lessP->val++;
    m--;
    help = stack->head->next;
    less = stack->head->val;
    lessP = stack->head;
  }

  return (0);
}
