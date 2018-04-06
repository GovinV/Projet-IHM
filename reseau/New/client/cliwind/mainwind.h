#ifndef MAINWIND_H
#define MAINWIND_H

#include <QMainWindow>
#include "ClientTcp.h"


namespace Ui {
class MainWind;
}

class MainWind : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWind(QWidget *parent = 0);
    ~MainWind();

private slots:
    void on_lineEdit_returnPressed();

private:
    Ui::MainWind *ui;
    ClientTcp client;
};

#endif // MAINWIND_H
