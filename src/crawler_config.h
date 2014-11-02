/**
 * 爬虫配置文件类
 * 作者：张春阳
 * 创建时间：2014-10-25
 */

#ifndef CRAWLER_CONFIG_H
#define CRAWLER_CONFIG_H

#include <stdio.h>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>


class crawler_config
{
public:
    std::vector<std::pair<std::string,int> > config_index;
    std::string config_file_name;
    std::map<std::string,std::string> config_map;
    int config_map_counts;
    crawler_config();
    crawler_config(const std::string&);
    ~crawler_config();
    bool config_init(const std::string&);
    int config_write(const std::string&,const std::string&);
private:
    std::fstream config_read_file;
    std::fstream config_write_file;
    std::map<std::string,std::string>::iterator config_map_iter;
    int config_generate_map();
    int config_trim(std::string&);
    bool config_is_space(char);
    bool config_is_comment(char);
};

#endif

