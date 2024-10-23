#ifndef _HEADER_H
#define _HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>

#if defined(_WIN32) || defined(_WIN64)
#include <io.h>
#define strcasecmp _stricmp
#define strncasecmp _strnicmp
#define localtime_r(X,Y) (localtime_s(Y,X))
#else
#include <unistd.h>
#include <sys/time.h>
#define O_BINARY 0
#endif

#ifdef MAIN
#define LINK
#else
#define LINK extern
#endif

#define VERSION  "1.2"

typedef unsigned char byte;
typedef unsigned short word;
typedef unsigned int   dword;

#define IDL      0x00
#define LDN      0x00
#define INC      0x10
#define DEC      0x20
#define BR       0x30
#define BQ       0x31
#define BZ       0x32
#define BDF      0x33
#define B1       0x34
#define B2       0x35
#define B3       0x36
#define B4       0x37
#define NBR      0x38
#define BNQ      0x39
#define BNZ      0x3a
#define BNF      0x3b
#define BN1      0x3c
#define BN2      0x3d
#define BN3      0x3e
#define BN4      0x3f
#define LDA      0x40
#define STR      0x50
#define IRX      0x60
#define OUT      0x60
#define INP      0x68
#define RET      0x70
#define DIS      0x71
#define LDXA     0x72
#define STXD     0x73
#define ADC      0x74
#define SDB      0x75
#define SHRC     0x76
#define SMB      0x77
#define SAV      0x78
#define MARK     0x79
#define REQ      0x7a
#define SEQ      0x7b
#define ADCI     0x7c
#define SDBI     0x7d
#define SHLC     0x7e
#define SMBI     0x7f
#define GLO      0x80
#define GHI      0x90
#define PLO      0xa0
#define PHI      0xb0
#define LBR      0xc0
#define LBQ      0xc1
#define LBZ      0xc2
#define LBDF     0xc3
#define NOP      0xc4
#define LSNQ     0xc5
#define LSNZ     0xc6
#define LSNF     0xc7
#define NLBR     0xc8
#define LSKP     0xc8
#define LBNQ     0xc9
#define LBNZ     0xca
#define LBNF     0xcb
#define LSIE     0xcc
#define LSQ      0xcd
#define LSZ      0xce
#define LSDF     0xcf
#define SEP      0xd0
#define SEX      0xe0
#define LDX      0xf0
#define OR       0xf1
#define AND      0xf2
#define XOR      0xf3
#define ADD      0xf4
#define SD       0xf5
#define SHR      0xf6
#define SM       0xf7
#define LDI      0xf8
#define ORI      0xf9
#define ANI      0xfa
#define XRI      0xfb
#define ADI      0xfc
#define SDI      0xfd
#define SHL      0xfe
#define SMI      0xff
#define R0       0x00
#define R1       0x01
#define R2       0x02
#define R3       0x03
#define R4       0x04
#define R5       0x05
#define R6       0x06
#define R7       0x07
#define R8       0x08
#define R9       0x09
#define RA       0x0a
#define RB       0x0b
#define RC       0x0c
#define RD       0x0d
#define RE       0x0e
#define RF       0x0f

typedef struct {
  char opcode[8];
  byte typ;
  byte byte1;
  } OPCODE;

#define OT_0ARG    0
#define OT_1ARG    1
#define OT_LBR     2
#define OT_DB      3
#define OT_DS      4
#define OT_NARG    5
#define OT_EQU     6
#define OT_ORG     7
#define OT_680ARG  8
#define OT_681ARG  9
#define OT_68NARG 10
#define OT_682ARG 11
#define OT_END    12
#define OT_SBR    13
#define OT_MACRO  19
#define OT_PUBLIC 20
#define OT_EXTRN  21
#define OT_PROC   22
#define OT_ENDP   23
#define OT_VER    24
#define OT_EVER   25
#define OT_EEVER  26
#define OT_DF     27

#define OP_LOW  0x94
#define OP_HIGH 0x93
#define OP_SGN  0x92
#define OP_ABS  0x91
#define OP_DOT  0x80
#define OP_MUL  0x70
#define OP_DIV  0x71
#define OP_MOD  0x72
#define OP_ADD  0x60
#define OP_SUB  0x61
#define OP_SHR  0x50
#define OP_SHL  0x51
#define OP_AND  0x40
#define OP_OR   0x41
#define OP_XOR  0x42
#define OP_NOT  0x43
#define OP_EQ   0x30
#define OP_NE   0x31
#define OP_LT   0x32
#define OP_GT   0x33
#define OP_LTE  0x34
#define OP_GTE  0x35
#define OP_LAND 0x20
#define OP_LOR  0x21
#define OP_CP   0x10
#define OP_OP   0x02
#define OP_END  0x01
#define OP_NUM  0x00

typedef union {
  float f;
  dword i;
  } FTOI;

LINK char** defines;
LINK char** defineValues;
LINK int    numDefines;
LINK char** clDefines;
LINK char** clDefineValues;
LINK int    numClDefines;
LINK char** labels;
LINK char** labelProcs;
LINK word*  labelValues;
LINK char   module[128];
LINK int    numLabels;
LINK word   asmAddress;
LINK char   nests[10];
LINK int    numNests;
LINK char** ops;
LINK char** arglist;
LINK char** translation;
LINK int    numOps;
LINK int   *externals;
LINK int    numExternals;
LINK int    usedReference;
LINK char   referenceType;
LINK byte   referenceLowOffset;
LINK word   fixups[10000];
LINK char   fixupTypes[10000];
LINK byte   fixupLowOffset[10000];
LINK int    numFixups;
LINK int    usedLocal;

LINK word   address;
LINK int    asmFile;
LINK char   asmName[64];
LINK char   baseName[64];
LINK char   buffer[2048];
LINK int    buildMonth;
LINK int    buildDay;
LINK int    buildYear;
LINK int    buildHour;
LINK int    buildMinute;
LINK int    buildSecond;
LINK int    buildNumber;
LINK word   codeGenerated;
LINK char   compMode;
LINK char   createLst;
LINK int    errors;
LINK word   execAddr;
LINK word   highest;
LINK word   highAddress;
LINK char **incPath;
LINK int    numIncPath;
LINK int    inProc;
LINK char   lineEnding[3];
LINK int    linesAssembled;
LINK char   listLine[256];
LINK word   lowAddress;
LINK FILE  *lstFile;
LINK char   lstName[64];
LINK byte   memory[65536];
LINK word   outAddress;
LINK byte   outBuffer[16];
LINK byte   outCount;
LINK int    outFile;
LINK char   outMode;
LINK char   outName[64];
LINK int    passNumber;
LINK word   ramEnd;
LINK word   ramStart;
LINK word   romEnd;
LINK word   romStart;
LINK char   showAsm;
LINK char   showList;
LINK char   showSymbols;
LINK char **sourceFiles;
LINK int    suppression;
LINK int    numSourceFiles;
LINK char   use1805;
LINK byte   useAsm;
LINK byte   useExtended;
LINK char sourceLine[1024];
LINK word lstCount;


LINK FILE  *sourceFile[100];
LINK int    lineNumber[100];
LINK int    fileNumber;

extern void  addDefine(char* define, char* value);
extern void  addLabel(char* label, word value);
extern void  Asm(char* line);
extern char* asm_convertNumber(char* buffer, dword* value, byte* success);
extern void  assembleFile(char* sourceFile, int argc, char** argv);
extern void  clear();
extern void  compileOp(char* line);
extern void  defReplace(char* line);
extern void  delDefine(char* define);
extern char* evaluate(char *pos, dword* result);
extern char* findDefine(char* define);
extern int   findLabel(char* label);
extern word  getHex(char* line);
extern word  getLabel(char* label);
extern int   isAlpha(char c);
extern int   isExternal(int v);
extern int   isRReg(char* line);
extern char* lineNo();
extern void  list(char* message);
extern char* nextLine(char* line);
extern void  output(byte value);
extern int   pass(int p, char* srcFile);
extern dword processArgs(char* args);
extern void  processDb(char* args,char typ);
extern void  processDf(char* args);
extern void  processDs(word arg);
extern void  processOption(char* option);
extern void  processOrg(word arg);
extern void  processRAM(char* buffer);
extern void  processROM(char* buffer);
extern void  setLabel(char* label, word value);
extern char* trim(char* line);
extern void  writeOutput();


#endif
