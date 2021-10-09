/*
  获取系统变量, 没有缓存变量, 每次函数调用都直接读取系统信息
*/
#include <string>

class system
{
public:
    system();
    ~system();
    
    // get current ip address 
    std::string ip();

    // get current cpu tempture
    std::string temperature();

    // get sd card usage
    std::string storage();

    // get ram usage
    std::string memory();

    // get cpu usage
    std::string cpu();
};
