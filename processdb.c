#include "header.h"

void processDb(char* args,char typ) {
  dword num;
  char buffer[256];
  args = trim(args);
  while (*args != 0) {
    if (*args == '\'' && *(args+2) != '\'') {
      args++;
      while (*args != 0 && *args != '\'')
        output(*args++);
      if (*args == '\'') args++;
      }
    else if (*args == '"' && *(args+2) != '"') {
      args++;
      while (*args != 0 && *args != '"')
        output(*args++);
      if (*args == '"') args++;
      }
    else if (*args == '{') {
      args++;
      while (*args != 0 && *args != '{')
        output(*args++);
      if (*args == '{') args++;
      }
    else {
      args = evaluate(args, &num);
      if (typ == 'B') {
        if (passNumber == 2 && usedReference >= 0) {
          if (referenceType == 'W' || referenceType == 'L')
            sprintf(buffer,"\\%s %04x\n",labels[usedReference],address);
          else
            sprintf(buffer,"/%s %04x\n",labels[usedReference],address);
          write(outFile, buffer, strlen(buffer));
          }
        if (passNumber == 2 && usedLocal >= 0) {
          fixups[numFixups] = address;
          fixupTypes[numFixups] = referenceType;
          if (referenceType == 'H')
            fixupLowOffset[numFixups] = referenceLowOffset;
          else
            fixupLowOffset[numFixups] = 0;
          numFixups++;
          }
        output(num & 0xff);
        }
      else if (typ == 'W') {
        if (passNumber == 2 && usedReference >= 0) {
          sprintf(buffer,"?%s %04x\n",labels[usedReference],address);
          write(outFile, buffer, strlen(buffer));
          }
        if (passNumber == 2 && usedLocal >= 0) {
          fixups[numFixups] = address;
          fixupTypes[numFixups] = 'W';
          numFixups++;
          }
        output(((num & 0x0000FF00) >> 8) & 0xff);
        output(num & 0xff);
        }
      else {
        output(((num & 0xff000000) >> 24) & 0xff);
        output(((num & 0x00ff0000) >> 16) & 0xff);
        output(((num & 0x0000FF00) >> 8) & 0xff);
        output(num & 0xff);
        }
      }
    args = trim(args);
    if (*args == ',') {
      args++;
      args = trim(args);
      }
    }
  }
