TEMPLATE = subdirs

SUBDIRS += \
   lib \
   test

test.depends = lib

DISTFILES += \
   common.pri \
   generate_coverage.sh
