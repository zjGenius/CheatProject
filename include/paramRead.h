#ifndef _PARAMREAD_H
#define _PARAMREAD_H

#include <stdio.h>
#include <string.h>
#include <vector>
#include <stdlib.h>
#include <string>
#include <sstream>
#pragma pack(1)
typedef struct
{
    int isuse;
    int freq;
    int gain;
    float band_width;
    float samp_freq;
    int type; // 0是wifi频点，1是正常频点
} FreqCorInfo;

typedef struct
{
    int freq;
    int gain;
    int isuse;
    int num;
} FreqInfo;
#pragma pack()

#define BUFFSIZE 8192

int getfreqinfo(char *fileName, struct Freq_info *freqinfos);
int getfreqlist(char *FreqListPath, FreqCorInfo *freq_tab);
int getfreqlist(char *FreqListPath, std::vector<FreqInfo> &vec_scan, bool with_notuse = true);


int GetIniKeyString(char *, const char *, const char *, const char *);
int GetIniKeyFloatArray(const char *, const char *, float *, int, const char *);
int GetIniKeyIntArray(const char *, const char *, int *, int, const char *);
long long GetIniKeyInt(const char *, const char *, const char *);
float GetIniKeyFloat(const char *, const char *, const char *);
int update_param_key(const char *fileName, const char *key, const char *data);
long GetFileRefreshTime(char *FilePath);
int PutIniKeyInt(const char *title, const char *key, int val, const char *filename);
std::vector<std::string> split(const std::string &s, char delimiter);
#endif
