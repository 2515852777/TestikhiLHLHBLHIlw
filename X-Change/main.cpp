#include "Clientdialog.h"
#include <QApplication>
#include <QDir>
#include <QTextCodec>
#include <QCoreApplication>
#include"qwindow.h"
#include <QLibrary>
#include <QMessageBox>
#include<QDebug>
#include<iostream>


using namespace std;
typedef char* (*Fun)(char*, char*, char*, int*);
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Clientdialog w;
	w.show();
	return a.exec();

}
