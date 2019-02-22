#include <iostream>
#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <memory.h>
#include "log.h"
#include "myini.h"


CLog::CLog()
{
    InitLogCfg();
}
CLog::~CLog()
{

}
//初始化配置
void CLog::InitLogCfg()
{
    std::string config = "logconfig.ini";
    std::string group = "log";
    //日志文件路径
    ReadConfig(config, group, "logpath", m_path);
    if(m_path.empty()){
        m_path = "./log";
        WriteConfig(config, group, "logpath", m_path);
    }
    Mkdir(m_path);
    //日志文件存储时长/天
    ReadConfig(config, group, "savedays", m_savedays);
    if(m_savedays.empty()){
        m_savedays = "30";
        WriteConfig(config, group, "savedays", m_savedays);
    }
    //
}
//清理日志
void CLog::ClearLog()
{
    int ndays = atoi(m_savedays.c_str());
    //生成要删除的文件名
    char filename[128];
    memset(filename, 0, sizeof(filename));
    time_t curTimestamp = time(NULL)+8*3600 - ndays*24*3600;
    struct tm *mt = localtime(&curTimestamp);
    sprintf(filename, "%s/%04d%02d%02d.log",m_path.c_str(), mt->tm_year + 1900, mt->tm_mon + 1, mt->tm_mday);
    Delete(filename);
}


void CLog::ReadConfig(std::string config, std::string group, std::string key, std::string& value)
{
    MyINI *p = new MyINI();
    if(p->ReadINI(config))
    {
        value = p->GetValue2(group, key);
    }
    delete p;
}
void CLog::WriteConfig(std::string config, std::string group, std::string key, std::string value)
{
    Create(config.c_str());
    MyINI *p = new MyINI();
    if(p->ReadINI(config))
    {
        p->SetValue(group, key, value);
        p->WriteINI(config);
    }
    delete p;
}
