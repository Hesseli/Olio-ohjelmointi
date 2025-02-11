TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Notifier.cpp \
        Follower.cpp \
        main.cpp

HEADERS += \
    Notifier.h \
    Follower.h
