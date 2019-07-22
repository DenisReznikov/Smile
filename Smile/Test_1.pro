QT += testlib
QT += gui
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app
HEADERS += \
  ../authentication.h
SOURCES += \
  ../authentication.cpp \
  tst_test_authentication.cpp
