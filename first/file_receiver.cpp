#include "file_receiver.h"

FileReceiver::FileReceiver(MainWindow *mw)
{
	this->thread = new QThread();
	/*FileReceiver *receiver = new FileReceiver();
	receiver->moveToThread(thread);
	connect(thread, &QThread::finished, receiver, &QObject::deleteLater);
	connect(this, StartExchange());
	thread->start();*/
}


void FileReceiver::OnReceive(MainWindow *mw) {
	Recieve_file_mode *window = new Recieve_file_mode(mw->GetLinkLevelInstance(), mw);
	window->show();
}


FileReceiver::~FileReceiver() {
	thread->quit();
	delete thread;
}
