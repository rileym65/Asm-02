#include "header.h"

char* lineNo() {
  static char buffer[10];
  if (fileNumber == 0) sprintf(buffer, "[%05d]",lineNumber[fileNumber]);
    else sprintf(buffer, "<%05d>",lineNumber[fileNumber]);
  return buffer;
  }
