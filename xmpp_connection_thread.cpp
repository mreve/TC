#include "xmpp_connection_thread.h"

XmppConnectionThread::XmppConnectionThread(gloox::Client *client) {
    this->client = client;
}

void XmppConnectionThread::run() {
    client->connect();
}
