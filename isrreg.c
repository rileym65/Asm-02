#include "header.h"

int isRReg(char* line) {
  if (*line != 'r' && *line != 'R') return 0;
  line++;
  if ((*line >= '2' && *line <= '9') ||
      (*line >= 'a' && *line <= 'f') ||
      (*line >= 'A' && *line <= 'F')) {
    line++;
    if (*line >= '0' && *line <= '9') return 0;
    if (*line >= 'a' && *line <= 'z') return 0;
    if (*line >= 'A' && *line <= 'Z') return 0;
    return -1;
    }
  if (*line == '1') {
    line++;
    if (*line >= '0' && *line <= '5') {
      line++;
      if (*line >= '0' && *line <= '9') return 0;
      if (*line >= 'a' && *line <= 'z') return 0;
      if (*line >= 'A' && *line <= 'Z') return 0;
      return -1;
      }
    if (*line >= '0' && *line <= '9') return 0;
    if (*line >= 'a' && *line <= 'z') return 0;
    if (*line >= 'A' && *line <= 'Z') return 0;
    return -1;
    }
  return 0;
  }
