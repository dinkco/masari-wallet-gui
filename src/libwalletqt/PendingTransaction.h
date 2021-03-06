#ifndef PENDINGTRANSACTION_H
#define PENDINGTRANSACTION_H

#include <QObject>

#include <wallet/wallet2_api.h>

//namespace Masari {
//class PendingTransaction;
//}

class PendingTransaction : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Status status READ status)
    Q_PROPERTY(QString errorString READ errorString)
    Q_PROPERTY(quint64 amount READ amount)
    Q_PROPERTY(quint64 fee READ fee)
    Q_PROPERTY(QStringList txid READ txid)
    Q_PROPERTY(quint64 txCount READ txCount)

public:
    enum Status {
        Status_Ok       = Masari::PendingTransaction::Status_Ok,
        Status_Error    = Masari::PendingTransaction::Status_Error,
        Status_Critical    = Masari::PendingTransaction::Status_Critical
    };
    Q_ENUM(Status)

    enum Priority {
        Priority_Low    = Masari::PendingTransaction::Priority_Low,
        Priority_Medium = Masari::PendingTransaction::Priority_Medium,
        Priority_High   = Masari::PendingTransaction::Priority_High
    };
    Q_ENUM(Priority)


    Status status() const;
    QString errorString() const;
    Q_INVOKABLE bool commit();
    quint64 amount() const;
    quint64 fee() const;
    QStringList txid() const;
    quint64 txCount() const;
    Q_INVOKABLE void setFilename(const QString &fileName);

private:
    explicit PendingTransaction(Masari::PendingTransaction * pt, QObject *parent = 0);

private:
    friend class Wallet;
    Masari::PendingTransaction * m_pimpl;
    QString m_fileName;
};

#endif // PENDINGTRANSACTION_H
