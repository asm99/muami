/*
 * MELKONIAN Marc - 13410425
 * helper.c - helpful set of functions to work with strings primarily
 * Date: 04 May 2015
 */

#include "helper.h"

/* static functions */
static char* reverse(char* s);

/* Return the highest number of two unsigned int */
unsigned int
uimin(unsigned int a, unsigned int b)
{
        return a > b ? b : a;
}

/* Count the number of occurences of a character in a string */
int
countcstr(char c, char* s)
{
        int count = 0;
        char* s_cpy = strdup(s);
        while(*s_cpy) {
                if (*s_cpy++ == c) {
                        count++;
                }
        }
        return count;
}

/*
 * Compute the number of digits of a positive number
 * tip: log(10^n) = n.log(10)
 * count_digits(10) => 2
 * count_digits(12345) => 5
 */
int
count_digits(int x)
{
        if (x == 0) {
                return 1;
        }

        x = x < 0 ? -x : x;  /* abs value */

        return log(x)/log(10) + 1;
}

/*
 * Extract length chars from string from start
 * substr("abcdef", 0, 0) => ""
 * substr("abcdef", 1, 3) => "bcd"
 * substr("abcdef", 4, 10) => "ef"
 * substr("abcdef", -1, -1) => NULL
 */
char*
substr(char* s, int start, int length)
{
        if (start < 0 || length < 0) {
                return NULL;
        }

        int len = strlen(s);
        int sz = len < length ? len : length;
        char* str = malloc(sz + 1);
        if (!str) {
                return NULL;
        }

        int i = 0;
        while (i < sz) {
                str[i] = s[start+i];
                i++;
        }

        str[sz] = '\0';
        return str;
}

/*
 * Find a position of a substring in a string
 * if substring is not found, return -1
 */
long int
strpos(char* haystack, char* needle)
{
        char* match = strcasestr(haystack, needle);
        if (!match) {
                return -1;
        }
        return match - haystack;
}

/* Strip occurences of a character off a string */
char*
strip_chr(char* src, char c)
{
       int count = countcstr(c, src);
       int srclen = strlen(src);
       char* dst = calloc(0, srclen - count + 1);

       int i, j = 0;
       for (i = 0; i < srclen; i++) {
               if (src[i] != c) {
                       dst[j++] = src[i];
               }
       }
       return dst;
}

/* Strip occurences of characters in a set off a string */
char*
strip_chars(char* src, char* set)
{
        int count = 0;
        char* set_cpy = strdup(set);
        while(*set_cpy) {
                count += countcstr(*set_cpy++, src);
        }

       int srclen = strlen(src);
       char* dst = calloc(srclen - count + 1, 1);

       int i, j = 0;
       for (i = 0; i < srclen; i++) {
               set_cpy = strdup(set);
               if (strchr(set_cpy, src[i]) == NULL) {
                       dst[j++] = src[i];
               }
               free(set_cpy);
       }
       return dst;
}

/* Split a string around a character into a NULL-terminated array */
char**
split_str(char* s, char delim)
{
        int count = countcstr(delim, s);
        char** arr = malloc(sizeof(char*) * count + 1);
        char* s_cpy = strdup(s);
        char* delim_s = calloc(0, 2);
        sprintf(delim_s, "%c", delim);

        int i, delimpos;
        char* subs;
        for (i = 0; i < count+1; i++) {
                delimpos = strpos(s_cpy, delim_s);
                if (delimpos == -1) {     /* last chunk */
                        subs = substr(s_cpy, 0, strlen(s_cpy));
                } else {
                        subs = substr(s_cpy, 0, delimpos);
                }

                arr[i] = strip_chars(subs, "(\")");
                free(subs);
                s_cpy += delimpos + 1;
        }
        arr[count+1] = '\0';
        return arr;
}

/*
 * Replace a string in a string by another string
 * str_replace("abcd", "b", "zz") => "azzcd"
 */
char*
str_replace(const char *s, const char *old_s, const char *new_s)
{
    char *ret;
    int i, count = 0;
    int newlen = strlen(new_s);
    int oldlen = strlen(old_s);

    for (i = 0; s[i] != '\0'; i++) {
        if (strstr(&s[i], old_s) == &s[i]) {
            count++;
            i += oldlen - 1;
        }
    }
    ret = (char *)malloc(i + count * (newlen - oldlen));
    if (!ret) {
            return NULL;
    }
    i = 0;
    while (*s) {
        if (strstr(s, old_s) == s) {/* compare the substring with the new one */
            strcpy(&ret[i], new_s);
            i += newlen; /* add newlength to the new string */
            s += oldlen; /* add the same old length the old string */
        } else {
                ret[i++] = *s++;
        }
    }
    ret[i] = '\0';
    return ret;
}

/*
 * Reverse a string
 * reverse("ABCD") => "DCBA"
 */
static char*
reverse(char* s)
{
        int slen = strlen(s);
        char* rev = malloc(slen + 1);
        int i, j;
        for (i = slen-1, j = 0; i > -1 ; i--, j++) {
                rev[j] = s[i];
        }
        return rev;
}

/*
 * Convert a number to its base36 representation
 * FIXME: char* res allocation size
 */
char*
to_base36(unsigned long num)
{
        const char base36symbols[] = "0123456789abcdefghijklmnopqrstuvwxyz";

        int base = 36;
        int mod;
        char* res;

        res = calloc(64, 1);
        if (!res) {
                return NULL;
        }

        char symbol[2];
        symbol[1] = '\0';

        do {
                mod = num % base;
                symbol[0] = base36symbols[mod];
                strncat(res, symbol, 1);
                num /= base;
        } while (num > 0);

        char* rev = reverse(res);
        free(res);

        return rev;
}

#ifdef DEBUG
/* Dump content of a NULL-terminated array of strings */
static void
dump_array(char** arr)
{
        while(*arr) {
                ttydebug("arr el: %s\n", *arr++);
        }
}

int
main()
{
        printf("uimin(0, 1): %d\n", uimin(0, 1));
        printf("uimin(7, 4): %d\n\n", uimin(7, 4));

        int nb[5] = { 0, 1, 123, 123456789, -123456789 };

        unsigned int i;
        for (i = 0; i < (sizeof nb)/(sizeof nb[0]); i++) {
                printf("count_digits(%d): %d\n", nb[i], count_digits(nb[i]));
        }

        puts("");

        char* strs[][2] = {
                { "abcd", "a" },
                { "abcd", "b" },
                { "abcd", "c" },
                { "abcd", "d" },
                { "abcd", "e" },
                { NULL, NULL }
        };

        for (i = 0; strs[i][0]; i++) {
                printf("strpos(\"%s\", \"%s\"): %ld\n",
                       strs[i][0], strs[i][1], strpos(strs[i][0], strs[i][1]));
        }

        char* s = "abcdef";
        int idx[5][2] = {
                {  0,  0 },
                {  0,  4 },
                {  1,  3 },
                {  4, 10 },
                { -1, 10 }
        };

        for (i = 0; i < (sizeof idx)/(sizeof idx[0]); i++) {
                printf("substr(\"%s\", %d, %d): %s\n",
                       s, idx[i][0], idx[i][1],
                       substr(s, idx[i][0], idx[i][1]));
        }

        puts("");

        char dot = '.';
        char* strings[] = { "1.2.3.4", "1234", "... ... ...", NULL };

        for (i = 0; strings[i]; i++) {
                printf("countcstr('%c', \"%s\") => %d\n",
                       dot, strings[i], countcstr(dot, strings[i]));
        }

        puts("");

        printf("strip_chr(\"1.2.3\", '.') => %s\n", strip_chr("1.2.3", '.'));
        printf("strip_chr(\"AbacAaaz\", 'a') => %s\n\n",
               strip_chr("AbacAaaz",'a'));
        printf("strip_chars(\"AbacCaCaa9dauciCaz\", \"aCi\") => %s\n\n",
               strip_chars("AbacCaCaa9dauciCaz","aCi"));

        char** arr =
                split_str("(\"charset\" \"UTF-8\" \"Param\" \"Value\")", ' ');
        dump_array(arr);
        free(arr);

        char* mystr = "ABCDEF";
        char* rev = reverse(mystr);
        printf("reverse: %s => %s\n\n", mystr, rev);
        free(rev);

        long int rand = random();
        char* b36 = to_base36(rand);
        printf("to_base36: %li => %s\n\n", rand, b36);
        free(b36);
        return 0;
}
#endif
