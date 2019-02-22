#-------------------------------------------------
# Project created by QtCreator 2019-02-15T14:53:09
#-------------------------------------------------
QT  += test
QT  -= gui

TARGET = test
CONFIG   += console
CONFIG   -= app_bundle

INCLUDEPATH += ./include

HEADERS += \
    testlog.h \
    include/loginterface.h

SOURCES += \
    main.cpp \
    testlog.cpp

unix:!macx: LIBS += -L./lib -lLog
unix:!macx: PRE_TARGETDEPS += ./lib/libLog.so

