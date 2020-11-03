#include "mystruct.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
  srand( time(NULL) );
  struct food *bacon = NULL;

  printf("<<< Printing empty list >>>\n");
  print_list(bacon);

  struct food *burger;
  struct food *fries;
  struct food *eggs;
  struct food *pizza;

  bacon = new_food("bacon", 5, 3.49);
  burger = new_food("burger", 6, 2.49);
  fries = new_food("fries", 10, 5.49);
  eggs = new_food("eggs", 7, 6.49);
  pizza = new_food("pizza", 8, 7.49);

  bacon->next = burger;
  burger->next = fries;
  fries->next = eggs;
  eggs->next = pizza;


  printf("<<< Printing list with food >>>\n");
  print_list(bacon);

  printf("<<< Removing eggs >>>\n");
  remove_food(bacon, "eggs", 7, 6.49);
  print_list(bacon);

  printf("<<< Removing pizza >>>\n");
  remove_food(bacon, "pizza", 8, 7.49);
  print_list(bacon);

  printf("<<< Inserting pancakes >>>\n");
  struct food *pancakes;
  pancakes = insert_front(bacon, "pancakes", 5, 2.49);
  print_list(pancakes);

  printf("<<< Freeing list >>>\n");
  struct food *empty;
  empty =  free_list(pancakes);

  printf("<<< Printing empty list >>>\n");
  print_list(empty);


}
