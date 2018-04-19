#ifndef SERVERMODEL_H
#define SERVERMODEL_H

#include <QAbstractListModel>
//#include <QDebug>

class ServerList;

class ServerModel: public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(ServerList *list READ list WRITE setList)

public:
    explicit ServerModel(QObject *parent = nullptr);

    enum {
        NameRole,
        IdRole,
        PlayerRole,
        MaxRole,
    };

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    virtual QHash<int, QByteArray> roleNames() const override;

    ServerList* list() const;
    void setList(ServerList* list);

private:
    ServerList* _list;
};


#endif // SERVERMODEL_H
