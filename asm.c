/*
 *******************************************************************
 *** This software is copyright 2021 by Michael H Riley          ***
 *** You have permission to use, modify, copy, and distribute    ***
 *** this software so long as this copyright notice is retained. ***
 *** This software may not be used in commercial applications    ***
 *** without express written permission from the author.         ***
 *******************************************************************
*/

#include "header.h"

OPCODE opcodes[] = {
  { "adc",   OT_0ARG,   ADC   },
  { "adci",  OT_1ARG,   ADCI  },
  { "add",   OT_0ARG,   ADD   },
  { "adi",   OT_1ARG,   ADI   },
  { "and",   OT_0ARG,   AND   },
  { "ani",   OT_1ARG,   ANI   },
  { "b1",    OT_SBR,    B1    },
  { "b2",    OT_SBR,    B2    },
  { "b3",    OT_SBR,    B3    },
  { "b4",    OT_SBR,    B4    },
  { "bdf",   OT_SBR,    BDF   },
  { "bge",   OT_SBR,    BDF   },
  { "bpz",   OT_SBR,    BDF   },
  { "bn1",   OT_SBR,    BN1   },
  { "bn2",   OT_SBR,    BN2   },
  { "bn3",   OT_SBR,    BN3   },
  { "bn4",   OT_SBR,    BN4   },
  { "bnf",   OT_SBR,    BNF   },
  { "bl",    OT_SBR,    BNF   },
  { "bm",    OT_SBR,    BNF   },
  { "bnq",   OT_SBR,    BNQ   },
  { "bnz",   OT_SBR,    BNZ   },
  { "bq",    OT_SBR,    BQ    },
  { "br",    OT_SBR,    BR    },
  { "bz",    OT_SBR,    BZ    },
  { "db",    OT_DB,     'B'   },
  { "df",    OT_DF,     0     },
  { "dw",    OT_DB,     'W'   },
  { "dd",    OT_DB,     'D'   },
  { "ds",    OT_DS,     0     },
  { "dec",   OT_NARG,   DEC   },
  { "dis",   OT_0ARG,   DIS   },
  { "equ",   OT_EQU,    0     },
  { "ghi",   OT_NARG,   GHI   },
  { "glo",   OT_NARG,   GLO   },
  { "idl",   OT_0ARG,   IDL   },
  { "inc",   OT_NARG,   INC   },
  { "inp",   OT_NARG,   INP   },
  { "irx",   OT_0ARG,   IRX   },
  { "lda",   OT_NARG,   LDA   },
  { "lbdf",  OT_LBR,    LBDF  },
  { "lbnf",  OT_LBR,    LBNF  },
  { "lbnq",  OT_LBR,    LBNQ  },
  { "lbnz",  OT_LBR,    LBNZ  },
  { "lbq",   OT_LBR,    LBQ   },
  { "lbr",   OT_LBR,    LBR   },
  { "lbz",   OT_LBR,    LBZ   },
  { "ldi",   OT_1ARG,   LDI   },
  { "ldn",   OT_NARG,   LDN   },
  { "ldx",   OT_0ARG,   LDX   },
  { "ldxa",  OT_0ARG,   LDXA  },
  { "lsdf",  OT_0ARG,   LSDF  },
  { "lsie",  OT_0ARG,   LSIE  },
  { "lskp",  OT_0ARG,   NLBR  },
  { "lsnf",  OT_0ARG,   LSNF  },
  { "lsnq",  OT_0ARG,   LSNQ  },
  { "lsnz",  OT_0ARG,   LSNZ  },
  { "lsq",   OT_0ARG,   LSQ   },
  { "lsz",   OT_0ARG,   LSZ   },
  { "mark",  OT_0ARG,   MARK  },
  { "nbr",   OT_0ARG,   NBR   },
  { "nlbr",  OT_0ARG,   NLBR  },
  { "nop",   OT_0ARG,   NOP   },
  { "or",    OT_0ARG,   OR    },
  { "ori",   OT_1ARG,   ORI   },
  { "out",   OT_NARG,   OUT   },
  { "phi",   OT_NARG,   PHI   },
  { "plo",   OT_NARG,   PLO   },
  { "req",   OT_0ARG,   REQ   },
  { "ret",   OT_0ARG,   RET   },
  { "sav",   OT_0ARG,   SAV   },
  { "sd",    OT_0ARG,   SD    },
  { "sdb",   OT_0ARG,   SDB   },
  { "sdi",   OT_1ARG,   SDI   },
  { "sdbi",  OT_1ARG,   SDBI  },
  { "sep",   OT_NARG,   SEP   },
  { "seq",   OT_0ARG,   SEQ   },
  { "sex",   OT_NARG,   SEX   },
  { "shl",   OT_0ARG,   SHL   },
  { "shlc",  OT_0ARG,   SHLC  },
  { "rshl",  OT_0ARG,   SHLC  },
  { "shr",   OT_0ARG,   SHR   },
  { "shrc",  OT_0ARG,   SHRC  },
  { "rshr",  OT_0ARG,   SHRC  },
  { "skp",   OT_0ARG,   NBR   },
  { "sm",    OT_0ARG,   SM    },
  { "smb",   OT_0ARG,   SMB   },
  { "smbi",  OT_1ARG,   SMBI  },
  { "smi",   OT_1ARG,   SMI   },
  { "str",   OT_NARG,   STR   },
  { "stxd",  OT_0ARG,   STXD  },
  { "xor",   OT_0ARG,   XOR   },
  { "xri",   OT_1ARG,   XRI   },
  { "org",   OT_ORG,    0     },
  { "rldi",  OT_682ARG, 0xc0  },
  { "rlxa",  OT_68NARG, 0x60  },
  { "rsxd",  OT_68NARG, 0xa0  },
  { "dbnz",  OT_682ARG, 0x20  },
  { "rnx",   OT_68NARG, 0xb0  },
  { "dadd",  OT_680ARG, 0xf4  },
  { "dadi",  OT_681ARG, 0xfc  },
  { "dadc",  OT_680ARG, 0x74  },
  { "daci",  OT_681ARG, 0x7c  },
  { "dsm",   OT_680ARG, 0xf7  },
  { "dsmi",  OT_681ARG, 0xff  },
  { "dsmb",  OT_680ARG, 0x77  },
  { "dsbi",  OT_681ARG, 0x7f  },
  { "bci",   OT_681ARG, 0x3e  },
  { "bxi",   OT_681ARG, 0x3f  },
  { "ldc",   OT_680ARG, 0x06  },
  { "gec",   OT_680ARG, 0x08  },
  { "stpc",  OT_680ARG, 0x00  },
  { "dtc",   OT_680ARG, 0x01  },
  { "stm",   OT_680ARG, 0x07  },
  { "scm1",  OT_680ARG, 0x05  },
  { "scm2",  OT_680ARG, 0x03  },
  { "spm1",  OT_680ARG, 0x04  },
  { "spm2",  OT_680ARG, 0x02  },
  { "etq",   OT_680ARG, 0x09  },
  { "xie",   OT_680ARG, 0x0a  },
  { "xid",   OT_680ARG, 0x0b  },
  { "cie",   OT_680ARG, 0x0c  },
  { "cid",   OT_680ARG, 0x0d  },
  { "dsav",  OT_680ARG, 0x76  },
  { "scal",  OT_682ARG, 0x80  },
  { "sret",  OT_68NARG, 0x90  },
  { "end",   OT_END,    0x00  },
  { "public",OT_PUBLIC, 0x00  },
  { "extrn", OT_EXTRN,  0x00  },
  { "proc",  OT_PROC,   0x00  },
  { "endp",  OT_ENDP,   0x00  },
  { "ver",   OT_VER,    0x00  },
  { "ever",  OT_EVER,   0x00  },
  { "eever", OT_EEVER,  0x00  },
  { "",      0,         0     },
  };

void Asm(char* line) {
  int   pos;
  char  qt;
  char *orig;
  char  label[32];
  char  opcode[32];
  char  args[128];
  word  operands[32];
  char  operandsEType[32];
  int   operandsERef[32];
  byte  isreg[32];
  char  *opline;
  int   opcount;
  char *pargs;
  char  buffer[256];
  dword  value;
  int    macro;
  byte  flag;
  byte  c;
  int   i,j;
  byte  b;
  byte valid;
  char  lst[1024];
  usedReference = -1;
  orig = sourceLine;
  if (*line == '.') {
    sprintf(lst, "                  %s\n", orig);
    strcat(listLine, lst);
    list(listLine);
    if (strncasecmp(line,".align ",7) == 0) {
      if (passNumber == 2 && outCount > 0) writeOutput();
      outCount = 0;
      line += 7;
      line = trim(line);
      if (strncasecmp(line,"word",4) == 0) address = (address+1) & 0xfffe;
      if (strncasecmp(line,"dword",5) == 0) address = (address+3) & 0xfffc;
      if (strncasecmp(line,"qword",5) == 0) address = (address+7) & 0xfff8;
      if (strncasecmp(line,"para",4) == 0) address = (address+15) & 0xfff0;
      if (strncasecmp(line,"32",2) == 0) address = (address+31) & 0xffe0;
      if (strncasecmp(line,"64",2) == 0) address = (address+63) & 0xffc0;
      if (strncasecmp(line,"128",3) == 0) address = (address+127) & 0xff80;
      if (strncasecmp(line,"page",4) == 0) address = (address+255) & 0xff00;
      outAddress = address;
      return;
      }
    if (strncasecmp(line,".1805",5) == 0) {
      use1805 = 0xff;
      return;
      }
    if (strncasecmp(line,".list",5) == 0) {
      showList = 0xff;
      return;
       }
    if (strncasecmp(line,".sym",4) == 0) {
      showSymbols = 0xff;
      return;
      }
    if (strncasecmp(line,".op ",4) == 0) {
      compileOp(line+4);
      return;
      }
    if (strncasecmp(line,".intel",6) == 0) {
      outMode = 'I';
      return;
      }
    if (strncasecmp(line,".rcs",4) == 0) {
      outMode = 'R';
      return;
      }
    if (strncasecmp(line,".binary",7) == 0) {
      outMode = 'B';
      return;
      }
    if (strncasecmp(line,".arch=melf",10) == 0) {
      ramStart = 0x0000;
      ramEnd = 0x7fff;
      romStart = 0x8000;
      romEnd = 0xffff;
      }
    if (strncasecmp(line,".arch=pev",9) == 0) {
      ramStart = 0x0000;
      ramEnd = 0x7fff;
      romStart = 0x8000;
      romEnd = 0xffff;
      }
    if (strncasecmp(line,".arch=pev2",10) == 0) {
      ramStart = 0x0000;
      ramEnd = 0x7fff;
      romStart = 0x8000;
      romEnd = 0xffff;
      }
    if (strncasecmp(line,".arch=elf2k",11) == 0) {
      ramStart = 0x0000;
      ramEnd = 0x7fff;
      romStart = 0x8000;
      romEnd = 0xffff;
      }
    if (strncasecmp(line,".arch=mclo",10) == 0) {
      ramStart = 0x0000;
      ramEnd = 0x7fff;
      romStart = 0x8000;
      romEnd = 0xffff;
      }
    if (strncasecmp(line,".arch=mchi",10) == 0) {
      ramStart = 0x8000;
      ramEnd = 0xffff;
      romStart = 0x0000;
      romEnd = 0x7fff;
      }
    if (strncasecmp(line,".arch=mchip",11) == 0) {
      ramStart = 0x8000;
      ramEnd = 0xffff;
      romStart = 0x0000;
      romEnd = 0x7fff;
      }
    if (strncasecmp(line,".link ",6) == 0) {
      line += 6;
      while (*line == ' ' || *line == '\t') line++;
      if (passNumber == 2 && outMode == 'R') {
        sprintf(buffer,"%s\n",line);
        write(outFile, buffer, strlen(buffer));
        }
      return;
      }
    }

  if (strncasecmp(line,".suppress",9) == 0) {
    suppression = -1;
    return;
    }

  asmAddress = address;
  strcpy(label,"");
  strcpy(opcode,"");
  strcpy(args,"");
  if ((*line >= 'a' && *line <= 'z') ||
      (*line >= 'A' && *line <= 'Z')) {
    pos = 0;
    while ((*line >= 'a' && *line <= 'z') ||
           (*line >= 'A' && *line <= 'Z') ||
           (*line >= '0' && *line <= '9') ||
           *line == '_' || *line == '!' || *line == '$') {
      label[pos++] = *line++;
      }
    label[pos] = 0;
    if (*line != ':') {
      printf("***ERROR: Invalid label");
      printf("%s\n",orig);
      errors++;
      sprintf(lst, "%7s                   %s\n",lineNo(), orig); list(lst);
      return;
      }
    line++;
    }

  line = trim(line);
  if ((*line >= 'a' && *line <= 'z') ||
      (*line >= 'A' && *line <= 'Z')) {
    pos = 0;
    while ((*line >= 'a' && *line <= 'z') ||
           (*line >= 'A' && *line <= 'Z') ||
           (*line >= '0' && *line <= '9')) {
      opcode[pos++] = *line++;
      }
    opcode[pos] = 0;
    }
  line = trim(line);
  pos = 0;
  qt = 0;
  while (((qt == 0 && *line != ';') || qt) && *line != 0) {
    if (*line == '\'') qt = 1 - qt;
    args[pos++] = *line++;
    }
  args[pos] = 0;
  if (passNumber == 1 && strlen(label) > 0) {
    addLabel(label, address);
    }
  if (strlen(opcode) > 0) {
    macro = -1;
    if (passNumber == 2) {
      sprintf(buffer,"%04x: ",address);
      strcat(listLine, buffer);
      }

    lstCount = 0;
    i = 0;
    pos = -1;
    while (pos < 0 && opcodes[i].opcode[0] != 0) {
      if (strcasecmp(opcode, opcodes[i].opcode) == 0) pos = i;
      i++;
      }
    opline = trim(args);
    if (pos < 0 && numOps > 0) {
      opcount = 0;
      while (*opline != 0) {
        isreg[opcount] = isRReg(opline);
        opline = evaluate(opline, &value);
        operands[opcount++] = value;
        operandsEType[opcount-1] = ' ';
        if (usedReference >= 0) {
          operandsEType[opcount-1] = referenceType;
          operandsERef[opcount-1] = usedReference;
          }
        opline = trim(opline);
        if (*opline != 0 && *opline != ',') {
          printf("ERROR: Invalid operand list: %s\n",orig);
          exit(1);
          }
        if (*opline == ',') opline++;
        opline = trim(opline);
        }
      for (i=0; i<numOps; i++)
        if (strcasecmp(opcode, ops[i]) == 0 && strlen(arglist[i]) == opcount) {
          flag = 0xff;
          for (j=0; j<strlen(arglist[i]); j++) {
            if (arglist[i][j] == 'N' || arglist[i][j] == 'n')
              if (operands[j] > 15) flag = 0;
            if (arglist[i][j] == 'B' || arglist[i][j] == 'b')
              if (operands[j] > 255) flag = 0;
            if (arglist[i][j] == 'R' || arglist[i][j] == 'r')
              if (isreg[j] == 0 || operands[j] > 15) flag = 0;
            }
          if (flag) {
            macro = i;
            i = numOps+1; 
            }
          }
      }
    if (pos < 0 && macro == -1) {
      printf("***ERROR: Unknown opcode: %s\n",opcode);
      errors++;
      sprintf(lst, "%7s                   %s\n",lineNo(), orig); list(lst);
      return;
      }
    linesAssembled++;
    while (*args != 0 && args[strlen(args)-1] <= ' ')
      args[strlen(args)-1] = 0;
    if (macro >= 0) {
      b = 0;
      i = 0;
      valid = 0;
      while ((c = translation[macro][i]) != 0) {

        if (c == ' ') {
          if (valid) output(b);
          b = 0;
          valid = 0;
          }
        if (c >= '0' && c <='9') { b = (b << 4) | (c - '0'); valid = 0xff; }
        if (c >= 'A' && c <='F') { b = (b << 4) | (c - 55); valid = 0xff; }
        if (c >= 'a' && c <='f') { b = (b << 4) | (c - 87); valid = 0xff; }
        if (c == '$') {
          i++;
          c = translation[macro][i] - '1';
          b = (b << 4) | (operands[c] & 0xf);
          valid = 0xff;
          }

        if (c == 'w' || c == 'W') {
          i++;
           if (passNumber == 2 && usedLocal >= 0) {
             fixups[numFixups] = address;
             fixupTypes[numFixups] = 'W';
             numFixups++;
             }
          if (valid) output(b);
          c = translation[macro][i] - '1';
          if (passNumber == 2 && operandsEType[c] != ' ') {
            sprintf(buffer,"?%s %04x\n",labels[operandsERef[c]],address);
            write(outFile, buffer, strlen(buffer));
            }
          if (c >= 0 && c<= 9) {
            b = ((operands[c] >> 8) & 0xff);
            output(b);
            b = (operands[c] & 0xff);
            output(b);
            }
          valid = 0;
          }

        if (c == 'l' || c == 'L') {
          i++;
           if (passNumber == 2 && usedLocal >= 0) {
             fixups[numFixups] = address;
             fixupTypes[numFixups] = 'L';
             numFixups++;
             }
          if (valid) output(b);
          c = translation[macro][i] - '1';
          if (passNumber == 2 && operandsEType[c] != ' ') {
            sprintf(buffer,"\\%s %04x\n",labels[operandsERef[c]],address);
            write(outFile, buffer, strlen(buffer));
            }
          if (c >= 0 && c<= 9) b = (operands[c] & 0xff);
          valid = 0xff;
          }

        if (c == 'h' || c == 'H') {
          i++;
           if (passNumber == 2 && usedLocal >= 0) {
             fixups[numFixups] = address;
             fixupTypes[numFixups] = 'H';
             fixupLowOffset[numFixups] = ((operands[translation[macro][i] - '1'] & 0xff) - referenceLowOffset) & 0xff;
             numFixups++;
             }
          if (valid) output(b);
          c = translation[macro][i] - '1';
          if (passNumber == 2 && operandsEType[c] != ' ') {
            sprintf(buffer,"/%s %04x %02x\n",labels[operandsERef[c]],address,operands[c] & 0xff);
            write(outFile, buffer, strlen(buffer));
            }
          b = ((operands[c] >> 8) & 0xff);
          valid = 0xff;
          }
        i++;
        }
      if (valid) output(b);
      }
    else {
      switch (opcodes[pos].typ) {
        case OT_0ARG:
             if (strlen(args) > 0 && passNumber == 2) {
               printf("WARNING: %s does not take operands\n",opcodes[pos].opcode);
               }
             output(opcodes[pos].byte1);
             break;
        case OT_1ARG:
             output(opcodes[pos].byte1);
             output(processArgs(args) & 0xff);
             if (passNumber == 2 && usedReference >= 0) {
               if (referenceType == 'W' || referenceType == 'L')
                 sprintf(buffer,"\\%s %04x\n",labels[usedReference],address-1);
               else {
                 if (referenceLowOffset == 0)
                   sprintf(buffer,"/%s %04x\n",labels[usedReference],address-1);
                 else
                   sprintf(buffer,"/%s %04x %02x\n",labels[usedReference],address-1,referenceLowOffset);
                 }
               write(outFile, buffer, strlen(buffer));
               }
             if (passNumber == 2 && usedLocal >= 0) {
               fixups[numFixups] = address-1;
               fixupTypes[numFixups] = referenceType;
               if (referenceType == 'H')
                 fixupLowOffset[numFixups] = referenceLowOffset;
               else
                 fixupLowOffset[numFixups] = 0;
               numFixups++;
               }
             break;
        case OT_SBR:
             output(opcodes[pos].byte1);
             value = processArgs(args);
             if (passNumber == 2 && (value & 0xff00) != (address & 0xff00)) {
               if (fileNumber == 0)
                 printf("[%05d]: Short branch out of page\n",lineNumber[fileNumber]);
               else
                 printf("<%05d>: Short branch out of page\n",lineNumber[fileNumber]);
               errors++;
               }
             output(value & 0xff);
             if (passNumber == 2 && usedLocal >= 0) {
               fixups[numFixups] = address-1;
               fixupTypes[numFixups] = 'S';
               fixupLowOffset[numFixups] = 0;
               numFixups++;
               }
             break;
        case OT_NARG:
             output(opcodes[pos].byte1 | (processArgs(args) & 0xf));
             break;
        case OT_DB:
             processDb(args,opcodes[pos].byte1);
             break;
        case OT_DF:
             processDf(args);
             break;
        case OT_DS:
             processDs(processArgs(args));
             break;
        case OT_ORG:
             if (inProc == 0) {
               value = processArgs(args);
               processOrg(processArgs(args));
               }
             else {
               printf("!!!WARNING!!! ORG not allowed inside of PROC\n");
               }
             break;
        case OT_EQU:
             value = processArgs(args);
             setLabel(label, value);
             break;
        case OT_LBR:
             value = processArgs(args);
             output(opcodes[pos].byte1);
             if (passNumber == 2 && usedReference >= 0) {
               sprintf(buffer,"?%s %04x\n",labels[usedReference],address);
               write(outFile, buffer, strlen(buffer));
               }
             if (passNumber == 2 && usedLocal >= 0) {
               fixups[numFixups] = address;
               fixupTypes[numFixups] = referenceType;
               numFixups++;
               }
             output(value/256);
             output(value%256);
             break;
        case OT_680ARG:
             if (use1805 == 0) {
               printf("***ERROR: 1805 Instruction used while not in 1805 mode\n");
               errors++;
               }
             output(0x68);
             output(opcodes[pos].byte1);
             break;
        case OT_681ARG:
             if (use1805 == 0) {
               printf("***ERROR: 1805 Instruction used while not in 1805 mode\n");
               errors++;
               }
             output(0x68);
             output(opcodes[pos].byte1);
             output(processArgs(args) & 0xff);
             break;
        case OT_682ARG:
             if (use1805 == 0) {
               printf("***ERROR: 1805 Instruction used while not in 1805 mode\n");
               errors++;
               }
             output(0x68);
             pargs = evaluate(args, &value);
             output(opcodes[pos].byte1 | (value & 0xf));
             pargs = trim(pargs);
             if (*pargs == ',') {
               pargs++;
               pargs = trim(pargs);
               pargs = evaluate(pargs, &value);
               output((value & 0xff00) >> 8);
               output(value & 0xff);
               }
             else {
               printf("***ERROR: Missing argument\n");
               errors++;
               }
             break;
        case OT_68NARG:
             if (use1805 == 0) {
               printf("***ERROR: 1805 Instruction used while not in 1805 mode\n");
               errors++;
               }
             output(0x68);
             output(opcodes[pos].byte1 | (processArgs(args) & 0xf));
             break;
        case OT_END:
             if (passNumber == 1) {
               execAddr = processArgs(args) & 0xffff;
               }
             break;
        case OT_PUBLIC:
             if (passNumber == 2) {
               i = findLabel(args);
               if (i >= 0) {
                 if (outMode == 'R') {
                   sprintf(buffer,"=%s %04x\n",labels[i], labelValues[i]);
                   write(outFile, buffer, strlen(buffer));
                   }
                 }
               }
             break;
        case OT_EXTRN:
             if (passNumber == 1) {
               addLabel(args, 0);
               i = findLabel(args);
               numExternals++;
               if (numExternals == 1)
                 externals = (int*)malloc(sizeof(int));
               else
                 externals = (int*)realloc(externals,sizeof(int)*numExternals);
               externals[numExternals-1] = i;
               }
             break;
        case OT_PROC:
             inProc = -1;
             strcpy(module,args);
             if (passNumber == 2 && outCount > 0) {
               writeOutput();    
               outCount = 0;
               }
             address = 0;
             outAddress = 0;
             if (passNumber == 1) {
               addLabel(args, 0);
               }
             if (outMode == 'R' && passNumber == 2) {
               sprintf(buffer,"{%s\n",args);
               write(outFile, buffer, strlen(buffer));
               }
             numFixups = 0;
             break;
        case OT_ENDP:
             if (inProc == 0) {
               printf("***ERROR: ENDP encountered outside PROC\n");
               errors++;
               }
             if (passNumber == 2 && outCount > 0) {
               writeOutput();    
               outCount = 0;
               outAddress = address;
               }
             if (outMode == 'R' && passNumber == 2) {
               for (i=0; i<numFixups; i++) {
                 if (fixupTypes[i] == 'W')
                   sprintf(buffer,"+%04x\n",fixups[i]);
                 if (fixupTypes[i] == 'H') {
                   if (fixupLowOffset[i] != 0)
                     sprintf(buffer,"^%04x %02x\n",fixups[i],fixupLowOffset[i]);
                   else
                     sprintf(buffer,"^%04x\n",fixups[i]);
                   }
                 if (fixupTypes[i] == 'L')
                   sprintf(buffer,"v%04x\n",fixups[i]);
                 if (fixupTypes[i] == 'S')
                   sprintf(buffer,"$%04x\n",fixups[i]);
                 write(outFile, buffer, strlen(buffer));
                 }
               sprintf(buffer,"}\n");
               write(outFile, buffer, strlen(buffer));
               }
             inProc = 0;
             strcpy(module,"*");
             break;
        case OT_VER:
             output(buildMonth);
             output(buildDay);
             output((buildYear >> 8) & 0xff);
             output(buildYear & 0xff);
             break;
        case OT_EVER:
             output(buildMonth | 0x80);
             output(buildDay);
             output((buildYear >> 8) & 0xff);
             output(buildYear & 0xff);
             output((buildNumber >> 8) & 0xff);
             output(buildNumber & 0xff);
             break;
        case OT_EEVER:
             output(buildMonth | 0xc0);
             output(buildDay);
             output((buildYear >> 8) & 0xff);
             output(buildYear & 0xff);
             output(buildHour);
             output(buildMinute);
             output(buildSecond);
             output((buildNumber >> 8) & 0xff);
             output(buildNumber & 0xff);
             break;
        default:
             printf("***ERROR: Unknown instruction type: %d\n",opcodes[pos].typ);
             errors++;
             break;
        }
      }
    if (passNumber == 2) {
      while (lstCount < 4) {
        strcat(listLine, "   ");
        lstCount++;
        }
      strcat(listLine, sourceLine);
      strcat(listLine, "\n");
      list(listLine);
      }
    }
  else {
    sprintf(lst, "%7s                   %s\n",lineNo(), orig); list(lst);
    }
  }

