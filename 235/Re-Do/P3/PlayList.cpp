#include <iostream>

#include "PlayList.h"

// default constructor
PlayList::PlayList() {

}

// parameterized constructor
PlayList::PlayList(const Song& a_song) {
	add(a_song);
}

// copy constructor
PlayList::PlayList(const PlayList& a_play_list) {
	tail_ptr_ = getPointerToLastNode();	
}

// destructor
PlayList::~PlayList() {
	unloop();
	clear();
}

bool PlayList::add(const Song& new_song) {
	//make new node to store new song
	Node<Song>* new_ptr = new Node<Song>(new_song);

	//check if list already contains song
	if ((contains(new_song))) {
		return false;
	}
	// if contains song, retain 
	else {
		// Case 1: Empty List - adds song as first element and redirects tail_ptr
		if ( isEmpty()) {
			head_ptr_ = new_ptr;
			tail_ptr_ = head_ptr_;
		}
		// Case 2: Not empty list, adds to end of list
		else {
			// arrow notation because tail_prt_ is a pointer
			// equlivalent to (*tail_ptr_).setNext()
			tail_ptr_->setNext(new_ptr);
			tail_ptr_ = tail_ptr_->getNext();
		}
		item_count_++;
		return true;
	}
}

bool PlayList::remove(const Song& old_song) {
	Node<Song>* prev_ptr = nullptr;
	Node<Song>* node_to_remove_ptr = getPointerTo(old_song, prev_ptr);

	// 2 ways for not being able to remove song
	// empty list or song not in list
	bool can_remove_song = !(isEmpty()) && (node_to_remove_ptr != nullptr);

	if (can_remove_song) {

		// default option, found song
		// redirects previous pointer to next node
		if (prev_ptr != nullptr) {
			prev_ptr->setNext( node_to_remove_ptr->getNext() );
		}
		// case for if song is first item in list
		else {
			head_ptr_ = node_to_remove_ptr->getNext();
		}

		// case for if song is last item in list
		if (node_to_remove_ptr->getNext() == nullptr) {
			tail_ptr_ = nullptr;
		}

		// process for removing dynamically allocated node
		node_to_remove_ptr->setNext(nullptr);
		delete node_to_remove_ptr;
		node_to_remove_ptr = nullptr;

		item_count_--;
	}

	return can_remove_song;
}

void PlayList::loop() {
	tail_ptr_->setNext(head_ptr_);
}

void PlayList::unloop() {
	tail_ptr_->setNext(nullptr);
}

void PlayList::displayPlayList() {
	loop();

	std::vector<Song> list = toVector();

	for (int i = 0; i < getCurrentSize(); i++) {
		std::cout << "* Title: " << list[i].getTitle()
					<< " * Author: " << list[i].getAuthor()
					<< " * Album: " << list[i].getAlbum() << " *" << "\n";
	}

	std::cout << "End of playlist\n";

	unloop();
}

Node<Song>* PlayList::getPointerTo(const Song& target, Node<Song>*& previous_ptr) const {
	Node<Song>* prev_ptr = head_ptr_;
	Node<Song>* curr_ptr = prev_ptr;

	while ( (curr_ptr != nullptr) && !(curr_ptr->getItem() == target) ) {
		prev_ptr = curr_ptr;
		curr_ptr = curr_ptr->getNext();
	}

	previous_ptr = prev_ptr;

	return curr_ptr;
}

Node<Song>* PlayList::getPointerToLastNode() const {
	Node<Song>* curr_ptr = head_ptr_;

	while (curr_ptr->getNext() != nullptr) {
		curr_ptr = curr_ptr->getNext();
	}

	return curr_ptr;
}