// Kun Yu
// Main file for Part2(a) of Homework 2.

#include "avl_tree.h"
#include "SequenceMap.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

namespace {

// @ Param: a line from the database
// Returns enzyme acronym from line
// Modifies db_line to be the part without the enzyme acronym
string GetEnzymeAcronym(string &db_line) {
	// Finds index of first /
	size_t slash_index = db_line.find("/");
	// Substring from start to first / is the enzyme acronym
	string an_enz_acro = db_line.substr(0, slash_index);
	// Discards enzyme acronym since it got parsed
	db_line = db_line.substr(slash_index + 1);
  	return an_enz_acro;
}

// Param : a line from the database, an empty string
// Puts next recognition sequence into empty string
// Modifies db_line to the part without the recongition sequence
bool GetNextRecognitionSequence(string &db_line, string &a_reco_seq) {
	// Finds index of first /
	size_t slash_index = db_line.find("/");

	// cout << db_line << "\t" << slash_index << "\t" << string::npos << endl;
	// Check if a slash was found
	if (slash_index == string::npos) {
		return false;
	}

	a_reco_seq = db_line.substr(0, slash_index);
	db_line = db_line.substr(slash_index + 1);
	return true;
}

// Prompts User Input to get and print all enzymes matching a recongition sequence
template<typename TreeType>
void QueryTreeInput(TreeType &a_tree) {
	string a_reco_seq;
	while(getline(std::cin, a_reco_seq)) {
		SequenceMap a_seq_map {a_reco_seq, ""};
		SequenceMap *enzymes = a_tree.find(a_seq_map);
		if (enzymes == nullptr) {
			cout << "Not Found" << endl;
		}
		else {
			cout << *enzymes << endl;
		}
	}
}

// @db_filename: an input filename.
// @a_tree: an input tree of the type TreeType. It is assumed to be
//  empty.
template <typename TreeType>
void QueryTree(const string &db_filename, TreeType &a_tree) {
	// Code for running Part2(a)
	string db_line;
	ifstream db_file;
	db_file.open(db_filename);

	if (db_file.fail()) {
		cout << "Unable to open file\n";
		exit(1);
	}
	// Ignore first 10 lines of rebase210.txt which arent sequences
	for (int i = 0; i < 10; ++i) {
		getline(db_file, db_line);
	}

	while (getline(db_file, db_line)) {
		string an_enz_acro = GetEnzymeAcronym(db_line);
		string a_reco_seq;

	  while(GetNextRecognitionSequence(db_line, a_reco_seq)) {
			SequenceMap new_sequence_map(a_reco_seq, an_enz_acro);
			a_tree.insert(new_sequence_map);
	  }
	}

	db_file.close();
	QueryTreeInput(a_tree);
}

}  // namespace

int
main(int argc, char **argv) {
	if (argc != 2) {
		cout << "Usage: " << argv[0] << " <databasefilename>" << endl;
		return 0;
  	}
  	const string db_filename(argv[1]);
  	cout << "Input filename is " << db_filename << endl;
  	// Note that you will replace AvlTree<int> with AvlTree<SequenceMap>
  	AvlTree<SequenceMap> a_tree;
  	QueryTree(db_filename, a_tree);
  	return 0;
}
