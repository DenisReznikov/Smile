TEMPLATE = subdirs
SUBDIRS = \
  Test \
  Smile/Smile.pro


DISTFILES += \
  Server/test.db

DESTDIR = $$absolute_path($${_PRO_FILE_PWD_}/bin/)
