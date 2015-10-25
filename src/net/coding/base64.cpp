#include "base64.hpp"

/* Encode from a human readable string to a base64 representation */
string
base64::to_base64(const string& s)
{
    int t;
	BIO* bmem = NULL;
	BIO* b64 = NULL;
	BUF_MEM* bptr = NULL;

	b64 = BIO_new(BIO_f_base64());
    BIO_set_flags(b64, BIO_FLAGS_BASE64_NO_NL); // no newlines
	bmem = BIO_new(BIO_s_mem());
	b64 = BIO_push(b64, bmem);
	BIO_write(b64, s.c_str(), s.length());
	t = BIO_flush(b64);
    if (t <= 0) {
        cerr << "error flushing b64." << endl;
    }
	BIO_get_mem_ptr(b64, &bptr);

	char* buff = (char*)malloc(bptr->length + 1);
    if (!buff) {
        cerr << "error: cannot malloc buff." << endl;
    }
	memcpy(buff, bptr->data, bptr->length);
	buff[bptr->length] = 0;

	BIO_free_all(b64);

	return buff;
}

/* Decode from a base64 representation to a human readable string */
string
base64::from_base64(string s)
{
	BIO* b64 = NULL;
	BIO* bmem = NULL;
    size_t length = s.length();
	char* buffer = (char*)malloc(length);
	memset(buffer, 0, length);

	b64 = BIO_new(BIO_f_base64());
    BIO_set_flags(b64, BIO_FLAGS_BASE64_NO_NL);
	bmem = BIO_new_mem_buf((void*)s.c_str(), length);
	bmem = BIO_push(b64, bmem);
	BIO_read(bmem, buffer, length);

	BIO_free_all(bmem);

	return buffer;
}

#ifdef BASE64_DEBUG

#include <map>

// Various test cases
int
main()
{
    map<string, string> m = {
        { "123456789", "MTIzNDU2Nzg5" },
        { "1234567890", "MTIzNDU2Nzg5MA==" },
        { "13410425@foad.iedparis8.net",
            "MTM0MTA0MjVAZm9hZC5pZWRwYXJpczgubmV0" },
        { "abcdefghi", "YWJjZGVmZ2hp" },
        { "A0b1C3d4", "QTBiMUMzZDQ=" },
        { "cet algorithme fonctionne-t-il ?",
            "Y2V0IGFsZ29yaXRobWUgZm9uY3Rpb25uZS10LWlsID8=" },
        { "=_test_!*@/-ésotériqueè?zZ^",
            "PV90ZXN0XyEqQC8tw6lzb3TDqXJpcXVlw6g/elpe" },
        { "", "5L2g5aW977yM5JWF6Z2i56qd" },
    };

    for (map<string, string>::const_iterator it = m.begin();
            it != m.end(); ++it) {
        string encoded = to_base64(it->first);
        if (encoded != it->second) {
            cerr << "Error encoding: " << it->first
                 << "\n  =>          " << encoded
                 << "\n  (should be: " << it->second << ")"
                 << endl;
        }
    }

    for (map<string, string>::const_iterator it = m.begin();
            it != m.end(); ++it) {
        string decoded = from_base64(it->second);
        if (decoded != it->first) {
            cerr << "Error decoding: " << it->second
                 << "\n  =>          " << decoded
                 << "\n  (should be: " << it->first << ")"
                 << endl;
        }
    }

    return 0;
}

#endif
