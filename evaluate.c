#include "header.h"

char* evaluate(char *pos, dword* result) {
  int i;
  int numbers[256];
  byte ops[256];
  int  nstack;
  int  ostack;
  int  op;
  int  flag;
  int  p;
  char term;
  byte success;
  dword number;
  char token[64];
  nstack = 0;
  ostack = 0;
  op = 0;
  usedReference = -1;
  usedLocal = -1;
  while (*pos  != 0 && op != OP_END) {

    flag = -1;
    while (flag) {
      flag = 0;
      if (*pos == '(') {
        ops[ostack++] = OP_OP;
        flag = -1;
        }
      else if (strncasecmp(pos, "abs(", 4) == 0) {
        ops[ostack++] = OP_ABS;
        ops[ostack++] = OP_OP;
        pos += 3;
        flag = -1;
        }
      else if (strncasecmp(pos, "sgn(", 4) == 0) {
        ops[ostack++] = OP_SGN;
        ops[ostack++] = OP_OP;
        pos += 3;
        flag = -1;
        }
      else if (strncasecmp(pos, "high ", 5) == 0) {
        ops[ostack++] = OP_HIGH;
        pos += 3;
        flag = -1;
        }
      else if (strncasecmp(pos, "low ", 4) == 0) {
        ops[ostack++] = OP_LOW;
        pos += 2;
        flag = -1;
        }
      else if (strncasecmp(pos, "[month]", 7) == 0) {
        pos += 6;
        numbers[nstack++] = buildMonth;
        }
      else if (strncasecmp(pos, "[day]", 5) == 0) {
        pos += 4;
        numbers[nstack++] = buildDay;
        }
      else if (strncasecmp(pos, "[year]", 6) == 0) {
        pos += 5;
        numbers[nstack++] = buildYear;
        }
      else if (strncasecmp(pos, "[hour]", 6) == 0) {
        pos += 5;
        numbers[nstack++] = buildHour;
        }
      else if (strncasecmp(pos, "[minute]", 8) == 0) {
        pos += 7;
        numbers[nstack++] = buildMinute;
        }
      else if (strncasecmp(pos, "[second]", 8) == 0) {
        pos += 7;
        numbers[nstack++] = buildSecond;
        }
      else if (strncasecmp(pos, "[build]", 7) == 0) {
        pos += 6;
        numbers[nstack++] = buildNumber;
        }

      else {
        term = 0;
        pos = asm_convertNumber(pos, &number, &success);
        if (success != 0) {
          numbers[nstack++] = number;
          term = -1;
          pos--;
          }

        if (term == 0) {
          if ((*pos >= 'a' && *pos <= 'z') ||
              (*pos >= 'A' && *pos <= 'Z')) {
            p = 0;
            while ((*pos >= 'a' && *pos <= 'z') ||
                   (*pos >= 'A' && *pos <= 'Z') ||
                   (*pos >= '0' && *pos <= '9') ||
                    *pos == '_' || *pos == '!' || *pos == '$') {
              token[p++] = *pos++;
              }
            token[p] = 0;
            numbers[nstack++] = getLabel(token);
            term = -1;
            pos--;
            i = findLabel(token);
            if (i >= 0) {
              usedReference = isExternal(i);
              if (usedReference >= 0) {
                referenceType = 'W';
                referenceLowOffset = labelValues[i] & 0xff;
                }
              else if (inProc != 0 && strcasecmp(labelProcs[i],module) == 0) {
                 usedLocal = 1;
                 referenceType = 'W';
                 referenceLowOffset = labelValues[i] & 0xff;
                 }
              }
            }
          }
        if (term == 0) {
          printf("Non-number found\n");
          printf("  %s\n",sourceLine);
          return 0;
          }
        }

      if (*pos != 0) pos++;
      pos = trim(pos);
      }
    flag = -1;
    while (flag) {
      flag = 0;
      op = 0;
      switch (*pos) {
        case 0  : op = OP_END; break;
        case ',': op = OP_END; break;
        case '.': op = OP_DOT; break;
        case '*': op = OP_MUL; break;
        case '/': op = OP_DIV; break;
        case '%': op = OP_MOD; break;
        case '+': op = OP_ADD; break;
        case '-': op = OP_SUB; break;
        case '^': op = OP_XOR; break;
        case ')': op = OP_CP ; break;
        case '&':
             if (*(pos+1) == '&') { op = OP_LAND; pos++; }
               else op = OP_AND;
             break;
        case '|':
             if (*(pos+1) == '|') { op = OP_LOR; pos++; }
               else op = OP_OR;
             break;
        case '=':
             if (*(pos+1) == '=') { op = OP_EQ; pos++; }
               else op = OP_EQ;
             break;
        case '!':
             if (*(pos+1) == '=') { op = OP_NE; pos++; }
             else op = OP_NOT;
             break;
        case '<':
             if (*(pos+1) == '<') { op = OP_SHL; pos++; }
             else if (*(pos+1) == '=') { op = OP_LTE; pos++; }
             else op = OP_LT;
             break;
        case '>':
             if (*(pos+1) == '>') { op = OP_SHR; pos++; }
             else if (*(pos+1) == '=') { op = OP_GTE; pos++; }
             else op = OP_GT;
             break;
        }
      if (op == 0) { printf("Invalid OP %c (%02x)\n",*pos, *pos); return 0; }
      while (ostack > 0 && (ops[ostack-1] & 0xf0) >= (op & 0xf0)) {
        nstack--;
        ostack--;
        switch (ops[ostack]) {
          case OP_MUL : numbers[nstack-1] *= numbers[nstack]; break;
          case OP_DIV : numbers[nstack-1] /= numbers[nstack]; break;
          case OP_MOD : numbers[nstack-1] %= numbers[nstack]; break;
          case OP_ADD : numbers[nstack-1] += numbers[nstack]; break;
          case OP_SUB : numbers[nstack-1] -= numbers[nstack]; break;
          case OP_SHL : numbers[nstack-1] <<= numbers[nstack]; break;
          case OP_SHR : numbers[nstack-1] >>= numbers[nstack]; break;
          case OP_AND : numbers[nstack-1] &= numbers[nstack]; break;
          case OP_OR  : numbers[nstack-1] |= numbers[nstack]; break;
          case OP_NOT : numbers[nstack] = !numbers[nstack]; break;
          case OP_LAND: numbers[nstack-1] &= numbers[nstack]; break;
          case OP_LOR : numbers[nstack-1] |= numbers[nstack]; break;
          case OP_XOR : numbers[nstack-1] ^= numbers[nstack]; break;
          case OP_EQ  : numbers[nstack-1] = (numbers[nstack-1] == numbers[nstack]); break;
          case OP_NE  : numbers[nstack-1] = (numbers[nstack-1] != numbers[nstack]); break;
          case OP_LT  : numbers[nstack-1] = (numbers[nstack-1] <  numbers[nstack]); break;
          case OP_GT  : numbers[nstack-1] = (numbers[nstack-1] >  numbers[nstack]); break;
          case OP_LTE : numbers[nstack-1] = (numbers[nstack-1] <= numbers[nstack]); break;
          case OP_GTE : numbers[nstack-1] = (numbers[nstack-1] >= numbers[nstack]); break;
          case OP_ABS : numbers[nstack]   = abs(numbers[nstack]); break;
          case OP_HIGH:
               numbers[nstack]   = (numbers[nstack] >> 8) & 0xff;
               referenceType = 'H';
               break;
          case OP_LOW :
               numbers[nstack]   = numbers[nstack] & 0xff;
               referenceType = 'L';
               break;
          case OP_DOT :
               if (numbers[nstack] & 1) {
                 numbers[nstack-1] = (numbers[nstack-1] >> 8) & 0xff;
                 referenceType = 'H';
                 }
               else {
                 numbers[nstack-1] = numbers[nstack-1] & 0xff;
                 referenceType = 'L';
                 }
               break;
          case OP_SGN:
               if (numbers[nstack] > 0) numbers[nstack] = 1;
               else if (numbers[nstack] < 0) numbers[nstack] = -1;
               else numbers[nstack] = 0;
               break;
          }
        if (ops[ostack] >= 0x90) nstack++;
        }
      if (op != OP_END) {
        if (op == OP_CP) {
          if (usedLocal >= 0 || usedReference >= 0) 
            referenceLowOffset = numbers[nstack-1] & 0xff;
          if (ops[ostack-1] != OP_OP) {
            printf("Expression error, ) without (\n");
            return 0;
            }
          ostack--;
          flag = -1;
          }
        else
          ops[ostack++] = op;
        pos++;
        while (*pos == ' ') pos++;
        pos = trim(pos);
        }
      }
    }
  if (nstack == 0) { printf("nstack empty\n"); return pos; }
  if (nstack != 1) {
     printf("Did not reduce to 1 term: %d\n",nstack);
     return pos;
     }
  *result = numbers[0];
  return pos;
  }
