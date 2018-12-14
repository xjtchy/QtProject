#include "inireader.h"
#include <stdio.h>
#include <Windows.h>
IniReader::IniReader()
{

}

IniReader::IniReader(const char *fileName)
{
    sprintf(m_pFileName,"%s",fileName);
}

/*
 * ��������         GetIniKeyString
 * ��ڲ�����        title
 *                      �����ļ���һ�����ݵı�ʶ
 *                  key
 *                      ����������Ҫ������ֵ�ı�ʶ
 *                  filename
 *                      Ҫ��ȡ���ļ�·��
 * ����ֵ��         �ҵ���Ҫ���ֵ�򷵻���ȷ���
 *                  ���򷵻�NULL
 */
char *IniReader::GetIniKeyString(const char *title, const char *key, const char *filename)
{
    FILE *fp;
    int  flag = 0;
    char sTitle[32], *wTmp;
    static char sLine[1024];

    sprintf(sTitle, "[%s]", title);
    if(NULL == (fp = fopen(filename, "r"))) {
        perror("fopen");
        return NULL;
    }

    while (NULL != fgets(sLine, 1024, fp)) {
        // ����ע����
        if (0 == strncmp("//", sLine, 2)) continue;
        if ('#' == sLine[0])              continue;

        wTmp = strchr(sLine, '=');
        if ((NULL != wTmp) && (1 == flag)) {
            if (0 == strncmp(key, sLine, wTmp-sLine)) { // �������ļ���ȡ��Ϊ׼
                sLine[strlen(sLine) - 1] = '\0';
                fclose(fp);
                return wTmp + 1;
            }
        } else {
            if (0 == strncmp(sTitle, sLine, strlen(sLine) - 1)) { // �������ļ���ȡ��Ϊ׼
                flag = 1; // �ҵ�����λ��
            }
        }
    }
    fclose(fp);
    return NULL;
}

/*
 * ��������         GetIniKeyInt
 * ��ڲ�����        title
 *                      �����ļ���һ�����ݵı�ʶ
 *                  key
 *                      ����������Ҫ������ֵ�ı�ʶ
 *                  filename
 *                      Ҫ��ȡ���ļ�·��
 * ����ֵ��         �ҵ���Ҫ���ֵ�򷵻���ȷ���
 *                  ���򷵻�NULL
 */
int IniReader::GetIniKeyInt(const char *title, const char *key, const char *filename)
{
    return atoi(GetIniKeyString(title, key, filename));
}

/*
 * ��������         PutIniKeyString
 * ��ڲ�����        title
 *                      �����ļ���һ�����ݵı�ʶ
 *                  key
 *                      ����������Ҫ������ֵ�ı�ʶ
 *                  val
 *                      ���ĺ��ֵ
 *                  filename
 *                      Ҫ��ȡ���ļ�·��
 * ����ֵ��         �ɹ�����  0
 *                  ���򷵻� -1
 */
int IniReader::PutIniKeyString(char *title,char *key,char *val,char *filename)
{
    FILE *fpr, *fpw;
    int  flag = 0;
    char sLine[1024], sTitle[32], *wTmp;

    sprintf(sTitle, "[%s]", title);
    if (NULL == (fpr = fopen(filename, "r")))
        PRN_ERRMSG_RETURN("fopen");// ��ȡԭ�ļ�
    sprintf(sLine, "%s.tmp", filename);
    if (NULL == (fpw = fopen(sLine,    "w")))
        PRN_ERRMSG_RETURN("fopen");// д����ʱ�ļ�

    while (NULL != fgets(sLine, 1024, fpr)) {
        if (2 != flag) { // ����ҵ�Ҫ�޸ĵ���һ�У��򲻻�ִ���ڲ��Ĳ���
            wTmp = strchr(sLine, '=');
            if ((NULL != wTmp) && (1 == flag)) {
                if (0 == strncmp(key, sLine, wTmp-sLine)) { // �������ļ���ȡ��Ϊ׼
                    flag = 2;// ����ֵ������д���ļ�
                    sprintf(wTmp + 1, "%s\n", val);
                }
            } else {
                if (0 == strncmp(sTitle, sLine, strlen(sLine) - 1)) { // �������ļ���ȡ��Ϊ׼
                    flag = 1; // �ҵ�����λ��
                }
            }
        }

        fputs(sLine, fpw); // д����ʱ�ļ�
    }
    fclose(fpr);
    fclose(fpw);

    sprintf(sLine, "%s.tmp", filename);
    return rename(sLine, filename);// ����ʱ�ļ����µ�ԭ�ļ�
}

/*
 * ��������         PutIniKeyString
 * ��ڲ�����        title
 *                      �����ļ���һ�����ݵı�ʶ
 *                  key
 *                      ����������Ҫ������ֵ�ı�ʶ
 *                  val
 *                      ���ĺ��ֵ
 *                  filename
 *                      Ҫ��ȡ���ļ�·��
 * ����ֵ��         �ɹ�����  0
 *                  ���򷵻� -1
 */
int IniReader::PutIniKeyInt(char *title,char *key,int val,char *filename)
{
    char sVal[32];
    sprintf(sVal, "%d", val);
    return PutIniKeyString(title, key, sVal, filename);
}
