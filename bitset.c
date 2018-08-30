#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * make_empty_bit_set(int capacity)
{
  return (char*)malloc(capacity/8 + 1);

}

void add_to_set(char* s, int digit)
{
  s[digit >> 3] = s[digit >> 3] | (1 << (digit%8));
}

int is_in_set(char* s, int digit)
{
  return s[digit >> 3] & (1 << (digit%8));
}


int main()
{
  char *s = make_empty_bit_set(1029);

  add_to_set(s,75);
  printf("45 in set? %d\n", is_in_set(s,45));
  printf("75 in set? %d\n", is_in_set(s,75));

  return 0;
}
