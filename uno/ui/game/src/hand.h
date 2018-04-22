#ifndef HAND_H
#define HAND_H

#include <QObject>
#include <QVector>

#define TYPE_NB 0   // number
#define TYPE_S_P2 1 // +2
#define TYPE_S_SW 2 // switch
#define TYPE_S_SK 3 // skip
#define TYPE_S_P4 4 // +4
#define TYPE_S_CO 5 // color

struct HandItem
{
    int type;
    QString color;
    int value;
    // ajouter une var pour le style des cartes ?
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
    HandItem getItem(int index);
    void removeItem(int index);
    void clear();

private:
    QVector<HandItem> _items;
};

#endif // HAND_H
