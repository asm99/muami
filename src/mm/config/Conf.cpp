#include "Conf.hpp"

// Setters

void
Conf::set_in_server(const string& s)
{
	conf_in_server = s;
}

void
Conf::set_in_port(const string& s)
{
	conf_in_port = s;
}

void
Conf::set_smtp_server(const string& s)
{
	conf_smtp_server = s;
}

void
Conf::set_smtp_port(const string& s)
{
	conf_smtp_port = s;
}

void
Conf::set_from(const string& s)
{
	conf_from = s;
}

void
Conf::set_user(const string& s)
{
	conf_user = s;
}

void
Conf::set_pass(const string& s)
{
	conf_pass = s;
}

void
Conf::set_protocol(Email_Protocol ep)
{
    conf_protocol = ep;
}

// Getters

string
Conf::in_server() const
{
	return conf_in_server;
}

string
Conf::in_port() const
{
	return conf_in_port;
}

string
Conf::smtp_server() const
{
	return conf_smtp_server;
}

string
Conf::smtp_port() const
{
	return conf_smtp_port;
}

string
Conf::from() const
{
	return conf_from;
}

string
Conf::user() const
{
	return conf_user;
}

string
Conf::pass() const
{
	return conf_pass;
}

Email_Protocol
Conf::protocol() const
{
    return conf_protocol;
}


// DEBUG

void
Conf::dump() const
{
    cout << "--- Account ---\n"
         << "in_server  : " << in_server()   << endl
         << "in_port    : " << in_port()     << endl
         << "smtp_server: " << smtp_server() << endl
         << "smtp_port  : " << smtp_port()   << endl
         << "from       : " << from()        << endl
         << "user       : " << user()        << endl
         << "pass       : " << pass()        << endl;
}

