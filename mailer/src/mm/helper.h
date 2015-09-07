/*
 * MELKONIAN Marc - 13410425
 * helper.h - helpful set of functions to work with strings primarily
 * Date: 04 May 2015
 */

#define _GNU_SOURCE  /* enable strncasecmp */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include "debug.h"

unsigned int uimin(unsigned int a, unsigned int b);
long int strpos(char* haystack, char* needle);
int    countcstr(char c, char* s);
int    count_digits(int x);
char*  substr(char* s, int start, int length);
char*  strip_chr(char* src, char c);
char*  strip_chars(char* src, char* set);
char** split_str(char* s, char delim);
char*  str_replace(const char *s, const char *old_s, const char *new_s);
char*  to_base36(unsigned long num);

