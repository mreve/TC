#include "threading_chat.h"
#include <QDebug>
#include <QGraphicsWebView>
#include <QWebFrame>

ThreadingChat::ThreadingChat(QWidget *parent) : Html5ApplicationViewer(parent) {
    QObject::connect(webView()->page()->mainFrame(),
            SIGNAL(javaScriptWindowObjectCleared()), SLOT(addToJavaScript()));
}

void ThreadingChat::addToJavaScript() {
    webView()->page()->mainFrame()->addToJavaScriptWindowObject("TChat", this);
    webView()->page()->mainFrame()->addToJavaScriptWindowObject("UserStore", &UserStore::getInstance());
}

void ThreadingChat::init() {
    this->setOrientation(Html5ApplicationViewer::ScreenOrientationAuto);
    this->resize(600, 500);
    this->loadFile("html/index.html");
}

void ThreadingChat::loadMain(int x, int y, int width, int height) {
    this->resize(width, height);
    this->move(x, y);
    this->loadFile("html/main.html");
}
