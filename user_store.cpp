#include "user_store.h"

UserStore::UserStore(){
}

UserStore::~UserStore(){
    delete options;
}

bool UserStore::login(const QString& username, const QString& password) {
    /*
     *TODO: not yet implemented
     */
    this->username = username;
    this->logged = true;
    return true;
}

/*!
 * \brief UserStore::registerUser
 * \param username
 * \param password
 * \return false if username already exists, true if registration was succesful
 */
bool UserStore::registerUser(const QString &username, const QString &password) {
    /*
     *TODO: not yet implemented
     */
    return true;
}

QString UserStore::getUsername() {
    if (logged) {
        return this->username;
    }
    return "";
}

UserOptions *UserStore::getOptions() {
    return this->options;
}

QVector<XmppAccount*> UserStore::getXmppAccounts() {
    return xmppAccounts;
}
