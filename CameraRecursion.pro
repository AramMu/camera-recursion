TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += $$PWD\opencv_3_1_mingw\include
LIBS += -L$$PWD\opencv_3_1_mingw\lib -lopencv_world310.dll

SOURCES += main.cpp
