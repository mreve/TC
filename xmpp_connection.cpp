#include "xmpp_connection.h"
#include "xmpp_connection_thread.h"
#include "xmpp_message_handler.h"

XmppConnection::XmppConnection(QString sender_username,
                               QString sender_password,
                               QString receiver_username) {
    gloox::JID jid(sender_username.toStdString());
    this->client = new gloox::Client(jid, sender_password.toStdString());
    this->receiver_username = receiver_username.toStdString();
}

void XmppConnection::sendMessage(QString message_text) {
    gloox::Message msg(gloox::Message::Chat, receiver_username, message_text.toStdString());
    client->send(msg);
}

void XmppConnection::start() {
    connection_thread = new XmppConnectionThread(client);
    connection_thread->start();
}

void XmppConnection::registerConnectionListener(gloox::ConnectionListener *cl) {
    client->registerConnectionListener(cl);
}

void XmppConnection::registerMessageHandler(QMessageHandler *mh) {
    this->my_message_handler = new XmppMessageHandler(this);
    this->registered_message_handler = mh;
    this->client->registerMessageHandler(my_message_handler);
}

void XmppConnection::onMessageArrived(QMessageDetails message) {
    this->registered_message_handler->handleMessage(message);
}

XmppConnection::~XmppConnection() {
    delete client;
    if (connection_thread != NULL && connection_thread->isRunning()) {
        connection_thread->exit();
    }
    delete connection_thread;
    delete my_message_handler;
}

