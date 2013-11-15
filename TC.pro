greaterThan(QT_MAJOR_VERSION, 4):QT += widgets webkitwidgets

# Add more folders to ship with the application, here
folder_01.source = html
folder_01.target = .
DEPLOYMENTFOLDERS = folder_01

# Define TOUCH_OPTIMIZED_NAVIGATION for touch optimization and flicking
#DEFINES += TOUCH_OPTIMIZED_NAVIGATION

# If your application uses the Qt Mobility libraries, uncomment the following
# lines and add the respective components to the MOBILITY variable.
# CONFIG += mobility
# MOBILITY +=

LIBS += -lgloox

# The .cpp file which was generated for your project. Feel free to hack it.
SOURCES += *.cpp \
    XmppTest/xmpptest.cpp
HEADERS += *.h \
    QWrappers/qmessage_details.h \
    QWrappers/qmessage_handler.h \
    XmppTest/xmpptest.h

# Please do not modify the following two lines. Required for deployment.
include(html5applicationviewer/html5applicationviewer.pri)
qtcAddDeployment()

OTHER_FILES += \
    html/app.js \
    html/main.js \
    html/main.html
