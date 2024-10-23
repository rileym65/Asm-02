#include "header.h"

void processDf(char* args) {
  dword num;
  char buffer[256];
  int  pos;
  FTOI ftoi;
  args = trim(args);
  while (*args != 0) {
    pos = 0;
    while (*args > ' ' && *args != ',' && *args != ';') {
      buffer[pos++] = *args++;
      }
    buffer[pos] = 0;
    ftoi.f = atof(buffer);
    num = ftoi.i;
    output(((num & 0xff000000) >> 24) & 0xff);
    output(((num & 0x00ff0000) >> 16) & 0xff);
    output(((num & 0x0000FF00) >> 8) & 0xff);
    output(num & 0xff);
    args = trim(args);
    if (*args == ',') {
      args++;
      args = trim(args);
      }
    }
  }
