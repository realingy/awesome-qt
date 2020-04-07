QT += gui core
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# 如果使用Qt的任何标记为已弃用的特性，下面的定义将使编译器发出警告。
DEFINES += QT_DEPRECATED_WARNINGS

TEMPLATE      = app
HEADERS       = hexspinbox.h
SOURCES       = hexspinbox.cpp \
                main.cpp
