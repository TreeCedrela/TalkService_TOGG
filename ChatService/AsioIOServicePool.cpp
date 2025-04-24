#include "AsioIOServicePool.h"

AsioIOServicePool::AsioIOServicePool(std::size_t size):_ioSerivce(size),
_works(size), _nextIOService(0){
	for (size_t i = 0; i < _works.size(); ++i) {
		_works[i] = std::unique_ptr<Work>(new Work(_ioSerivce[i]));
	}

	for (size_t i = 0; i < _works.size(); ++i) {
		_threads.emplace_back([this, i]() {
			_ioSerivce[i].run();
		});
	}
}

AsioIOServicePool::~AsioIOServicePool() {
	std::cout << "AsioIOServicePool destruct" << std::endl;
}

boost::asio::io_context& AsioIOServicePool::GetIOService()
{
	auto& service = _ioSerivce[_nextIOService++];
	if (_nextIOService == _ioSerivce.size()) {
		_nextIOService = 0;
	}
	return service;
}

void AsioIOServicePool::Stop()
{
	for (auto& work : _works) {
		work->get_io_context().stop();
		work.reset();
	}

	for (auto& t : _threads) {
		t.join();
	}
}

