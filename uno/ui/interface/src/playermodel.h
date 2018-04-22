#ifndef PLAYERMODEL_H
#define PLAYERMODEL_H

#include <QAbstractListModel>
#include <QDebug>

class PlayerList;

class PlayerModel: public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(PlayerList *list READ list WRITE setList)

public:
    explicit PlayerModel(QObject *parent = nullptr);

    enum {
        IdRole,
        NameRole,
        ReadyRole,
    };
    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    virtual QHash<int, QByteArray> roleNames() const override;

    PlayerList* list() const;
    void setList(PlayerList* list);

private:
    PlayerList* _list;
};


#endif // PLAYERMODEL_H
