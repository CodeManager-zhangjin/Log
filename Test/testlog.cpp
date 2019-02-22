#include "testlog.h"

void testLog()
{
    LOG(debug, "%s : hello world", __FUNCTION__);
    LOG(info, "%s : hello", __FUNCTION__);
    LOG_WARN("%s : world", __FUNCTION__);
    LOG_ERROR("%s : haha", __FUNCTION__);
}

void testConfig()
{
    std::string config = "setting.ini";
    std::string group = "log";
    std::string value;
    WriteConfig(config, group, "key", "hello");
    LOG_DEBUG("path = %s", value.c_str());
    ReadConfig(config, group, "key", value);
    LOG_DEBUG("path = %s", value.c_str());
    WriteConfig(config, group, "key2", "hello");
    LOG_DEBUG("path = %s", value.c_str());
    ReadConfig(config, group, "key2", value);
    LOG_DEBUG("path = %s", value.c_str());

}


