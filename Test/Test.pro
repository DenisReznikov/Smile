
QT +=  core gui sql testlib
CONFIG += qt warn_on depend_includepath testcase
QT += widgets
TEMPLATE = app

SOURCES += \
        ../Smile/Server/toolsfordb.cpp \
        ../Smile/UI/auftragsannahme_alone.cpp \
        ../Smile/UI/auftragsannahme_many.cpp \
        ../Smile/UI/auftragsannahme_telas.cpp \
        ../Smile/UI/auftragsauswahl.cpp \
        ../Smile/UI/auftragsliste.cpp \
        ../Smile/UI/auswahl_dispo_center.cpp \
        ../Smile/UI/authentication.cpp \
        ../Smile/UI/base_window_with_table.cpp \
        ../Smile/UI/dispositionsdater_for_hvt_schaltauftrag.cpp \
        ../Smile/UI/mainwindow.cpp \
        ../Smile/UI/new_passwort.cpp \
        ../Smile/UI/bearbzust.cpp \
        ../Smile/UI/msqlquerymodel.cpp \
        tst_authentication_test.cpp

HEADERS += \
  ../Smile/Server/toolsfordb.h \
  ../Smile/UI/auftragsannahme_alone.h \
  ../Smile/UI/auftragsannahme_many.h \
  ../Smile/UI/auftragsannahme_telas.h \
  ../Smile/UI/auftragsauswahl.h \
  ../Smile/UI/auftragsliste.h \
  ../Smile/UI/auswahl_dispo_center.h \
  ../Smile/UI/authentication.h \
  ../Smile/UI/base_window_with_table.h \
  ../Smile/UI/dispositionsdater_for_hvt_schaltauftrag.h \
  ../Smile/UI/mainwindow.h \
  ../Smile/UI/bearbzust.h \
  ../Smile/UI/msqlquerymodel.h \
  ../Smile/UI/new_passwort.h
FORMS  +=\
  ../Smile/UI/auftragsannahme_alone.ui \
  ../Smile/UI/auftragsannahme_many.ui \
  ../Smile/UI/auftragsannahme_telas.ui \
  ../Smile/UI/auftragsauswahl.ui \
  ../Smile/UI/auftragsliste.ui \
  ../Smile/UI/auswahl_dispo_center.ui \
  ../Smile/UI/authentication.ui \
  ../Smile/UI/dispositionsdater_for_hvt_schaltauftrag.ui \
  ../Smile/UI/mainwindow.ui \
  ../Smile/UI/new_passwort.ui \
  ../Smile/UI/bearbzust.ui
INCLUDEPATH += $$PWD/..
