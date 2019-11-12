#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include "random.h"

int rand_num() {
  int f = open("/dev/random",O_RDONLY);
  int i;
  read(f, &i,sizeof(i));

  if (errno) {
    printf("Error: %s\n", strerror(errno));
  }

  close(f);
  return i;
}
