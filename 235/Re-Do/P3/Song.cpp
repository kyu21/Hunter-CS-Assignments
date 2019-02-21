#include "Song.h"

// default constructor
Song::Song() {
	
}

// parameterized constructor that initiates song with title, author and album
Song::Song(const std::string& title, const std::string& author, const std::string& album) {
	title_ = title;
	author_ = author;
	album_ = album;
}

// setter for title
void Song::setTitle(std::string title) {
	title_ = title;
}

// setter for author
void Song::setAuthor(std::string author) {
	author_ = author;
}

// setter for album
void Song::setAlbum(std::string album) {
	album_ = album;
}

// getter for title
std::string Song::getTitle() const {
	return title_;
}

// getter for author
std::string Song::getAuthor() const {
	return author_;
}

// getter for album
std::string Song::getAlbum() const {
	return album_;
}

// defines what equality means for songs
bool operator==(const Song& lhs, const Song& rhs) {
	return lhs.title_ == rhs.title_ && lhs.author_ == rhs.author_ && lhs.album_ == rhs.album_;
}
