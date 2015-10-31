CPP = g++
CFLAGS = -g -Wall -Wextra -std=c++11 -O0
LIBS = -lcrypto -lssl
BIN = muami
BLD_DIR = build

# DBG : debug flag used for unit testing.
# Refer to the specific file to get the appropriate flag. 
# Note: leave the flag blank for production.
# DBG = -DIMAP_PARSER_DEBUG 
DBG = -DDEBUG
#DBG = -DBASE36_DEBUG

SRCS = coding/base36.cpp \
	   coding/base64.cpp \
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
	   email/Body_ext_1part.cpp \
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
	   smtp/Out_email.cpp \
	   smtp/SMTP_manager.cpp \
	   smtp/SMTP_parser.cpp \
	   ssl/SSL_manager.cpp \
	   util/error.cpp \
	   util/date.cpp \
	   util/util.cpp

HDRS = $(patsubst %.cpp, %.hpp, $(SRCS)) \
	   protocol/Protocol_manager.hpp \
	   email/flags.hpp

OBJS = $(addprefix $(BLD_DIR)/, \
	   $(notdir \
	   $(patsubst %.cpp, %.o, $(SRCS))))

vpath %.hpp coding \
			config \
			crypto \
			debug \
			email \
			protocol \
			protocol/imap \
			smtp \
			ssl \
			util

vpath %.cpp coding \
			config \
			crypto \
			debug \
			email \
			protocol \
			protocol/imap \
			smtp \
			ssl \
			util

$(BLD_DIR)/%.o: %.cpp
	@[ -d $(BLD_DIR) ] || mkdir $(BLD_DIR)
	$(CPP) $(CFLAGS) -c -o $@ $^ $(DBG)

$(BIN): main.cpp $(OBJS) $(HDRS)
	$(CPP) $(CFLAGS) -o $(BLD_DIR)/$@ main.cpp $(OBJS) $(LIBS) -DDEBUG

imap_parser: $(OBJS) $(HDRS)
	$(CPP) $(CFLAGS) -o $(BLD_DIR)/$@ $(OBJS) $(LIBS) $(DBG)

base36: $(OBJS) $(HDRS)
	$(CPP) $(CFLAGS) -o $(BLD_DIR)/$@ $(OBJS) $(LIBS) $(DBG)

.PHONY:
	clean cleanall

clean:
	rm -rf $(BLD_DIR)/*.o

cleanall:
	rm -rf $(BLD_DIR)/*

