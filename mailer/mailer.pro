#-------------------------------------------------
#
# Project created by QtCreator 2015-06-30T18:18:24
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = mailer
TEMPLATE = app


SOURCES += src/gui/main.cpp\
	src/gui/mainwindow.cpp \
    src/gui/mailbox.cpp \
    src/gui/writemail.cpp \
    src/gui/addressbook.cpp \
    src/gui/addaccount.cpp \
    src/gui/handleissues.cpp \
    src/gui/attachfilewindow.cpp

HEADERS  += src/gui/mainwindow.h \
    src/gui/mailbox.h \
    src/gui/writemail.h \
    src/gui/addressbook.h \
    src/gui/addaccount.h \
    src/gui/handleissues.h \
    src/gui/attachfilewindow.h
	
FORMS    += src/gui/gen/mainwindow.ui \
    src/gui/gen/mailbox.ui \
    src/gui/gen/writemail.ui \
    src/gui/gen/addressbook.ui \
    src/gui/gen/addaccount.ui \
    src/gui/gen/handleissues.ui \
    src/gui/gen/attachfilewindow.ui

RESOURCES += \
    src/gui/pictures.qrc
