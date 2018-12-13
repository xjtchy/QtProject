TEMPLATE = app
LANGUAGE	= C++

QT += core gui

CONFIG		+= qt warn_on debug thread dll uic

INCLUDEPATH 	+= .
INCLUDEPATH 	+= $(MCSSOURCE_ROOT)/mcs-interface
INCLUDEPATH 	+= $(MCSSOURCE_ROOT)/mcs-include
INCLUDEPATH 	+= $(MCSSOURCE_ROOT)/mcs-interface/appintf
INCLUDEPATH 	+= $(MCSSOURCE_ROOT)/mcs-interface/viewintf

OBJECTS_DIR 	= ../bin/mainvariation
UI_DIR 		= ../bin/mainvariation
MOC_DIR 	= ../bin/mainvariation

TARGET		= mainvariation
DESTDIR		= ../bin

HEADERS		+= $(MCSSOURCE_ROOT)/mcs-include/dbconnect.h	\		
			alarmclientlib.h \
			alarmconsumer.h \
			alarmevent.h \
			mainvariation.h \
			datetime.h \
			mainvariationconfig.h

                  		  
SOURCES	   	+=	main.cpp  \
			$(MCSSOURCE_ROOT)/mcs-include/dbconnect.cpp	\
			alarmclientlib.cpp \
			alarmconsumer.cpp \
			alarmevent.cpp \
			mainvariation.cpp \
			datetime.cpp \
			mainvariationconfig.cpp


#The following line was changed from FORMS to FORMS3 by qt3to4
FORMS		+=	mainvariation.ui mainvariationconfig_1.ui
				     		
#The following line was inserted by qt3to4
QT +=  sql qt3support 
