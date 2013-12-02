#ifndef USER_STORE_H
#define USER_STORE_H

#include <QObject>
#include <QString>
#include <QVector>

#include "UserComponents/user_options.h"
#include "UserComponents/xmpp_account.h"

/*!
 * \class UserStore
 * \brief Class for managing user data stored in application.
 */
class UserStore : public QObject {
    Q_OBJECT
private:
    UserStore();
    UserStore(const UserStore &);
    ~UserStore();

private:
    bool logged;
    QString username;
    UserOptions* options;
    QVector<XmppAccount*> xmppAccounts;


public:
    static UserStore &getInstance() {
        static UserStore instance;
        return instance;
    }

public slots:
    bool login(const QString& username, const QString& password);
    bool registerUser(const QString& username, const QString& password);
    QString getUsername();
    UserOptions* getOptions();
    QVector<XmppAccount*> getXmppAccounts();
};

#endif // USER_STORE_H
