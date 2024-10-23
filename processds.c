#include "header.h"

void processDs(word arg) {
  address += arg;
  if (passNumber == 2 && outCount > 0) {
    writeOutput();
    }
  if (passNumber == 2) {
    sprintf(buffer,">%04x\n",arg);
    write(outFile, buffer, strlen(buffer));
    }
  outAddress = address;
  outCount = 0;
  }
