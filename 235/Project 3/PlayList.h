// CSCI 235 Fall 2018 Project 3
// Kun Yu
// 10-17-2018
// Playlist Interface

#pragma once

#include "LinkedSet.h"
#include "Song.h"

class PlayList : public LinkedSet<Song>{
	public:
		PlayList();								// default constructor
		PlayList(const Song& a_song);			// parameterized constructor
		PlayList(const PlayList& a_play_list);	// copy constructor
		~PlayList();							// destructor

		bool add(const Song& new_song) override;
		bool remove(const Song& old_song) override;
		void loop();
		void unloop();
		void displayPlayList();
	private:
    	Node<Song>* tail_ptr_;
    	Node<Song>* getPointerTo(const Song& target, Node<Song>*& previous_ptr) const;
    	Node<Song>* getPointerToLastNode() const;
};
