/*
 * MELKONIAN Marc - 13410425
 * md5.hpp - MD5 encryption algorithm
 * Date: 04 August 2015
 */

#ifndef MD5_H
#define MD5_H

#include <iostream>
#include <string>
#include <openssl/md5.h>

using namespace std;

string md5_encode(string s);

#endif /* end of include guard: MD5_H */
