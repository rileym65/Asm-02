#include "header.h"

void compileOp(char* line) {
  char op[32];
  char args[32];
  char trans[1024];
  char *oline;
  int  pos;
  oline = line;
  line = trim(line);
  if (*line != '"') {
    printf("Invalid .op format: %s\n",oline);
    exit(1);
    }
  line++;
  line = trim(line);
  pos = 0;
  while (*line != '"' && *line != 0) {
    if ((*line >= 'a' && *line <= 'z') ||
        (*line >= 'A' && *line <= 'Z') ||
        (*line >= '0' && *line <= '9') ||
         *line == '_') {
      op[pos++] = *line++;
      }
    else {
      printf("Invalid character in opcode name: %s\n",oline);
      exit(1);
      }
    }
  op[pos] = 0;
  if (*line != '"') {
    printf("Invalid .op format: %s\n",oline);
    exit(1);
    }
  line++;
  line = trim(line);
  if (*line != ',') {
    printf("Invalid .op format: %s\n",oline);
    exit(1);
    }
  line++;
  line = trim(line);
  if (*line != '"') {
    printf("Invalid .op format: %s\n",oline);
    exit(1);
    }
  line++;
  pos = 0;
  while (*line == 'n' || *line == 'N' ||
         *line == 'b' || *line == 'B' ||
         *line == 'w' || *line == 'W' ||
         *line == 'r' || *line == 'R') {
    args[pos++] = *line++;
    }
  args[pos] = 0;
  if (*line != '"') {
    printf("Invalid .op format: %s\n",oline);
    exit(1);
    }
  line++;
  line = trim(line);
  if (*line != ',') {
    printf("Invalid .op format: %s\n",oline);
    exit(1);
    }
  line++;
  line = trim(line);
  if (*line != '"') {
    printf("Invalid .op format: %s\n",oline);
    exit(1);
    }
  line++;
  pos = 0;
  while (*line != '"' && *line != 0) {
    trans[pos++] = *line++;
    }
  trans[pos] = 0;
  if (*line != '"') {
    printf("Invalid .op format: %s\n",oline);
    exit(1);
    }
  numOps++;
  if (numOps == 1) {
    ops = (char**)malloc(sizeof(char*));
    arglist = (char**)malloc(sizeof(char*));
    translation = (char**)malloc(sizeof(char*));
    }
  else {
    ops = (char**)realloc(ops, sizeof(char*) * numOps);
    arglist = (char**)realloc(arglist, sizeof(char*) * numOps);
    translation = (char**)realloc(translation, sizeof(char*) * numOps);
    }
  ops[numOps-1] = (char*)malloc(strlen(op) + 1);
  strcpy(ops[numOps-1], op);
  arglist[numOps-1] = (char*)malloc(strlen(args) + 1);
  strcpy(arglist[numOps-1], args);
  translation[numOps-1] = (char*)malloc(strlen(trans) + 1);
  strcpy(translation[numOps-1], trans);
  }
