#ifndef FILERECEIVER_H
#define FILERECEIVER_H

#include "mainwindow.h"
#include <QThread>

class MainWindow;

class FileReceiver: public QObject
{
	public:
		FileReceiver(MainWindow *mw);

		~FileReceiver();

	public slots:
		void OnReceive(MainWindow *mw);

	signals:
		void StartExchange();

	private:
		QThread *thread;
};

#endif // FILERECEIVER_H
