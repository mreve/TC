#ifndef USER_STORE_H
#define USER_STORE_H

#include <QObject>
#include <QString>

class UserStore : public QObject {
    Q_OBJECT
private:
    UserStore(QString db_name);
    UserStore(const UserStore &);
    ~UserStore();

private:

public:
    bool login(QString username, QString password);

    static UserStore &getInstance() {
        static UserStore instance;
        return instance;
    }
};

#endif // USER_STORE_H
