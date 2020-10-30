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
  if (ood != NULL)
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
  if (ood == NULL)
  {
    return;
  }
  else
  {
    free_list(ood->next);
    free(ood);
  }
}
