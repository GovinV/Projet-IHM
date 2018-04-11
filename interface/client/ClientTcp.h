#include "QtNetwork/QTcpSocket"

class ClientTcp : public QObject
{
Q_OBJECT
public :
    ClientTcp();
public slots :
    void UI_to_Soc(QString t); // UI to socket
private slots :
    void connec_OK();     // soc to UI
    void reading();       // soc read then to UI
signals :
    void UI_connec_OK();
    void UI_text(QString);
    void readingComplete(QString str);
private :
    QString IP;
    int port;
    QTcpSocket soc;
    QString msg;
};
