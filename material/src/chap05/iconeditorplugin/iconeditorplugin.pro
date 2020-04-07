QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#Qt已弃用特性警告
DEFINES += QT_DEPRECATED_WARNINGS

TEMPLATE      = lib
CONFIG       += designer plugin release
HEADERS       = ../iconeditor/iconeditor.h \
                iconeditorplugin.h
SOURCES       = ../iconeditor/iconeditor.cpp \
                iconeditorplugin.cpp
RESOURCES     = iconeditorplugin.qrc
DESTDIR       = $$[QT_INSTALL_PLUGINS]/designer
