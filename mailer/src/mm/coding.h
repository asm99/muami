/*
 * MELKONIAN Marc - 13410425
 * coding.h - General entry file for encoding/decoding strings
 * Date: 04 May 2015
 */

#define _GNU_SOURCE

#include <string.h>
#include <stdbool.h>
#include "debug.h"
#include "qp.h"

char* decode(char*, bool);
