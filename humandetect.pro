#-------------------------------------------------
#
# Project created by QtCreator 2014-01-04T14:57:00
#
#-------------------------------------------------

QT       += core gui

TARGET = humandetect
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    humandetect.cpp \
    processImage.cpp \
    videodevice.cpp \
    thread.cpp \
    qextserialport.cpp \
    qextserialenumerator_unix.cpp \
    posix_qextserialport.cpp \
    PortListener.cpp \
    gpio.cpp \
    gpio_monitor.cpp

HEADERS  += mainwindow.h \
    processImage.h \
    thread.h \
    humandetect.h \
    videodevice.h \
    qextserialport_global.h \
    qextserialport.h \
    qextserialenumerator.h \
    posix_qextserialport.3.h \
    PortListener.h \
    gpio.h \
    gpio_monitor.h

FORMS    += mainwindow.ui


INCLUDEPATH +=/usr/local/include
INCLUDEPATH +=/usr/local/include/opencv
INCLUDEPATH +=/usr/local/include/opencv2

LIBS += -L/usr/local/lib
LIBS += -lopencv_core
LIBS += -lopencv_imgproc
LIBS += -lopencv_highgui
LIBS += -lopencv_ml
LIBS += -lopencv_video
LIBS += -lopencv_features2d
LIBS += -lopencv_calib3d
LIBS += -lopencv_objdetect
LIBS += -lopencv_contrib
LIBS += -lopencv_legacy
LIBS += -lopencv_flann
LIBS += -lpthread
LIBS += -lrt
