/*
 * MELKONIAN Marc - 13410425
 * qp.h - Encode/decode "quoted-printable" strings
 * Date: 04 May 2015
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "helper.h"

char* qp_decode(char* s, bool is_hdr);
char* qp_encode(char* s);
