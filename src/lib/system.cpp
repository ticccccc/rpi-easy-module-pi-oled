#include <fstream>
#include <ifaddrs.h>
#include <arpa/inet.h>
#include <numeric>
#include <filesystem>
#include "system.h"

// constructor
System::System(){
    pidle_time = 0;
    ptotal_time = 0;
}

const size_t System::getIdleTime()const {
    return pidle_time;
}

void System::setIdleTime(const size_t i) {
    pidle_time = i;
}

const size_t System::getTotalTime()const{
    return ptotal_time;
}

void System::setTotalTime(const size_t t) {
    ptotal_time = t;
}

// destructor
System::~System(){}

bool System::cpu(size_t& idle, size_t& total){
    std::vector<size_t> times = getCurrentCpuTime();

    if (times.size() < 4){
        return false;
    }

    idle = times.at(3);

    total = std::accumulate(times.begin(), times.end(), 0);
    return true;
}

std::string System::ip(){
    std::string ipAddress = "NONE";
        struct ifaddrs *interfaces = NULL;
        struct ifaddrs *temp_addr = NULL;
        int success = 0;
        // retrieve the current interfaces - returns 0 on success
        success = getifaddrs(&interfaces);
        if (success == 0) {
            // Loop through linked list of interfaces
            temp_addr = interfaces;
            while(temp_addr != NULL) {
                if(temp_addr->ifa_addr->sa_family == AF_INET) {
                    // Check if interface is en0 which is the wifi connection on the iPhone
                    if(std::string(temp_addr->ifa_name).compare("wlan0") == 0){
                        ipAddress = inet_ntoa(((struct sockaddr_in*)temp_addr->ifa_addr)->sin_addr);
                    }
                }
                temp_addr = temp_addr->ifa_next;
            }
        }
        // Free memory
        freeifaddrs(interfaces);
        return ipAddress;
}

float System::memory(){
    std::ifstream proc_stat("/proc/meminfo");
    
    size_t s, total, avaliable;
    for(std::string name, unit; proc_stat >> name >> s >> unit; ){
        if (name.compare("MemTotal:") == 0) {
            total = s;
        }

        if (name.compare("MemAvailable:") == 0) {
            avaliable = s;
        }
    }

    return 100.0*(total - avaliable)/total;
}

float System::storage(){
    std::filesystem::space_info fs = std::filesystem::space("/");
    return 100.0*(1 - 1.0 * fs.available / fs.capacity);
}

std::string System::temperature(){
    return "";
}

std::vector<size_t> System::getCurrentCpuTime(){
    std::ifstream proc_stat("/proc/stat");
    proc_stat.ignore(5, ' '); // Skip the 'cpu' prefix.
    std::vector<size_t> times;
    for (size_t time; proc_stat >> time; times.push_back(time));
    return times;
}
