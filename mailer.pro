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

OBJECTS_DIR = builds/objects
MOC_DIR = builds/moc
UI_DIR = builds/ui

SOURCES += src/gui/main.cpp\
    src/net/config/Account.cpp \
    src/net/config/Conf.cpp \
    src/net/config/Config_manager.cpp \
    src/net/crypto/md5.cpp \
    src/net/debug/debug.cpp \
    src/net/email/Address.cpp \
    src/net/email/Addresses.cpp \
    src/net/email/Body.cpp \
    src/net/email/Body_ext_1part.cpp \
    src/net/email/Body_ext_mpart.cpp \
    src/net/email/Body_fields.cpp \
    src/net/email/Body_params.cpp \
    src/net/email/Bodypart.cpp \
    src/net/email/Email.cpp \
    src/net/email/Envelope.cpp \
    src/net/email/Mailbox.cpp \
    src/net/email/Nstring.cpp \
    src/net/email/RFC822_header.cpp \
    src/net/smtp/Out_email.cpp \
    src/net/smtp/SMTP_manager.cpp \
    src/net/smtp/SMTP_parser.cpp \
    src/net/coding/base36.cpp \
    src/net/coding/base64.cpp \
    src/net/coding/coding.cpp \
    src/net/coding/qp.cpp \
    src/net/coding/qp.hpp \
    src/net/protocol/imap/IMAP_manager.cpp \
    src/net/protocol/imap/IMAP_parser.cpp \
    src/net/ssl/SSL_manager.cpp \
    src/net/util/date.cpp \
    src/net/util/error.cpp \
    src/net/util/util.cpp \
    src/gui/gui_addressbook.cpp \
    src/gui/gui_attachfilewindow.cpp \
    src/gui/gui_handleissues.cpp \
    src/gui/gui_mailbox.cpp \
    src/gui/gui_writemail.cpp

HEADERS  += \
    src/net/config/Account.hpp \
    src/net/config/Conf.hpp \
    src/net/config/Config_manager.hpp \
    src/net/crypto/md5.hpp \
    src/net/debug/debug.hpp \
    src/net/email/Address.hpp \
    src/net/email/Addresses.hpp \
    src/net/email/Body.hpp \
    src/net/email/Body_ext_1part.hpp \
    src/net/email/Body_ext_mpart.hpp \
    src/net/email/Body_fields.hpp \
    src/net/email/Body_params.hpp \
    src/net/email/Bodypart.hpp \
    src/net/email/Email.hpp \
    src/net/email/Envelope.hpp \
    src/net/email/Mailbox.hpp \
    src/net/email/Nstring.hpp \
    src/net/email/RFC822_header.hpp \
    src/net/smtp/Out_email.hpp \
    src/net/smtp/SMTP_manager.hpp \
    src/net/smtp/SMTP_parser.hpp \
    src/net/coding/base36.hpp \
    src/net/coding/base64.hpp \
    src/net/coding/coding.hpp \
    src/net/coding/qp.hpp \
    src/net/coding/qp.hpp \
    src/net/protocol/imap/IMAP_manager.hpp \
    src/net/protocol/imap/IMAP_parser.hpp \
    src/net/protocol/Protocol_manager.hpp \
    src/net/ssl/SSL_manager.hpp \
    src/net/util/date.hpp \
    src/net/util/error.hpp \
    src/net/util/util.hpp \
    src/gui/gui_addressbook.h \
    src/gui/gui_attachfilewindow.h \
    src/gui/gui_handleissues.h \
    src/gui/gui_mailbox.h \
    src/gui/gui_writemail.h
	
FORMS += \
    src/gui/gen/gui_addressbook.ui \
    src/gui/gen/gui_attachfilewindow.ui \
    src/gui/gen/gui_handleissues.ui \
    src/gui/gen/gui_mailbox.ui \
    src/gui/gen/gui_writemail.ui

RESOURCES += \
    src/gui/icons.qrc
