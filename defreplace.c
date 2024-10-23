#include "header.h"

void defReplace(char* line) {
  char  buffer[1024];
  char *pchar;
  byte  flag;
  int i;
  for (i=0; i<numDefines; i++) {
    flag = 0xff;
    while (flag) {
      pchar = strstr(line, defines[i]);
      if (pchar == NULL) flag = 0;
      else if (isAlpha(*(pchar-1)) != 0 ||
               isAlpha(*(pchar+strlen(defines[i]))) != 0) flag = 0;
      if (flag) {
        strncpy(buffer,line,pchar-line);
        buffer[pchar-line] = 0;
        strcat(buffer,defineValues[i]);
        strcat(buffer,pchar+strlen(defines[i]));
        strcpy(line,buffer);
        }
      }
    }
  }
