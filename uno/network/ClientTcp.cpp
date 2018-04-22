#include "ClientTcp.h"

ClientTcp::ClientTcp()
{
    port=2213;
    IP="130.79.49.198";
    soc.connectToHost(IP,port);
    QObject::connect(&soc,SIGNAL(connected()),this,SLOT(connec_OK()));
	// signal emit when co
    QObject:: connect(&soc, SIGNAL(readyRead()), this, SLOT(reading()));
	// signal emit when reading possible
}

void ClientTcp::UI_to_Soc(QString t)
{
	QTextStream texte(&soc); // stream to soc
	texte << t<<endl;        // write into soc from UI
}
void ClientTcp::connec_OK()
{
    emit UI_connec_OK(); // signal to UI
}
void ClientTcp::reading()
{
    qDebug() << "read";
    QString line="";
	while(soc.canReadLine()) // while anything to read
	{
        line = soc.readLine();     // read a line
        //ui->insertPlainText(line);
        //emit UI_text(line); // send to UI
    }
    qDebug() << "end read";
    emit readingComplete(line);
}
