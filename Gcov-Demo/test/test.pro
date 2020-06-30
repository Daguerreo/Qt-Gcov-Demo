QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_test.cpp

!include(../common.pri){
   error(common.pri not found)
}

mkpath($$TEST_DIR)
DESTDIR     = $$TEST_DIR
OBJECTS_DIR = $$OBJ_DIR
MOC_DIR     = $$MOCS_DIR
DESTDIR     = $$TEST_DIR

INCLUDEPATH += $$INCLUDE_DIR
LIBS += -L$$LIB_DIR -Wl,-rpath=$$LIB_DIR -lmylib


