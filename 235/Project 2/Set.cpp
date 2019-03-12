#include "Set.h"

/** Default Constructor
	Initializes item count and max count of set. */
template<class ItemType>
Set<ItemType>::Set(): item_count_(0), max_items_(DEFAULT_SET_SIZE) {

}

/** Gets the current number of entries in this set.
	@return The integer number of entries currently in this set. */
template<class ItemType>
int Set<ItemType>::getCurrentSize() const {
	return item_count_;
}

/** Checks whether this set is empty.
 @return True if the set is empty, or false if not. */
template<class ItemType>
bool Set<ItemType>::isEmpty() const {
	return item_count_ == 0;
}

/** Adds a new entry to this set.
 @post  If successful, newEntry is stored in the set and
		the count of items in the set has increased by 1.
 @param newEntry  The object to be added as a new entry.
 @return  True if addition was successful, or false if not. */
template<class ItemType>
bool Set<ItemType>::add(const ItemType& newEntry) {
	if (item_count_ >= max_items_) {
		return false;
	}
	if (getIndexOf(newEntry) != -1) {
		return false;
	}
	items_[item_count_] = newEntry;
	item_count_++;
	return true;
}

/** Removes a given entry from this set,if possible.
 @post  If successful, anEntry has been removed from the set
		and the count of items in the set has decreased by 1.
 @param anEntry  The entry to be removed.
 @return  True if removal was successful, or false if not. */
template<class ItemType>
bool Set<ItemType>::remove(const ItemType& anEntry) {
	if (item_count_ == 0) {
		return false;
	}
	items_[getIndexOf(anEntry)] = items_[item_count_ - 1];
	item_count_--;
	return true;
}

/** Removes all entries from this set.
 @post  set contains no items, and the count of items is 0. */
template<class ItemType>
void Set<ItemType>::clear() {
	item_count_ = 0;
}

/** Tests whether this set contains a given entry.
 @param anEntry  The entry to locate.
 @return  True if set contains anEntry, or false otherwise. */
template<class ItemType>
bool Set<ItemType>::contains(const ItemType& anEntry) const {
	return getIndexOf(anEntry) != -1;
}

/** Fills a vector with all entries that are in this set.
 @return  A vector containing all the entries in the set. */
template<class ItemType>
std::vector<ItemType> Set<ItemType>::toVector() const {
	return std::vector<ItemType>(std::begin(items_), std::begin(items_) + max_items_);
}

/** Returns index of given entry in this set. -1 if not found.
 @param target  The entry to locate.
 @return  interger index if found, or -1 if not found */
template<class ItemType>
int Set<ItemType>::getIndexOf(const ItemType& target) const {
	for (int i = 0; i < item_count_; i++) {
		if (target == items_[i]) {
			return i;
		}
	}
	return -1;
} // end Set
