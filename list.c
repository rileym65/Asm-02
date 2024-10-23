#include "header.h"

void list(char* message) {
  if (passNumber != 2) return;
  if (showList != 0) printf("%s",message);
  if ( createLst != 0) fprintf(lstFile, "%s",message);
  }
