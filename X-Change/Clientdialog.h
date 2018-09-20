#pragma once

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef CLIENTDIALOG_H
#define CLIENTDIALOG_H
#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QTextEdit>
#include <QListWidget>
#include <QPushButton>
#include <QObject>
#include <QWidget>
#include <QUrl>
#include <time.h>
#include <QByteArray>
#include<QLibrary>
#include <QDir>
#include <QTextCodec>
#include <QCoreApplication>
#include"qwindow.h"
#include <QMessageBox>
#include<QDebug>
#include<iostream>
#include<QMetaEnum>
#include<QComboBox>
#include<QListWidgetItem>

class Clientdialog : public QWidget
{
	Q_OBJECT

public:
	explicit Clientdialog( QWidget *parent = 0);
	~Clientdialog();
public slots:
	void onStartbuttonclick();
	void onStopbuttonclick();
	void onClearbuttonclick();
	void onComboboxclick(const QString&);
	void onSeekbuttonclick();
	void onserialmsg(QListWidgetItem *current, QListWidgetItem *previous);
	static void callback(const char*);
	void onSendbuttonclick();

	void startbutton();
	void stopbutton();
	void pausebutton();
	void continbutton();

signals:
	void sendstring(QString mag);
private slots:

public :
	QPushButton* m_startbutton;
	QPushButton* m_stopbutton;
	QPushButton* m_sendbutton;
	QPushButton* m_clearbutton;
	QPushButton* m_seekbutton;
	QComboBox* m_combobox;
    QListWidget*  m_iplist;
	QTextEdit* m_sendtextedit;
	QTextEdit* m_receivetextedit;
	QLineEdit* m_seriallineedit;
	QLabel *statusLabel; 
	QUrl m_url;
	QLineEdit* m_line1Edit;
	QLineEdit* m_line2Edit;
	QLineEdit* m_line3Edit;
	QLineEdit* m_line4Edit;
	bool m_debug;
	QDateTime *current_date_time;
	QButtonGroup *pButtonGroup;
	void Open(char* p1, char* p2, char* p3);

	QLineEdit* scriptline;
	QPushButton* b_start;
	QPushButton* b_stop;
	QPushButton* b_pause;
	QPushButton* b_contin;

};
#endif // CLIENTDIALOG_H
