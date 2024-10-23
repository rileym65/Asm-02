#include "header.h"

void addDefine(char* define, char* value) {
  int i;
  for (i=0; i<numDefines; i++)
    if (strcasecmp(define, defines[i]) == 0) {
      printf("***ERROR: Duplicate define: %s\n",define);
      errors++;
      return;
      }
  numDefines++;
  if (numDefines == 1) {
    defines = (char**)malloc(sizeof(char*));
    defineValues = (char**)malloc(sizeof(char*));
    }
  else {
    defines = (char**)realloc(defines, sizeof(char*) * numDefines);
    defineValues = (char**)realloc(defineValues, sizeof(char*) * numDefines);
    }
  defines[numDefines-1] = (char*)malloc(strlen(define) + 1);
  strcpy(defines[numDefines-1], define);
  defineValues[numDefines-1] = (char*)malloc(strlen(value) + 1);
  strcpy(defineValues[numDefines-1], value);
  }
