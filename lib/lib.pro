QT -= gui

TEMPLATE = lib
DEFINES += LIB_LIBRARY

CONFIG += c++14

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
   angle.cpp

HEADERS += \
    angle.h

TARGET = mylib

!include(../common.pri){
   error(common.pri not found)
}

QMAKE_CXXFLAGS += --coverage
QMAKE_LFLAGS   += --coverage

OBJECTS_DIR = $$OBJ_DIR
MOC_DIR = $$MOCS_DIR
DESTDIR = $$LIB_DIR

mkpath($$INCLUDE_DIR)
QMAKE_POST_LINK += $$QMAKE_COPY $$quote($$HEADERS) $$quote($$INCLUDE_DIR) $$escape_expand(\\n\\t)
QMAKE_POST_LINK += $$QMAKE_COPY $$quote(../generate_coverage.sh) $$quote($$BUILD_DIR) $$escape_expand(\\n\\t)

