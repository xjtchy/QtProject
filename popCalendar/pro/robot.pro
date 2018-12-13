TEMPLATE	= app

CONFIG      += warn_on dll debug_and_release
QT  += sql xml

TARGET = robot

DESTDIR = ../../target/bin

INCLUDEPATH = ../inc ../../inc ../../robotmsg

win32{
	LIBS += ../../target/bin/taskmanage.lib
	LIBS += ../../target/bin/configtool.lib
	LIBS += ../../target/bin/taskdisplay.lib
	LIBS += ../../target/bin/importdb.lib
	LIBS += ../../target/bin/resultconfig.lib
	LIBS += ../../target/bin/robotmanger.lib  
	LIBS += ../../target/bin/realinspect.lib
	LIBS += ../../target/bin/yuzhishezhi.lib
	LIBS += ../../target/bin/zhuangtaishezhi.lib
	LIBS += ../../target/bin/RbacMsg.lib
}

#UI_DIR = ../
UI_HEADERS_DIR = ../inc
UI_SOURCES_DIR = ../src
RCC_DIR = ../src
FORMS = ../ui/robothmi.ui ../ui/ccenter.ui ../ui/ztest.ui ../ui/cnav1st.ui ../ui/cfun1.ui ../ui/cfun2.ui ../ui/cfun3.ui ../ui/cfun4.ui \
        ../ui/cfun5.ui ../ui/cfun6.ui ../ui/cfun7.ui ../ui/cfun8.ui ../ui/userlogindialog.ui ../ui/userlogoutdialog.ui

HEADERS     =  ../inc/robothmi.h ../inc/ccenter.h ../inc/ztest.h ../inc/cnav1st.h ../inc/cfun1.h ../inc/cfun2.h ../inc/cfun3.h ../inc/cfun4.h \
               ../inc/cfun5.h ../inc/cfun6.h ../inc/cfun7.h ../inc/cfun8.h ../inc/ctopleft.h ../inc/ctopright.h ../inc/common.h  ../../inc/configtool_global.h \
			   ../../inc/taskmanage_global.h ../../inc/taskdisplay_global.h ../../inc/importdb_global.h ../../inc/commondef.h ../../inc/glbtypes.h \
			   ../../inc/realinspect.h ../../inc/robotmanger.h ../inc/systemalarmthread.h \
			   ../../inc/webservice.h ../../inc/str_codec.h ../../inc/soapH.h  ../../inc/soapStub.h ../../inc/stdsoap2.h \
			   ../../inc/yuzhishezhi_global.h ../../inc/zhuangtaishezhi_global.h  ../inc/userlogindialog.h  ../inc/userlogoutdialog.h ../inc/robotauth.h ../inc/errorinfo.h \
			   ../inc/rbacmsg_global.h ../inc/errorcode.h

RESOURCES   = ../src/robothmi.qrc
#RC_FILE = rebotmanger.rc
SOURCES     = ../src/main.cpp ../src/robothmi.cpp ../src/ccenter.cpp ../src/ztest.cpp ../src/cnav1st.cpp ../src/cfun1.cpp ../src/cfun2.cpp ../src/cfun3.cpp ../src/cfun4.cpp \
              ../src/cfun5.cpp ../src/cfun6.cpp ../src/cfun7.cpp ../src/cfun8.cpp ../src/ctopleft.cpp ../src/ctopright.cpp  ../src/systemalarmthread.cpp ../../inc/webservice.cpp \
			  ../../inc/str_codec.cpp ../../inc/soapC.cpp ../../inc/soapClient.cpp ../../inc/stdsoap2.cpp ../src/userlogindialog.cpp  ../src/userlogoutdialog.cpp ../src/robotauth.cpp

MOC_DIR = ../../obj/robothmi/moc
OBJECTS_DIR = ../../obj/robothmi/debug
