TEMPLATE = app

QT += qml quick

CONFIG += c++11

SOURCES += \
    src/main.cpp \
    src/multisorter.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    src/multisorter.h \
    src/multisorter.tpp

OTHER_FILES += \
    src/qml/main.qml
