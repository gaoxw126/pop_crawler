#################################
类名：crawler_config
功能：配置文件的读写
作者：张春阳
创建时间：2014-10-28
#################################
测试项：

⑴ 配置文件的读取
        情景1：正常格式的key = value格式                         OK
        情景2：'#'注释标识行忽略                                 OK
        情景3：空行忽略                                          OK
        情景4：key = value混合'#'注释                            OK
        情景5：中文key和value的读取                              OK
        情景6：非正常格式的key = value
        （key不在首个位置，key/value之间有不定数量的空格)        OK 
        情景7：相同的key值                                       不支持（会存储最后的赋值）

⑵ 配置文件的写入
        情景1：正常写入key和value
        （key和value都不是中文,key在配置文件中不存在）           OK
        情景2：key为中文                                         OK
        情景3：value为中文                                       OK
        情景4：key在配置文件已存在（修改value）                  OK
        情景5：写入注释                                          不支持（未添加该接口）
        情景6：有空行的准确写入                                  OK 
        情景7：配置文件项和注释混合行                            暂不支持（写完文件中文出现乱码）
    
类接口说明项：

⑴ 读配置文件并生成配置config_map：
        方法1：直接调用构造函数，crawler_config(文件名),自动生成config_map成员，可以从中取出想取出的配置项
        方法2：调用无参数的构造行数，使用config_init(文件名)生成config_map成员，可以从中取出想取出的配置项

⑵ 写入配置文件并且可以通过config_map立即使用：
        方法：使用config_write(键，值),会自动在配置文件中生成相应的配置项，并且可以立即使用。

⑶ 获取配置文件中配置项的个数：
        方法；使用成员变量config_map_counts获取配置文件中配置项的个数

⑷ 获取配置文件名：
        方法：使用成员变量config_file_name获取配置文件的名称

⑸ 获取配置文件的索引：
        方法；使用成员变量config_index获取配置文件的索引,索引包括配置文件的缩略信息

接口项：
        方法1（构造函数）：
        crawler_config(string file_name);
        说明：生成配置对象,并进行初始化

        方法2（构造函数）：
        crawler_config();
        说明：生成配置文件对象

        方法3（配置文件对象初始化）：
        bool config_init(string file_name);
        返回值：true成功，false失败
        说明：舒适化配置文件对象

        方法4（写入配置文件）：
        int config_write(string key,string value);
        返回值：0添加配置项，1更新配置项
        说明：写入配置文件

测试项：

        #include <iostream>
        #include "crawler_config.h"
        #include <string>
        #include <vector>
        #include <map>
        using namespace std;

        int main(int argv,char** argc)
        {
            crawler_config m_conf("./server.config");
            
            vector<pair<string,int> >::iterator iter = m_conf.config_index.begin();
            for(;iter != m_conf.config_index.end();iter++)
            {
                cout << iter->first << "\t" << iter->second << endl;
            }
            cout << "+++++++++++++++++++++++++++++++++++++++++++" << endl;

            map<string,string>::iterator iter = m_conf.config_map.begin();
            for(;iter != m_conf.config_map.end();iter++)
            {
                cout << iter->first << "\t" << iter->second << endl;
            }
            cout << "++++++++++++++++++++++++++++++++++++++++++++" << endl;
            
            m_conf.config_write("who","zhangchunyang");
            //m_conf.config_write("love","o");
            //m_conf.config_write("this","爱");
            return 0;
        }
        
#################################
类名：crawler_log
功能：配置文件的读写
作者：张春阳
创建时间：2014-10-26
#################################
      BUG:多个log实例打开的为同一个文件，需要解决 


