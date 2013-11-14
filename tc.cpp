#include <QDebug>
#include <QGraphicsWebView>
#include <QWebFrame>

#include "tc.h"

TChat::TChat(QWidget *parent) : Html5ApplicationViewer(parent) {
    QObject::connect(webView()->page()->mainFrame(),
            SIGNAL(javaScriptWindowObjectCleared()), SLOT(addToJavaScript()));
}

void TChat::addToJavaScript() {
    webView()->page()->mainFrame()->addToJavaScriptWindowObject("TChat", this);
}

void TChat::loadMain(int x, int y, int width, int height) {
    this->resize(width, height);
    this->move(x, y);
    this->loadFile("html/main.html");
}

void TChat::setUserAndPassword(QString username, QString password) {
    this->username = username;
    this->password = password;
}

QString TChat::getUser() {
    return this->username;
}
