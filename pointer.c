#include <stdio.h>

int main() {
  int n = 10;

  /* your code goes here */
  int * pointer_to_n = &n;
  *pointer_to_n += 1;
  /* testing code */
  if (pointer_to_n != &n) {
      printf("pointer is not equal to n");
      printf("pointer equals to %d", *pointer_to_n);
      return 1;}
  if (*pointer_to_n != 11) {
      printf("validated pointer is not equal to 11");
      return 1;}
  printf("pointer equals to %d\n", *pointer_to_n);
  printf("Done!\n");
  return 0;
}