#ifndef MYSTRUCT_H
#define MYSTRUCT_H

struct food
{
  char name[256];
  int rating;
  double price;

  struct food *next;
};

struct food * new_food(char *n, int r, double p);
void print_food(struct food *ood);
void print_list(struct food *ood);
struct food * insert_front(struct food *ood, char *n, int r, double p);
struct food * free_list(struct food *ood);
struct food * free_list_help(struct food *ood);
struct food * remove_food(struct food *front, char *n, int r, double p);
void remove_food_help(struct food *front, char *n, int r, double p);

#endif
