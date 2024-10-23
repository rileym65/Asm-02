#define MAIN

#include "header.h"

int main(int argc, char** argv) {
  int i;
  time_t tv;
  struct tm dt;
  printf("Asm/02 v%s\n",VERSION);
  printf("by Michael H. Riley\n");
  createLst = 0;
  outMode = 'R';
  ramStart = 0x0000;
  ramEnd = 0xffff;
  romStart = 0xffff;
  romEnd = 0xffff;
  showList = 0;
  showSymbols = 0;
  use1805 = 0;
  useExtended = 0;
  numSourceFiles = 0;
  numLabels = 0;
  numExternals = 0;
  numIncPath = 0;
  strcpy(lineEnding,"\n");
  tv = time(NULL);
  localtime_r(&tv, &dt);
  buildMonth = dt.tm_mon + 1;
  buildDay = dt.tm_mday;
  buildYear = dt.tm_year + 1900;
  buildHour = dt.tm_hour;
  buildMinute = dt.tm_min;
  buildSecond = dt.tm_sec;
  i = 1;
  while (i < argc) {
    if (argv[i][0] != '-') {
      numSourceFiles++;
      if (numSourceFiles == 0)
        sourceFiles = (char**)malloc(sizeof(char*));
      else
        sourceFiles = (char**)realloc(sourceFiles,sizeof(char*)*numSourceFiles);
      sourceFiles[numSourceFiles-1] = (char*)malloc(strlen(argv[i])+1);
      strcpy(sourceFiles[numSourceFiles-1], argv[i]);
      }
    else processOption(argv[i]);
    i++;
    }
  if (numSourceFiles == 0) {
    printf("No source files specified\n");
    exit(1);
    }
  for (i=0; i<numSourceFiles; i++)
    assembleFile(sourceFiles[i], argc, argv);
  if (errors > 0) return 1;
  return 0;
  }
