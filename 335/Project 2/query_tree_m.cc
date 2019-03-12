// Kun Yu
// Main file for Part2(a) of Homework 2.

#include "avl_tree.h"
#include "SequenceMap.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

namespace {

/*
  sample string
            AarI/CACCTGCNNNN'NNNN/'NNNNNNNNGCAGGTG//
index 0    [sIndex]

*/

// @param: takes in a database string line, then isolates the acronym
string GetEnzymeAcronym(string &db_line) {
  // indexes from the start ending at the / of the string (enzyme acronym)
  size_t startIndex = db_line.find("/");

  //the acronym starts at the beginning and ends at 
  string enzyme = db_line.substr(0,startIndex);
  db_line = db_line.substr(startIndex+1);

  return enzyme;
}

// @param: takes in next database line, and returns true if theres a recog seq for the while loop.
bool GetNextRecognitionSequence(string &db_line, string &recog_seq) {  
  //find index of "/" again 
  size_t index = db_line.find("/");
  // if the index is the last of the string, the line doesn't have a recognition sequence
  if (index == string::npos) return false;

  //splitting sequence using substring
  recog_seq = db_line.substr(0, index);
  db_line = db_line.substr(index+1);
  return true;
}

template<typename TreeType>
void TestTree(TreeType &a_tree) {
  string recog_seq;
  while(getline(std::cin, recog_seq))  {
    SequenceMap seqmap{recog_seq, ""};
    //find returns a pointer to the sequence map
    SequenceMap *enzymes = a_tree.find(seqmap);
    //if the query is not found, it will return a nullptr
    if(enzymes == nullptr) cout << "Not Found" << endl;
    //taking advantage of sequence map's overloading function
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
  //normal ifstream reading
  string db_line; 
  ifstream inFile;
  inFile.open(db_filename);
  if(inFile.fail()) {
    cout << "Error occured " << endl;
    exit(1);
  }
  //the first 10 lines of rebase210.txt is the header, we ignore this.
  for(int i = 0; i < 10; i++) {
    getline(inFile, db_line);
  }
  while(getline(inFile, db_line)) {
    string enzymeAcronym = GetEnzymeAcronym(db_line);
    string recogSequence;
    // cout << enzymeAcronym << endl;
    while (GetNextRecognitionSequence(db_line, recogSequence)) {
    // cout << db_line << endl << recogSequence;
      SequenceMap seqMap (recogSequence, enzymeAcronym);
      a_tree.insert(seqMap);
    }
  }
  // Code for running Part2(a)
  // You can use public functions of TreeType. For example:
  inFile.close();
  TestTree(a_tree);
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

