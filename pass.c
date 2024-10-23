#include "header.h"

int pass(int p, char* srcFile) {
  int i;
  char buffer[256];
  suppression = 0;
  passNumber = p;
  address = 0;
  outCount = 0;
  numNests = 0;
  outAddress = 0;
  linesAssembled = 0;
  numFixups = 0;
  lowAddress = 0xffff;
  highAddress = 0x0000;
  strcpy(module,"*");
  fileNumber = 0;
  sourceFile[0] = fopen(srcFile,"r");
  if (sourceFile[0] == NULL) {
    printf("Could not open source file: %s\n",srcFile);
    exit(1);
    }
  lineNumber[0] = 0;
  if (passNumber == 2) {
      if (outMode != 'B') {
      outFile = open(outName,O_CREAT|O_TRUNC|O_WRONLY|O_BINARY,0666);
      if (outFile < 0) {
        printf("Could not open output file: %s\n",outName);
        exit(1);
        }
      if (outMode == 'R') {
        sprintf(buffer,".big\n");
        write(outFile, buffer, strlen(buffer));
        }
      }
    if (createLst) lstFile = fopen(lstName,"w");
    }
  nests[0] = 'Y';
  while (nextLine(buffer) != NULL) {
    for (i=0; i<strlen(buffer); i++)
      if (buffer[i] < 32 && buffer[i] != '\t') buffer[i] = 0;
    Asm(buffer);
    }
  fclose(sourceFile[0]);
  if (inProc) {
    printf("***ERROR: PROC without ENDP\n");
    errors++;
    }
  if (passNumber == 2 && outCount > 0) writeOutput();    
  if (passNumber == 2 && outMode != 'B') {
    //write EOF before closing intel hex file
    if (outMode == 'I') {
      write(outFile, ":00000001ff\n", 12);
      }
    if (outMode == 'R') {
      if (execAddr != 0xffff) {
        sprintf(buffer,"@%04x\n",execAddr);
        write(outFile, buffer, strlen(buffer));
        }
      }
    close(outFile); 
  }
  if (passNumber == 2 && createLst) fclose(lstFile);
  if (numNests > 0) printf("#ifdef without #endif\n");

  for (i=0; i<numDefines; i++)
    free(defines[i]);
  if (numDefines > 0) {
    free(defines);
    free(defineValues);
    }
  return 0;
  }
