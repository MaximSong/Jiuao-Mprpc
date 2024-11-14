# Mprpc Distributed Network Communication Framework

## Project Overview

Mprpc is a high-performance distributed network communication framework that aims to achieve high efficiency and reliability. The main features of the project include efficient I/O processing using the muduo network library, RPC parameter serialization and deserialization with Protobuf, an asynchronous logging module, and using Zookeeper as a distributed configuration center.

## Project Repository

[GitHub Repository](https://github.com/MaximSong/Jiuao-Mprpc)

## Key Features

- **Efficient I/O Processing**: Utilizes the `muduo` network library, managing connections via TcpServer and binding callback methods to implement efficient I/O processing and event loop mechanisms.
- **RPC Parameter Serialization and Deserialization**: Uses `Protobuf` for RPC parameter serialization and deserialization, ensuring efficient and compatible data transmission, simplifying cross-language communication.
- **Asynchronous Logging Module**: Implements an asynchronous logging module with a `singleton pattern` and `dedicated threads` to write logs to disk by date, reducing I/O overhead and improving overall framework performance.
- **Distributed Configuration Center**: Uses `Zookeeper` as a distributed configuration center for service node registration and discovery, ensuring that clients can correctly locate service instances and enhancing system scalability and stability.

## Compilation and Execution
### Configuration

Define the `conf` file in the `bin` directory with the following parameters:

- `rpcserverip`
- `rpcserverport`
- `zookeeperip`
- `zookeeperport`

### Compilation

The project provides an automated build script, `autobuild.sh`. You can compile the project using the following command:

```bash
./autobuild.sh
```
### Execution
After compilation, the `bin` directory will contain the provider and consumer executable files.
1. Enter the `bin` directory
```bash
cd bin
```
2. Run the `provider` example
```bash
./provider -i test.conf
```
3. Run the`consumer` example
```bash
./consumer -i test.conf
```

