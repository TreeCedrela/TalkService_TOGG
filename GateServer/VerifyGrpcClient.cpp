#include "VerifyGrpcClient.h"
#include "ConfigMgr.h"

VerifyGrpcClient::VerifyGrpcClient() {
	auto& gcfgmgr = ConfigMgr::Ins();
	std::string host = gcfgmgr["VarifyServer"]["Host"];
	std::string port = gcfgmgr["VarifyServer"]["Port"];
	pool_.reset(new RPCConPoll(5, host, port));
}
