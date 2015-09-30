#include "Account.hpp"

// Setters

void
Account::set_id(const string& s)
{
	acc_id = s;
}

void
Account::set_imap(const string& s)
{
	acc_imap = s;
}

void
Account::set_iport(const string& s)
{
	acc_iport = s;
}

void
Account::set_smtp(const string& s)
{
	acc_smtp = s;
}

void
Account::set_sport(const string& s)
{
	acc_sport = s;
}

void
Account::set_from(const string& s)
{
	acc_from = s;
}

void
Account::set_user(const string& s)
{
	acc_user = s;
}

void
Account::set_pass(const string& s)
{
	acc_pass = s;
}

// Getters

string
Account::id()
{
	return acc_id;
}

string
Account::imap()
{
	return acc_imap;
}

string
Account::iport()
{
	return acc_iport;
}

string
Account::smtp()
{
	return acc_smtp;
}

string
Account::sport()
{
	return acc_sport;
}

string
Account::from()
{
	return acc_from;
}

string
Account::user()
{
	return acc_user;
}

string
Account::pass()
{
	return acc_pass;
}

// DEBUG

void
Account::dump()
{
    cout << "--- Account ---\n"
         << "id:    " << id()    << endl
         << "imap:  " << imap()  << endl
         << "iport: " << iport() << endl
         << "smtp:  " << smtp()  << endl
         << "sport: " << sport() << endl
         << "from:  " << from()  << endl
         << "user:  " << user()  << endl
         << "pass:  " << pass()  << endl;
}

