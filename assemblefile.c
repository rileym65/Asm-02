#include "header.h"

void assembleFile(char* sourceFile, int argc, char** argv) {
  int i;
  char tmp[1024];
  FILE *buildFile;
  inProc = 0;
  numDefines = 0;
  errors = 0;
  numOps = 0;
  passNumber = 1;
  codeGenerated = 0;
  clear();
  strcpy(baseName, sourceFile);
  for (i=0; i<strlen(baseName); i++)
    if (baseName[i] == '.') baseName[i] = 0;
  strcpy(outName,baseName);
  switch (outMode) {
    case 'R': strcat(outName, ".prg"); break;
    case 'I': strcat(outName, ".hex"); break;
    case 'B': strcat(outName, ".bin"); break;
    }
  strcpy(lstName,baseName);
  strcat(lstName,".lst");

  strcpy(tmp, baseName);
  strcat(tmp,".build");
  buildFile = fopen(tmp, "r");
  if (buildFile == NULL) {
    buildNumber = 1;
    }
  else {
    fgets(buffer, 32, buildFile);
    buildNumber = atoi(buffer) + 1;
    fclose(buildFile);
    }
  buildFile = fopen(tmp,"w");
  fprintf(buildFile,"%d\n",buildNumber);
  fclose(buildFile);
  

//  for (i=0; i<argc; i++) {
//    if (strncmp(argv[i],"-D",2) == 0) {
//      addDefine(argv[i]+2,"1");
//      }
//    }

  for (i=0; i<numClDefines; i++)
    addDefine(clDefines[i], clDefineValues[i]);

  i = pass(1, sourceFile);
  numDefines = 0;
  if (i == 0 && errors == 0) {
//    for (i=0; i<argc; i++) {
//      if (strncmp(argv[i],"-D",2) == 0) {
//        addDefine(argv[i]+2,"1");
//        }
//      }
    for (i=0; i<numClDefines; i++)
      addDefine(clDefines[i], clDefineValues[i]);
    i = pass(2, sourceFile);
    if (outMode == 'B' && i == 0 && errors == 0) {
      outFile = open(outName,O_CREAT|O_TRUNC|O_WRONLY|O_BINARY,0666);
      if (outFile < 0) {
        printf("Could not open output file: %s\n",outName);
        exit(1);
        }
      write(outFile, memory+lowAddress, (highAddress-lowAddress) + 1);
      close(outFile);
      }
    }
  else printf("Errors during pass 1, aborting pass 2\n");

  printf("\n");
  printf("Lines Assembled   : %d\n",linesAssembled);
  printf("Code Generated    : %d\n",codeGenerated);
  printf("Errors            : %d\n",errors);
  printf("\n");

  if (showSymbols) {
    printf("Symbols:\n");
    for (i=22; i<numLabels; i++) {
      printf("  %04x  %-20s %-20s",labelValues[i],labels[i],labelProcs[i]);
      if (isExternal(i) >= 0) printf(" *");
      printf("\n");
      }
    }

  if (numLabels > 0) {
    for (i=0; i<numLabels; i++) {
      free(labels[i]);
      free(labelProcs[i]);
      }
    free(labels);
    free(labelValues);
    free(labelProcs);
    }
  if (errors > 0) exit(1);
  numLabels = 0;
  }
