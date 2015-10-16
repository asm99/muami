#-------------------------------------------------
#
# Project created by QtCreator 2015-06-30T18:18:24
#
#-------------------------------------------------

QT	+= core gui widgets

CONFIG	+= c++11
LIBS	+= -lcrypto -lssl
TARGET	= mailer
TEMPLATE= app


SOURCES += src/gui/main.cpp\
    src/mm/coding/base64.cpp \
    src/mm/coding/coding.cpp \
    src/mm/coding/qp.cpp \
    src/mm/config/Account.cpp \
    src/mm/config/Conf.cpp \
    src/mm/config/Config_manager.cpp \
    src/mm/crypto/md5.cpp \
    src/mm/debug/debug.cpp \
    src/mm/email/Address.cpp \
    src/mm/email/Addresses.cpp \
    src/mm/email/Body.cpp \
    src/mm/email/Body_ext_1part.cpp \
    src/mm/email/Body_ext_mpart.cpp \
    src/mm/email/Body_fields.cpp \
    src/mm/email/Body_params.cpp \
    src/mm/email/Bodypart.cpp \
    src/mm/email/Email.cpp \
    src/mm/email/Envelope.cpp \
    src/mm/email/Mailbox.cpp \
    src/mm/email/Nstring.cpp \
    src/mm/email/RFC822_header.cpp \
    src/mm/protocol/imap/IMAP_manager.cpp \
    src/mm/protocol/imap/IMAP_parser.cpp \
    src/mm/ssl/SSL_manager.cpp \
    src/mm/utils/date.cpp \
    src/mm/utils/error.cpp \
    src/mm/utils/util.cpp \
    src/gui/gui_addressbook.cpp \
    src/gui/gui_attachfilewindow.cpp \
    src/gui/gui_handleissues.cpp \
    src/gui/gui_mailbox.cpp \
    src/gui/gui_writemail.cpp

HEADERS  += \
    src/mm/coding/base64.hpp \
    src/mm/coding/coding.hpp \
    src/mm/coding/qp.hpp \
    src/mm/config/Account.hpp \
    src/mm/config/Conf.hpp \
    src/mm/config/Config_manager.hpp \
    src/mm/crypto/md5.hpp \
    src/mm/debug/debug.hpp \
    src/mm/email/Address.hpp \
    src/mm/email/Addresses.hpp \
    src/mm/email/Body.hpp \
    src/mm/email/Body_ext_1part.hpp \
    src/mm/email/Body_ext_mpart.hpp \
    src/mm/email/Body_fields.hpp \
    src/mm/email/Body_params.hpp \
    src/mm/email/Bodypart.hpp \
    src/mm/email/Email.hpp \
    src/mm/email/Envelope.hpp \
    src/mm/email/Mailbox.hpp \
    src/mm/email/Nstring.hpp \
    src/mm/email/RFC822_header.hpp \
    src/mm/protocol/imap/IMAP_manager.hpp \
    src/mm/protocol/imap/IMAP_parser.hpp \
    src/mm/protocol/Protocol_manager.hpp \
    src/mm/ssl/SSL_manager.hpp \
    src/mm/utils/date.hpp \
    src/mm/utils/error.hpp \
    src/mm/utils/util.hpp \
    src/gui/gui_addressbook.h \
    src/gui/gui_attachfilewindow.h \
    src/gui/gui_handleissues.h \
    src/gui/gui_mailbox.h \
    src/gui/gui_writemail.h
	
FORMS    += \
    src/gui/gen/gui_addressbook.ui \
    src/gui/gen/gui_attachfilewindow.ui \
    src/gui/gen/gui_handleissues.ui \
    src/gui/gen/gui_mailbox.ui \
    src/gui/gen/gui_writemail.ui

RESOURCES += \
    src/gui/icons.qrc
