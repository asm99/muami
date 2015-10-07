#include "util.hpp"

// From string "1.2.3" to vector of ints (1, 2, 3)
vector<int>
util::explode_to_ints(string s, const string& delim)
{
    string token;
    size_t pos;
    vector<int> vec {};

    while ((pos = s.find(delim)) != string::npos) {
        token = s.substr(0, pos);
        vec.push_back(stoi(token));
        s.erase(0, pos + delim.length());
    }
    vec.push_back(stoi(s));
    return vec;
}

// Strip chars of a set off a string
string
util::strip_chars(string& src, const string& set)
{
    string dst = src;
    for (unsigned int i = 0; i < set.length(); i++) {
        size_t pos = 0;
        while ((pos = dst.find(set[i])) != string::npos) {
            dst.erase(pos, 1);
        }
    }
    return dst;
}

/*
 * Compute the next section of a body based on wether its a child or a
 * sibling within a bodys prefix tree
 * Children/Siblings scheme (nested = child):
 * (((bp) (bp)) (bp))
 * |||    |     |
 * R12    3     4
 * R: root, 1:child of R, 2/3: siblings, 1/4: siblings
 */
string
util::get_new_section(string section, bool is_child)
{
    if (section == "0")
        return "1";

    if (is_child)
        return section + ".1";

    /* top level sibling, no dot in section */
    if (section.find(".") != string::npos
        || (!is_child && section.find(".") == string::npos))
        return to_string(stoi(section) + 1);

    vector<int> arr = util::explode_to_ints(section, ".");
    arr[arr.size()-1] = arr[arr.size()-1] + 1; // increment last section number

	stringstream ss;
	for (unsigned int i = 0; i < arr.size(); i++) {
		ss << arr[i];
        if (i != arr.size() -1)
            ss << ".";
	}
	string new_section = ss.str();
//     new_section[new_section.length()-1] = '\0'; /* delete trailing dot */
    new_section.back() = '\0'; /* delete trailing dot */
    return new_section;
}

/*
 * Count a body length
 * Note: by definition a body is contained inside parenthesis but fields
 * can also have parenthesis so we delimit a body only by the first and
 * last parenthesis (toplevel parenthesis)
 */
int
util::get_body_length(const string& s)
{
    int level = 0;
    unsigned int count;
    for (count = 0; count < s.length(); count++) {
        if (count != 0 && level == 0)
            break;


        if (s[count] == '(')
            level++;
        else if (s[count] == ')')
            level--;
    }
    return count;
}

// Split a string by a substring into a vector of strings
vector<string>
util::split_string(string src, const string& delim)
{
    vector<string> vec {};
    size_t pos = 0;
    string token;

    while ((pos = src.find(delim)) != string::npos) {
        token = src.substr(0, pos);
        vec.push_back(token);
        src.erase(0, pos + delim.length());
    }
    vec.push_back(src); // store remaining token or full src if delim not found

    return vec;
}

// Empty a nstring with the string "NIL"
void
util::nullify_string(string& s)
{
    if (s.length() == 3 && (s == "NIL" || s == "nil"))
        s.clear();
}

#ifdef UTIL_DEBUG

// Dummy class to test the strip_chars function
class TripleString {
    public:
        string start;       // initial string
        string set;         // chars to strip
        string expected;    // expected result

        TripleString(string st, string se, string ex)
            :start(st), set(se), expected(ex) {};
        ~TripleString() {};
};

// Print sections modification facility
void
print_before_after_section(bool is_child, string old)
{
	string new_s = util::get_new_section(old, is_child);
	cout << "section old, new => " << old << ", " << new_s << ", ";
	if (is_child) cout << "CHILD";
	else          cout << "SIBLING";
	cout << endl;
}

// Test various cases of sections labelling and nesting
int
main()
{
    // Sections numbers test
	print_before_after_section(true,  "1");
	print_before_after_section(true,  "1.2");
	print_before_after_section(false, "1");
	print_before_after_section(false, "1.2");
	print_before_after_section(false, "1.2.3");

    // Explode to ints test
    string s = "1.2.3";
    vector<int> ints = util::explode_to_ints(s, ".");
    cout << "explode_to_ints \"" << s << "\" =>\n";

    for (unsigned int i = 0; i < ints.size(); i++) {
        cout << ints[i] << endl;
    }

    // Strip chars test
    vector<TripleString*> *vec = new vector<TripleString*>();
    vec->push_back(new TripleString("abcabcabc", "a", "bcbcbc"));
    vec->push_back(new TripleString("abcabcabc", "bc", "aaa"));
    vec->push_back(new TripleString("abcabcabc", ",", "abcabcabc"));

    for (unsigned int i = 0; i < vec->size(); i++) {
        TripleString* ts = vec->at(i);
        if (util::strip_chars(ts->start, ts->set) != ts->expected) {
            cout << "Strip chars failed on test no " << i << endl;
        }
    }

    string bs = "(\"text\" \"plain\" (\"charset\" \"UTF-8\") NIL NIL \"7bit\" 12 2 NIL NIL NIL NIL))";
    cout << "bs length: " << util::get_body_length(bs)
         << " - bs.length(): " << bs.length() << endl;

    string to_split = "abc;.def;.ghi;jkl;.mno;pqr;.stu";
    string delim_s = ";.";
    vector<string> strs = util::split_string(to_split, delim_s);
    cout << "Splitting \"" << to_split << "\" by \"" << delim_s << "\": \n";
    for (auto s : strs) {
        cout << " | " << s;
    }
    cout << " |" << endl;

    vector<string> strv = { "abc", "NIL" };
    for (auto s : strv) {
        cout << s << " == nullify ==> ";
        util::nullify_string(s);
        cout << s << endl;
    }

    return 0;
}

#endif
