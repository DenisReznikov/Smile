TEMPLATE = subdirs
SUBDIRS = \
  Test \
  Smile/Smile.pro


DISTFILES += \
  Server/test.db

DESTDIR = $$absolute_path($${_PRO_FILE_PWD_}/bin/)
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
