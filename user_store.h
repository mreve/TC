#ifndef USER_STORE_H
#define USER_STORE_H

#include <QObject>
#include <QString>

#include "UserComponents/user_options.h"
#include "UserComponents/xmpp_account.h"

/*!
 * \class UserStore
 * \brief Class for managing user data stored in application.
 */
class UserStore : public QObject {
    Q_OBJECT
private:
    UserStore(QString db_name);
    UserStore(const UserStore &);
    ~UserStore();

private:
    bool logged;
    QString username;
    UserOptions options;
    QVector<XmppAccount*> xmppAccounts;


public:
    bool login(QString username, QString password);
    bool getUsername(QString&);
    bool getOptions(UserOptions&);
    QVector<XmppAccount*> &getXmppAccounts();

    static UserStore &getInstance() {
        static UserStore instance;
        return instance;
    }
};

#endif // USER_STORE_H
