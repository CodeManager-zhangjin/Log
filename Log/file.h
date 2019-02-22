#ifndef FILE_H
#define FILE_H
#include <iostream>
#include <cstdio>

class CFile
{
public:
    CFile();
    ~CFile();
    //创建目录
    int Mkdir(std::string dir);
    //删除目录
    int Rmdir(std::string dir);

    //创建文件
    int Create(std::string filename);
    //删除文件
    int Delete(std::string filename);
    //重命名文件
    int Rename(std::string filename, std::string newname);
protected:
    int _mkdir(std::string dir);
};
#endif // FILE_H
