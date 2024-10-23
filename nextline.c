#include "header.h"

char* nextLine(char* line) {
  char* ret;
  int   flag;
  char  buffer[1024];
  char  path[2048];
  int   pos;
  char *pchar;
  word  value;
  dword dvalue;
  int   i;
  flag = -1;
  while (flag) {
    ret = fgets(line, 1024, sourceFile[fileNumber]);
    if (ret != NULL) {
      while (strlen(ret) > 0 && line[strlen(ret)-1] <= ' ')
        line[strlen(ret)-1] = 0;
      strcpy(sourceLine, line);
      linesAssembled++;
      lineNumber[fileNumber]++;
      flag = 0;
      while (*ret == ' ') ret++;
      if (*ret == '#') {

        if (nests[numNests] != 'I') {

          if (nests[numNests] == 'Y') {

            if (strncmp(ret,"#include ",9) == 0) {
              ret += 9;
              while (*ret == ' ' || *ret == '\t') ret++;
              pos = 0;
              while (*ret != 0 && *ret > ' ')
                buffer[pos++] = *ret++;
              buffer[pos] = 0;
              fileNumber++;
              lineNumber[fileNumber] = 0;
              sourceFile[fileNumber] = fopen(buffer,"r");
              if (sourceFile[fileNumber] == NULL) {
                i = 0;
                while (i < numIncPath) {
                  strcpy(path, incPath[i]);
                  if (path[strlen(path)-1] != '/') strcat(path,"/");
                  strcat(path, buffer);
                  sourceFile[fileNumber] = fopen(path, "r");
                  if (sourceFile[fileNumber] != NULL) i = numIncPath;
                  i++;
                  }
                if (sourceFile[fileNumber] == NULL) {
                  printf("***ERROR: Could not open: %s\n",buffer);
                  errors++;
                  }
                }
              }

            if (strncmp(ret,"#define ",8) == 0) {
              ret += 8;
              while (*ret == ' ' || *ret == '\t') ret++;
              pos = 0;
              while (*ret != 0 && *ret > ' ')
                buffer[pos++] = *ret++;
              buffer[pos] = 0;
              while (*ret == ' ' || *ret == '\t') ret++;
              if (*ret == 0) addDefine(buffer,"1");
                else addDefine(buffer, ret);
              }

            if (strncasecmp(ret,"#error",6) == 0) {
              ret += 6;
              ret = trim(ret);
              printf("***ERROR: %s\n",ret);
              errors++;
              }

            if (strncasecmp(ret,"#undef",6) == 0) {
              ret += 6;
              ret = trim(ret);
              delDefine(ret);
              }

            }

          if (strncmp(ret,"#ifdef ",7) == 0) {
            if (nests[numNests] == 'N') {
              numNests++;
              nests[numNests] = 'I';
              }
            else {
              ret += 7;
              while (*ret == ' ' || *ret == '\t') ret++;
              pos = 0;
              while (*ret != 0 && *ret > ' ')
                buffer[pos++] = *ret++;
              buffer[pos] = 0;
              pchar = findDefine(buffer);
              numNests++;
              if (pchar != NULL) nests[numNests] = 'Y';
                else nests[numNests] = 'N';
              }
            }

          if (strncmp(ret,"#ifndef ",8) == 0) {
            if (nests[numNests] == 'N') {
              numNests++;
              nests[numNests] = 'I';
              }
            else {
              ret += 8;
              while (*ret == ' ' || *ret == '\t') ret++;
              pos = 0;
              while (*ret != 0 && *ret > ' ')
                buffer[pos++] = *ret++;
              buffer[pos] = 0;
              pchar = findDefine(buffer);
              numNests++;
              if (pchar != NULL) nests[numNests] = 'N';
                else nests[numNests] = 'Y';
              }
            }

          if (strncmp(ret,"#if ",4) == 0) {
            if (nests[numNests] == 'N') {
              numNests++;
              nests[numNests] = 'I';
              }
            else {
              ret += 4;
              while (*ret == ' ' || *ret == '\t') ret++;
              defReplace(ret);
              evaluate(ret, &dvalue);
              value = dvalue;
              numNests++;
              if (value != 0) nests[numNests] = 'Y';
                else nests[numNests] = 'N';
              }
            }

          if (strncmp(ret,"#else",5) == 0) {
            if (numNests > 0)
              nests[numNests] = (nests[numNests] == 'Y') ? 'N' : 'Y';
            else {
              printf("***Error: Unmatched #else\n");
              errors++;
              }
            }

          }

        if (strncmp(ret,"#endif",6) == 0) {
          if (numNests > 0) numNests--;
          else {
            printf("***Error: Unmatched #endif\n");
            errors++;
            }
          }

        if (nests[numNests] == 'Y') {
          if (fileNumber == 0)
            sprintf(listLine,"[%05d] ",lineNumber[fileNumber]);
          else
            sprintf(listLine,"<%05d> ",lineNumber[fileNumber]);
          while (strlen(listLine) < 24) strcat(listLine," ");
          strcat(listLine,"  ");
          strcat(listLine,sourceLine);
          if (passNumber == 2) {
            if (showList != 0) printf("%s\n",listLine);
            if (createLst != 0) fprintf(lstFile,"%s\n",listLine);
            }
          }

        flag = -1;
        }

      else if (nests[numNests] != 'Y') {
        flag = -1;
        }
      else {
        defReplace(ret);
        }
      }
    else {
      if (fileNumber == 0) flag = 0;
      else {
        fclose(sourceFile[fileNumber]);
        fileNumber--;
        flag = -1;
        }
      }
    }
  if (fileNumber == 0)
    sprintf(listLine,"[%05d] ",lineNumber[fileNumber]);
  else
    sprintf(listLine,"<%05d> ",lineNumber[fileNumber]);
  return ret;
  }
