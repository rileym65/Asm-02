#include "header.h"

int findLabel(char* label) {
  int i;
  if (passNumber == 1) {
    for (i=0; i<numLabels; i++)
      if (strcasecmp(label, labels[i]) == 0 &&
          strcasecmp(module, labelProcs[i]) == 0) {
        return i;
        }
    for (i=0; i<numLabels; i++)
      if (strcasecmp(label, labels[i]) == 0 &&
          (strcasecmp(" ", labelProcs[i]) == 0 ||
           strcasecmp("*", labelProcs[i]) == 0)) {
        return i;
        }
    return 0;
    }
  for (i=0; i<numLabels; i++)
    if (strcasecmp(label, labels[i]) == 0 &&
          strcasecmp(module, labelProcs[i]) == 0) {
      return i;
      }
  for (i=0; i<numLabels; i++)
    if (strcasecmp(label, labels[i]) == 0 &&
          (strcasecmp(" ", labelProcs[i]) == 0 ||
           strcasecmp("*", labelProcs[i]) == 0)) {
      return i;
      }
  printf("***ERROR: Label not found: %s\n",label);
  printf("%s\n",sourceLine);
  errors++;
  return -1;
  }
