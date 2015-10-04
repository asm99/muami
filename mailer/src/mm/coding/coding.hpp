/*
 * MELKONIAN Marc - 13410425
 * coding.hpp - MIME encoded-words
 * Date: 30 Sep 2015
 *
 * Grammar:
 * --------
 *
 *   encoded-word = "=?" charset "?" encoding "?" encoded-text "?="
 *
 *   charset = token    ; any valid IANA charset
 *
 *   encoding = token   ; "Q" or "B" (quoted-printable or base64)
 *
 *   token = 1*<Any CHAR except SPACE, CTLs, and especials>
 *
 *   especials = "(" / ")" / "<" / ">" / "@" / "," / ";" / ":" / "
 *               <"> / "/" / "[" / "]" / "?" / "." / "="
 *
 *   encoded-text = 1*<Any printable ASCII character other than "?"
 *                     or SPACE>
 *                  ; (but see "Use of encoded-words in message
 *                  ; headers", section 5)
 *
 */

#ifndef CODING_H
#define CODING_H

#include <iostream>
#include "base64.hpp"
#include "qp.hpp"

using namespace std;

enum class Encoding : char {
    ENC_7BIT = 0,
    ENC_8BIT,
    ENC_BINARY,
    ENC_BASE64,
    ENC_QUOTED_PRINTABLE,
};

string mmdecode(string s, bool is_hdr);

#endif /* end of include guard: CODING_H */
