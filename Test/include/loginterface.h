#ifndef LOGINTERFACE_H
#define LOGINTERFACE_H
#include <iostream>
#include <cstdio>

/* 日志级别
 * debug : 调试输出信息，级别最低
 * info  : 重要输出信息，反馈系统当前运行状态
 * warn  : 警告输出信息，可修复系统可继续运行下去
 * error : 错误输出信息，可修复性但无法确定系统会正常工作下去
 * fatal : 严重输出信息，无法修复系统继续运行后果严重
 */
enum log_levels
{
    debug,
    info,
    warn,
    error,
    fatal
};

/* 日志格式
 * 格式1.[日期时间][日志级别][代码位置][日志内容]
 */
void LOG(log_levels level, const char *format, ...);
void LOG_DEBUG(const char *format, ...);
void LOG_INFO(const char *format, ...);
void LOG_WARN(const char *format, ...);
void LOG_ERROR(const char *format, ...);
void LOG_FATAL(const char *format, ...);

/* 读写配置
 * config: 文件路径名
 * group: 组名称
 * key->value: 键值对
 */
void ReadConfig(std::string config, std::string group, std::string key, std::string& value);
void WriteConfig(std::string config, std::string group, std::string key, std::string value);

/* 日志配置
 *
 **/
#endif // LOGINTERFACE_H
