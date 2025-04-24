#pragma once
#include "const.h"


class AsioIOServicePool:public Singleton<AsioIOServicePool>
{
	friend Singleton<AsioIOServicePool>;
public:
	using IOService = boost::asio::io_context;
	using Work = boost::asio::io_context::work;
	using WorkPtr = std::unique_ptr<boost::asio::io_context::work>;
	~AsioIOServicePool();
	AsioIOServicePool(const AsioIOServicePool&) = delete;
	AsioIOServicePool& operator=(const AsioIOServicePool&) = delete;
	boost::asio::io_context& GetIOService();
	void Stop();
	 
private:
	AsioIOServicePool(std::size_t size = std::thread::hardware_concurrency());
	std::vector<IOService> _ioSerivce;
	std::vector<WorkPtr> _works;
	std::vector<std::thread> _threads;
	std::size_t _nextIOService;
};

