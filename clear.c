#include "header.h"

void clear() {
  int i;
  if (numLabels != 0) {
    for (i=0; i<numLabels; i++) {
      free(labels[i]);
      free(labelProcs[i]);
      }
    free(labels);
    free(labelValues);
    free(labelProcs);
    }
  numLabels = 0;
  numExternals = 0;
  execAddr = 0xffff;
  strcpy(module," ");
  addLabel("r0",0);
  addLabel("r1",1);
  addLabel("r2",2);
  addLabel("r3",3);
  addLabel("r4",4);
  addLabel("r5",5);
  addLabel("r6",6);
  addLabel("r7",7);
  addLabel("r8",8);
  addLabel("r9",9);
  addLabel("r10",10);
  addLabel("r11",11);
  addLabel("r12",12);
  addLabel("r13",13);
  addLabel("r14",14);
  addLabel("r15",15);
  addLabel("ra",10);
  addLabel("rb",11);
  addLabel("rc",12);
  addLabel("rd",13);
  addLabel("re",14);
  addLabel("rf",15);
  }
