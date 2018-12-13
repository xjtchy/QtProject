#include "mycalendar.h"

MyCalendar::MyCalendar(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	this->setFixedHeight(100);
	this->setFixedWidth(200);

	m_defDateTimeEdit = new DefDateTimeEdit(this);

	ui.verticalLayout->addWidget(m_defDateTimeEdit);
}

MyCalendar::~MyCalendar()
{

}
