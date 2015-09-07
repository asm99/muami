CPP = g++
CFLAGS = -g -Wall -Wextra -std=c++11
LIBS = -lcrypto -lssl 
DBGFLAG = -DDEBUG
EXE = muami
SRCS = IMAP_manager.cpp \
	   IMAP_parser.cpp \
	   main.cpp \
	   error.cpp \
	   Date_formatter.cpp \
	   Config_manager.cpp \
	   Email.cpp \
	   Email_infos.cpp \
	   RFC822_header.cpp \
	   SSL_manager.cpp \
	   SDebugger.cpp

all: $(SRCS)
	$(CPP) $(CFLAGS) $^ -o $(EXE) $(LIBS)  $(DBGFLAG)

debug: SDebugger.cpp error.cpp
	$(CPP) $(CFLAGS) $^ -o $@ -DTTY_DEBUG

config_manager: Config_manager.cpp error.cpp
	$(CPP) $(CFLAGS) $^ -o $@ -DCONFIG_MANAGER_DEBUG

date_formatter: Date_formatter.cpp
	$(CPP) $(CFLAGS) $^ -o $@ $(DBGFLAG) -DDATE_FORMATTER_DEBUG

imap_parser: IMAP_parser.cpp RFC822_header.cpp Bodystructure.cpp Bodypart.cpp \
	Date_formatter.cpp Email_infos.cpp Email.cpp
	$(CPP) $(CFLAGS) $^ -o $@ $(DBGFLAG) -DIMAP_PARSER_DEBUG

imap_manager: IMAP_manager.cpp IMAP_parser.cpp SSL_manager.cpp \
	Date_formatter.cpp error.cpp
	$(CPP) $(CFLAGS) $^ -o $@ $(DBGFLAG) $(LIBS) -DIMAP_MANAGER_DEBUG

ssl_manager: SSL_manager.cpp Config_manager.cpp error.cpp IMAP_parser.cpp
	$(CPP) $(CFLAGS) $^ -o $@ $(DBGFLAG) $(LIBS) -DSSL_MANAGER_DEBUG

.PHONY: 
	clean cleanall

clean:
	rm -rf *.o

cleanall:
	rm -rf $(EXE) *.o *.dSYM tags \
		config_manager \
		date_formatter \
		ssl_manager \
		debug \
		imap_parser
