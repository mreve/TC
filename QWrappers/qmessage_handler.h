#ifndef QMESSAGE_HANDLER_H
#define QMESSAGE_HANDLER_H

#include <QWrappers/qmessage_details.h>

class QMessageHandler : public QObject {
    Q_OBJECT

public:
    virtual void handleMessage(QMessageDetails &message) = 0;
};

#endif // QMESSAGE_HANDLER_H
