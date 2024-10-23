#include "header.h"

void processOption(char* option) {
  char def[256];
  char *equals;
    if (strcmp(option,"-1805") == 0) use1805 = -1;
    if (strcmp(option,"-b") == 0) outMode = 'B';
    if (strcmp(option,"-i") == 0) outMode = 'I';
    if (strcmp(option,"-r") == 0) outMode = 'R';
    if (strcmp(option,"-l") == 0) showList = -1;
    if (strcmp(option,"-L") == 0) createLst = -1;
    if (strcmp(option,"-s") == 0) showSymbols = -1;
    if (strcmp(option,"-e") == 0) useExtended = -1;
    if (strcmp(option,"-lf") == 0) strcpy(lineEnding,"\n");
    if (strcmp(option,"-cr") == 0) strcpy(lineEnding,"\r");
    if (strcmp(option,"-crlf") == 0) strcpy(lineEnding,"\r\n");
    if (strcmp(option,"-lfcr") == 0) strcpy(lineEnding,"\n\r");
    if (strncmp(option,"-D",2) == 0) {
      option += 2;
      strcpy(def,option);
      equals = strchr(def,'=');
      numClDefines++;
      if (numClDefines == 1) {
        clDefines = (char**)malloc(sizeof(char*));
        clDefineValues = (char**)malloc(sizeof(char*));
        }
      else {
        clDefines = (char**)realloc(clDefines,sizeof(char*)*numClDefines);
        clDefineValues = (char**)realloc(clDefineValues,sizeof(char*)*numClDefines);
        }
      if (equals != NULL) {
        *equals = 0;
        equals++;
        clDefines[numClDefines-1] = (char*)malloc(strlen(def)+1);
        clDefineValues[numClDefines-1] = (char*)malloc(strlen(equals)+1);
        strcpy(clDefines[numClDefines-1], def);
        strcpy(clDefineValues[numClDefines-1], equals);
        }
      else {
        clDefines[numClDefines-1] = (char*)malloc(strlen(option)+1);
        clDefineValues[numClDefines-1] = (char*)malloc(2);
        strcpy(clDefines[numClDefines-1], option);
        strcpy(clDefineValues[numClDefines-1], "1");
        }
      }
    if (strncmp(option,"-I",2) == 0) {
      option += 2;
      numIncPath++;
      if (numIncPath == 1) 
        incPath = (char**)malloc(sizeof(char*));
      else
        incPath = (char**)realloc(incPath,sizeof(char*)*numIncPath);
      incPath[numIncPath-1] = (char*)malloc(strlen(option)+1);
      strcpy(incPath[numIncPath-1], option);
printf("adding %s to include path\n",option);
      }

    if (strcmp(option,"-melf") == 0) {
      ramStart = 0x0000;
      ramEnd = 0x7fff;
      romStart = 0x8000;
      romEnd = 0xffff;
      }
    if (strcmp(option,"-pev") == 0) {
      ramStart = 0x0000;
      ramEnd = 0x7fff;
      romStart = 0x8000;
      romEnd = 0xffff;
      }
    if (strcmp(option,"-pev2") == 0) {
      ramStart = 0x0000;
      ramEnd = 0x7fff;
      romStart = 0x8000;
      romEnd = 0xffff;
      }
    if (strcmp(option,"-elf2k") == 0) {
      ramStart = 0x0000;
      ramEnd = 0x7fff;
      romStart = 0x8000;
      romEnd = 0xffff;
      }
    if (strcmp(option,"-mclo") == 0) {
      ramStart = 0x0000;
      ramEnd = 0x7fff;
      romStart = 0x8000;
      romEnd = 0xffff;
      }
    if (strcmp(option,"-mchi") == 0) {
      ramStart = 0x8000;
      ramEnd = 0xffff;
      romStart = 0x0000;
      romEnd = 0x7fff;
      }
    if (strcmp(option,"-mchip") == 0) {
      ramStart = 0x8000;
      ramEnd = 0xffff;
      romStart = 0x0000;
      romEnd = 0x7fff;
      }
    if (strncmp(option,"-ram=",5) == 0) processRAM(option+5);
    if (strncmp(option,"-rom=",5) == 0) processROM(option+5);
  }
