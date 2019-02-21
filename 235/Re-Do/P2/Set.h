#pragma once
#include <vector>

#include "SetInterface.h"

template<class ItemType>
class Set : public SetInterface<ItemType> {
	public:
		Set();
		int getCurrentSize() const;
		bool isEmpty() const;
		bool add(const ItemType& newEntry);
		bool remove(const ItemType& anEntry);
		void clear();
		bool contains(const ItemType& anEntry) const;
		std::vector<ItemType> toVector() const;
	private:
		static const int DEFAULT_SET_SIZE = 4;
		ItemType items_[DEFAULT_SET_SIZE];
		int item_count_;
		int max_items_;
		int getIndexOf(const ItemType& target) const;
};

#include "Set.cpp"