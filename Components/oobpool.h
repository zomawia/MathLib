#pragma once
#include <iostream>
#include <vector>

template <typename T>
class obpool
{
	// Default capacity for object pool.
	const static size_t DEFAULT_POOL_SIZE = 100;
	size_t counter;
	// Backing array for object pool.
	std::vector<T> pool;
	std::vector<bool> poolValidity;
	//std::vector<size_t> nextList; //given an index, what is the next valid slot?

	//size_t openHead, closedHead;  // the idx of the open and closed slots

	// Returns the index of the first empty slot found.
	// Returns -1 if an empty index cannot be found.
	size_t nextEmpty() {
		// linearly search for the index of an empty slot
		for (size_t i = 0; i < poolValidity.size(); ++i)
		{
			if (poolValidity[i] == false)
			{
				return i;
			}
		}

		// vec[100]
		// size is? 100
		// valid idx range from 0 - 99
		size_t newIdx = pool.size();

		// vec[150]
		// size is? 150
		// valid idx range from 0 - 149
		pool.resize(pool.size() * 1.5);
		poolValidity.resize(poolValidity.size() * 1.5);
		//memset(&poolValidity[newIdx], 0, sizeof(bool) * (newIdx / 2));    // zero out memory to be false

		// returns a value of 100
		return newIdx;
	}

public:
	obpool() {
		counter = 0;
		pool.resize(DEFAULT_POOL_SIZE);
		poolValidity.resize(DEFAULT_POOL_SIZE);

		// setting all values to zero
		for (size_t i = 0; i < DEFAULT_POOL_SIZE; ++i)
		{
			pool.push_back(T());
			poolValidity.push_back(false);
		}
	}

	~obpool() {};

	class handle
	{
		// back-pointer to pool
		obpool * pool;
		size_t index;

	public:
		handle() : pool(NULL) {};
		handle(obpool * poolPtr, size_t poolIdx) : pool(poolPtr), index(poolIdx) {};

		// Returns a reference to the object in the object pool.
		T &value() const { return pool->at(index); }

		// Instructs the object pool to free the slot occupied by this handle's slot.
		void free() { pool->pop(index); }

		// Returns true if the slot that this handle is referring to is occupied.
		// Otherwise, it should return false.
		bool isValid() const { return pool->isValid(index); }

		// Returns the index of the slot pointed to by this handle.
		int getIndex() const { return index; };

		// Moves the handle to the next valid element in the pool
		handle &operator++() {

			for (size_t i = index + 1; i < pool->poolValidity.size(); ++i) {
				if (pool->poolValidity[i]) {
					index = i;
					return *this;
				}
			}
			index = pool->pool.size();
			return *this;

			//index++;
			//while (!isValid()) {
			//	index++;
			//}
			//return handle(pool, index);	
		}

		// Returns a reference to the object in the object pool
		T& operator*() { return pool->at(index); }

		// Returns a const reference to the object in the object pool
		const T& operator*() const { return pool->at(index); }

		// Returns a reference to the object in the object pool
		T& operator->() { return pool->at(index); }

		// Returns a const reference to the object in the object pool
		const T& operator->() const { return pool->at(index); }

		// Returns true they're pointing to the same slot.
		// Otherwise, returns false.
		bool operator==(const handle& other) {
			return other.index == index && other.pool == pool;
		}

		// Returns true they're NOT pointing to the same slot.
		// Otherwise, returns false.
		bool operator!=(const handle& other) {
			return other.index != index || other.pool != pool;
		}

	};

	// Adds the given object to the object pool.
	// Returns a handle with the appropriate information to access the object pool.
	handle push(T cpy) {
		size_t idx = nextEmpty();
		pool[idx] = cpy;
		poolValidity[idx] = true;
		++counter;
		return handle(this, idx);
	}

	void pop(size_t idx) { poolValidity[idx] = false; --counter; }

	// Returns true if the handle
	bool isValid(size_t idx) const
	{		
		return poolValidity[idx];
	}

	// Returns a reference to the object stored in the pool at the given index.
	T & at(size_t idx) {
		//assert(isValid(idx));
		return pool[idx];
	}

	// Returns a const reference to the object stored in the pool at the given index.
	const T& at(size_t idx) const {
		assert(isValid(idx));
		return pool[idx];
	}

	// Returns a handle referring to the first valid slot.
	handle begin() {
		for (size_t i = 0; i < poolValidity.size(); ++i)
			if (poolValidity[i])
				return handle(this, i);
	}

	// Returns a handle referring to the slot at the given index
	handle get(size_t idx) { return handle(this, idx); }

	// Returns a handle referring to the last valid slot.
	handle end() {
		//int temp = 0;
		//for (int i = 0; i < DEFAULT_POOL_SIZE; ++i)
		//	if (isValid(i))
		//		temp = i;
		return handle(this, poolValidity.size());
	}

	int Count() {
		return counter;
	}

};
