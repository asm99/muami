#include "Body_ext_1part.hpp"

// Setters
void
Body_ext_1part::set_md5(const string& s)
{
	body_fld_md5 = s;
}

void
Body_ext_1part::set_dsp(const string& s)
{
	body_fld_dsp = s;
}

void
Body_ext_1part::set_lang(const string& s)
{
	body_fld_lang = s;
}

void
Body_ext_1part::set_loc(const string& s)
{
	body_fld_loc = s;
}

void
Body_ext_1part::set_extension(const string& s)
{
	body_extension = s;
}

// Getters
string
Body_ext_1part::md5()
{
	return body_fld_md5;
}

string
Body_ext_1part::dsp()
{
	return body_fld_dsp;
}

string
Body_ext_1part::lang()
{
	return body_fld_lang;
}

string
Body_ext_1part::loc()
{
	return body_fld_loc;
}

string
Body_ext_1part::extension()
{
	return body_extension;
}

// DEBUG
void
Body_ext_1part::dump()
{
    cout << "+----------------+----------------" << endl
         << "|         body-ext-1part          " << endl
         << "+----------------+----------------" << endl
         << "| body_fld_md5   |" + md5()		     << endl
         << "| body_fld_dsp   |" + dsp()		     << endl
         << "| body_fld_lang  |" + lang()	     << endl
         << "| body_fld_loc   |" + loc()		     << endl
         << "| body_extension |" + extension()	 << endl;
}

// Operators overload

/*
 * Parse fld into a Body_ext_1part*
 * Stops when, either:
 *  - flds count is reached,
 *  - ")(" is encountered in token
 *  - token is "N.*)"
 * FIXME: only "NIL)" is parsed correctly for body_extension
 *        (body_extension must be accepted as stated in the RFC3501)
 */
stringstream&
operator>>(stringstream& ss, Body_ext_1part* bep)
{
    string tok;
    size_t pos;  // ")(" pos
    int count = 0;

    while (ss >> tok) {
        if (count > 4) {
            break;
        }

        if ((pos = tok.find(")(")) != string::npos) {
            ss.seekg(-(tok.length() - pos) + 1, ss.cur);
            string tmp = tok.substr(0, pos+1);
            tok = tmp;
            break;
        }

        if (tok.front() == 'N') {     // string is NIL
            if (tok.back() == ')') {  // string is last fld
                break;
            }
            else  {
                count++;
                continue;
            }
        }

        switch (count) {
            case 0:
                bep->set_md5(tok);
            break;
            case 1:
            {
                if (tok.front() == '(') {  // body_fld_dsp is list, not NIL
                    string acc = tok;
                    while (ss >> tok) {
                        acc += tok;
                        if (tok.back() == ')') {
                            break;
                        }
                    }
                    bep->set_dsp(acc);
                }
                else {
                    bep->set_dsp(tok);
                }
            }
            break;
            case 2:
                bep->set_lang(tok);
            break;
            case 3:
            {
                bep->set_loc(tok);
            }
            break;
            case 4:
                bep->set_extension(tok);
            break;
            default:
            break;
        }

        count++;
    }

    return ss;
}

