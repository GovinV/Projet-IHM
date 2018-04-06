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
private : 
	QString IP;
	int port;
	QTcpSocket soc;
};

ClientTCP::ClientTcp()
{
	port=8888; 
	IP="127.0.0.1";
	soc.connectToHost(IP,port); 
	QObject::connect(&soc,SIGNAL(connected()),this,SLOT(connec_OK()));
	// signal emit when co
	QObject:: connect(&soc, SIGNAL(readyRead()), this, SLOT(reading()));
	// signal emit when reading possible
}

void ClientTCP::UI_to_Soc(QString t)
{
	QTextStream texte(&soc); // stream to soc
	texte << t<<endl;        // write into soc from UI
}
void ClientTCP::connec_OK()
{
	emit vers_UI_connexion_OK(); // signal to UI
}
void ClientTCP::reading()
{
	QString line;
	while(soc.canReadLine()) // while anything to read
	{
		line = soc.readLine();     // read a line
		emit vers_UI_texte(ligne); // send to UI
	}
}