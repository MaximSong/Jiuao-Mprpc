#pragma once
#include "lockqueue.h"
// Mprpc框架提供的日志系统
enum LogLevel
{
    INFO,
    ERROR,
};
class logger
{
public:
    static logger &GetInstance(); // 获取单例对象
    void SetLogLevel(int level);  // 设置日志级别
    void Log(std::string msg);    // 打印日志

private:
    int m_logLevel; // 日志级别
    LockQueue<std::string> m_logQueue;
    logger();
    logger(const logger &) = delete;
    logger(logger &&) = delete;
};
// 日志宏定义
#define M_RPC_LOG_INFO(logmsgFormat, ...)               \
    do                                                  \
    {                                                   \
        logger &logger = logger::GetInstance();         \
        logger.SetLogLevel(INFO);                       \
        char c[1024] = {0};                             \
        snprintf(c, 1024, logmsgFormat, ##__VA_ARGS__); \
        logger.Log(c);                                  \
    } while (0);

#define M_RPC_LOG_ERR(logmsgFormat, ...)                \
    do                                                  \
    {                                                   \
        logger &logger = logger::GetInstance();         \
        logger.SetLogLevel(ERROR);                      \
        char c[1024] = {0};                             \
        snprintf(c, 1024, logmsgFormat, ##__VA_ARGS__); \
        logger.Log(c);                                  \
    } while (0);