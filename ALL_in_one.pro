TEMPLATE = subdirs
SUBDIRS = \
  Smile/Smile.pro \
  Test

DISTFILES += \
  Server/test.db
QMAKE_CXX = g++-7
QMAKE_CC = gcc-7
