# Mprpc 分布式网络通信框架

## 项目概述

Mprpc 是一个高效的分布式网络通信框架，利用多种先进技术实现高性能和高可靠性。项目的主要特性包括使用 muduo 网络库进行高效的 I/O 处理、利用 Protobuf 进行 RPC 参数的序列化和反序列化、实现异步日志模块，以及采用 Zookeeper 作为分布式配置中心。

## 项目地址

[GitHub Repository](https://github.com/MaximSong/Jiuao-Mprpc)

## 主要功能及原理

- **高效 I/O 处理**：使用 muduo 网络库，通过 TcpServer 管理连接，绑定回调方法，实现高效的 I/O 处理和事件循环机制，提升网络通信性能。
- **RPC 参数序列化与反序列化**：利用 Protobuf 进行 RPC 参数的序列化和反序列化，确保数据传输的高效性和兼容性，简化跨语言通信。
- **异步日志模块**：实现异步日志模块，采用单例模式和独立线程将日志按日期写入磁盘，减少 I/O 开销，提升框架整体性能。
- **分布式配置中心**：采用 Zookeeper 作为分布式配置中心，通过注册和发现服务节点，确保客户端能够正确定位到服务实例，提高系统的可扩展性和稳定性。

## 编译与运行
### 项目配置

在 `bin` 目录下定义 `conf` 文件，包括以下内容：

- `rpcserverip`
- `rpcserverport`
- `zookeeperip`
- `zookeeperport`


### 编译项目

项目提供了自动化编译脚本 `autobuild.sh`。你可以使用以下命令编译项目：

```bash
./autobuild.sh
```
### 项目运行
编译完成后，`bin` 目录下会生成 `provider` 和 `consumer` 可执行文件
1.进入`bin`目录
```bash
cd bin
```
2.运行`provider`示例
```bash
./provider -i test.conf
```
3.运行`consumer`示例
```bash
./consumer -i test.conf
```

