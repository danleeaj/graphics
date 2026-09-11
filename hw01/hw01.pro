TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        mat4.cpp \
        vec4.cpp

HEADERS += \
        vec4.h \
        mat4.h

DISTFILES += \
    README \
    log