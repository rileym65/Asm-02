#include "header.h"

int isExternal(int v) {
  int i;
  for (i=0; i<numExternals; i++)
    if (externals[i] == v) return v;
  return -1;
  }
