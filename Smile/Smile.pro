#-------------------------------------------------
#
# Project created by QtCreator 2019-07-18T18:03:24
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = Smile
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += $$PWD/..
SOURCES += \
  Server/toolsfordb.cpp \
  UI/auftragsannahme_alone.cpp \
  UI/auftragsannahme_many.cpp \
  UI/auftragsannahme_telas.cpp \
  UI/auftragsauswahl.cpp \
  UI/auftragsliste.cpp \
  UI/auswahl_dispo_center.cpp \
  UI/authentication.cpp \
  UI/base_window_with_table.cpp \
  UI/bearbzust.cpp \
  UI/checkboxdelegate.cpp \
  UI/dispositionsdater_for_hvt_schaltauftrag.cpp \
  UI/mainwindow.cpp \
  UI/msqlquerymodel.cpp \
  UI/new_passwort.cpp \
  main.cpp

HEADERS += \
  Server/toolsfordb.h \
  UI/auftragsannahme_alone.h \
  UI/auftragsannahme_many.h \
  UI/auftragsannahme_telas.h \
  UI/auftragsauswahl.h \
  UI/auftragsliste.h \
  UI/auswahl_dispo_center.h \
  UI/authentication.h \
  UI/base_window_with_table.h \
  UI/bearbzust.h \
  UI/checkboxdelegate.h \
  UI/dispositionsdater_for_hvt_schaltauftrag.h \
  UI/mainwindow.h \
  UI/msqlquerymodel.h \
  UI/new_passwort.h


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
  UI/auftragsannahme_alone.ui \
  UI/auftragsannahme_many.ui \
  UI/auftragsannahme_telas.ui \
  UI/auftragsauswahl.ui \
  UI/auftragsliste.ui \
  UI/auswahl_dispo_center.ui \
  UI/authentication.ui \
  UI/bearbzust.ui \
  UI/dispositionsdater_for_hvt_schaltauftrag.ui \
  UI/mainwindow.ui \
  UI/new_passwort.ui

DISTFILES += \
  Server/test.db
