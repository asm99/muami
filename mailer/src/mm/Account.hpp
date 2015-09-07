
typedef enum Email_Protocol {
    PROTOCOL_IMAP = 0,
    PROTOCOL_POP3,
} Email_Protocol;

class Account {
    public:
        std::string id;      // identifier (used in UI status bar)
        std::string imap;    // IMAP server address
        std::string iport;   // IMAPS port
        std::string smtp;    // SMTP server address
        std::string sport;   // SMTPS port
        std::string from;    // username + email "Marc" <marc@ok.com>
        std::string user;    // username to connect to server
        std::string pass;    // password

        Account() {};
        ~Account();
};
