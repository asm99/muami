#include "md5.hpp"

/* Encode a string to a MD5 hash string */
string
md5_encode(string s)
{
    unsigned char digest[MD5_DIGEST_LENGTH];
    MD5((unsigned char*)s.c_str(), s.length(), digest);

    /* As result is an integer representation of the hash, we need to
     * convert it to a string */
    char md5[MD5_DIGEST_LENGTH*2+1];

    for(int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        sprintf(&md5[i*2], "%02x", (unsigned int)digest[i]);
    }

    return md5;
}

#ifdef MD5_DEBUG

#include <map>

int
main()
{
    map<string, string> m = {
        { "Ceci est un test.", "ae4f19c5cc162906c5b14ec640c622b8" },
        { "bépoè^vdljQ*?;", "4b41d630a1a57163710859ab138b0fc7" },
    };

    for (map<string, string>::const_iterator it = m.begin();
            it != m.end(); ++it) {
        string md5 = md5_encode(it->first);
        if (md5 != it->second) {
            cerr << "Error in MD5 encoding for: " << it->first
                 << "\n  => " << md5
                 << "\n  (should be: " << it->second << ")"
                 << endl;
        }
    }

    return 0;
}
#endif
