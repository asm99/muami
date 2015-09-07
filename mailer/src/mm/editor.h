/*
 * MELKONIAN Marc - 13410425
 * editor.h - Manage external editor to compose/reply to e-mails
 * Date: 04 May 2015
 */

#ifndef EDITOR_H
#define EDITOR_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "helper.h"
#include "imap_parser.h"

#define EMAIL_COMPOSE_SEPARATOR "---------"

char* compose_message(email* em);

#endif /* end of include guard: EDITOR_H */
