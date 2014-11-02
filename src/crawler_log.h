/**
 * 爬虫日志类
 * 作者：张春阳
 * 创建日期：2014-10-24
 */
#ifndef CRAWLER_LOG_H
#define CRAWLER_LOG_H

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <fstream>
#include <string>
#include <time.h>
#include <dirent.h>
#include <string.h>
#include <stdarg.h>
#include "crawler_config.h"


extern std::ofstream log_file;
extern std::string current_log_time;
extern int INTERVAL_TIME;//单位为小时
extern std::string LOG_PATH;
extern int switch_time;
static void log_switch_fn(int);
int itoa(int,char*);

class crawler_log
{
public:
    crawler_log();
    ~crawler_log();
    //初始化日志对象
    bool log_init();
    //打印流程日志
    void LOG_WRITE_PROCESS(const std::string&,...);
    //打印错误日志
    void LOG_WRITE_ERROR(const std::string&,...); //打印系统日志
    void LOG_WRITE_SYS(const std::string&,...);
private:
    crawler_config log_config;
    std::string LAST_LOG_TIME;
    enum LEVEL{
        SYS = -2,
        ERROR = -1,
        PROCESS = 0
     } level;
    int log_check();
    void get_current_time(struct tm*&);
};

#endif


