CPP = g++
CFLAGS = -g -Wall -Wextra -std=c++11
LIBS = -lcrypto -lssl 
DBGFLAG = -DDEBUG
EXE = muami
SRCS = protocol/imap/IMAP_manager.cpp \
	   protocol/imap/IMAP_parser.cpp \
	   main.cpp \
	   utils/error.cpp \
	   utils/Date_formatter.cpp \
	   crypto/md5.cpp \
	   coding/base64.cpp \
	   config/Config_manager.cpp \
	   config/Account.cpp \
	   email/Email.cpp \
	   email/Envelope.cpp \
	   email/RFC822_header.cpp \
	   ssl/SSL_manager.cpp \
	   utils/util.cpp \
	   email/Nstring.cpp \
	   email/Address.cpp \
	   email/Addresses.cpp

all: $(SRCS)
	$(CPP) $(CFLAGS) $^ -o $(EXE) $(LIBS) 

config_manager: config/Config_manager.cpp config/Account.cpp utils/error.cpp
	$(CPP) $(CFLAGS) $^ -o $@ -DCONFIG_MANAGER_DEBUG

md5: crypto/md5.cpp
	$(CPP) $(CFLAGS) $^ -o $@ -DMD5_DEBUG -lcrypto

base64: coding/base64.cpp
	$(CPP) $(CFLAGS) $^ -o $@ -DBASE64_DEBUG

date_formatter: utils/Date_formatter.cpp
	$(CPP) $(CFLAGS) $^ -o $@ $(DBGFLAG) -DDATE_FORMATTER_DEBUG

debug: SDebugger.cpp utils/error.cpp
	$(CPP) $(CFLAGS) $^ -o $@ -DTTY_DEBUG

imap_manager: protocol/imap/IMAP_manager.cpp protocol/imap/IMAP_parser.cpp \
	ssl/SSL_manager.cpp config/Config_manager.cpp config/Account.cpp \
	utils/error.cpp email/Email.cpp utils/Date_formatter.cpp utils/util.cpp \
	email/Envelope.cpp email/Address.cpp email/Addresses.cpp \
	email/Nstring.cpp
	$(CPP) $(CFLAGS) $^ -o $@ $(DBGFLAG) $(LIBS) -DIMAP_MANAGER_DEBUG

imap_parser: protocol/imap/IMAP_parser.cpp email/RFC822_header.cpp \
	utils/Date_formatter.cpp email/Email.cpp email/Envelope.cpp \
	email/Nstring.cpp email/Address.cpp email/Addresses.cpp utils/util.cpp
	$(CPP) $(CFLAGS) $^ -o $@ $(DBGFLAG) -DIMAP_PARSER_DEBUG

util: utils/util.cpp 
	$(CPP) $(CFLAGS) $^ -o $@ -DUTIL_DEBUG

envelope: email/Envelope.cpp email/Address.cpp email/Addresses.cpp \
	email/Nstring.cpp utils/util.cpp
	$(CPP) $(CFLAGS) $^ -o $@ -DENVELOPE_DEBUG

address: email/Address.cpp utils/util.cpp
	$(CPP) $(CFLAGS) $^ -o $@ -DADDRESS_DEBUG

addresses: email/Addresses.cpp email/Address.cpp utils/util.cpp
	$(CPP) $(CFLAGS) $^ -o $@ -DADDRESSES_DEBUG

nstring: email/nstring.cpp utils/util.cpp
	$(CPP) $(CFLAGS) $^ -o $@ -DNSTRING_DEBUG

.PHONY: 
	clean cleanall

clean:
	rm -rf *.o

cleanall:
	rm -rf $(EXE) *.o *.dSYM tags \
		config_manager \
		date_formatter \
		debug \
		md5 \
		base64 \
		imap_manager \
		imap_parser \
		util \
		envelope \
		address \
		addresses \
		nstring

