TEMPLATE = app

MOC_DIR = .build
UI_DIR = .build
RCC_DIR = .build
OBJECTS_DIR = .build
BUILD_DIR = .build

include (parser/parser.pri)
include (symbol/symbol.pri)

HEADERS += \
  archiveloader.h \
  odbppviewwidget.h \
  parser.h

SOURCES += \
  main.cpp \
  archiveloader.cpp \
  odbppviewwidget.cpp \
  parser.cpp 

INCLUDEPATH += . .. parser symbol

DESTDIR = ../bin
TARGET = camview