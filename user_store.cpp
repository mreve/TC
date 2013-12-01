#include "user_store.h"

UserStore::UserStore(){
}

UserStore::~UserStore(){
    delete options;
}

void UserStore::login(const QString& username, const QString& password) {
    /*
     *TODO: not yet implemented
     */
    this->username = username;
    this->logged = true;
}


bool UserStore::getUsername(QString &result) {
    if (logged) {
        result = this->username;
    }
    return logged;
}

bool UserStore::getOptions(UserOptions &result) {
    result = this->options;
    return true;
}

QVector<XmppAccount*> UserStore::getXmppAccounts() {
    return xmppAccounts;
}
