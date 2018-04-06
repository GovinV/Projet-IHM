#include "mainwind.h"
#include "ui_mainwind.h"

MainWind::MainWind(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWind)
{
    ui->setupUi(this);
    client.ui=ui->textBrowser;
}

MainWind::~MainWind()
{
    delete ui;
}

void MainWind::on_lineEdit_returnPressed()
{
    client.UI_to_Soc(ui->lineEdit->text());
    ui->textBrowser->insertPlainText("you: " + ui->lineEdit->text() +"\n");
}


