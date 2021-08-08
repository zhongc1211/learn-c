#include <stdio.h>
#include <assert.h>

/* Finish initializing the flags */

const short FLAG_ON          = 1 << 0; // 1  (0x01)
const short FLAG_MOVEMENT    = 1 << 1; // 2  (0x02)
const short FLAG_TRANSPARENT = 1 << 2; // 4  (0x04)
const short FLAG_ALIVE       = 1 << 3;
const short FLAG_BROKEN      = 1 << 4;
const short FLAG_EDIBLE      = 1 << 5; // 32 (0x20)

int main() {
  short attributes = 0;

  /* Set the attributes ON, TRANSPARENT, and BROKEN */
  attributes |= FLAG_ON;
  attributes |= FLAG_TRANSPARENT;
  attributes |= FLAG_BROKEN;
  assert(attributes == (FLAG_ON | FLAG_TRANSPARENT | FLAG_BROKEN));
  printf("1st assert done.\n");
  /* Modify (set/clear/toggle) so the only attributes are ON and ALIVE */
  
  attributes ~= FLAG_ON;
  attributes ~= FLAG_ALIVE;
  assert(attributes == (FLAG_ON | FLAG_ALIVE));
  printf("2nd assert done.\n");
  /* Check if the ALIVE flag is set */
  assert(FLAG_ALIVE);
  printf("3rd assert done.\nn");
  /* Check if the BROKEN flag is not set */
  assert(FLAG_BROKEN);
  printf("4th assert done.\n");
  /* Modify so only the EDIBLE attribute is set */

  assert(attributes == FLAG_EDIBLE);
  printf("5th assert done.");
  printf("Done!");
}