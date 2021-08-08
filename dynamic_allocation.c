#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int x;
  int y;
} point;

int main() {
  point * mypoint = (point *) malloc(sizeof(point));
  /* this does the same thing
  point * mypoint = malloc(sizeof(point));
  */

  /* Dynamically allocate a new point
     struct which mypoint points to here */

  mypoint->x = 10;
  mypoint->y =5 ;
  printf("mypoint coordinates: %d, %d\n", mypoint->x, mypoint->y);

  free(mypoint);

  /*
  Note that the free does not delete the myperson variable itself, it simply releases the data that it points to. 
  The myperson variable will still point to somewhere in the memory - but after calling myperson we are not allowed to access that area anymore. 
  We must not use that pointer again until we allocate new data using it.
  */

  int *n_pointer = malloc(sizeof(int));
  
  printf("This is n:%d\n", *n_pointer);
  printf("Goint to free n pointer\n");
  free(n_pointer);
  printf("Free n pointer done\n");
  printf("This is n:%d\n", *n_pointer);

  return 0;
}