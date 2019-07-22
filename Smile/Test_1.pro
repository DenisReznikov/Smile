QT += testlib
QT += gui
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app
HEADERS += \
  ../Smile/UI/authentication.h
SOURCES += \
  ../Smile/UI/authentication.cpp \
  ../Smile/Test/tst_test_authentication.cpp
