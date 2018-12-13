#ifndef MYCALENDAR_H
#define MYCALENDAR_H

#include <QWidget>
#include "ui_mycalendar.h"
#include "defDateTimeEdit.h"

class MyCalendar : public QWidget
{
	Q_OBJECT

public:
	MyCalendar(QWidget *parent = 0);
	~MyCalendar();

private:
	Ui::MyCalendarClass ui;
	DefDateTimeEdit* m_defDateTimeEdit;
};

#endif // MYCALENDAR_H
