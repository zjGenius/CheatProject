#include "paramRead.h"
#include "time.h"
#include <sys/types.h>
#include <sys/stat.h>
/*
   读取字符类型的值
 */
int GetIniKeyString(char *dst, const char *title, const char *key, const char *filename)
{

    FILE *fp = NULL;
    int flag = 0;
    char sTitle[32], *wTmp;
    char sLine[1024];

    sprintf(sTitle, "[%s]", title);
    if (NULL == (fp = fopen(filename, "r")))
    {
        // fclose(fp);band_width
        perror("fopen");
        return -1;
    }
    else
    {
        while (NULL != fgets(sLine, 1024, fp))
        {
            // 这是注释行
            if (0 == strncmp("//", sLine, 2))
                continue;
            if ('#' == sLine[0])
                continue;

            wTmp = strchr(sLine, '=');
            if ((NULL != wTmp) && (1 == flag))
            {
                if (0 == strncmp(key, sLine, strlen(key)))
                { // 长度依文件读取的为准

                    if (sLine[strlen(sLine) - 2] == '\r')
                    {
                        sLine[strlen(sLine) - 2] = '\0';
                    }
                    else
                    {
                        sLine[strlen(sLine) - 1] = '\0';
                    }
                    fclose(fp);
                    strcpy(dst, wTmp + 1);
                    return 0;
                }
            }
            else
            {
                if (0 == strncmp(sTitle, sLine, strlen(sTitle)))
                {             // 长度依文件读取的为准
                    flag = 1; // 找到标题位置
                }
            }
        }
    }
    fclose(fp);
    return -1;
}

/*
   读取数组类型的值
 */
int GetIniKeyFloatArray(const char *title, const char *key, float *array, int arraySize, const char *filename)
{
    FILE *fp = NULL;
    int flag = 0;
    char sTitle[32];
    char sLine[1024];
    char *p;
    int i = 0;

    sprintf(sTitle, "[%s]", title);
    if (NULL == (fp = fopen(filename, "r")))
    {
        //  fclose(fp);
        perror("fopen");
        return -1;
    }
    else
    {
        while (NULL != fgets(sLine, 1024, fp))
        {
            // 这是注释行
            if (0 == strncmp("//", sLine, 2))
                continue;
            if ('#' == sLine[0])
                continue;

            if ((1 == flag) && 0 == strncmp(sLine, key, strlen(key))) // 找到键值位置
            {
                p = strtok(sLine + strlen(key) + 1, ",");
                while (i < arraySize)
                {
                    if (p != NULL && *p != '\n' && *p != '\r')
                    {
                        array[i] = atof(p);
                        p = strtok(NULL, ",");
                        i++;
                    }
                    else
                    {
                        if (NULL == fgets(sLine, 1024, fp))
                        {
                            fclose(fp);
                            return -1;
                        }
                        else
                            p = strtok(sLine, ",");
                    }
                }
                fclose(fp);
                return 0;
            }
            else
            {
                if (0 == strncmp(sTitle, sLine, strlen(sTitle)))
                {             // 长度依文件读取的为准
                    flag = 1; // 找到标题位置
                }
            }
        }
    }
    fclose(fp);
    return -1;
}

int GetIniKeyIntArray(const char *title, const char *key, int *array, int arraySize, const char *filename)
{
    FILE *fp = NULL;
    int flag = 0;
    char sTitle[32];
    char sLine[1024];
    char *p;
    int i = 0;

    sprintf(sTitle, "[%s]", title);
    if (NULL == (fp = fopen(filename, "r")))
    {
        //  fclose(fp);
        perror("fopen");
        return -1;
    }
    else
    {
        while (NULL != fgets(sLine, 1024, fp))
        {
            // 这是注释行
            if (0 == strncmp("//", sLine, 2))
                continue;
            if ('#' == sLine[0])
                continue;

            if ((1 == flag) && 0 == strncmp(sLine, key, strlen(key))) // 找到键值位置
            {
                p = strtok(sLine + strlen(key) + 1, ",");
                while (i < arraySize)
                {
                    if (p != NULL && *p != '\n' && *p != '\r')
                    {
                        array[i] = atoi(p);
                        p = strtok(NULL, ",");
                        i++;
                    }
                    else
                    {
                        if (NULL == fgets(sLine, 1024, fp))
                        {
                            fclose(fp);
                            return -1;
                        }
                        else
                            p = strtok(sLine, ",");
                    }
                }
                fclose(fp);
                return 0;
            }
            else
            {
                if (0 == strncmp(sTitle, sLine, strlen(sTitle)))
                {             // 长度依文件读取的为准
                    flag = 1; // 找到标题位置
                }
            }
        }
    }
    fclose(fp);
    return -1;
}
/*
   读取整数类型的值
 */
long long GetIniKeyInt(const char *title, const char *key, const char *filename)
{
    char str[1024];
    if (!GetIniKeyString(str, title, key, filename))
        return strtoll(str, NULL, 0);
    else
        return -1;
}

/*
   读取浮点型的值
 */
float GetIniKeyFloat(const char *title, const char *key, const char *filename)
{
    char str[1024];
    if (!GetIniKeyString(str, title, key, filename))
        return atof(str);
    else
        return -1;
}
/*修改内容*/
int update_param_key(const char *fileName, const char *key, const char *data)
{
    static int fileIndex = 0;
    if (fileIndex > 60000)
        fileIndex = 0;

    FILE *fp = fopen(fileName, "r+");
    if (fp == NULL)
    {
        return -1;
    }
    char tempFile[64] = {0};
    sprintf(tempFile, "temp%d.ini", ++fileIndex);
    FILE *fp2 = fopen(tempFile, "w+");
    if (fp2 == NULL)
    {
        fclose(fp);
        return -2;
    }

    char check_buf[BUFFSIZE] = {0};
    char delete_buf[BUFFSIZE] = {0};
    char temp[BUFFSIZE] = {0};
    char *ptemp = NULL, *readKey = NULL;
    while (fgets(check_buf, BUFFSIZE, fp) != NULL)
    {
    MATCH:
        readKey = NULL;
        strcpy(temp, check_buf);
        ptemp = temp;
        if (strstr(temp, "=") != NULL)
        {
            readKey = strsep(&ptemp, "=");
        }
        else
        {
            readKey = check_buf;
        }
        if (strcmp(readKey, key) == 0) // 匹配成功
        {
            memset(check_buf, 0, BUFFSIZE);
            sprintf(check_buf, "%s=%s\n", key, data); // 把关键字和值的内容填充好
            // printf("update key:%s data:%s\n",key,data);
            while (1) // 忽略该关键字下面行的值
            {
                if (fgets(delete_buf, BUFFSIZE, fp) != NULL) // 有下面行
                {
                    if (strstr(delete_buf, "=") != NULL) // 有=,说明是第二个关键字,不能忽略,必须要复制到文件中去
                    {
                        fprintf(fp2, "%s", check_buf);
                        strcpy(check_buf, delete_buf); // 复制,跳转到下一次匹配(其实也可以不用匹配了)
                        goto MATCH;
                    }
                    else // 无=,可能为关键字的值
                    {
                        if ((strstr(delete_buf, "#") == NULL && strstr(delete_buf, "//") == NULL) && delete_buf[0] != '\n') // 不是注释或者空行,是值,忽略,不复制
                        {
                            continue;
                        }
                        else // 是注释或者空行,不忽略,直接复制并跳转
                        {
                            fprintf(fp2, "%s", check_buf);
                            strcpy(check_buf, delete_buf);
                            goto MATCH;
                        }
                    }
                }
                else // 无下面行,结束
                {
                    fprintf(fp2, "%s", check_buf);
                    break;
                }
            }
        }
        else
        {
            fprintf(fp2, "%s", check_buf);
        }
    }

    fclose(fp);
    fclose(fp2);

    // memset(check_buf,0,BUFFSIZE);
    // sprintf(check_buf,"rm -r %s", fileName);
    // system(check_buf);
    memset(check_buf, 0, BUFFSIZE);
    sprintf(check_buf, "mv %s %s", tempFile, fileName);
    system(check_buf);
    return 0;
}

/**
 * @brief 判断文件更新时间
 *
 */
long GetFileRefreshTime(char *FilePath)
{
    FILE *fp;
    int fd1;
    struct stat buf;
    fp = fopen(FilePath, "r");
    fd1 = fileno(fp);
    fstat(fd1, &buf);
    int size = buf.st_size;
    long modify_time = buf.st_mtime;
    // 时戳转时间
    time_t timep = (time_t)modify_time;
    struct tm *p;
    char s[100];
    p = localtime(&timep);
    strftime(s, sizeof(s), "%Y-%m-%d %H:%M:%S", p);
    // printf("时间戳为：%d 转换成标准时间为： %s\n", (int)timep, s);
    fclose(fp);
    return modify_time;
}

/*
 * 函数名：         PutIniKeyInt
 * 入口参数：        title
 *                      配置文件中一组数据的标识
 *                  key
 *                      这组数据中要读出的值的标识
 *                  val
 *                      更改后的值
 *                  filename
 *                      要读取的文件路径
 * 返回值：         成功返回  0
 *                  否则返回 -1
 */
int PutIniKeyInt(const char *title, const char *key, int val, const char *filename)
{
    FILE *fpr, *fpw;
    char sLine[1024], sTitle[32], *wTmp;

    if (NULL == (fpr = fopen(filename, "r")))
        return 0; // 读取原文件
    sprintf(sLine, "%s.tmp", filename);
    if (NULL == (fpw = fopen(sLine, "w")))
    { // 写入临时文件
        fclose(fpr);
        return 0;
    }
    int flag = 0;
    sprintf(sTitle, "[%s]", title);

    while (NULL != fgets(sLine, 1024, fpr))
    {
        if (2 != flag)
        { // 如果找到要修改的那一行，则不会执行内部的操作
            wTmp = strchr(sLine, '=');
            if ((NULL != wTmp) && (1 == flag))
            {
                if (0 == strncmp(key, sLine, wTmp - sLine))
                {             // 长度依文件读取的为准
                    flag = 2; // 更改值，方便写入文件
                    sprintf(wTmp + 1, "%d\n", val);
                }
            }
            else
            {
                if (0 == strncmp(sTitle, sLine, strlen(sLine) - 1))
                {             // 长度依文件读取的为准
                    flag = 1; // 找到标题位置
                }
            }
        }

        fputs(sLine, fpw); // 写入临时文件
    }
    fclose(fpr);
    fclose(fpw);

    sprintf(sLine, "%s.tmp", filename);
    return rename(sLine, filename); // 将临时文件更新到原文件
}

/**
 * @brief 读取pscan.ini频表
 */
int getfreqlist(char *FreqListPath, FreqCorInfo *Freq_tab)
{
    char freq_file[10];
    strcpy(freq_file, FreqListPath);
    char title[15] = {0};
    // corfreq_num频表中设置的扫描频点个数
    int corfreq_num = GetIniKeyInt((char *)"pscan_info", (char *)"freq_num", FreqListPath);

    if (corfreq_num <= 0)
    {
        printf("error freq List length= 0!!!\n");
        return 0;
    }
    printf("corfreq_num= %d\n", corfreq_num);
    if (corfreq_num > 0)
        memset(Freq_tab, 0, corfreq_num * sizeof(FreqCorInfo));
    int j = 0;
    // int isuse = 0;
    for (int i = 0; i < corfreq_num; i++)
    {
        sprintf(title, "freq%d", i + 1);
        // isuse = GetIniKeyInt((char *)title, (char *)"isuse", freq_file);
        // if (isuse == 0)
        //     continue;
        // 如果没有填频点
        if (GetIniKeyInt((char *)title, (char *)"freq", freq_file) == -1)
        {
            continue;
        }
        (Freq_tab + j)->isuse = GetIniKeyInt((char *)title, (char *)"isuse", freq_file);
        (Freq_tab + j)->freq = GetIniKeyInt((char *)title, (char *)"freq", freq_file);
        (Freq_tab + j)->gain = GetIniKeyInt((char *)title, (char *)"gain", freq_file);
        (Freq_tab + j)->band_width = GetIniKeyFloat((char *)title, (char *)"band_width", freq_file);
        (Freq_tab + j)->samp_freq = GetIniKeyFloat((char *)title, (char *)"samp_freq", freq_file);
        (Freq_tab + j)->type = GetIniKeyInt((char *)title, (char *)"type", freq_file);
        j++;
    }
    return j;
}

int getfreqlist(char *FreqListPath, std::vector<FreqInfo> &vec_scan, bool with_notuse)
{
    char freq_file[10];
    strcpy(freq_file, FreqListPath);
    char title[15] = {0};
    // corfreq_num频表中设置的扫描频点个数
    int corfreq_num = GetIniKeyInt((char *)"pscan_info", (char *)"freq_num", FreqListPath);

    if (corfreq_num <= 0)
    {
        printf("error freq List length= 0!!!\n");
        return 0;
    }
    int j = 0;
    for (int i = 0; i < corfreq_num; i++)
    {
        FreqInfo tmp_freq;
        tmp_freq.num = i + 1;
        sprintf(title, "freq%d", tmp_freq.num);
        tmp_freq.isuse = GetIniKeyInt((char *)title, (char *)"isuse", freq_file);
        if (!with_notuse && tmp_freq.isuse == 0)
            continue;
        // 如果没有填频点
        tmp_freq.freq = GetIniKeyInt((char *)title, (char *)"freq", freq_file);
        if (tmp_freq.freq == -1)
            continue;

        tmp_freq.gain = GetIniKeyInt((char *)title, (char *)"gain", freq_file);
        if (tmp_freq.gain == -1)
            tmp_freq.gain = 0;

        vec_scan.push_back(tmp_freq);
    }
    return vec_scan.size();
}

std::vector<std::string> split(const std::string &s, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);

    while (std::getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }

    return tokens;
}
