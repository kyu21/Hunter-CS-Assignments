// CSCI 235 Fall 2018 Project 3
// Kun Yu
// 10-17-2018
// Playlist Implementation

#include <iostream>
#include <cassert>
#include <utility>

#include "PlayList.h"

// default constructor
PlayList::PlayList() : tail_ptr_(nullptr) {}

// Parametrized Constructor that starts playlist with given song
PlayList::PlayList(const Song& a_song) {
	add(a_song);
}

// copy constructor
PlayList::PlayList(const PlayList& a_play_list) : LinkedSet<Song>(a_play_list) {
    tail_ptr_ = getPointerToLastNode();
}

// destructor
PlayList::~PlayList() {
	unloop();
	clear();
}

// loops linked list until finds target or curr_node is nullptr and returns node of target
Node<Song>* PlayList::getPointerTo(const Song& target, Node<Song>*& previous_ptr) const {
	Node<Song>* prev_node = head_ptr_;
	Node<Song>* curr_node = prev_node;

	while (curr_node && !(curr_node->getItem() == target)) {
		prev_node = curr_node;
		curr_node = curr_node->getNext();
	}

	assert(prev_node != nullptr);

	previous_ptr = prev_node;

	return curr_node;
}

// loops linked list until last node
Node<Song>* PlayList::getPointerToLastNode() const {
	Node<Song>* curr_node = head_ptr_;

	while (curr_node->getNext() != nullptr) {
		curr_node = curr_node->getNext();
	}

	return curr_node;
}

// checks if linked list already contains song and is non-empty, then adds song to end of list
bool PlayList::add(const Song& new_song) {
	Node<Song>* new_node = new Node<Song>(new_song);

	if (!(contains(new_song))) {

		if (isEmpty()) {
			head_ptr_ = new_node;
			tail_ptr_ = head_ptr_;
		}
		else {
			tail_ptr_->setNext(new_node);
			tail_ptr_ = tail_ptr_->getNext();
		}

		item_count_++;
	}
	else {
		return false;
	}

	return true;
}


// checks for non-empty list and song exists in list and removes song while redirecting pointers to appropiate node
bool PlayList::remove(const Song& old_song) {
	Node<Song>* prev_node = new Node<Song>();
	Node<Song>* old_node = getPointerTo(old_song, prev_node);

	if (!(isEmpty()) && old_node != nullptr) {

		if (old_node == head_ptr_) {
			head_ptr_ = old_node->getNext();
			delete old_node;
		}
		else {
			prev_node->setNext(old_node->getNext());
			prev_node = prev_node->getNext();
		}

		item_count_--;

		return true;
	}

	return false;
}

// links last node pointer to head node
void PlayList::loop() {
    tail_ptr_->setNext(head_ptr_);
}

// points tail pointer to null pointer, cutting off loop
void PlayList::unloop() {
	tail_ptr_->setNext(nullptr);
}

// couts song information in specifc order
// * Title : title * Author : author * Album : album *
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
