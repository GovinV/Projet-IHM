#ifndef HANDMODEL_H
#define HANDMODEL_H

#include <QAbstractListModel>

#include "core/carte.h"

#include "hand.h"

class HandModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum CarteRoles{
        CouleurRole = Qt::UserRole+1,
        TypeRole,
        ValeurRole
    };

    HandModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    virtual QHash<int, QByteArray> roleNames() const override;

    Hand *hand() const;
    void setHand(Hand *hand);

private:
    Hand *m_hand;
};

#endif // HANDMODEL_H
