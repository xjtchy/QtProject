#ifndef INIREADER_H
#define INIREADER_H
#define MAX_FILENAME_SIZE 64
#define PRN_ERRMSG_RETURN printf

class IniReader
{
public:
    IniReader();
    IniReader(const char *fileName);

    char *GetIniKeyString(const char *title, const char *key, const char *filename);

    int GetIniKeyInt(const char *title, const char *key, const char *filename);

    int PutIniKeyString(char *title,char *key,char *val,char *filename);

    int PutIniKeyInt(char *title,char *key,int val,char *filename);

private:
    char m_pFileName[MAX_FILENAME_SIZE];
};

#endif // INIREADER_H
