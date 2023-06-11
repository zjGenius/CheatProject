#include <stdio.h>
#include "func.h"

void func(unsigned int var)
{
    char version_str[10];
    int version_int;
    float version_float;
    GetIniKeyString(version_str, (char *)"version", (char *)"p_v", "version.ini");
    version_int = GetIniKeyInt((char *)"version", (char *)"p_i", "version.ini");
    version_float = GetIniKeyFloat((char *)"version", (char *)"p_f", "version.ini");
    printf("MyProject string:%s int:%d float:%f\r\n", version_str, version_int, version_float);
	printf("para var:%d\r\n", var);
}
