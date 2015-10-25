/*
 * MELKONIAN Marc - 13410425
 * base64.hpp - base64 encode/decode functions
 */

#ifndef BASE64_H
#define BASE64_H

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <openssl/evp.h>
#include <openssl/bio.h>
#include <openssl/buffer.h>

using namespace std;

namespace base64 {

    string to_base64(const string& s);
    string from_base64(string s);

} /* namespace base64 */

#endif /* end of include guard: BASE64_H */
