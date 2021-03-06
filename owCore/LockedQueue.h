/*
* Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
* Copyright (C) 2005-2008 MaNGOS <http://getmangos.com/>
*
* This program is free software; you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the
* Free Software Foundation; either version 2 of the License, or (at your
* option) any later version.
*
* This program is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
* more details.
*
* You should have received a copy of the GNU General Public License along
* with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include <deque>
#include <mutex>

template <class T, typename StorageType = std::deque<T> >
class LockedQueue
{
public:
	LockedQueue() :
		_canceled(false)
	{ }

	virtual ~LockedQueue()
	{ }

	//! Adds an item to the queue.
	void add(const T& item)
	{
		lock();

		_queue.push_back(item);

		unlock();
	}

	//! Adds items back to front of the queue
	template<class Iterator>
	void readd(Iterator begin, Iterator end)
	{
		std::lock_guard<std::mutex> lock(m_Lock);
		_queue.insert(_queue.begin(), begin, end);
	}

	//! Gets the next result in the queue, if any.
	bool next(T& result)
	{
		std::lock_guard<std::mutex> lock(m_Lock);

		if (_queue.empty())
		{
			return false;
		}

		result = _queue.front();
		_queue.pop_front();

		return true;
	}

	template<class Checker>
	bool next(T& result, Checker& check)
	{
		std::lock_guard<std::mutex> lock(m_Lock);

		if (_queue.empty())
		{
			return false;
		}

		result = _queue.front();
		if (!check.Process(result))
		{
			return false;
		}

		_queue.pop_front();
		return true;
	}

	//! Peeks at the top of the queue. Check if the queue is empty before calling! Remember to unlock after use if autoUnlock == false.
	T& peek(bool autoUnlock = false)
	{
		lock();

		T& result = _queue.front();

		if (autoUnlock)
			unlock();

		return result;
	}

	void lock()
	{
		this->m_Lock.lock();
	}

	void unlock()
	{
		this->m_Lock.unlock();
	}

	void pop_front()
	{
		std::lock_guard<std::mutex> lock(m_Lock);

		_queue.pop_front();
	}

	bool empty()
	{
		std::lock_guard<std::mutex> lock(m_Lock);
		return _queue.empty();
	}

private:
	std::mutex m_Lock;
	StorageType _queue;
};