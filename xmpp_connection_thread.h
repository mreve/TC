#ifndef XMPP_CONNECTION_THREAD_H
#define XMPP_CONNECTION_THREAD_H

#include <QThread>
#include <gloox/client.h>

class XmppConnectionThread : public QThread {
    Q_OBJECT

public:
    XmppConnectionThread(gloox::Client *client);

private:
    gloox::Client *client;

protected:
    void run();
};

#endif // XMPP_CONNECTION_THREAD_H
