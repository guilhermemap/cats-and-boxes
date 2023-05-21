#include <stdio.h>
#include "catsandboxes.h"
#include <time.h>
#include <stdlib.h>


static int box;

void oi(void) {
  printf("oi!\n");
}

void startBox(void) {
  srand(time(NULL));   // Initialization, should only be called once.
  int r = rand();      // Returns a pseudo-random integer between 0 and RAND_MAX.
  printf("rand: %d\n", r);
  box = r % NUMBER_OF_BOXES;
}

bool isCatInBox(int guess) {
  return guess == box;
}