#include "catsandboxes.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>

static int box = -1;
static void startsrand(void);

static void startsrand(void)
{
  // Initialization, should only be called once.
  if (box == -1)
  {
    // unsigned int t = (unsigned int)time(NULL); // se programa é chamado num script num loop, pode ficar igual
    unsigned int t = (unsigned int)getpid(); // força cada chamada a ter um t diferente ao chamar por script
    // printf("srand: %d\n", t);

    srand(t);
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
  if (box == 0)
  {
    box = 1;
    return;
  }
  if (box == NUMBER_OF_BOXES - 1)
  {
    box -= 1;
    return;
  }
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
  box += step;
}