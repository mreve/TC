#include "html5applicationviewer/html5applicationviewer.h"

class TChat : public Html5ApplicationViewer
{
    Q_OBJECT
public:
    explicit TChat(QWidget *parent=0);
private:
    QString username;
    QString password;
private slots:
    void addToJavaScript();
public slots:
    void loadMain(int x, int y, int width, int height);
    void setUserAndPassword(QString username, QString password);
    QString getUser();
};
