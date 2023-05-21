#include <stdio.h>
#include "catsandboxes.h"

int main(void) {

  printf("hello?\n");
  oi();
  startBox();
  for (int i = 0; i < NUMBER_OF_BOXES; i++) {
    bool b = isCatInBox(i);
    printf("%d - %s\n", i, b ? "true": "false");
  }

  return 0;
}