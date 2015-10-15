CPP = g++
CFLAGS = -g -Wall -Wextra -std=c++11 -O0
LIBS = -lcrypto -lssl
BIN = muami
BLD_DIR = build

# DBG : debug flag used for unit testing.
# Refer to the specific file to get the appropriate flag. 
# Note: leave the flag blank for production.
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
	   ssl/SSL_manager.cpp \
	   utils/error.cpp \
	   utils/date.cpp \
	   utils/util.cpp

HDRS = $(patsubst %.cpp, %.hpp, $(SRCS)) \
	   protocol/Protocol_manager.hpp

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
			ssl \
			utils

vpath %.cpp coding \
			config \
			crypto \
			debug \
			email \
			protocol \
			protocol/imap \
			ssl \
			utils

$(BLD_DIR)/%.o: %.cpp 
	$(CPP) $(CFLAGS) -c -o $@ $^ $(DBG)

imap_parser: $(OBJS) $(HDRS)
	@[ -d $(BLD_DIR) ] || mkdir -p $(BLD_DIR)
	$(CPP) $(CFLAGS) -o $(BLD_DIR)/$@ $(OBJS) $(LIBS) $(DBG)

.PHONY:
	clean cleanall

clean:
	rm -rf $(BLD_DIR)/*.o

cleanall:
	rm -rf $(BLD_DIR)/*

