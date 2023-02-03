QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

qtHaveModule(printsupport): QT += printsupport
qtHaveModule(opengl): QT += opengl

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    DieGraphicsItem.cpp \
    GLWaferView.cpp \
    MappingView.cpp \
    WaferGraphicsItem.cpp \
    WaferGridItem.cpp \
    WaferPixmapItem.cpp \
    main.cpp \
    MainWindow.cpp

HEADERS += \
    DieGraphicsItem.h \
    GLWaferView.h \
    MainWindow.h \
    MappingData.h \
    MappingView.h \
    WaferGraphicsItem.h \
    WaferGridItem.h \
    WaferPixmapItem.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
