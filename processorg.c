#include "header.h"

void processOrg(word arg) {
  if (passNumber == 2 && outCount > 0) writeOutput();
  outCount = 0;
  address = arg;
  outAddress = address;
  }
