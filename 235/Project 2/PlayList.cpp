#include <iostream>

#include "PlayList.h"

// default constructor
PlayList::PlayList() {

}

// Parametrized Constructor that starts playlist with given song
PlayList::PlayList(const Song& a_song) {
	addSong(a_song);
}

// return number of songs currently in playlist
int PlayList::getNumberOfSongs() const {
	return playlist_.getCurrentSize();
}

// returns if playlist is empty
bool PlayList::isEmpty() const {
	return playlist_.isEmpty();
}

// returns a bool value if song has been successfully added
bool PlayList::addSong(const Song& new_song) {
	return playlist_.add(new_song);
}

// returns a bool value if song has been successfully removed
bool PlayList::removeSong(const Song& a_song) {
	return playlist_.remove(a_song);
}

// clears playlist of all songs
void PlayList::clearPlayList() {
	playlist_.clear();
}

// couts song information in specifc order
// * Title : title * Author : author * Album : album *
void PlayList::displayPlayList() const {
	std::vector<Song> list = playlist_.toVector();

	for (int i = 0; i < playlist_.getCurrentSize(); i++) {
		std::cout << "* Title: " << list[i].getTitle()
					<< " * Author: " << list[i].getAuthor()
					<< " * Album: " << list[i].getAlbum() << " *" << "\n";
	}

	std::cout << "End of playlist\n";
}
