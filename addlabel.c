#include "header.h"

void addLabel(char* label, word value) {
  int i;
  if (passNumber == 2) return;
  for (i=0; i<numLabels; i++)
    if (strcasecmp(label, labels[i]) == 0 &&
        strcasecmp(module, labelProcs[i]) == 0) {
      printf("***ERROR: Duplicate label: %s\n",label);
      printf("          %s\n",sourceLine);
      errors++;
      return;
      }
  numLabels++;
  if (numLabels == 1) {
    labels = (char**)malloc(sizeof(char*));
    labelValues = (word*)malloc(sizeof(word));
    labelProcs = (char**)malloc(sizeof(char*));
    }
  else {
    labels = (char**)realloc(labels, sizeof(char*) * numLabels);
    labelValues = (word*)realloc(labelValues, sizeof(word) * numLabels);
    labelProcs = (char**)realloc(labelProcs, sizeof(char*) * numLabels);
    }
  labels[numLabels-1] = (char*)malloc(strlen(label) + 1);
  strcpy(labels[numLabels-1], label);
  labelProcs[numLabels-1] = (char*)malloc(strlen(module) + 1);
  strcpy(labelProcs[numLabels-1], module);
  labelValues[numLabels-1] = value;
  }
