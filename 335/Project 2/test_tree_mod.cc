// Kun Yu
// Main file for Part2(c) of Homework 2.

#include "avl_tree.h"
#include "SequenceMap.h"
#include <fstream>
#include <iostream>
#include <string>
#include <math.h>
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
}

// Calculates the values assignment asks for
// Haves a flag for using the same function for part 2 and 6
template<typename TreeType>
void CalculateValues(TreeType &a_tree, bool removedSeqFlag) {
  int node_count = a_tree.numberOfNodes();
  float average_depth = (float) a_tree.internalPathLength() / node_count;
  float log_ratio = average_depth / (log2(node_count));

  if (!(removedSeqFlag)) {
    cout << "2: " << node_count << endl;
    cout << "3a: " << average_depth << endl;
    cout << "3b: " << log_ratio << endl;
  }
  else {
    cout << "6a: " << node_count << endl;
    cout << "6b: " << average_depth << endl;
    cout << "6c: " << log_ratio << endl;
  }
}

// Queries Database again but this time keeps track of number of times functions are called
template<typename TreeType>
void QueryAndCount(const string &seq_filename, TreeType &a_tree) {
  int execution_counter = 0; // Number of queries
  int execution_calls = 0; // Number of recursive calls
  int sequences_found = 0; // Number of sequences found

  string seq_line;
  ifstream seq_file;
  seq_file.open(seq_filename);
  if (seq_file.fail()) {
    cout << "Unable to open file\n";
    exit(1);
  }

  while (getline(seq_file, seq_line)) {
    execution_counter++;

    SequenceMap seq_map(seq_line, "");
    if (a_tree.contains(seq_map, execution_calls)) {
      sequences_found++;
    }
  }
  
  seq_file.close();
  cout << "4a: " << sequences_found << endl;
  cout << "4b: " << (float) execution_calls / execution_counter << endl;
}

// Queries every other sequence in database and removes them
// Keeps track of number of times functions are called
template<typename TreeType>
void RemoveSequences(const string &seq_filename, TreeType &a_tree) {
  ifstream seq_file;
  string seq_line;

  int num_sequences_removed = 0; // Number of sequences removed
  int recursion_calls = 0; // Number of recursive calls
  int remove_calls = 0; // Number of queries

  seq_file.open(seq_filename);
  if (seq_file.fail()) {
    cout << "Unable to open file\n";
    exit(1);
  }

  while(getline(seq_file, seq_line)) {
    remove_calls++;

    bool removed_flag = false;

    SequenceMap seq_map(seq_line, "");
    a_tree.remove(seq_map, recursion_calls, removed_flag);
    if (removed_flag) {
      num_sequences_removed++;
    }

    // skips every other line
    getline(seq_file, seq_line);
  }

  seq_file.close();
  cout << "5a: " << num_sequences_removed << endl;
  cout << "5b: " << (float) recursion_calls / remove_calls << endl;
}


// @db_filename: an input database filename.
// @seq_filename: an input sequences filename.
// @a_tree: an input tree of the type TreeType. It is assumed to be
//  empty.
template <typename TreeType>
void TestTree(const string &db_filename, const string &seq_filename, TreeType &a_tree) {
  // Code for running Part2(b) 
  QueryTree(db_filename, a_tree); 
  CalculateValues(a_tree, false);
  QueryAndCount(seq_filename, a_tree);
  RemoveSequences(seq_filename, a_tree);
  CalculateValues(a_tree, true);
}

}  // namespace

int
main(int argc, char **argv) {
    if (argc != 3) {
    cout << "Usage: " << argv[0] << " <databasefilename> <queryfilename>" << endl;
    return 0;
    }
    const string db_filename(argv[1]);
    const string seq_filename(argv[2]);
    cout << "Input file is " << db_filename << ", and sequences file is " << seq_filename << endl;
    // Note that you will replace AvlTree<int> with AvlTree<SequenceMap>
    AvlTree<SequenceMap> a_tree;
    TestTree(db_filename, seq_filename, a_tree);

    return 0;
}
