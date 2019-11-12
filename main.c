#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include "random.h"

int main() {

  printf("\n----------Random Numbers---------\n");
  int ary[10];
  int i = 0;
  for (i = 0; i<10; i++) {
    ary[i] = rand_num();
    printf("%d\n", ary[i]);
  }

  printf("\n......Writing to file...... \n");
  int file = open("rand_file", O_CREAT | O_WRONLY, 0644);
  write(file, ary, sizeof(ary));
  if (errno) {
    printf("Error: %s\n", strerror(errno));
  }
  close(file);

  printf("\n......Reading from file......\n");
  int ary2[10];
  file = open("rand_file", O_RDONLY);
  read(file, ary2, sizeof(ary2));
  if (errno) {
    printf("Error: %s\n", strerror(errno));
  }
  close(file);

  printf("\n----------Verifying values are the same----------\n");
  i = 0;
  for (i = 0; i < 10; i++) {
    printf("%d\n", ary2[i]);
  }
  return 0;
}
