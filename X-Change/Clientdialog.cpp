#include "Clientdialog.h"
#include <QLabel>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QtCore>
#include <QDebug>
#include <iostream>
#include <QMetaEnum>
#include"qmenu.h"
#include"addon.h"
#include<QIcon>
#include<fstream>
#include <QFileDialog>      
#include <QFile>            
#include <QTextStream>  
#include<QFont>
using namespace std;
void Clientdialog::callback(const char * message)
{
	qDebug() << message;
	QFile file("data.txt");
	QByteArray msg;
	if (file.open(QIODevice::Append|QIODevice::WriteOnly|QIODevice::Text))
	{
		QByteArray msg = message;
		QJsonValue str0, str1, str2;
		QJsonParseError jsonError;
		QJsonDocument document = QJsonDocument::fromJson(msg, &jsonError);
		if (!document.isNull() && (jsonError.error == QJsonParseError::NoError))
		{
			if (document.isObject())
			{
				QJsonObject object = document.object();
				if (object.contains("data"))
				{
					str0 = object.value("data");
					if (str0.isObject())
					{
						QJsonObject object1 = str0.toObject();

						if (object1.contains("device_ip"))
						{
							str1 = object1.value("device_ip");
						}
						if (object1.contains("serial"))
						{
							str2 = object1.value("serial");
						}
					}
				}
			}
		}
		QString Str1, Str2;
		Str1 =str1.toString();
		Str2 = str2.toString();
		qDebug() << Str1 << Str2;
		QByteArray s1 = nullptr;
		QByteArray s2 = nullptr;
		s1 = Str1.toLatin1();
		s2 = Str2.toLatin1();
		file.write(s2 + ' '+' '+' '+' '+' '+' '+ s1+ '\n');

	}
   file.close();
}

Clientdialog::Clientdialog( QWidget *parent)
	: QWidget(parent)
{
	QFont Font("STZhongsong", 12, 50);
	QFont font1("Times New Roman", 12, 50);
	m_startbutton = new QPushButton("启动");
	m_startbutton->setFont(Font);
	QLabel *label_1 = new QLabel("网段");
	QLabel *label_2 = new QLabel(":");
	QLabel *label_3 = new QLabel(":");
	QLabel *label_4 = new QLabel("  端口");
	label_1->setFont(Font);
	label_2->setFont(Font);
	label_3->setFont(Font);
	label_4->setFont(Font);
	QSpacerItem* hSpacer0 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
	m_line1Edit = new QLineEdit;
	m_line1Edit->setFixedWidth(50);
	m_line2Edit = new QLineEdit;
	m_line2Edit->setFixedWidth(50);
	m_line3Edit = new QLineEdit;
	m_line3Edit->setFixedWidth(50);
	m_line4Edit = new QLineEdit;
	m_line4Edit->setFixedWidth(50);
	m_line1Edit->setFont(font1);
	m_line2Edit->setFont(font1);
	m_line3Edit->setFont(font1);
	m_line4Edit->setFont(font1);

	QHBoxLayout *lay0 = new QHBoxLayout;
	lay0->addWidget(label_1);
	lay0->addWidget(m_line1Edit);
	lay0->addWidget(label_2);
	lay0->addWidget(m_line2Edit);
	lay0->addWidget(label_3);
	lay0->addWidget(m_line3Edit);
	lay0->addWidget(label_4);
	lay0->addWidget(m_line4Edit);
	lay0->addSpacerItem(hSpacer0);
	lay0->addStretch();
	lay0->addWidget(m_startbutton);

	QLabel* Cmd = new QLabel("接口命令调用列表");
	Cmd->setFont(Font);
	m_stopbutton = new QPushButton("重置");
	m_stopbutton->setEnabled(true);
	m_stopbutton->setFont(Font);
	QHBoxLayout* lay1 = new QHBoxLayout;
	lay1->addWidget(Cmd);
	lay1->addStretch();
	lay1->addWidget(m_stopbutton);
	
	m_combobox = new QComboBox;
	m_combobox->setFixedSize(210, 30);
	QFont font("Times New Roman", 14, 50);
	m_combobox->setFont(font);
	m_combobox->addItem(tr("device.arc.run"));
	m_combobox->addItem(tr("device.config"));	
	m_combobox->addItem(tr("device.control"));
	
	m_combobox->addItem(tr("device.detail.read"));
	m_combobox->addItem(tr("device.drag"));
	m_combobox->addItem(tr("device.drag.stop"));
	m_combobox->addItem(tr("device.file.receive"));
	m_combobox->addItem(tr("device.file.send"));
	m_combobox->addItem(tr("device.info.read"));
	m_combobox->addItem(tr("device.initialize"));
	m_combobox->addItem(tr("device.initialize.abort"));
	m_combobox->addItem(tr("device.initialized.read"));
	m_combobox->addItem(tr("device.io.config"));
	m_combobox->addItem(tr("device.io.read"));
	m_combobox->addItem(tr("device.joint.run"));
	m_combobox->addItem(tr("device.log.query"));
	m_combobox->addItem(tr("device.monitor"));
	m_combobox->addItem(tr("device.motion.config"));
	m_combobox->addItem(tr("device.motion.read"));
	m_combobox->addItem(tr("device.param.read"));
	m_combobox->addItem(tr("device.power.off"));
	m_combobox->addItem(tr("device.reconnect"));
	m_combobox->addItem(tr("device.release"));
	m_combobox->addItem(tr("device.run"));
	m_combobox->addItem(tr("device.running.read"));
	m_combobox->addItem(tr("device.script.query"));
	m_combobox->addItem(tr("device.script.delete"));
	m_combobox->addItem(tr("device.teach.query"));
	m_combobox->addItem(tr("device.update"));
	m_combobox->addItem(tr("device.velocity.config"));
	m_combobox->addItem(tr("utils.local.ip4"));
	
	b_start = new QPushButton("开始");
	b_stop = new QPushButton("停止");
	b_pause = new QPushButton("暂停");
	b_contin = new QPushButton("继续");
	b_start->setFont(Font);
	b_stop->setFont(Font);
	b_pause->setFont(Font);
	b_contin->setFont(Font);

	QHBoxLayout* lay2 = new QHBoxLayout;
	lay2->addWidget(m_combobox);
	lay2->addWidget(b_start);
	lay2->addWidget(b_stop);
	lay2->addWidget(b_pause);
	lay2->addWidget(b_contin);
	lay2->addStretch();


	QLabel* send = new QLabel("发送消息");
	send->setFont(Font);
	m_sendbutton = new QPushButton("发送");
	m_sendbutton->setFont(Font);
	m_sendtextedit = new  QTextEdit();
	m_sendtextedit->setEnabled(true);
	m_sendtextedit->setFont(font1);

	QHBoxLayout* lay03 = new QHBoxLayout;
	QHBoxLayout* lay04 = new QHBoxLayout;
	lay03->addWidget(send);
	lay03->addStretch();
	lay03->addWidget(m_sendbutton);
	lay04->addWidget(m_sendtextedit);
	QVBoxLayout* lay21 = new QVBoxLayout;
	lay21->addLayout(lay03);
	lay21->addLayout(lay04);
	
	QLabel* rece = new QLabel("接收消息");
	rece->setFont(Font);
	m_clearbutton = new QPushButton("清除");
	m_clearbutton->setFont(Font);
	m_receivetextedit = new QTextEdit();
	m_receivetextedit->setFont(font1);
	m_receivetextedit->setEnabled(true);


	QHBoxLayout* lay01 = new QHBoxLayout;
	QHBoxLayout* lay02 = new QHBoxLayout;
	lay01->addWidget(rece);
	lay01->addStretch();
	lay01->addWidget(m_clearbutton);
	lay02->addWidget(m_receivetextedit);
	QVBoxLayout* lay22 = new QVBoxLayout;
	lay22->addLayout(lay01);
	lay22->addLayout(lay02);

	QHBoxLayout* lay3 = new QHBoxLayout;
	lay3->addLayout(lay21, 1);
	lay3->addLayout(lay22, 1);

	QLabel* serial = new QLabel("序列号");
	serial->setFont(Font);
	m_seriallineedit = new QLineEdit();
	m_seriallineedit->setEnabled(true);
	m_seriallineedit->setFixedSize(290,25);
	m_seriallineedit->setFont(font1);
	QLabel* scri = new QLabel("脚本名");
	scri->setFont(Font);
	scriptline = new QLineEdit();
	scriptline->setEnabled(true);
	scriptline->setFixedSize(130,25);
	scriptline->setFont(Font);
	
	QHBoxLayout* lay5 = new QHBoxLayout;
	lay5->addWidget(serial);
	lay5->addWidget(m_seriallineedit);
	lay5->addWidget(scri);
	lay5->addWidget(scriptline);
	lay5->addStretch();


	QLabel* iplist = new QLabel("设备列表  序列号    IP");
	m_seekbutton = new QPushButton("查询");
	iplist->setFont(Font);
	m_seekbutton->setFont(Font);
	m_seekbutton->setEnabled(true);
	QHBoxLayout* lay6 = new QHBoxLayout;
	lay6->addWidget(iplist);
	lay6->addStretch();
	lay6->addWidget(m_seekbutton);

	m_iplist = new QListWidget();
	m_iplist->setFont(font1);
	QHBoxLayout* lay7 = new QHBoxLayout;
	lay7->addWidget(m_iplist);
	
	QVBoxLayout* mywidget = new QVBoxLayout;
	mywidget->addLayout(lay0, 1);
	mywidget->addLayout(lay1, 1);
	mywidget->addLayout(lay2, 1);
	mywidget->addLayout(lay5, 1);
	mywidget->addLayout(lay3, 3);
	mywidget->addLayout(lay6, 1);
	mywidget->addLayout(lay7, 1);
	
	
	QIcon icon("tubiao.png");
	setLayout(mywidget);
	setMinimumSize(700, 630);
	setWindowTitle("机器人接口测试工具    版本 0.1.0");
	setWindowIcon(icon);

	connect(m_startbutton, SIGNAL(clicked(bool)), this, SLOT(onStartbuttonclick()));
	connect(m_stopbutton, SIGNAL(clicked(bool)), this, SLOT(onStopbuttonclick()));
	connect(m_clearbutton, SIGNAL(clicked(bool)), this, SLOT(onClearbuttonclick()));
	connect(m_combobox, SIGNAL(currentIndexChanged(const QString &)), this, SLOT(onComboboxclick(const QString &)));
	connect(m_seekbutton, SIGNAL(clicked(bool)), this, SLOT(onSeekbuttonclick()));
	connect(m_iplist, SIGNAL(currentItemChanged(QListWidgetItem *, QListWidgetItem *)), this, SLOT(onserialmsg(QListWidgetItem *, QListWidgetItem *)));
	connect(m_sendbutton, SIGNAL(clicked(bool)), this, SLOT(onSendbuttonclick()));
	connect(b_start, SIGNAL(clicked(bool)), this, SLOT(startbutton()));
	connect(b_stop, SIGNAL(clicked(bool)), this, SLOT(stopbutton()));
	connect(b_pause, SIGNAL(clicked(bool)), this, SLOT(pausebutton()));
	connect(b_contin, SIGNAL(clicked(bool)), this, SLOT(continbutton()));

	QFile file("data.txt");
	if (file.open(QIODevice::WriteOnly))
	{
	}
	file.close();

	typedef void(*Fun2)(callback_async_event);
	QLibrary mylib("addon.dll");
	if (mylib.load())
	{
		Fun2 register_action_callback_async_event = (Fun2)mylib.resolve("register_action_callback_async_event");
		if (register_action_callback_async_event)
		{
			register_action_callback_async_event(callback);
		}
	}
}

Clientdialog::~Clientdialog()
{
	;
}
void Clientdialog::onStartbuttonclick()
{
	QString S1 = m_line1Edit->text();
	QString S2 = m_line2Edit->text();
	QString S3 = m_line3Edit->text();
	QString S4 = m_line4Edit->text();
	
	int s1 = S1.toInt();
	int s2 = S2.toInt();
	int s3 = S3.toInt();
	int s4 = S4.toInt();
	char* p1 = "device.refresh";
	char* p2 = "";
	QJsonObject obj;
	QJsonDocument document;
	char* p3 = nullptr;
	obj.insert("ip_1", s1);
	obj.insert("ip_2", s2);
	obj.insert("ip_3", s3);
	obj.insert("port", s4);
	obj.insert("timeout", 3);
	obj.insert("num", 10);
	document.setObject(obj);
	QByteArray array1 = document.toJson(QJsonDocument::Indented);
	p3 = array1.data();
	Open(p1, p2, p3);
	
}
void Clientdialog::onStopbuttonclick()
{
	m_sendtextedit->clear();
	m_seriallineedit->clear();
	m_receivetextedit->clear();
	m_iplist->clear();
	scriptline->clear();
	m_line1Edit->clear();
	m_line2Edit->clear();
	m_line3Edit->clear();
	m_line4Edit->clear();

	QFile file("data.txt");
	if (file.open(QIODevice::WriteOnly))
	{
	}
	file.close();
	
}
void Clientdialog::onClearbuttonclick()
{
	m_receivetextedit->clear();
}

void Clientdialog::onComboboxclick(const QString & index)
{
	QString Str = m_combobox->currentText();
	if (Str == "device.control")
	{
		m_sendtextedit->clear();
		QString str2 = m_seriallineedit->text();
		QJsonObject obj1;
		obj1.insert("action", "device.control");
		obj1.insert("serial", str2);
		obj1.insert("password", "123456");
		obj1.insert("username", "admin");
		obj1.insert("user_ip", "10.0.0.120 ");
		QJsonDocument document;
		document.setObject(obj1);
		QByteArray byteArray = document.toJson(QJsonDocument::Indented);
		QString msg(byteArray);
		m_sendtextedit->setText(msg);
	}
	else if (Str == "device.info.read")
	{
		m_sendtextedit->clear();
		QJsonObject obj1;
		obj1.insert("time", "2018-01-01 00:00:00");
		QJsonDocument document;
		document.setObject(obj1);
		QByteArray byteArray = document.toJson(QJsonDocument::Indented);
		QString msg(byteArray);
		m_sendtextedit->setText(msg);
	}
	else if (Str == "device.monitor")
	{
		m_sendtextedit->clear();
		QJsonObject obj1;
		obj1.insert("monitor_name", "monitor");
		obj1.insert("monitor_ip", "10.0.0.100");
		QJsonDocument document;
		document.setObject(obj1);
		QByteArray byteArray = document.toJson(QJsonDocument::Indented);
		QString msg(byteArray);
		m_sendtextedit->setText(msg);
	}
	else if (Str == "device.config")
	{
		m_sendtextedit->clear();
		
		QJsonObject obj1;
		obj1.insert("name", "device1");
		obj1.insert("group", "group1");
		obj1.insert("password", "123456");
		obj1.insert("new_password", "101010");
		obj1.insert("ip", "192.168.1.105");
		obj1.insert("mask", "255.255.255.0");
		obj1.insert("gateway", "192.168.1.1");
		QJsonDocument document;
		document.setObject(obj1);
		QByteArray byteArray = document.toJson(QJsonDocument::Indented);
		QString msg(byteArray);
		m_sendtextedit->setText(msg);
	}
	else if (Str == "device.param.read")
	{
		m_sendtextedit->clear();
		
		QJsonObject obj1;
		QJsonDocument document;
		document.setObject(obj1);
		QByteArray byteArray = document.toJson(QJsonDocument::Indented);
		QString msg(byteArray);
		m_sendtextedit->setText(msg);
	}
	else if (Str == "device.detail.read")
	{
		m_sendtextedit->clear();
		QJsonObject obj1;
		QJsonDocument document;
		document.setObject(obj1);
		QByteArray byteArray = document.toJson(QJsonDocument::Indented);
		QString msg(byteArray);
		m_sendtextedit->setText(msg);
	}
	else if (Str == "device.running.read")
	{
		m_sendtextedit->clear();
		QJsonObject obj1;
		QJsonDocument document;
		document.setObject(obj1);
		QByteArray byteArray = document.toJson(QJsonDocument::Indented);
		QString msg(byteArray);
		m_sendtextedit->setText(msg);
	}
	else if (Str == "device.power.off")
	{
		m_sendtextedit->clear();
		QJsonObject obj1;
		QJsonDocument document;
		document.setObject(obj1);
		QByteArray byteArray = document.toJson(QJsonDocument::Indented);
		QString msg(byteArray);
		m_sendtextedit->setText(msg);
	}
	else if (Str == "device.monitor")
	{
		m_sendtextedit->clear();
		QJsonObject obj1;
		obj1.insert("monitor_name", "monitor");
		obj1.insert("monitor_ip", "196.168.1.97");
		QJsonDocument document;
		document.setObject(obj1);
		QString msg = document.toJson(QJsonDocument::Indented);
		//QString msg(byteArray);
		m_sendtextedit->setText(msg);
	}
	else if (Str == "device.release")
	{
		m_sendtextedit->clear();
		QJsonObject obj1;
		QJsonDocument document;
		document.setObject(obj1);
		QByteArray byteArray = document.toJson(QJsonDocument::Indented);
		QString msg(byteArray);
		m_sendtextedit->setText(msg);
	}
	else if (Str == "device.initialize")
	{
		m_sendtextedit->clear();
		QJsonObject obj1;
		obj1.insert("mode", 0);
		obj1.insert("joint_1", true);
		obj1.insert("joint_2", true);
		obj1.insert("joint_3", true);
		obj1.insert("joint_4", true);
		QJsonDocument document;
		document.setObject(obj1);
		QByteArray byteArray = document.toJson(QJsonDocument::Indented);
		QString msg(byteArray);
		m_sendtextedit->setText(msg);
	}
	else if (Str == "device.initialized.read")
	{
		m_sendtextedit->clear();
		QJsonObject obj1;
		QJsonDocument document;
		document.setObject(obj1);
		QByteArray byteArray = document.toJson(QJsonDocument::Indented);
		QString msg(byteArray);
		m_sendtextedit->setText(msg);
	}
	else if (Str == "device.initialize.abort")
	{
		m_sendtextedit->clear();
		QJsonObject obj1;
		QJsonDocument document;
		document.setObject(obj1);
		QByteArray byteArray = document.toJson(QJsonDocument::Indented);
		QString msg(byteArray);
		m_sendtextedit->setText(msg);
	}
	else if (Str == "device.joint.run")
	{
		m_sendtextedit->clear();
		QJsonObject obj1;
		obj1.insert("velocity", 1);
		obj1.insert("joint_1", 0);
		obj1.insert("joint_2", 0);
		obj1.insert("joint_3", 0);
		obj1.insert("joint_4", 0);
		QJsonDocument document;
		document.setObject(obj1);
		QByteArray byteArray = document.toJson(QJsonDocument::Indented);
		QString msg(byteArray);
		m_sendtextedit->setText(msg);
	}
	else if (Str == "device.drag")
	{
		m_sendtextedit->clear();
		QJsonObject obj1;
		obj1.insert("joint_1", true);
		obj1.insert("joint_2", true);
		obj1.insert("joint_3", true);
		obj1.insert("joint_4", true);
		obj1.insert("joint_1_current", 0.1);
		obj1.insert("joint_2_current", 0.1);
		obj1.insert("joint_3_current", 0.1);
		obj1.insert("joint_4_current", 0.1);
		QJsonDocument document;
		document.setObject(obj1);
		QByteArray byteArray = document.toJson(QJsonDocument::Indented);
		QString msg(byteArray);
		m_sendtextedit->setText(msg);
	}
	else if (Str == "device.drag.stop")
	{
		m_sendtextedit->clear();
		QJsonObject obj1;
	
		obj1.insert("joint_1", true);
		obj1.insert("joint_2", true);
		obj1.insert("joint_3", true);
		obj1.insert("joint_4", true);
		QJsonDocument document;
		document.setObject(obj1);
		QByteArray byteArray = document.toJson(QJsonDocument::Indented);
		QString msg(byteArray);
		m_sendtextedit->setText(msg);
	}
	else if (Str == "device.teach.query")
	{
		m_sendtextedit->clear();
		QJsonObject obj1;
		QJsonDocument document;
		document.setObject(obj1);
		QByteArray byteArray = document.toJson(QJsonDocument::Indented);
		QString msg(byteArray);
		m_sendtextedit->setText(msg);
	}
	else if (Str == "device.velocity.config")
	{
		m_sendtextedit->clear();
		QJsonObject obj1;
		obj1.insert("velocity", 0.5);
		QJsonDocument document;
		document.setObject(obj1);
		QByteArray byteArray = document.toJson(QJsonDocument::Indented);
		QString msg(byteArray);
		m_sendtextedit->setText(msg);
	}
	else if (Str == "device.run")
	{
		m_sendtextedit->clear();
		QJsonObject obj1;
		obj1.insert("script_name", "program_1.lua");
		obj1.insert("cmd", "start");
		obj1.insert("def", false);
		QJsonDocument document;
		document.setObject(obj1);
		QByteArray byteArray = document.toJson(QJsonDocument::Indented);
		QString msg(byteArray);
		m_sendtextedit->setText(msg);
	}
	else if (Str == "device.script.query")
	{
		m_sendtextedit->clear();
		QJsonObject obj1;
		QJsonDocument document;
		document.setObject(obj1);
		QByteArray byteArray = document.toJson(QJsonDocument::Indented);
		QString msg(byteArray);
		m_sendtextedit->setText(msg);
	}
	else if (Str == "device.script.delete")
	{
		m_sendtextedit->clear();
		QJsonObject obj1;
		obj1.insert("name", "a_lua");
		QJsonDocument document;
		document.setObject(obj1);
		QByteArray byteArray = document.toJson(QJsonDocument::Indented);
		QString msg(byteArray);
		m_sendtextedit->setText(msg);
	}
	else if (Str == "device.io.config")
	{
		m_sendtextedit->clear();
		QJsonObject obj1;
		obj1.insert("version", "3.2M");

		QJsonObject obj111, obj112;
		obj111.insert("channel", 1);
		obj111.insert("value", false);
		obj112.insert("channel", 2);
		obj112.insert("value", false);
		QJsonArray arr1;
		arr1.append(obj111);
		arr1.append(obj112);

		QJsonObject obj121, obj122;
		obj121.insert("channel", 1);
		obj121.insert("value", false);
		obj122.insert("channel", 2);
		obj122.insert("value", false);
		QJsonArray arr2;
		arr2.append(obj121);
		arr2.append(obj122);

		QJsonObject obj131;
		obj131.insert("channel", 1);
		obj131.insert("mode","current");
		obj131.insert("value", 10);
		QJsonArray arr3;
		arr3.append(obj131);

		QJsonObject obj141, obj142;
		obj141.insert("channel", 1);
		obj141.insert("sample_mode","5V");
		obj141.insert("trigger_mode", ">=");
		obj141.insert("trigger_data", 3);
		obj142.insert("channel", 2);
		obj142.insert("sample_mode", "current");
		obj142.insert("trigger_mode", ">=");
		obj142.insert("trigger_data", 10);
		QJsonArray arr4;
		arr4.append(obj141);
		arr4.append(obj142);

		QJsonObject ob1, ob2, ob3;
		ob1.insert("value", false);
		ob2.insert("frequency", 0);
		ob2.insert("cycle", 0);
		ob3.insert("frequency", 0);
		ob3.insert("count", 0);
		QJsonObject obj151;
		obj151.insert("channel", 1);
		obj151.insert("mode", "digital");
		obj151.insert("digital", QJsonValue(ob1));
		obj151.insert("pwm", QJsonValue(ob2));
		obj151.insert("frequency", QJsonValue(ob3));
		QJsonArray arr5;
		arr5.append(obj151);
		
		obj1.insert("di", QJsonValue(arr1));
		obj1.insert("d_o", QJsonValue(arr2));
		obj1.insert("da", QJsonValue(arr3));
		obj1.insert("ad", QJsonValue(arr4));
		obj1.insert("dof", QJsonValue(arr5));

		QJsonDocument document;
		document.setObject(obj1);
		QByteArray byteArray = document.toJson(QJsonDocument::Indented);
		QString msg(byteArray);
		m_sendtextedit->setText(msg);
	}
	else if (Str == "device.io.read")
	{
		m_sendtextedit->clear();
		QJsonObject obj1;
		obj1.insert("version", "3.2M");
		QJsonDocument document;
		document.setObject(obj1);
		QByteArray byteArray = document.toJson(QJsonDocument::Indented);
		QString msg(byteArray);
		m_sendtextedit->setText(msg);
	}
	else if (Str == "device.arc.run")
	{
		m_sendtextedit->clear();
		QJsonObject obj1;
		obj1.insert("velocity", 100);
		obj1.insert("x", 0);
		obj1.insert("y", 0);
		obj1.insert("z", 0);
		obj1.insert("rz", 0);
		obj1.insert("x2", 0);
		obj1.insert("y2", 0);
		obj1.insert("z2", 0);
		obj1.insert("rz2", 0);
		QJsonDocument document;
		document.setObject(obj1);
		QByteArray byteArray = document.toJson(QJsonDocument::Indented);
		QString msg(byteArray);
		m_sendtextedit->setText(msg);
	}
	else if (Str == "device.line.run")
	{
		m_sendtextedit->clear();
		QJsonObject obj1;
		obj1.insert("velocity", 100);
		obj1.insert("x", 0);
		obj1.insert("y", 0);
		obj1.insert("z", 0);
		obj1.insert("rz", 0);
		QJsonDocument document;
		document.setObject(obj1);
		QByteArray byteArray = document.toJson(QJsonDocument::Indented);
		QString msg(byteArray);
		m_sendtextedit->setText(msg);
	}
	//device.mod.read传递参数为空
	//device.log.query传递参数为空
	//device.motion.read传递参数为空
	else if (Str == "device.mod.read")
	{
		m_sendtextedit->clear();
		QJsonObject obj1;
		QJsonDocument document;
		document.setObject(obj1);
		QByteArray byteArray = document.toJson(QJsonDocument::Indented);
		QString msg(byteArray);
		m_sendtextedit->setText(msg);
	}
	else if (Str == "device.log.query")
	{
		m_sendtextedit->clear();
		QJsonObject obj1;
		QJsonDocument document;
		document.setObject(obj1);
		QByteArray byteArray = document.toJson(QJsonDocument::Indented);
		QString msg(byteArray);
		m_sendtextedit->setText(msg);
	}
	else if (Str == "device.motion.read")
	{
		m_sendtextedit->clear();
		QJsonObject obj1;
		QJsonDocument document;
		document.setObject(obj1);
		QByteArray byteArray = document.toJson(QJsonDocument::Indented);
		QString msg(byteArray);
		m_sendtextedit->setText(msg);
	}
	else if (Str == "motion.kdl.inverse")
	{
		m_sendtextedit->clear();
		QJsonObject obj11;
		QJsonObject obj1;
		QJsonArray array1;
		array1.append(0);
		array1.append(0);
		array1.append(0);
		obj11.insert("frame_x", 100);
		obj11.insert("frame_y", 100);
		obj11.insert("frame_z", 80);
		obj11.insert("frame_rx", 1.1);
		obj11.insert("frame_ry", 2.1);
		obj11.insert("frame_rz", 3.1);
		obj1.insert("pose", QJsonValue(obj11));
		obj1.insert("ext_posit", QJsonValue(array1));
		obj1.insert("ik_flag", 1);
		QJsonDocument document;
		document.setObject(obj1);
		QByteArray byteArray = document.toJson(QJsonDocument::Indented);
		QString msg(byteArray);
		m_sendtextedit->setText(msg);
	}
	else if (Str == "motion.kdl.forward")
	{
		m_sendtextedit->clear();
		QJsonObject obj1;
		QJsonArray array1;
		QJsonArray array2;
		array1.append(0);
		array1.append(0);
		array1.append(0);
		array1.append(0);
		array2.append(0);
		array2.append(0);
		array2.append(0);
		obj1.insert("arm_joint", QJsonValue(array1));
		obj1.insert("ext_poist", QJsonValue(array2));
		QJsonDocument document;
		document.setObject(obj1);
		QByteArray byteArray = document.toJson(QJsonDocument::Indented);
		QString msg(byteArray);
		m_sendtextedit->setText(msg);
	}
	else if (Str == "device.update")
	{
		m_sendtextedit->clear();
		QJsonObject obj1;
		obj1.insert("name", "joint_1");
		QJsonDocument document;
		document.setObject(obj1);
		QByteArray byteArray = document.toJson(QJsonDocument::Indented);
		QString msg(byteArray);
		m_sendtextedit->setText(msg);
	}
	else if (Str == "device.file.receive")
	{
		m_sendtextedit->clear();
		QJsonObject obj1;
		obj1.insert("type", "script");
		obj1.insert("file_name", "program_1.lua");
		obj1.insert("index", 1);
		QJsonDocument document;
		document.setObject(obj1);
		QByteArray byteArray = document.toJson(QJsonDocument::Indented);
		QString msg(byteArray);
		m_sendtextedit->setText(msg);
	}
	else if (Str == "device.file.send")
	{
		m_sendtextedit->clear();
		QJsonObject obj1;
		obj1.insert("type", "script");
		obj1.insert("file_name", "program_1.lua");
		obj1.insert("md5", "xxxxxxxxxx");
		obj1.insert("total", 100);
		obj1.insert("index", 10);
		obj1.insert("content", "");
		QJsonDocument document;
		document.setObject(obj1);
		QByteArray byteArray = document.toJson(QJsonDocument::Indented);
		QString msg(byteArray);
		m_sendtextedit->setText(msg);
	}
	else if (Str == "device.script.delete")
	{
		m_sendtextedit->clear();
		QJsonObject obj1;
		obj1.insert("name", "a.lua");
		QJsonDocument document;
		document.setObject(obj1);
		QByteArray byteArray = document.toJson(QJsonDocument::Indented);
		QString msg(byteArray);
		m_sendtextedit->setText(msg);
	}
	else if (Str == "device.motion.config")
	{
		m_sendtextedit->clear();
		QJsonObject obj11;
		QJsonObject obj12;
		QJsonObject obj13;
		QJsonObject obj14;
		QJsonObject obj15;
		QJsonObject obj16;
		QJsonObject obj1;
		QJsonArray array1;
		QJsonArray array2;
		QJsonArray array3;
		array1.append(0);
		array1.append(0);
		array1.append(0);
		array2.append(0);
		array2.append(0);
		array2.append(0);
		obj11.insert("a", 250);
		obj11.insert("alpha", 0);
		obj11.insert("d", 0);
		obj11.insert("theta", 0);
		obj11.insert("abs_limit_1", -2.6);
		obj11.insert("abs_limit_h", 3.14);
		obj11.insert("soft_limit_l", -2.6);
		obj11.insert("soft_limit_h", 3.14);
		obj11.insert("max_vel", 5.8);
		obj11.insert("max_acc", 25);
		obj11.insert("max_dec", 23);
		obj11.insert("max_jerk", 0.1);
		obj11.insert("vel_limit", 17.5);
		obj11.insert("acc_limit", 230);

		obj12.insert("a", 150);
		obj12.insert("alpha", 0);
		obj12.insert("d", 0);
		obj12.insert("theta", 0);
		obj12.insert("abs_limit_1", -2.2);
		obj12.insert("abs_limit_h", 2.2);
		obj12.insert("soft_limit_l", -2.2);
		obj12.insert("soft_limit_h", 2.2);
		obj12.insert("max_vel", 5.8);
		obj12.insert("max_acc", 60);
		obj12.insert("max_dec", 57);
		obj12.insert("max_jerk", 0.1);
		obj12.insert("vel_limit", 17.5);
		obj12.insert("acc_limit", 230);

		obj13.insert("a", 0);
		obj13.insert("alpha", 0);
		obj13.insert("d", 0);
		obj13.insert("theta", 0);
		obj13.insert("abs_limit_1", -150);
		obj13.insert("abs_limit_h", 10);
		obj13.insert("soft_limit_l", -150);
		obj13.insert("soft_limit_h", 10);
		obj13.insert("max_vel", 750);
		obj13.insert("max_acc", 13000);
		obj13.insert("max_dec", 10000);
		obj13.insert("max_jerk", 0.1);
		obj13.insert("vel_limit", 1000);
		obj13.insert("acc_limit", 25000);

		obj14.insert("a", 0);
		obj14.insert("alpha", 0);
		obj14.insert("d", 0);
		obj14.insert("theta", 0);
		obj14.insert("abs_limit_1", -6.28319);
		obj14.insert("abs_limit_h", 6.28319);
		obj14.insert("soft_limit_l", -6.28319);
		obj14.insert("soft_limit_h", 6.28319);
		obj14.insert("max_vel", 9.2);
		obj14.insert("max_acc", 210);
		obj14.insert("max_dec", 200);
		obj14.insert("max_jerk", 0.1);
		obj14.insert("vel_limit", 30);
		obj14.insert("acc_limit", 400);
		array3.append(obj11);
		array3.append(obj12);
		array3.append(obj13);
		array3.append(obj14);
		obj15.insert("max_vel", 200);
		obj15.insert("max_acc", 1000);
		obj15.insert("max_dec", 1000);
		obj15.insert("max_jerk", 1000);
		obj16.insert("p", QJsonValue(array1));
		obj16.insert("rpy", QJsonValue(array2));
		obj1.insert("robot_name", "scara_v2");
		obj1.insert("robot_model", "scara");
		obj1.insert("end_effector", QJsonValue(obj16));
		obj1.insert("arm_joint", QJsonValue(array3));
		obj1.insert("cartesian", QJsonValue(obj15));
		obj1.insert("ext_joint", "[]");
		QJsonDocument document;
		document.setObject(obj1);
		QByteArray byteArray = document.toJson(QJsonDocument::Indented);
		QString msg(byteArray);
		m_sendtextedit->setText(msg);
	}
	else if (Str == "device.mod.config")
	{
		m_sendtextedit->clear();
		QJsonObject obj11;
		QJsonObject obj12;
		QJsonObject obj13;
		QJsonObject obj14;
		QJsonObject obj15;
		QJsonObject obj1;
		QJsonArray array1;
		obj11.insert("index", 1);
		obj11.insert("enable", true);
		obj11.insert("ip", "");
		obj11.insert("port", 444);
		obj11.insert("cout", 5);
		obj11.insert("time", 10);

		obj12.insert("index", 2);
		obj12.insert("enable", false);
		obj12.insert("ip", "");
		obj12.insert("port", 444);
		obj12.insert("cout", 5);
		obj12.insert("time", 10);

		obj13.insert("index", 3);
		obj13.insert("enable", true);
		obj13.insert("ip", "");
		obj13.insert("port", 444);
		obj13.insert("cout", 5);
		obj13.insert("time", 10);

		obj14.insert("index", 4);
		obj14.insert("enable", true);
		obj14.insert("ip", "");
		obj14.insert("port", 444);
		obj14.insert("cout", 5);
		obj14.insert("time", 10);

		obj15.insert("index", 5);
		obj15.insert("enable", true);
		obj15.insert("ip", "");
		obj15.insert("port", 444);
		obj15.insert("cout", 5);
		obj15.insert("time", 10);

		array1.append(obj11);
		array1.append(obj12);
		array1.append(obj13);
		array1.append(obj14);
		array1.append(obj15);
		obj1.insert("device", QJsonValue(array1));
		QJsonDocument document;
		document.setObject(obj1);
		QByteArray byteArray = document.toJson(QJsonDocument::Indented);
		QString msg(byteArray);
		m_sendtextedit->setText(msg);
	}
}

void Clientdialog::Open(char* p1, char* p2, char* p3)
{
	typedef char* (*Fun)(char*, char*, char*, int*);
	QLibrary mylib("addon.dll");
	int p4 = 0;
	if (mylib.load())
	{
		Fun open = (Fun)mylib.resolve("action_event");
		if (open)
		{
			
			QByteArray result = open(p1, p2, p3, &p4);
			//qDebug() << result << endl;
			QJsonParseError json_error;
			QJsonDocument document = QJsonDocument::fromJson(result, &json_error);
			QByteArray byte = document.toJson(QJsonDocument::Indented);
			QString str(byte);	
			QString time = current_date_time->currentDateTime().toString("yyyy.MM.dd hh:mm:ss.zzz ddd");
			m_receivetextedit->append(time + "" + "\n" + str + "\n");
		}
	}
}
void Clientdialog::onSeekbuttonclick()
{
	QFile file("data.txt");
	if (file.open(QIODevice::ReadOnly))
	{
		while (!file.atEnd())
		{
			QByteArray data = file.readLine();
			m_iplist->addItem(data);
		}
	}
	file.close();
}
void Clientdialog::onserialmsg(QListWidgetItem* current, QListWidgetItem* previous)
{
	if (NULL == current)
	{
		return;
	}
	QString str = current->text();
	QString msg = str.mid(0, 36);
	m_seriallineedit->setText(msg);	
}
void Clientdialog::onSendbuttonclick()
{
	QString a1 = m_combobox->currentText();
	QString a2 = m_seriallineedit->text();
	QString a3 = m_sendtextedit->document()->toPlainText();
	//qDebug() << a1 << a2 << a3;
	QByteArray c1 = a1.toLatin1();
	QByteArray c2 = a2.toLatin1();
	QByteArray c3 = a3.toLatin1();
	char* d1 = c1.data();
	char* d2 = c2.data();
	char* d3 = c3.data();
	Open(d1, d2, d3);
}
void Clientdialog::startbutton()
{
	QString data = scriptline->text();
	char* p1 = "device.run";
	QString a2 = m_seriallineedit->text();
	QByteArray c2 = a2.toLatin1();
	char* p2 = c2.data();
	QJsonObject obj;
	QJsonDocument document;
	obj.insert("script_name", data);
	obj.insert("cmd", "start");
	obj.insert("def", false);
	document.setObject(obj);
	QByteArray array1 = document.toJson(QJsonDocument::Indented);
	char* p3 = array1.data();
	Open(p1, p2, p3);
}
void Clientdialog::stopbutton()
{
	QString data = scriptline->text();
	char* p1 = "device.run";
	QString a2 = m_seriallineedit->text();
	QByteArray c2 = a2.toLatin1();
	char* p2 = c2.data();
	QJsonObject obj;
	QJsonDocument document;
	obj.insert("script_name", data);
	obj.insert("cmd", "stop");
	obj.insert("def", false);
	document.setObject(obj);
	QByteArray array1 = document.toJson(QJsonDocument::Indented);
	char* p3 = array1.data();
	Open(p1, p2, p3);
}
void Clientdialog::pausebutton()
{
	QString data = scriptline->text();
	char* p1 = "device.run";
	QString a2 = m_seriallineedit->text();
	QByteArray c2 = a2.toLatin1();
	char* p2 = c2.data();
	QJsonObject obj;
	QJsonDocument document;
	obj.insert("script_name", data);
	obj.insert("cmd", "pause");
	obj.insert("def", false);
	document.setObject(obj);
	QByteArray array1 = document.toJson(QJsonDocument::Indented);
	char* p3 = array1.data();
	Open(p1, p2, p3);
}
void Clientdialog::continbutton()
{
	QString data = scriptline->text();
	char* p1 = "device.run";
	QString a2 = m_seriallineedit->text();
	QByteArray c2 = a2.toLatin1();
	char* p2 = c2.data();
	QJsonObject obj;
	QJsonDocument document;
	obj.insert("script_name", data);
	obj.insert("cmd", "continue");
	obj.insert("def", false);
	document.setObject(obj);
	QByteArray array1 = document.toJson(QJsonDocument::Indented);
	char* p3 = array1.data();
	Open(p1, p2, p3);
}