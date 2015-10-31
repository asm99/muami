/*
 * MELKONIAN Marc - 13410425
 * qp.h - Encode/decode "quoted-printable" strings
 * Date: 04 May 2015
 *
 * Doc: http://tools.ietf.org/html/rfc1521#section-5.1
 *
 * Grammar:
 * --------
 *
 *    quoted-printable := ([*(ptext / SPACE / TAB) ptext] ["="] CRLF)
 *         ; Maximum line length of 76 characters excluding CRLF
 *
 *    ptext := octet /<any ASCII character except "=", SPACE, or TAB>
 *         ; characters not listed as "mail-safe" in Appendix B
 *         ; are also not recommended.
 *
 *    octet := "=" 2(DIGIT / "A" / "B" / "C" / "D" / "E" / "F")
 *         ; octet must be used for characters > 127, =, SPACE, or TAB,
 *         ; and is recommended for any characters not listed in
 *         ; Appendix B as "mail-safe".
 */

#ifndef QP_H
#define QP_H

#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

namespace qp {

    string decode(const string& s);
    string encode(string s);

} /* namespace qp */


#endif /* end of include guard: QP_H */
