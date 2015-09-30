/*
 * MELKONIAN Marc - 13410425
 * qp.c - Encode/decode "quoted-printable" strings
 * Date: 04 May 2015
 */

#include "qp.h"

/*
 * Decode a quoted-printable string
 * FIXME: not implemented yet, just replacing underscores by spaces if
 *        the string is in a header
 */
char*
qp_decode(char* s, bool is_hdr)
{
        char* decoded = calloc(strlen(s) + 1, 1);
        if (!decoded) {
                return NULL;
        }

        char c;
        char* chunk;
        unsigned int i;
        int j = 0;
        for (i = 0; i < strlen(s); i++) {
                if (s[i] == '=') {
                        chunk = substr(s, i+1, i+2);
                        c = strtol(chunk, NULL, 16);
                        free(chunk);
                        i = i+2;
                        if (c < 32 || c == 127) {
                                continue;
                        }
                } else if (s[i] == '_' && is_hdr) {
                        c = ' ';
                } else {
                        c = s[i];
                }

                decoded[j] = c;
                j++;
        }
        return decoded;
}

/*
 * Encode a string into a quoted-printable string
 * TODO: not implemented yet
 */
char*
qp_encode(char* s)
{
        return s;
}

#ifdef DEBUG
int
main()
{
        char* s = "=A0Jusqu'a_-50%*_sur_votre_prochain_voyage_PARI?=";
        char* decoded = qp_decode(s, true);
        printf("quoted-printable: %s\n", s);
        printf("decoded         : %s\n", decoded);
        return 0;
}
#endif

