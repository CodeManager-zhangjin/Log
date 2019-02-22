#include <iostream>
#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <memory.h>
#include "logInterface.h"
#include "log.h"

CLog log;
void LOG(log_levels level, const char *format, ...)
{
    char filename[128];
    memset(filename, 0, sizeof(filename));
    time_t curTimestamp = time(NULL)+8*3600;
    struct tm *mt = localtime(&curTimestamp);
    sprintf(filename, "%s/%04d%02d%02d.log",log.m_path.c_str(), mt->tm_year + 1900, mt->tm_mon + 1, mt->tm_mday);

    int cnt = 0;
    char szbuff[512];
    memset(szbuff, 0, sizeof(szbuff));
    cnt += sprintf(szbuff, "[%04d-%02d-%02d %02d:%02d:%02d]", mt->tm_year + 1900, mt->tm_mon + 1, mt->tm_mday, mt->tm_hour, mt->tm_min, mt->tm_sec);

    switch(level)
    {
    case debug:
        cnt += sprintf(&szbuff[cnt], "[debug] ");
        break;
    case info:
        cnt += sprintf(&szbuff[cnt], "[info] ");
        break;
    case warn:
        cnt += sprintf(&szbuff[cnt], "[warn] ");
        break;
    case error:
        cnt += sprintf(&szbuff[cnt], "[error] ");
        break;
    case fatal:
        cnt += sprintf(&szbuff[cnt], "[fatal] ");
        break;
    }

    va_list args;
    va_start(args, format);
    cnt += vsprintf(&szbuff[cnt], format, args);
    va_end(args);

    szbuff[cnt] = '\n';
    printf("%s", szbuff);

    FILE *fp = fopen(filename, "ab");
    if(fp)
    {
        fputs(szbuff, fp);
    }
    fclose(fp);

}
void LOG_DEBUG(const char *format, ...)
{
    char filename[128];
    memset(filename, 0, sizeof(filename));
    time_t curTimestamp = time(NULL)+8*3600;
    struct tm *mt = localtime(&curTimestamp);
    sprintf(filename, "%s/%04d%02d%02d.log",log.m_path.c_str(), mt->tm_year + 1900, mt->tm_mon + 1, mt->tm_mday);

    int cnt = 0;
    char szbuff[512];
    memset(szbuff, 0, sizeof(szbuff));
    cnt += sprintf(szbuff, "[%04d-%02d-%02d %02d:%02d:%02d][debug] ", mt->tm_year + 1900, mt->tm_mon + 1, mt->tm_mday, mt->tm_hour, mt->tm_min, mt->tm_sec);

    va_list args;
    va_start(args, format);
    cnt += vsprintf(&szbuff[cnt], format, args);
    va_end(args);

    szbuff[cnt] = '\n';
    printf("%s", szbuff);

    FILE *fp = fopen(filename, "ab");
    if(fp)
    {
        fputs(szbuff, fp);
    }
    fclose(fp);
}
void LOG_INFO(const char *format, ...)
{
    char filename[128];
    memset(filename, 0, sizeof(filename));
    time_t curTimestamp = time(NULL)+8*3600;
    struct tm *mt = localtime(&curTimestamp);
    sprintf(filename, "%s/%04d%02d%02d.log",log.m_path.c_str(), mt->tm_year + 1900, mt->tm_mon + 1, mt->tm_mday);

    int cnt = 0;
    char szbuff[512];
    memset(szbuff, 0, sizeof(szbuff));
    cnt += sprintf(szbuff, "[%04d-%02d-%02d %02d:%02d:%02d][info] ", mt->tm_year + 1900, mt->tm_mon + 1, mt->tm_mday, mt->tm_hour, mt->tm_min, mt->tm_sec);

    va_list args;
    va_start(args, format);
    cnt += vsprintf(&szbuff[cnt], format, args);
    va_end(args);

    szbuff[cnt] = '\n';
    printf("%s", szbuff);

    FILE *fp = fopen(filename, "ab");
    if(fp)
    {
        fputs(szbuff, fp);
    }
    fclose(fp);
}
void LOG_WARN(const char *format, ...)
{
    char filename[128];
    memset(filename, 0, sizeof(filename));
    time_t curTimestamp = time(NULL)+8*3600;
    struct tm *mt = localtime(&curTimestamp);
    sprintf(filename, "%s/%04d%02d%02d.log",log.m_path.c_str(), mt->tm_year + 1900, mt->tm_mon + 1, mt->tm_mday);

    int cnt = 0;
    char szbuff[512];
    memset(szbuff, 0, sizeof(szbuff));
    cnt += sprintf(szbuff, "[%04d-%02d-%02d %02d:%02d:%02d][warn] ", mt->tm_year + 1900, mt->tm_mon + 1, mt->tm_mday, mt->tm_hour, mt->tm_min, mt->tm_sec);

    va_list args;
    va_start(args, format);
    cnt += vsprintf(&szbuff[cnt], format, args);
    va_end(args);

    szbuff[cnt] = '\n';
    printf("%s", szbuff);

    FILE *fp = fopen(filename, "ab");
    if(fp)
    {
        fputs(szbuff, fp);
    }
    fclose(fp);
}
void LOG_ERROR(const char *format, ...)
{
    char filename[128];
    memset(filename, 0, sizeof(filename));
    time_t curTimestamp = time(NULL)+8*3600;
    struct tm *mt = localtime(&curTimestamp);
    sprintf(filename, "%s/%04d%02d%02d.log",log.m_path.c_str(), mt->tm_year + 1900, mt->tm_mon + 1, mt->tm_mday);

    int cnt = 0;
    char szbuff[512];
    memset(szbuff, 0, sizeof(szbuff));
    cnt += sprintf(szbuff, "[%04d-%02d-%02d %02d:%02d:%02d][error] ", mt->tm_year + 1900, mt->tm_mon + 1, mt->tm_mday, mt->tm_hour, mt->tm_min, mt->tm_sec);

    va_list args;
    va_start(args, format);
    cnt += vsprintf(&szbuff[cnt], format, args);
    va_end(args);

    szbuff[cnt] = '\n';
    printf("%s", szbuff);

    FILE *fp = fopen(filename, "ab");
    if(fp)
    {
        fputs(szbuff, fp);
    }
    fclose(fp);
}
void LOG_FATAL(const char *format, ...)
{
    char filename[128];
    memset(filename, 0, sizeof(filename));
    time_t curTimestamp = time(NULL)+8*3600;
    struct tm *mt = localtime(&curTimestamp);
    sprintf(filename, "%s/%04d%02d%02d.log",log.m_path.c_str(), mt->tm_year + 1900, mt->tm_mon + 1, mt->tm_mday);

    int cnt = 0;
    char szbuff[512];
    memset(szbuff, 0, sizeof(szbuff));
    cnt += sprintf(szbuff, "[%04d-%02d-%02d %02d:%02d:%02d][fatal] ", mt->tm_year + 1900, mt->tm_mon + 1, mt->tm_mday, mt->tm_hour, mt->tm_min, mt->tm_sec);

    va_list args;
    va_start(args, format);
    cnt += vsprintf(&szbuff[cnt], format, args);
    va_end(args);

    szbuff[cnt] = '\n';
    printf("%s", szbuff);

    FILE *fp = fopen(filename, "ab");
    if(fp)
    {
        fputs(szbuff, fp);
    }
    fclose(fp);
}

void ReadConfig(std::string config, std::string group, std::string key, std::string& value)
{
    log.ReadConfig(config, group, key, value);
}
void WriteConfig(std::string config, std::string group, std::string key, std::string value)
{
    log.WriteConfig(config, group, key, value);
}
