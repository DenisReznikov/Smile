#-------------------------------------------------
#
# Project created by QtCreator 2019-07-17T17:38:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UI
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

CONFIG += c++17

SOURCES += \
        auftragsannahme_alone.cpp \
        auftragsannahme_many.cpp \
        auftragsannahme_telas.cpp \
        auftragsauswahl.cpp \
        auftragsliste.cpp \
        auswahl_dispo_center.cpp \
        authentication.cpp \
        base_window_with_table.cpp \
        dispositionsdater_for_hvt_schaltauftrag.cpp \
        main.cpp \
        mainwindow.cpp \
        new_passwort.cpp

HEADERS += \
        auftragsannahme_alone.h \
        auftragsannahme_many.h \
        auftragsannahme_telas.h \
        auftragsauswahl.h \
        auftragsliste.h \
        auswahl_dispo_center.h \
        authentication.h \
        base_window_with_table.h \
        dispositionsdater_for_hvt_schaltauftrag.h \
        mainwindow.h \
        new_passwort.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
  auftragsannahme_alone.ui \
  auftragsannahme_many.ui \
  auftragsannahme_telas.ui \
  auftragsauswahl.ui \
  auftragsliste.ui \
  auswahl_dispo_center.ui \
  authentication.ui \
  dispositionsdater_for_hvt_schaltauftrag.ui \
  mainwindow.ui \
  new_passwort.ui
