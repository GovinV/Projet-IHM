#ifndef HAND_H
#define HAND_H

#include <QObject>
#include <QVector>

#define TYPE_NB 0
#define TYPE_S_P2 1

struct HandItem
{
    int type;
    QString color;
    int value;
};

class Hand : public QObject
{
    Q_OBJECT

public:
    explicit Hand(QObject *parent = nullptr);

    QVector<HandItem> items() const;

    bool setItemAt(int index, HandItem &item);

signals:
    void preItemAppended();
    void postItemAppended();

    void preItemRemoved(int index);
    void postItemRemoved();

public slots:
    void appendItem(int type, QString color, int value);
    void removeItem(int index);
    void clear();

private:
    QVector<HandItem> _items;
};

#endif // HAND_H
