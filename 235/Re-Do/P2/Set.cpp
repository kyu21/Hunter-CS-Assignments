template<class ItemType>
Set<ItemType>::Set() {
	item_count_ = 0;
	max_items_ = DEFAULT_SET_SIZE;
}

template<class ItemType>
int Set<ItemType>::getCurrentSize() const {
	return item_count_;
}

template<class ItemType>
bool Set<ItemType>::isEmpty() const {
	return (item_count_ == 0);
}

template<class ItemType>
bool Set<ItemType>::add(const ItemType& newEntry) {
	if (item_count_ == max_items_ || contains(newEntry)) {
		return false;
	}
	else {
		items_[item_count_] = newEntry;
		item_count_++;

		return true;
	}
}

template<class ItemType>
bool Set<ItemType>::remove(const ItemType& anEntry) {
	if (item_count_ == 0) {
		return false;
	}
	else {
		items_[getIndexOf(anEntry)] = items_[item_count_ - 1];
		item_count_--;

		return true;
	}
}

template<class ItemType>
void Set<ItemType>::clear() {
	item_count_ = 0;
}

template<class ItemType>
bool Set<ItemType>::contains(const ItemType& anEntry) const {
	return getIndexOf(anEntry) != -1;
}

template<class ItemType>
std::vector<ItemType> Set<ItemType>::toVector() const {
	return std::vector<ItemType>(std::begin(items_), std::begin(items_) + max_items_);
}

template<class ItemType>
int Set<ItemType>::getIndexOf(const ItemType& target) const {
	for (auto i = 0; i < item_count_; ++i) {
		if (target == items_[i]) {
			return i;
		}
	}

	return -1;
}