#include "inireader.h"
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    IniReader reader("db.ini");
    printf("%s\n", reader.GetIniKeyString("mysql","host","db.ini"));
    printf("%d\n", reader.GetIniKeyInt("mysql", "port", "db.ini"));
	int tmp = PRN_ERRMSG_RETURN("test");
    system("pause");
    return 0;
}
