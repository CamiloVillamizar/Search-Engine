TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    test.cpp \
    question.cpp \
    porter2_stemmer.cpp \
    index.cpp \
    avlindex.cpp \
    hashindex.cpp \
    indexinterface.cpp \
    mapindex.cpp \
    reader.cpp \
    searchquery.cpp \
    tracker.cpp

HEADERS += \
    avltree.h \
    Catch.hpp \
    question.h \
    porter2_stemmer.h \
    hashtable.h \
    index.h \
    avlindex.h \
    hashindex.h \
    indexinterface.h \
    hashmap.h \
    mapindex.h \
    reader.h \
    searchquery.h \
    oldhashtable.h \
    tracker.h

DISTFILES +=
