#ifndef QMESSAGE_DETAILS_H
#define QMESSAGE_DETAILS_H

#include <QObject>
#include <QString>

class QMessageDetails {
private:
   QString m_from;
   QString m_to;
   QString m_body;
   QString m_threadId;
   QString m_subject;

public:
   QMessageDetails(QString from = "", QString to = "", QString body = "", QString threadId = "", QString subject = "")
       : m_from(from), m_to(to), m_body(body), m_threadId(threadId), m_subject(subject) {}

   QMessageDetails(const QMessageDetails &other) {
       this->m_from = other.m_from;
       this->m_to = other.m_to;
       this->m_body = other.m_body;
       this->m_threadId = other.m_threadId;
       this->m_subject = other.m_subject;
   }

   QString from() {
       return this->m_from;
   }

   QString to() {
       return this->m_to;
   }

   QString body() {
       return this->m_body;
   }

   QString subject() {
       return this->m_subject;
   }

   QString threadId() {
       return this->m_threadId;
   }
};

Q_DECLARE_METATYPE(QMessageDetails)

#endif // QMESSAGE_DETAILS_H
