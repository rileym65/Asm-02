#include "header.h"

word getLabel(char* label) {
  int i;
  if (passNumber == 1) {
    for (i=0; i<numLabels; i++)
      if (strcasecmp(label, labels[i]) == 0 &&
          strcasecmp(module, labelProcs[i]) == 0)
        return labelValues[i];
    for (i=0; i<numLabels; i++)
      if (strcasecmp(label, labels[i]) == 0 &&
          (strcasecmp("*", labelProcs[i]) == 0 ||
           strcasecmp(" ", labelProcs[i]) == 0))
        return labelValues[i];
    return 0;
    }
  for (i=0; i<numLabels; i++)
    if (strcasecmp(label, labels[i]) == 0 &&
        strcasecmp(module, labelProcs[i]) == 0)
      return labelValues[i];
  for (i=0; i<numLabels; i++)
    if (strcasecmp(label, labels[i]) == 0 &&
        (strcasecmp(" ", labelProcs[i]) == 0 ||
         strcasecmp("*", labelProcs[i]) == 0))
      return labelValues[i];
  printf("***ERROR: Label not found: %s\n",label);
  printf("%s\n",sourceLine);
  errors++;
  return 0;
  }
