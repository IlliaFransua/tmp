#include "constants.h"

void ft_putstr(char *str) {
  char *tmp = str;
  while (*tmp) {
    write(1, tmp, 1);
    ++tmp;
  }
}
