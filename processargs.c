#include "header.h"

dword processArgs(char* args) {
  dword result;
  args = evaluate(args, &result);
  return result;
  }
