CPP = g++
CFLAGS = -g -Wall -Wextra -std=c++11 -O0
LIBS = -lcrypto -lssl
EXE = muami
BLD = build
DBG = -DIMAP_PARSER_DEBUG 
SRCS = coding/base64.cpp \
	   coding/coding.cpp \
	   coding/qp.cpp \
	   config/Conf.cpp \
	   config/Config_manager.cpp \
	   config/Account.cpp \
	   crypto/md5.cpp \
	   debug/debug.cpp \
	   email/Address.cpp \
	   email/Addresses.cpp \
	   email/Body.cpp \
	   email/Body_ext_mpart.cpp \
	   email/Body_fields.cpp \
	   email/Body_params.cpp \
	   email/Bodypart.cpp \
	   email/Email.cpp \
	   email/Envelope.cpp \
	   email/Mailbox.cpp \
	   email/Nstring.cpp \
	   email/RFC822_header.cpp \
	   protocol/imap/IMAP_manager.cpp \
	   protocol/imap/IMAP_parser.cpp \
	   ssl/SSL_manager.cpp \
	   utils/error.cpp \
	   utils/date.cpp \
	   utils/util.cpp

all: $(SRCS) main.cpp
	$(CPP) $(CFLAGS) $^ -o $(EXE) $(LIBS) -DDEBUG

$(BLD)/address.o: email/Address.cpp email/Address.hpp 
	$(CPP) $(CFLAGS) $< -c -o $@ $(DBG) 

$(BLD)/addresses.o: email/Addresses.cpp email/Addresses.hpp 
	$(CPP) $(CFLAGS) $< -c -o $@ $(DBG) 

$(BLD)/base64.o: coding/base64.cpp coding/base64.hpp
	$(CPP) $(CFLAGS) $< -c -o $@ $(DBG)

$(BLD)/body.o: email/Body.cpp email/Body.hpp
	$(CPP) $(CFLAGS) $< -c -o $@ $(DBG)
 
$(BLD)/body_ext_1part.o: email/Body_ext_1part.cpp email/Body_ext_1part.hpp
	$(CPP) $(CFLAGS) $< -c -o $@ $(DBG)
 
$(BLD)/body_ext_mpart.o: email/Body_ext_mpart.cpp email/Body_ext_mpart.hpp
	$(CPP) $(CFLAGS) $< -c -o $@ $(DBG)
 
$(BLD)/body_fields.o: email/Body_fields.cpp email/Body_fields.hpp
	$(CPP) $(CFLAGS) $< -c -o $@ $(DBG)
 
$(BLD)/body_params.o: email/Body_params.cpp email/Body_params.hpp
	$(CPP) $(CFLAGS) $< -c -o $@ $(DBG)
 
$(BLD)/bodypart.o: email/Bodypart.cpp email/Bodypart.hpp
	$(CPP) $(CFLAGS) $< -c -o $@ $(DBG)

$(BLD)/email.o: email/Email.cpp email/Email.hpp
	$(CPP) $(CFLAGS) $< -c -o $@ $(DBG)
 
$(BLD)/envelope.o: email/Envelope.cpp email/Envelope.hpp
	$(CPP) $(CFLAGS) $< -c -o $@ $(DBG)
 
$(BLD)/mailbox.o: email/Mailbox.cpp email/Mailbox.hpp
	$(CPP) $(CFLAGS) $< -c -o $@ $(DBG)
 
$(BLD)/nstring.o: email/Nstring.cpp email/Nstring.hpp
	$(CPP) $(CFLAGS) $< -c -o $@ $(DBG)
 
$(BLD)/rfc822_header.o: email/RFC822_header.cpp email/RFC822_header.hpp
	$(CPP) $(CFLAGS) $< -c -o $@ $(DBG)
 
$(BLD)/coding.o: coding/coding.cpp coding/coding.hpp
	$(CPP) $(CFLAGS) $< -c -o $@ $(DBG) 

$(BLD)/qp.o: coding/qp.cpp coding/qp.hpp
	$(CPP) $(CFLAGS) $< -c -o $@ $(DBG) 

$(BLD)/date.o: utils/date.cpp utils/date.hpp
	$(CPP) $(CFLAGS) $< -c -o $@ $(DBG) 

$(BLD)/debug.o: debug/debug.cpp debug/debug.hpp
	$(CPP) $(CFLAGS) $< -c -o $@ $(DBG)

$(BLD)/imap_parser.o: protocol/imap/IMAP_parser.cpp protocol/imap/IMAP_parser.hpp
	$(CPP) $(CFLAGS) $< -c -o $@ $(DBG) 

$(BLD)/util.o: utils/util.cpp utils/util.hpp 
	$(CPP) $(CFLAGS) $< -c -o $@

imap_manager: \
	config/Config_manager.cpp \
	config/Account.cpp \
	email.o \
	address.o \
	addresses.o \
	body.o \
	bodypart.o \
	email/Envelope.cpp \
	email/Nstring.cpp \
	protocol/imap/IMAP_manager.cpp \
	protocol/imap/IMAP_parser.cpp \
	ssl/SSL_manager.cpp \
	utils/date.cpp \
	utils/error.cpp \
	utils/util.cpp
	$(CPP) $(CFLAGS) $^ -o $(BLD)/$@ $(DBGFLAG) $(LIBS) 

imap_parser: \
	$(BLD)/base64.o \
	$(BLD)/coding.o \
	$(BLD)/qp.o \
	$(BLD)/debug.o \
	$(BLD)/address.o \
	$(BLD)/addresses.o \
	$(BLD)/body.o \
	$(BLD)/body_ext_1part.o \
	$(BLD)/body_ext_mpart.o \
	$(BLD)/body_fields.o \
	$(BLD)/body_params.o \
	$(BLD)/bodypart.o \
	$(BLD)/email.o \
	$(BLD)/envelope.o \
	$(BLD)/mailbox.o \
	$(BLD)/nstring.o \
	$(BLD)/rfc822_header.o \
	$(BLD)/imap_parser.o \
	$(BLD)/date.o \
	$(BLD)/util.o
	$(CPP) $(CFLAGS) $^ -o $(BLD)/$@ $(DBGFLAG) $(LIBS)

mailbox: email/Mailbox.cpp email/Email.cpp email/Nstring.cpp \
	email/Envelope.cpp email/Address.cpp email/Addresses.cpp \
	utils/util.cpp coding/coding.cpp coding/base64.cpp coding/qp.cpp
	$(CPP) $(CFLAGS) $^ -o $@ -DMAILBOX_DEBUG -lssl -lcrypto

.PHONY: 
	clean cleanall

clean:
	rm -rf $(BLD)/*.o

cleanall:
	rm -rf $(BLD)/*
