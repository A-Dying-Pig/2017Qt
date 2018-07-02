QT += widgets

QT += network

QT +=xml

HEADERS += \
    card.h \
    cardlibrary.h \
    battleinterfaceview.h \
    choosecardinterface.h \
    game_local_logic.h \
    card_local_logic.h \
    battleendinterface.h \
    welcomeinterface.h \
    apprun.h \
    preparebattle.h \
    switchhandcard.h \
    roundendinterface.h \
    mybutton.h \
    tcpconnection.h \
    selectturncard.h

SOURCES += \
    card.cpp \
    cardlibrary.cpp \
    battleinterfaceview.cpp \
    main.cpp \
    choosecardinterface.cpp \
    game_local_logic.cpp \
    card_local_logic.cpp \
    battleendinterface.cpp \
    welcomeinterface.cpp \
    apprun.cpp \
    preparebattle.cpp \
    switchhandcard.cpp \
    roundendinterface.cpp \
    mybutton.cpp \
    tcpconnection.cpp \
    selectturncard.cpp

RESOURCES += \
    images.qrc

CONFIG+=resources_big


