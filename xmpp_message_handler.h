#ifndef XMPP_MESSAGE_HANDLER_H
#define XMPP_MESSAGE_HANDLER_H

#include <gloox/client.h>
#include <gloox/message.h>
#include <gloox/messagehandler.h>
#include <gloox/connectionlistener.h>
#include <QObject>
#include "xmpp_connection.h"

class XmppConnection;

class XmppMessageHandler : public QObject, public gloox::MessageHandler {
    Q_OBJECT
private:
    XmppConnection *xmpp_connection;
public:
    XmppMessageHandler(XmppConnection*);

    void handleMessage(const gloox::Message &stanza, gloox::MessageSession *session = 0);
};

#endif //XMPP_MESSAGE_HANDLER_H
