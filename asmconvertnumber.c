#include "header.h"

char* asm_convertNumber(char* buffer, dword* value, byte* success) {
  byte ishex;
  byte neg;
  dword val1,val2;
  ishex = 0;
  val1 = 0;
  val2 = 0;
  neg = 0;
  if (*buffer == '\'' && *(buffer+2) == '\'') {
    buffer++;
    *value = *buffer;
    buffer += 2;
    *success = 0xff;
    return buffer;
    }
  if (*buffer == '"' && *(buffer+2) == '"') {
    buffer++;
    *value = *buffer;
    buffer += 2;
    *success = 0xff;
    return buffer;
    }
  if (*buffer == '%') {
    buffer++;
    while (*buffer == '1' || *buffer == '0' || *buffer == '_') {
      if (*buffer != '_')
        val1 = (val1 << 1) | (*buffer - '0');
      buffer++;
      }
    *value = val1;
    *success = 0xff;
    return buffer;
    }
  if (*buffer == '$') {
    buffer++;
    if ((*buffer >= '0' && *buffer <= '9') ||
        (*buffer >= 'a' && *buffer <= 'f') ||
        (*buffer >= 'A' && *buffer <= 'F'))
      ishex = 0xff;
    else {
      *value = asmAddress;
      *success = 0xff;
      return buffer;
      }
    }
  if (*buffer == '-' && *(buffer+1) >= '0' && *(buffer+1) <= '9') {
    neg = 0xff;
    buffer++;
    }
  if (ishex == 0 && (*buffer < '0' || *buffer > '9')) {
    *success = 0;
    return buffer;
    }
  while ((*buffer >= '0' && *buffer <= '9') ||
         (*buffer >= 'a' && *buffer <= 'f') ||
         (*buffer >= 'A' && *buffer <= 'F')) {
      if (*buffer >= '0' && *buffer <= '9') {
        val1 = (val1 * 10) + (*buffer - '0');
        val2 = (val2 << 4) | (*buffer - '0');
        }
      if (*buffer >= 'a' && *buffer <= 'f')
        val2 = (val2 << 4) | (*buffer - 87);
      if (*buffer >= 'A' && *buffer <= 'F')
        val2 = (val2 << 4) | (*buffer - 55);
      buffer++;
    }
  if (*buffer == 'h' || *buffer == 'H') {
    ishex = 0xff;
    buffer++;
    }
  if (neg != 0) {
    val1 = (val1 ^ 0xffff) + 1;
    val2 = (val2 ^ 0xffff) + 1;
    }
  *success = 0xff;
  *value = (ishex != 0) ? val2 : val1;
  return buffer;
  }
