#!/bin/bash

lcov -c -d objs -o mylib.info
lcov -r "mylib.info" "*QtCore*" "*QtGui*" "*QtWidgets*" "*Qt*.framework*" "/usr/*" "*.moc" "*moc_*.cpp" -o "mylib-filtered.info"

genhtml mylib-filtered.info -o coverage

