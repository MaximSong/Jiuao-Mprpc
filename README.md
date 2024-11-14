# Mprpc Distributed Network Communication Framework

## Project Overview

Mprpc is a high-performance distributed network communication framework that leverages various advanced technologies to achieve high efficiency and reliability. The main features of the project include efficient I/O processing using the muduo network library, RPC parameter serialization and deserialization with Protobuf, an asynchronous logging module, and using Zookeeper as a distributed configuration center.

## Project Repository

[GitHub Repository](https://github.com/MaximSong/Jiuao-Mprpc)

## Key Features and Principles

- **Efficient I/O Processing**: Utilizes the muduo network library, managing connections via TcpServer and binding callback methods to implement efficient I/O processing and event loop mechanisms, enhancing network communication performance.
- **RPC Parameter Serialization and Deserialization**: Uses Protobuf for RPC parameter serialization and deserialization, ensuring efficient and compatible data transmission, simplifying cross-language communication.
- **Asynchronous Logging Module**: Implements an asynchronous logging module with a singleton pattern and dedicated threads to write logs to disk by date, reducing I/O overhead and improving overall framework performance.
- **Distributed Configuration Center**: Uses Zookeeper as a distributed configuration center for service node registration and discovery, ensuring that clients can correctly locate service instances and enhancing system scalability and stability.

## Compilation and Execution
### Project Configuration

Define the `conf` file in the `bin` directory with the following parameters:

- `rpcserverip`
- `rpcserverport`
- `zookeeperip`
- `zookeeperport`

### Compiling the Project

The project provides an automated build script, `autobuild.sh`. You can compile the project using the following command:

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

