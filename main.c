#include <stdio.h>
#include <stdlib.h>
#include "catsandboxes.h"
#define DEFAULT_TIMES 10

int read_args(int argc, char **argv);
void checkAllBoxes(void);
bool checkMoving(void);

int main(int argc, char **argv)
{
  int total_times = read_args(argc, argv);
  startBox();
  for (int i = 0; i < total_times; i++)
  {
    // checkAllBoxes();
    if (checkMoving())
    {
      printf("achou %d\n", i);
      break;
    }
    moveCat();
  }

  return 0;
}

int read_args(int argc, char **argv)
{
  if (argc == 1)
    return DEFAULT_TIMES;
  else
  {
    int t = atoi(argv[1]);
    if (t == 0)
      return DEFAULT_TIMES;
    else
      return t;
  }
}

void checkAllBoxes(void)
{
  bool achou = false;
  for (int i = 0; i < NUMBER_OF_BOXES; i++)
  {
    bool b = isCatInBox(i);
    if (b)
    {
      achou = true;
      printf("=> %d\n", i);
    }
  }
  if (!achou)
    printf("não achou?");
}

bool checkMoving(void)
{
  static int currentBox = 0;
  printf("currentBox: %d\n", currentBox);
  if (isCatInBox(currentBox))
    return true;
  currentBox += 1;
  return false;
}
