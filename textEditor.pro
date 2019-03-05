TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

HEADERS += \
        test_runner.h \
        profile.h \
    texteditor.h
    
        
SOURCES += \
        main.cpp \
        tests.cpp         

# remove possible other optimization flags
QMAKE_CXXFLAGS += -O
#QMAKE_CXXFLAGS -= -O1
#QMAKE_CXXFLAGS -= -O2

# add the desired -O3 if not present
#QMAKE_CXXFLAGS -= -O3
