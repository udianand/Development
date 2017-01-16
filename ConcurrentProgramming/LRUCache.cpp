#include "stdafx.h"
#include <iostream>
#include <unordered_map>
#include "thread"
#include "mutex"

class LRUCache
{

	std::mutex mu;

private:
	int cacheSize;
	std::unordered_map<int, std::pair<int, std::list<int>::iterator>> cache;
	std::list<int> lru;
	void update(std::unordered_map<int, std::pair<int, std::list<int>::iterator>>::iterator &it);

public:
	void setSize(int size);
	int get(int key);
	void set(int key, int value);
};

void LRUCache::setSize(int size)
{
	std::lock_guard <std::mutex> locker(mu);
	cacheSize = size;
}

int LRUCache::get(int key)
{
	std::lock_guard <std::mutex> locker(mu);
	auto item = cache.find(key);

	if (item == cache.end())
	{
		return -1;
	}

	update(item);

	return item->second.first;
}

void LRUCache::set(int key, int value)
{
	std::lock_guard <std::mutex> locker(mu);

	auto item = cache.find(key);

	if (item != cache.end())
	{
		update(item);
		cache[key] = { value, lru.begin() };
		return;
	}

	if (cache.size() == cacheSize)
	{
		cache.erase(lru.back());
		lru.pop_back();
	}

	lru.push_front(key);
	cache.insert({ key,{ value, lru.begin() } });
}

void LRUCache::update(std::unordered_map<int, std::pair<int, std::list<int>::iterator>>::iterator &it)
{
	lru.erase(it->second.second);
	lru.push_front(it->first);
	it->second.second = lru.begin();
}

void function2(LRUCache *lruCache)
{
	lruCache->set(5, 5);
	lruCache->set(6, 6);
	lruCache->set(1, 1);

	std::cout << "F2::Successful Execution: " << lruCache->get(4) << std::endl;

	lruCache->set(8, 8);

	std::cout << "F2::Successful Execution: " << lruCache->get(1) << std::endl;
}

void function1(LRUCache *lruCache)
{
	lruCache->set(1, 1);
	lruCache->set(2, 2);
	lruCache->set(3, 3);

	std::cout << "F1::Successful Execution: " << lruCache->get(3) << std::endl;

	lruCache->set(4, 4);

	std::cout << "F1::Successful Execution: " << lruCache->get(2) << std::endl;
}

int main() {

	LRUCache *lruCache = new LRUCache();
	lruCache->setSize(2);

	std::thread t1(function1, lruCache);
	t1.join();

	std::thread t2(function2, lruCache);
	t2.join();

	return 0;
}
