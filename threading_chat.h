#ifndef THREADING_CHAT_H
#define THREADING_CHAT_H

#include "html5applicationviewer/html5applicationviewer.h"
#include "user_store.h"

class ThreadingChat : public Html5ApplicationViewer {
    Q_OBJECT
public:
    explicit ThreadingChat(QWidget *parent=0);
    void init();

private slots:
    void addToJavaScript();

public slots:
    void loadMain(int x, int y, int width, int height);
};

#endif // THREADING_CHAT_H
