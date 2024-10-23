#include "header.h"

void processRAM(char* buffer) {
  ramStart = getHex(buffer);
  while (*buffer != '-' && *buffer != 0) buffer++;
  if (*buffer != '-') {
    printf("Invalid format for -ram\n");
    exit(1);
    }
  buffer++;
  ramEnd = getHex(buffer);
  }
