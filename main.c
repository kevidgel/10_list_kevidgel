#include "mystruct.h"
#include <time.h>

int main()
{
  srand( time(NULL) );
  struct user *bacon;

  bacon = new_food("bacon", rand() % 10, 3.49);

  print_food(bacon);

  free(bacon);
}
