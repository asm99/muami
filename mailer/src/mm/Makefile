CPP = g++
CFLAGS = -g -Wall -Wextra -std=c++11
LIBS = -lcrypto -lssl
EXE = muami
SRCS = main.cpp \
	   coding/base64.cpp \
	   coding/coding.cpp \
	   coding/qp.cpp \
	   config/Config_manager.cpp \
	   config/Account.cpp \
	   crypto/md5.cpp \
	   email/Address.cpp \
	   email/Addresses.cpp \
	   email/Email.cpp \
	   email/Envelope.cpp \
	   email/Mailbox.cpp \
	   email/Nstring.cpp \
	   email/RFC822_header.cpp \
	   protocol/imap/IMAP_manager.cpp \
	   protocol/imap/IMAP_parser.cpp \
	   ssl/SSL_manager.cpp \
	   utils/error.cpp \
	   utils/Date_formatter.cpp \
	   utils/util.cpp

all: $(SRCS)
	$(CPP) $(CFLAGS) $^ -o $(EXE) $(LIBS) -DDEBUG

address: email/Address.cpp utils/util.cpp
	$(CPP) $(CFLAGS) $^ -o $@ -DADDRESS_DEBUG

addresses: email/Addresses.cpp email/Address.cpp utils/util.cpp
	$(CPP) $(CFLAGS) $^ -o $@ -DADDRESSES_DEBUG

base64: coding/base64.cpp
	$(CPP) $(CFLAGS) $^ -o $@ -DBASE64_DEBUG -lssl -lcrypto

config_manager: config/Config_manager.cpp config/Account.cpp utils/error.cpp
	$(CPP) $(CFLAGS) $^ -o $@ -DCONFIG_MANAGER_DEBUG

date_formatter: utils/Date_formatter.cpp
	$(CPP) $(CFLAGS) $^ -o $@ $(DBGFLAG) -DDATE_FORMATTER_DEBUG

debug: SDebugger.cpp utils/error.cpp
	$(CPP) $(CFLAGS) $^ -o $@ -DTTY_DEBUG

encdec: coding/qp.cpp coding/coding.cpp coding/base64.cpp
	$(CPP) $(CFLAGS) $^ -o $@ -DCODING_DEBUG -lssl -lcrypto

envelope: email/Envelope.cpp email/Address.cpp email/Addresses.cpp \
	email/Nstring.cpp utils/util.cpp
	$(CPP) $(CFLAGS) $^ -o $@ -DENVELOPE_DEBUG

imap_manager: protocol/imap/IMAP_manager.cpp protocol/imap/IMAP_parser.cpp \
	ssl/SSL_manager.cpp config/Config_manager.cpp config/Account.cpp \
	utils/error.cpp email/Email.cpp utils/Date_formatter.cpp utils/util.cpp \
	email/Envelope.cpp email/Address.cpp email/Addresses.cpp \
	email/Nstring.cpp
	$(CPP) $(CFLAGS) $^ -o $@ $(DBGFLAG) $(LIBS) -DIMAP_MANAGER_DEBUG

imap_parser: protocol/imap/IMAP_parser.cpp email/RFC822_header.cpp \
	utils/Date_formatter.cpp email/Email.cpp email/Envelope.cpp \
	coding/coding.cpp coding/qp.cpp coding/base64.cpp \
	email/Nstring.cpp email/Address.cpp email/Addresses.cpp utils/util.cpp \
	email/Mailbox.cpp
	$(CPP) $(CFLAGS) $^ -o $@ $(DBGFLAG) -DIMAP_PARSER_DEBUG -lssl -lcrypto

mailbox: email/Mailbox.cpp email/Email.cpp email/Nstring.cpp \
	email/Envelope.cpp email/Address.cpp email/Addresses.cpp \
	utils/util.cpp coding/coding.cpp coding/base64.cpp coding/qp.cpp
	$(CPP) $(CFLAGS) $^ -o $@ -DMAILBOX_DEBUG -lssl -lcrypto

md5: crypto/md5.cpp
	$(CPP) $(CFLAGS) $^ -o $@ -DMD5_DEBUG -lcrypto

nstring: email/nstring.cpp utils/util.cpp
	$(CPP) $(CFLAGS) $^ -o $@ -DNSTRING_DEBUG

qp: coding/qp.cpp
	$(CPP) $(CFLAGS) $^ -o $@ -DQP_DEBUG

util: utils/util.cpp 
	$(CPP) $(CFLAGS) $^ -o $@ -DUTIL_DEBUG

.PHONY: 
	clean cleanall

clean:
	rm -rf *.o

cleanall:
	rm -rf $(EXE) *.o *.dSYM tags \
		address \
		addresses \
		base64 \
		config_manager \
		date_formatter \
		debug \
		encdec \
		envelope \
		imap_manager \
		imap_parser \
		mailbox \
		md5 \
		nstring \
		qp \
		util

