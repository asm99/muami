#-------------------------------------------------
#
# Project created by QtCreator 2015-06-30T18:18:24
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = mailer
TEMPLATE = app


SOURCES += src/gui/main.cpp\
    src/gui/mailbox.cpp \
    src/gui/writemail.cpp \
    src/gui/addressbook.cpp \
    src/gui/handleissues.cpp \
    src/gui/attachfilewindow.cpp \
    my_qlabel.cpp

HEADERS  += \
    src/gui/mailbox.h \
    src/gui/writemail.h \
    src/gui/addressbook.h \
    src/gui/handleissues.h \
    src/gui/attachfilewindow.h \
    my_qlabel.h
	
FORMS    += \
    src/gui/gen/mailbox.ui \
    src/gui/gen/writemail.ui \
    src/gui/gen/addressbook.ui \
    src/gui/gen/handleissues.ui \
    src/gui/gen/attachfilewindow.ui

RESOURCES += \
    src/gui/icons.qrc
