#include "Body_ext_mpart.hpp"

// Constructor
Body_ext_mpart::Body_ext_mpart()
{
    body_fld_param = new Body_params();
}

// Setters
void
Body_ext_mpart::set_dsp(const string& s)
{
	body_fld_dsp = s;
}

void
Body_ext_mpart::set_lang(const string& s)
{
	body_fld_lang = s;
}

void
Body_ext_mpart::set_loc(const string& s)
{
	body_fld_loc = s;
}

void
Body_ext_mpart::set_extension(const string& s)
{
    body_extension = s;
}

// Getters
string
Body_ext_mpart::dsp()
{
	return body_fld_dsp;
}

string
Body_ext_mpart::lang()
{
	return body_fld_lang;
}

string
Body_ext_mpart::loc()
{
	return body_fld_loc;
}

string
Body_ext_mpart::extension()
{
	return body_extension;
}

Body_params*
Body_ext_mpart::params()
{
    return body_fld_param;
}

// DEBUG
void
Body_ext_mpart::dump()
{
    cout << "+----------------+----------------" << endl
         << "|         body-ext-mpart          " << endl
         << "+----------------+----------------" << endl
         << "| body_fld_dsp   |" + dsp()		 << endl
         << "| body_fld_lang  |" + lang()	     << endl
         << "| body_fld_loc   |" + loc()		 << endl
         << "| body_extension |" + extension()	 << endl
         << "| body_fld_param | ";
    params()->dump();
}

// Operators overload
/*
 * FIXME: only "NIL)" is parsed correctly for body_extension
 *        (body_extension must be accepted as stated in the RFC3501)
 */
stringstream&
operator>>(stringstream& ss, Body_ext_mpart* bem)
{
    ss >> bem->params();

    int count = 0;
    size_t pos;   // ")(" pos
    string token;

    while (ss >> token) {
        if (count > 3) {
            break;
        }

        if ((pos = token.find(")(")) != string::npos) {
            ss.seekg(-(token.length() - pos) + 1, ss.cur);
            string tmp = token.substr(0, pos+1);
            token = tmp;
            break;
        }

        if (token.front() == 'N') {     // string is NIL
            if (token.back() == ')') {  // string is last fld
                break;
            }
            else  {
                count++;
                continue;
            }
        }

        switch (count) {
            case 0:
            case 1:
            case 3:
            {
                if (token.front() == '(') {  // body_fld_dsp is list, not NIL
                    string acc = token;
                    while (ss >> token) {
                        acc += token;
                        if (token.back() == ')') {
                            break;
                        }
                    }
                    if (count == 0)
                        bem->set_dsp(acc);
                    else if (count == 1)
                        bem->set_lang(acc);
                    else
                        bem->set_extension(acc);
                }
                else {
                    if (count == 0)
                        bem->set_dsp(token);
                    else if (count == 1)
                        bem->set_lang(token);
                    else
                        bem->set_extension(token);
                }
            }
            break;
            case 2:
                bem->set_loc(token);
            break;
            default:
            break;
        }

        count++;
    }

    return ss;
}
