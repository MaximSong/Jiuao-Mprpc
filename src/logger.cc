#include "logger.h"
#include <time.h>
#include <iostream>
logger &logger::GetInstance()
{
    static logger instance;
    return instance;
} // 获取单例对象
logger::logger()
{
    std::thread writeLogTask([&]()
                             {
        for(;;)
        {
            //获取当前的日期，然后取日志信息，写入相应的日志文件
            time_t now = time(nullptr);
            tm* nowtm = localtime(&now);
            char file_name[128] = {0};
            sprintf(file_name, "%d-%d-%d-log.txt", nowtm->tm_year + 1900, nowtm->tm_mon + 1, nowtm->tm_mday);
            FILE* pf = fopen(file_name, "a+");
            if(pf == nullptr)
            {
                std::cout<<"open file "<<file_name<<" error!"<<std::endl;
                return;
            }
            std::string msg = m_logQueue.Pop();
            char time_buf[128] = {0};
            sprintf(time_buf , "%d:%d:%d =>[%s]" , nowtm->tm_hour, nowtm->tm_min, nowtm->tm_sec, (m_logLevel == INFO ? "INFO" : "ERROR"));
            msg.insert(0, time_buf);
            msg.append("\n");
            fputs(msg.c_str(), pf);
            fclose(pf);
        } });
    // 设置分离线程，守护线程
    writeLogTask.detach();
}
void logger::SetLogLevel(int level)
{
    m_logLevel = level;
} // 设置日志级别
void logger::Log(std::string msg)
{
    m_logQueue.Push(msg);
} // 打印日志