#ifndef XMPPTEST_H
#define XMPPTEST_H

#include <QObject>
#include <QDebug>
#include "html5applicationviewer/html5applicationviewer.h"
#include "xmpp_connection.h"

class ConnListener : public gloox::ConnectionListener {
public:
    virtual void onConnect() {
            qDebug() << "ConnListener::onConnect()\n";
    }
    virtual void onDisconnect(gloox::ConnectionError e) {
            qDebug() << "ConnListener::onDisconnect() " << e << "\n";
    }
    virtual bool onTLSConnect(const gloox::CertInfo& info) {
            qDebug() << "ConnListener::onTLSConnect()";
            qDebug() << "TLS cert info: " << QString::fromUtf8(info.cipher.c_str());
            return true;
    }
};

class MsgHandler;

class XmppTest : public Html5ApplicationViewer
{
    Q_OBJECT
public:
    explicit XmppTest(QWidget *parent=0);
    ~XmppTest();
private:
    XmppConnection *xmpp_connection;
    ConnListener *cl;
    MsgHandler *mh;

private slots:
    void addToJavaScript();
public slots:
    void loadMain(int x, int y, int width, int height);
    void sendMessage(QString message);
    void login(QString username, QString password, QString friend_name);
    //void onMessageArrived(QMessageDetails);
};

class MsgHandler :  public QMessageHandler{
private:
    XmppTest *xmpp_test;
public:
    MsgHandler(XmppTest *ht);

    void handleMessage(QMessageDetails &);
};

#endif
