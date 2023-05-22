#include <stdio.h>
#include <stdlib.h>
#include "catsandboxes.h"
#define DEFAULT_TIMES 10

int read_args(int argc, char **argv);
void checkAllBoxes(void);
bool checkMoving(void);
bool checkMiddleAndBack(void);

int main(int argc, char **argv)
{
  bool achou = false;
  int total_times = read_args(argc, argv);
  startBox();
  int i = 0;
  for (; i < total_times; i++)
  {
    // checkAllBoxes();
    // if (checkMoving())
    if (checkMiddleAndBack())
    {
      printf("achou em %d tentativas\n", i + 1);
      achou = true;
      break;
    }
    moveCat();
  }

  return !achou;
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
  // printf("currentBox: %d\n", currentBox);
  if (isCatInBox(currentBox))
    return true;
  currentBox += 1;
  return false;
}

bool checkMiddleAndBack(void)
{
  // começa da segunda, vai até a penúltima, checa ela 2 vezes e depois volta
  static int currentBox = 1;
  static bool back = false;
  printf("currentBox: %d\n", currentBox);
  if (isCatInBox(currentBox))
  {
    printf("gato achado na currentBox: %d\n", currentBox);
    return true;
  }
  if (currentBox == NUMBER_OF_BOXES - 2 && !back)
  {
    back = true;
    return false;
  }
  if (back)
    currentBox -= 1;
  else
    currentBox += 1;
  return false;
}