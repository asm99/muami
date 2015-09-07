/*
 * MELKONIAN Marc - 13410425
 * md5.cpp - MD5 encryption algorithm
 * Date: 04 August 2015
 */

#include "md5.hpp"

/* Encode a string to a MD5 hash string */
std::string
md5_encode(std::string s)
{
        unsigned char digest[MD5_DIGEST_LENGTH];
        MD5((unsigned char*)s.c_str(), s.length(), digest);

        /* As result is an integer representation of the hash, we need to
         * convert it to a string */
        char* md5[MD5_DIGEST_LENGTH*2+1];

        int i;
        for(i = 0; i < MD5_DIGEST_LENGTH; i++) {
                sprintf(&md5[i*2], "%02x", (unsigned int)digest[i]);
        }

        return md5;
}

#ifdef DEBUG
int
main()
{
        char* md5 = md5_encode("MELKONIAN Marc");
        std::cout << "md5: " << s << " => " << md5 << std::endl;
        return 0;
}
#endif
