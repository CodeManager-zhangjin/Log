#ifndef MYINI_H
#define MYINI_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <map>
#include <vector>

using namespace std;

//INI文件节点存储结构
class ININode
{
public:
    ININode(string root, string key, string value)
    {
        this->root = root;
        this->key = key;
        this->value = value;
    }
    string root;
    string key;
    string value;
};

//键值对结构
class SubNode
{
public:
    void InsertElement(string key, string value)
    {
        sub_node.insert(pair<string, string>(key, value));
    }
    map<string, string> sub_node;
};

//INI文件操作类
class MyINI
{
public:
    MyINI();
    ~MyINI();

    //读取INI文件
    int ReadINI(string path);
    //写入INI文件
    int WriteINI(string path);
    //清空
    void Clear() { map_ini.clear(); }
    //查找配置项值
    string GetValue(string root, string key);
    string GetValue2(string root, string key);
    //遍历打印INI
    void Travel();

    //获取INI文件节点数
    vector<ININode>::size_type GetSize() { return map_ini.size(); }
    //设置根节点和键获取值
    vector<ININode>::size_type SetValue(string root, string key, string value);
private:
    //INI文件内容的存储变量
    map<string, SubNode> map_ini;
};

#endif // MYINI_H
