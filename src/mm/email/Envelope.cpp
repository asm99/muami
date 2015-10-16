#include "Envelope.hpp"

enum Parts {
    ENV_DATE = 0,
    ENV_SUBJECT,
    ENV_FROM,
    ENV_SENDER,
    ENV_REPLY_TO,
    ENV_TO,
    ENV_CC,
    ENV_BCC,
    ENV_IN_REPLY_TO,
    ENV_MESSAGE_ID
};

// Constructors

// Setters

void
Envelope::set_bcc(Addresses* const bcc)
{
    env_bcc = bcc;
}

void
Envelope::set_cc(Addresses* const cc)
{
    env_cc = cc;
}

void
Envelope::set_date(const Nstring& date)
{
    env_date = date;
}

void
Envelope::set_from(Address* const from)
{
    env_from = from;
}

void
Envelope::set_in_reply_to(const Nstring& in_reply_to)
{
    env_in_reply_to = in_reply_to;
}

void
Envelope::set_message_id(const Nstring& message_id)
{
    env_message_id = message_id;
}

void
Envelope::set_reply_to(Address* const reply_to)
{
    env_reply_to = reply_to;
}

void
Envelope::set_sender(Address* const sender)
{
    env_sender = sender;
}

void
Envelope::set_subject(const Nstring& subject)
{
    env_subject.set_str(mmdecode(subject.str(), true));
}

void
Envelope::set_to(Address* const to)
{
    env_to = to;
}


// Getters

Addresses*
Envelope::bcc() const
{
    return env_bcc;
}

Addresses*
Envelope::cc() const
{
    return env_cc;
}

Nstring
Envelope::date() const
{
    return env_date;
}

Address*
Envelope::from() const
{
    return env_from;
}

Nstring
Envelope::in_reply_to() const
{
    return env_in_reply_to;
}

Nstring
Envelope::message_id() const
{
    return env_message_id;
}

Address*
Envelope::reply_to() const
{
    return env_reply_to;
}

Address*
Envelope::sender() const
{
    return env_sender;
}

Nstring
Envelope::subject() const
{
    return env_subject;
}

Address*
Envelope::to() const
{
    return env_to;
}

// DEBUG

void
Envelope::dump()
{
    debug("Date: " + env_date.str());
    debug("Subject: " + env_subject.str());
    if (env_from)     { debug("From: ");    env_from->dump();     }
    if (env_sender)   { debug("Sender: ");  env_sender->dump();   }
    if (env_reply_to) { debug("Reply to:"); env_reply_to->dump(); }
    if (env_to)       { debug("To: ");      env_to->dump();       }
    if (env_cc)       { debug("CC:");       env_cc->dump();       }
    if (env_bcc)      { debug("BCC:");      env_bcc->dump();      }
    debug("env_in_reply_to: "); env_in_reply_to.str();
    debug("env_message_id: ");  env_message_id.str();
}

istream&
operator>>(istream& is, Envelope& env)
{
    Nstring d {};
    Nstring subj {};
    Address* f = new Address();
    Address* s = new Address();
    Address* rto = new Address();
    Address* to = new Address();
    Addresses* bccs = new Addresses();
    Addresses* ccs = new Addresses();
    Nstring irto {};
    Nstring msgid {};

    is >> d >> subj >> f >> s >> rto >> to >> ccs >> bccs >> irto >> msgid;

    env.set_date(d);
    env.set_subject(subj);
    env.set_from(f);
    env.set_sender(s);
    env.set_reply_to(rto);
    env.set_to(to);
    env.set_bcc(bccs);
    env.set_cc(ccs);
    env.set_in_reply_to(irto);
    env.set_message_id(msgid);

    return is;
}

#ifdef ENVELOPE_DEBUG

#include <vector>

int
main()
{
    vector<string> vec = {
        "(\"Sun, 20 Sep 2015 10:23:30 +0200\" \"=?utf-8?Q?Re:_Non,_mais_l=C3=A0,_c'est_chaud?=\" ((\"Robert Marechal\" NIL \"marechalr\" \"yahoo.com\")) ((\"Robert Marechal\" NIL \"marechalr\" \"yahoo.com\")) ((\"Robert Marechal\" NIL \"marechalr\" \"yahoo.com\")) ((\"mm@asm35.info\" NIL \"mm\" \"asm35.info\")) ((\"MC LAM\" NIL \"lam.mc\" \"gmail.com\")(\"Mariko K.\" NIL \"mariko\" \"yahoo.fr\")) NIL \"<cde37b3bdf7301df911d99e912a169c9.squirrel@mail.asm35.info>\" \"<D2245843-A1B6-420C-8781-D744AD2BA7B0@yahoo.com>\"))",
        "(\"Wed, 22 Apr 2015 15:05:41 +0200 (CEST)\" {34}\nConfirmation de commande BFN721693 ((\"=?UTF-8?Q?Service_client=C3=A8le_Fitnessboutique?=\" NIL \"mail-auto\" \"em2.fitnessboutique.fr\")) ((\"=?UTF-8?Q?Service_client=C3=A8le_Fitnessboutique?=\" NIL \"mail-auto\" \"em2.fitnessboutique.fr\")) ((\"=?UTF-8?Q?Service_client=C3=A8le_Fitnessboutique?=\" NIL \"mail-auto\" \"fitnessboutique.fr\")) ((NIL NIL \"mm\" \"asm35.info\")) NIL NIL NIL \"<2.2.0.1101042761.1528908.5718831763812@em2.fitnessboutique.fr>\"))",
        "(\"Thu, 15 Oct 2015 14:42:15 -0400\" \"Re: test de CC\" ((\"MELKONIAN Marc - 13410425\" NIL \"13410425\" \"foad.iedparis8.net\")) ((\"MELKONIAN Marc - 13410425\" NIL \"13410425\" \"foad.iedparis8.net\")) ((\"MELKONIAN Marc - 13410425\" NIL \"13410425\" \"foad.iedparis8.net\")) ((\"Antoine De Blieck\" NIL \"13409222\" \"foad.iedparis8.net\")) ((NIL NIL \"13410425\" \"foad.iedparis8.net\")(NIL NIL \"mm\" \"asm35.info\")) NIL \"<2b994ee1c594e524527f05415b085990@foad.iedparis8.net>\" \"<154885490b0b5207378b3939ef615aa5@foad.iedparis8.net>\"))",
    };

    for (auto s : vec) {
        cout << "\n=== ENVELOPE TEST ===" << endl;
        Envelope env {};
        istringstream iss(s);
        iss >> env;
        env.dump();
    }

    return 0;
}
#endif

