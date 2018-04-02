#ifndef HANDMODEL_H
#define HANDMODEL_H

// a row is a card
// a column is an attribute of a card

#include <QAbstractListModel>

class HandModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit HandModel(QObject *parent = nullptr);

    enum{
        SourceRole
    };

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Add data:
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;

    // Remove data:
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;

    virtual QHash<int, QByteArray> roleNames() const override;

private:
};

#endif // HANDMODEL_H
