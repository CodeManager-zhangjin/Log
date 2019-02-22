#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <cstdio>
#include <stdarg.h>
#include <time.h>
#include <memory.h>
#include "file.h"

class CLog : public CFile
{
public:
    CLog();
    ~CLog();
    //初始化配置
    void InitLogCfg();
    //清理日志
    void ClearLog();

    //读配置 config:文件路径名  group:组名称 key->value:键值对
    void ReadConfig(std::string config, std::string group, std::string key, std::string& value);
    //写配置 config:文件路径名  group:组名称 key->value:键值对
    void WriteConfig(std::string config, std::string group, std::string key, std::string value);

public:
    //日志文件保存路径
    std::string m_path;
    //日志文件保留时间/天
    std::string m_savedays;

};



#endif // LOG_H
