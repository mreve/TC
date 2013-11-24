#include "xmpp_message_handler.h"
#include <QDebug>

XmppMessageHandler::XmppMessageHandler(XmppConnection *xc) {
    this->xmpp_connection = xc;
}

void XmppMessageHandler::handleMessage(const gloox::Message &stanza, gloox::MessageSession *session) {
    QMessageDetails qmd(QString::fromUtf8(stanza.from().bare().c_str()),
                        QString::fromUtf8(stanza.from().bare().c_str()),
                        QString::fromUtf8(stanza.body().c_str()),
                        QString::fromUtf8(stanza.thread().c_str()),
                        QString::fromUtf8(stanza.subject().c_str()));

    emit xmpp_connection->messageArrived(qmd);
}
