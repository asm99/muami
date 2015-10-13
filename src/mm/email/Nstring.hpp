/*
 * MELKONIAN Marc
 * IED 13410425
 * Nstring.hpp: A Nstring in the ABNF syntax of RFC 3501
 *
 * Doc: https://tools.ietf.org/html/rfc3501#section-9
 *
 * Grammar:
 * --------
 *
 *   nstring         = string / nil
 *
 *   nil             = "NIL"
 *
 *   literal         = "{" number "}" CRLF *CHAR8
 *                       ; Number represents the number of CHAR8s
 *
 *   number          = 1*DIGIT
 *                       ; Unsigned 32-bit integer
 *                       ; (0 <= n < 4,294,967,296)
 *
 *   quoted          = DQUOTE *QUOTED-CHAR DQUOTE
 *
 *   QUOTED-CHAR     = <any TEXT-CHAR except quoted-specials> /
 *                     "\" quoted-specials
 *
 *   quoted-specials = DQUOTE / "\"
 *
 *   TEXT-CHAR       = <any CHAR except CR and LF>
 */

#ifndef NSTRING_H
#define NSTRING_H

#include <sstream>
#include "../utils/util.hpp"

class Nstring
{
    private:
        string nstr;

    public:
        Nstring() {};
        ~Nstring() {};

        void set_str(const string& s);
        string str() const;

        Nstring& operator=(const Nstring& ns);
};

istream& operator>>(istream& is, Nstring& ns);

#endif /* end of include guard: NSTRING_H */
