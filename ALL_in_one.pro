TEMPLATE = subdirs
SUBDIRS = \
  Smile/Smile.pro \
  Test

DISTFILES += \
  Server/test.db

DESTDIR = $$absolute_path($${_PRO_FILE_PWD_}/bin/)
