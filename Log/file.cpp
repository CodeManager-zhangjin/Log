#include <sys/types.h>
#include <sys/stat.h>
#include <cstring>
#include "file.h"

CFile::CFile()
{

}
CFile::~CFile()
{

}

//创建文件夹
int CFile::Mkdir(std::string pathdir)
{
    std::string dir;
    for(unsigned int i = 0; i <= pathdir.length(); i++){
        if(pathdir[i] == '/' || pathdir.length() == i){
            dir = pathdir.substr(0, i);
            printf("%s\n", dir.c_str());
            if(-1 == _mkdir(dir)) return -1;
        }
    }
    return 0;
}
//删除文件夹
int CFile::Rmdir(std::string dir)
{
    //检查目录是否存在
    if(0 == access(dir.c_str(), 0)){
        //删除目录
        if(0 != rmdir(dir.c_str())){
            printf("rmdir %s failed.\n", dir.c_str());
            return -1;
        }
    }
    return 0;
}

//创建文件
int CFile::Create(std::string filename)
{
    if(0 != access(filename.c_str(), 0))
    {
        FILE *fp = fopen(filename.c_str(), "at+");
        if(fp == NULL){
            printf("create %s failed.\n", filename.c_str());
            return -1;
        }
        fclose(fp);
    }
    return 0;
}
//删除文件
int CFile::Delete(std::string filename)
{
    //判断文件是否存在
    if(0 == access(filename.c_str(), 0)){
        if(remove(filename.c_str())){
            printf("remove %s failed.\n", filename.c_str());
            return -1;
        }else{
            printf("remove %s success.\n", filename.c_str());
            return 0;
        }
    }
    return 0;
}
//重命名文件
int CFile::Rename(std::string filename, std::string newname)
{
    if(rename(filename.c_str(), newname.c_str())){
        printf("rename %s failed.\n", filename.c_str());
        return -1;
    }
    return 0;
}

//
int CFile::_mkdir(std::string dir)
{
    //检查目录是否存在
    if(-1 == access(dir.c_str(), 0)){
        //创建目录
        if(0 != mkdir(dir.c_str(), 0777)){
            printf("mkdir %s failed.\n", dir.c_str());
            return -1;
        }
    }
    return 0;
}
