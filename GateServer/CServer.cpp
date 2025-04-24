#include "CServer.h"
#include "HttpConnection.h"
#include "AsioIOServicePool.h"

CServer::CServer(boost::asio::io_context& ioc, unsigned short& port):_ioc(ioc),
_acceptor(ioc, tcp::endpoint(tcp::v4(), port)) {

}

void CServer::Start() {
	auto self = shared_from_this();
	auto& _io_context = AsioIOServicePool::GetInstance()->GetIOService();
	std::shared_ptr<HttpConnection> new_con = std::make_shared<HttpConnection>(_io_context);
	_acceptor.async_accept(new_con->GetSocket(), [self, new_con](beast::error_code ec) {
		try{
			//����ͷ���������ӣ�����������������
			if (ec) {
				self->Start();
				return;
			}
			 
			//���������ӣ����Ҵ���HttpConnection������������
			new_con->Start();

			//��������
			self->Start();
		}
		catch (const std::exception& exp)
		{

		}
	});
}