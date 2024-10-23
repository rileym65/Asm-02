#include "header.h"

void delDefine(char* define) {
  int pos;
  int i;
  pos = -1;
  for (i=0; i<numDefines; i++)
    if (strcasecmp(define, defines[i]) == 0) pos = i;
  if (pos < 0) return;
  free(defines[pos]);
  free(defineValues[pos]);
  for (i=pos; i<numDefines-1; i++) {
    defines[i] = defines[i+1];
    defineValues[i] = defineValues[i+1];
    }
  numDefines--;
  if (numDefines == 0) {
    free(defines);
    free(defineValues);
    }
  else {
    defines = (char**)realloc(defines, sizeof(char*) * numDefines);
    defineValues = (char**)realloc(defineValues, sizeof(char*) * numDefines);
    }
  }
