#-------------------------------------------------
#
# Project created by QtCreator 2015-06-30T18:18:24
#
#-------------------------------------------------

QT       += core gui widgets

CONFIG += c++11
LIBS += -lcrypto -lssl
TARGET = mailer
TEMPLATE = app


SOURCES += src/gui/main.cpp\
    src/gui/mailbox.cpp \
    src/gui/writemail.cpp \
    src/gui/addressbook.cpp \
    src/gui/handleissues.cpp \
    src/gui/attachfilewindow.cpp \
    src/mm/coding/base64.cpp \
    src/mm/coding/coding.cpp \
    src/mm/coding/qp.cpp \
    src/mm/config/Account.cpp \
    src/mm/config/Config_manager.cpp \
    src/mm/crypto/md5.cpp \
    src/mm/email/Address.cpp \
    src/mm/email/Addresses.cpp \
    src/mm/email/Email.cpp \
    src/mm/email/Envelope.cpp \
    src/mm/email/Nstring.cpp \
    src/mm/email/RFC822_header.cpp \
    src/mm/protocol/imap/IMAP_manager.cpp \
    src/mm/protocol/imap/IMAP_parser.cpp \
    src/mm/ssl/SSL_manager.cpp \
    src/mm/utils/Date_formatter.cpp \
    src/mm/utils/error.cpp \
    src/mm/utils/util.cpp \
    my_qlabel.cpp

HEADERS  += \
    src/gui/mailbox.h \
    src/gui/writemail.h \
    src/gui/addressbook.h \
    src/gui/handleissues.h \
    src/gui/attachfilewindow.h \
    src/mm/coding/base64.hpp \
    src/mm/coding/coding.hpp \
    src/mm/coding/qp.hpp \
    src/mm/config/Account.hpp \
    src/mm/config/Config_manager.hpp \
    src/mm/crypto/md5.hpp \
    src/mm/email/Address.hpp \
    src/mm/email/Addresses.hpp \
    src/mm/email/Email.hpp \
    src/mm/email/Envelope.hpp \
    src/mm/email/Nstring.hpp \
    src/mm/email/RFC822_header.hpp \
    src/mm/protocol/imap/IMAP_manager.hpp \
    src/mm/protocol/imap/IMAP_parser.hpp \
    src/mm/protocol/Protocol_manager.hpp \
    src/mm/ssl/SSL_manager.hpp \
    src/mm/utils/Date_formatter.hpp \
    src/mm/utils/error.hpp \
    src/mm/utils/util.hpp \
    my_qlabel.h

	
FORMS    += \
    src/gui/gen/mailbox.ui \
    src/gui/gen/writemail.ui \
    src/gui/gen/addressbook.ui \
    src/gui/gen/handleissues.ui \
    src/gui/gen/attachfilewindow.ui

RESOURCES += \
    src/gui/icons.qrc
