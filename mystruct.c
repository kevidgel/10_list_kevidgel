#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mystruct.h"

struct food * new_food(char *n, int r, double p)
{
  struct food *foo;

  foo = malloc( sizeof(struct food) );

  strncpy(foo->name, n, sizeof(foo->name)-1);
  foo->rating = r;
  foo->price = p;

  return foo;
}

void print_food(struct food *ood)
{
  printf("name: ");
  int i;
  for(i=0; *(ood->name+i); i++) {
    printf("%c", *(ood->name+i));
  }
  printf("\n");
  printf("rating: %d\n", ood->rating);
  printf("price: %lf\n\n", ood->price);
}

void print_list(struct food *ood)
{
  if (ood != NULL) // some issue here, didn't know how to check if ood was not initialized
  {
    print_food(ood);
    print_list(ood->next);
  }
  else
  {
    return;
  }
}

struct food * insert_front(struct food *ood, char *n, int r, double p)
{
  struct food *out;
  out = new_food(n, r, p);
  out->next = ood;
  return out;
}

struct food * free_list(struct food *ood)
{
  free_list_help(ood);
  ood = NULL;
  return ood;
}

struct food * free_list_help(struct food *ood)
{
  if (ood == NULL)
  {
    return NULL;
  }
  else
  {
    ood->next = free_list_help(ood->next);
    printf("freeing ");
    print_food(ood);
    free(ood);
    return NULL;
  }
}

struct food * remove_food(struct food *front, char *n, int r, double p)
{
  if (front->rating == r && front->price == p && strcmp(n, front->name) == 0)
  {
    struct food *temp = front->next;
    free(front);
    return temp;
  }
  else
  {
    remove_food_help(front->next, n, r, p);
    return front;
  }
}

void remove_food_help(struct food *front, char *n, int r, double p)
{
  if (front->next->rating == r && front->next->price == p && strcmp(n, front->next->name) == 0)
  {
    struct food *temp = front->next->next;
    free(front->next);
    front->next = temp;
  }
  else
  {
    remove_food_help(front->next, n, r, p);
  }
}
