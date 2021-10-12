#include <ifaddrs.h>
#include <arpa/inet.h>
#include "system.h"

// constructor
system::system(){}

// destructor
system::~system(){}

std::string system::cpu(){
    return "";
}

std::string system::ip(){
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

std::string system::memory(){
    return "";
}

std::string system::storage(){
    return "";
}

std::string system::temperature(){
    return "";
}