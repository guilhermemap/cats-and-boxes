#include "catsandboxes.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static int box = -1;
static void startsrand(void);

static void startsrand(void)
{
  // Initialization, should only be called once.
  if (box == -1)
  {
    srand((unsigned int)time(NULL));
  }
}

void startBox(void)
{
  startsrand();
  // Returns a pseudo-random integer between 0 and RAND_MAX.
  int r = rand();
  // printf("rand: %d\n", r);
  box = r % NUMBER_OF_BOXES;
}

bool isCatInBox(int guess)
{
  // printf("guess: %d, box: %d\n", guess, box);
  return guess == box;
}

void moveCat(void)
{
  startsrand();
  int right_left = rand() % 2 == 0;
  int step = 0;
  if (right_left)
  {
    step = 1;
  }
  else
  {
    step = -1;
  }
  box = (box + step) % NUMBER_OF_BOXES;
  if (box < 0)
    box = NUMBER_OF_BOXES - 1;
}