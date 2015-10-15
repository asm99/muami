/*
 * MELKONIAN Marc
 * IED 13410425
 * Body_params.hpp: body parameters within a BODY message
 *
 * Doc: https://tools.ietf.org/html/rfc3501#section-9
 *
 * Grammar:
 * -------
 *
 *  body-fld-param  = "(" string SP string *(SP string SP string) ")" / nil
 *
 */

#ifndef BODY_PARAMS_H
#define BODY_PARAMS_H

#include <iostream>
#include <sstream>
#include <map>
#include "../coding/coding.hpp"
#include "../debug/debug.hpp"
#include "../utils/util.hpp"

using namespace std;

class Body_params
{
    private:
        map<string, string> body_fld_param;

    public:
        Body_params(): body_fld_param() {};
        ~Body_params();

        bool is_nil();
        void add_param(const string& key, const string& value);
        string get_value(const string& key);
        void dump();
};

stringstream& operator>>(stringstream& ss, Body_params* bp);

#endif /* end of include guard: BODY_PARAMS_H */
