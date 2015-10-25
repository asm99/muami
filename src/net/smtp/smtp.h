/*
 * MELKONIAN Marc - 13410425
 * smtp.h - Communication with SMTP server and related things
 * Date: 04 May 2015
 */

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include "config.h"
#include "ssl.h"
#include "smtp_parser.h"
#include "helper.h"
#include "debug.h"
#include "dateformat.h"
#include "md5.h"
#include "base64.h"

int   send_email(account* acc, newmessage* new_msg);
