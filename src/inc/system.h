/*
  获取系统变量, 没有缓存变量, 每次函数调用都直接读取系统信息
*/
#include <string>
#include <vector>

class System{
public:
    System();
    ~System();
    
    void setIdleTime(const size_t idle);

    const size_t getIdleTime() const;

    void setTotalTime(const size_t total);
    const size_t getTotalTime() const;

    // get current ip address 
    std::string ip();

    // get current cpu tempture
    // oled的屏幕太小 没地方展示温度了
    std::string temperature();

    // get sd card usage
    float storage();

    // get ram usage
    float memory();

    // get cpu usage
    bool cpu(size_t& idle, size_t& total);
private:
    size_t pidle_time, ptotal_time;
    std::vector<size_t> getCurrentCpuTime();
};
