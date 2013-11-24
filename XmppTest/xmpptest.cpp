#include <QDebug>
#include <QGraphicsWebView>
#include <QWebFrame>
#include <gloox/client.h>
#include <gloox/message.h>
#include <gloox/messagehandler.h>
#include <gloox/connectionlistener.h>

#include "xmpp_connection.h"
#include "xmpptest.h"

XmppTest::XmppTest(QWidget *parent) : Html5ApplicationViewer(parent) {
    QObject::connect(webView()->page()->mainFrame(),
            SIGNAL(javaScriptWindowObjectCleared()), SLOT(addToJavaScript()));
   }

XmppTest::~XmppTest() {
    delete xmpp_connection;
    delete mh;
    delete cl;
}

void XmppTest::addToJavaScript() {
    webView()->page()->mainFrame()->addToJavaScriptWindowObject("XmppTest", this);
}

void XmppTest::login(QString username, QString password, QString friend_name) {
    qDebug() << "Logowanie jako " << username << "z friendem" << friend_name;
    xmpp_connection = new XmppConnection(username, password, friend_name);
    mh = new MsgHandler(this);
    cl = new ConnListener();
    xmpp_connection->registerConnectionListener(cl);
    xmpp_connection->registerMessageHandler(mh);
    qRegisterMetaType<QMessageDetails>();
    QObject::connect(xmpp_connection, SIGNAL(messageArrived(QMessageDetails)),
                     xmpp_connection,SLOT(onMessageArrived(QMessageDetails)));
    xmpp_connection->start();
}

void XmppTest::loadMain(int x, int y, int width, int height) {
    this->resize(width, height);
    this->move(x, y);
    this->loadFile("html/xmpptest.html");
}

void XmppTest::sendMessage(QString message) {
    qDebug() << "Sending message...\n" << message << "\n";
    xmpp_connection->sendMessage(message);
    webView()->page()->mainFrame()->evaluateJavaScript("add_message('<<"+message+"'); null");
}

MsgHandler::MsgHandler(XmppTest *ht) {
    this->xmpp_test = ht;
}

void MsgHandler::handleMessage(QMessageDetails &message) {
    qDebug() << "Received message from: " << message.from() << "\n";
    qDebug() << "Body: " << message.body() << "\n";
    xmpp_test->webView()->page()->mainFrame()->evaluateJavaScript("add_message('>>"+message.body()+"'); null");
}
