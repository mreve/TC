#ifndef XMPP_CLIENT_H
#define XMPP_CLIENT_H

#include <QObject>
#include <gloox/client.h>
#include <gloox/message.h>
#include <gloox/messagehandler.h>
#include <gloox/connectionlistener.h>
#include <string>

#include "xmpp_connection_thread.h"
#include "QWrappers/qmessage_details.h"
#include "QWrappers/qmessage_handler.h"

class XmppMessageHandler;

class XmppConnection : public QObject
{
    Q_OBJECT
public:
    explicit XmppConnection(QString, QString, QString);
    ~XmppConnection();

private:
    std::string receiver_username;
    gloox::Client *client;
    XmppConnectionThread *connection_thread;
    XmppMessageHandler *my_message_handler;
    QMessageHandler *registered_message_handler;

public:
    void start();
    void registerMessageHandler(QMessageHandler*);
    void registerConnectionListener(gloox::ConnectionListener*);
    void sendMessage(QString);

signals:
    void messageArrived(QMessageDetails message);
public slots:
    void onMessageArrived(QMessageDetails message);
};

#endif

