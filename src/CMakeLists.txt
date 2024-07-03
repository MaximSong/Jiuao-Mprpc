#aux_source_directory(. SRC_LIST)
set(SRC_LIST mprpcapplication.cc mprpcconfig.cc rpcheader.pb.cc rpcprovider.cc mprpcchannel.cc mprpccontroller.cc logger.cc zookeeperutil.cc) 
add_library(mprpc ${SRC_LIST})
target_link_libraries(mprpc zookeeper_mt muduo_net muduo_base pthread )  