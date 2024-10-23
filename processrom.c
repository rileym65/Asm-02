#include "header.h"

void processROM(char* buffer) {
  romStart = getHex(buffer);
  while (*buffer != '-' && *buffer != 0) buffer++;
  if (*buffer != '-') {
    printf("Invalid format for -rom\n");
    exit(1);
    }
  buffer++;
  romEnd = getHex(buffer);
  }
