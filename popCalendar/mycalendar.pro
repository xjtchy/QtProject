TEMPLATE = app
LANGUAGE	= C++

QT += core gui

CONFIG		+= qt warn_on debug thread dll uic



OBJECTS_DIR 	= ../bin/popCalendar
UI_DIR 		= ../bin/popCalendar
MOC_DIR 	= ../bin/popCalendar

TARGET		= myCalendar
DESTDIR		= ../bin

HEADERS		+= mycalendar.h	\		
			defineCalendar.h \
			defDateTimeEdit.h \
	

                  		  
SOURCES	   	+=	main.cpp  \
			mycalendar.cpp	\
			defineCalendar.cpp \
			defDateTimeEdit.cpp \
	

#The following line was changed from FORMS to FORMS3 by qt3to4
FORMS		+=	mycalendar.ui 

RESOURCES += mycalendar.qrc
				     		
#The following line was inserted by qt3to4
QT +=  sql qt3support 
