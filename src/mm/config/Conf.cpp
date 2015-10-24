#include "Conf.hpp"

bool
Conf::is_complete() const
{
    if (   conf_in_server.empty()
        || conf_in_port.empty()
        || conf_smtp_server.empty()
        || conf_smtp_port.empty()
        || conf_from.empty()
        || conf_user.empty()
        || conf_pass.empty()
        || conf_protocol == PROTOCOL_UNDEFINED)
    {
        return false;
    }

    return true;
}

// Setters
void
Conf::set_fname(const string& s)
{
    conf_fname = s;
}

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
Conf::fname() const
{
	return conf_fname;
}

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
    debug(" --- Account ---");
    debug("fname      : " + fname()      );
    debug("in_server  : " + in_server()  );
    debug("in_port    : " + in_port()    );
    debug("smtp_server: " + smtp_server());
    debug("smtp_port  : " + smtp_port()  );
    debug("from       : " + from()       );
    debug("user       : " + user()       );
    debug("pass       : " + pass()       );
}

