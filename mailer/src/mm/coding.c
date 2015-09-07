/*
 * MELKONIAN Marc - 13410425
 * coding.c - General entry file for encoding/decoding strings
 * Date: 04 May 2015
 */

#include "coding.h"

/*
 * Find encoding of a string and decode it
 * TODO: implement decoding from qp, base64 and binary
 */
char*
decode(char* s, bool is_hdr)
{
        char* start;
        char* encoding;
        char* decoded = NULL;
        char* charset_opn = "=?"; /* charset start tag */
        char* charset_end = "?="; /* charset end tag */
        int charset_spos;
        int enc_endpos;

        if ((charset_spos = strpos(s, charset_opn)) >= 0) { /* charset */
                encoding = substr(s, 2,
                                  strpos(s+strlen(charset_opn), charset_end));
                enc_endpos = strpos(s, charset_end);
                start = substr(s, strlen(encoding)+5, enc_endpos);
        } else {
                start = strdup(s);
        }

        if ((start = strcasestr(s, "?Q?")) != NULL) {
                decoded = qp_decode(start+3, is_hdr);
        } else if ((start = strcasestr(s, "?B?")) != NULL) {
                /* decode from base64 */
        } else {
                return s;
        }

        return decoded;
}

#ifdef DEBUG
int
main()
{
        char* decoded;
        char* s[] = {
          "=?windows-1252?q?=a0jusqu'a_-50%*_sur_votre_prochain_voyage_par?=",
          "=?UTF-8?Q?Re=3A_Projet_tutor=C3=A9_L2?=",
          "=?UTF-8?Q?Re=3A_R=C3=A9seaux_=2F_m=2Dprojeval?=",
          NULL
        };

        int i;
        for (i = 0; s[i]; i++) {
                decoded = decode(s[i], true);
                printf("decode: %s => %s\n", s[i], decoded);
                free(decoded);
        }

        return 0;
}
#endif

