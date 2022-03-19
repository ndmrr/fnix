

#ifndef LOG_H
#define LOG_H

enum LogType
{
    LOG_ERROR = 0x0,
    LOG_OK    = 0X1,
    LOG_INFO  = 0X2
};

void LogOut(enum LogType lt, const char* file, const char* msg);
#define LOG(type, msg) LogOut(type, __FILE__, msg)

#endif 
