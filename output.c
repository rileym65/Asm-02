#include "header.h"

void output(byte value) {
  char tmp[4];
  if (compMode == 'A' && (address < ramStart || address > ramEnd)) {
    printf("***ERROR: Address exceeded available RAM");
    errors++;
    }
  if (compMode == 'O' && (address < romStart || address > romEnd)) {
    printf("***ERROR: Address exceeded available ROM");
    errors++;
    }
  if (passNumber == 1) {
    if (address > highest) highest = address;
    }
  if (passNumber == 2) {
    codeGenerated++;
    if (outMode == 'B') {
      if (address < lowAddress) lowAddress = address;
      if (address > highAddress) highAddress = address;
      memory[address] = value;
      }
    else {
      if (suppression == 0) {
        outBuffer[outCount++] = value;
        if (outCount == 16) {
          writeOutput();
          outCount = 0;
          outAddress = address+1;
          }
        }
      }
    if (createLst != 0 || showList != 0) {
      if (lstCount == 4) {
        strcat(listLine, "\n");
        list(listLine);
        strcpy(listLine,"              ");
        }
      else if (lstCount > 4 && (lstCount % 4) == 0) {
        strcat(listLine, "\n");
        list(listLine);
        strcpy(listLine,"              ");
        }
      sprintf(tmp, "%02x ", value);
      strcat(listLine, tmp);
      lstCount++;
      }
    }
  address++;
  }
