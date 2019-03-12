// Miguel Acero
// Main file for Part2(b) of Homework 2.

#include "AvlTree.h"
#include "BinarySearchTree.h"
#include "SequenceMap.h"
// for calculating execution time
#include <ctime>
#include <iostream>
#include <string>
#include <sstream>
#include <math.h> //needed for log 
#include <iomanip>
using namespace std;

namespace {

//first 3 functions from part 2a
// ########################################################
string GetEnzymeAcronym(string &db_line) {
  size_t startIndex = db_line.find("/");
  string enzyme = db_line.substr(0,startIndex);
  db_line = db_line.substr(startIndex+1);
  return enzyme;
}

bool GetNextRecognitionSequence(string &db_line, string &recog_seq) {  
  size_t index = db_line.find("/");
  if (index == string::npos) return false;
  recog_seq = db_line.substr(0, index);
  db_line = db_line.substr(index+1);
  return true;
}

template <typename TreeType>
void QueryTree(const string &db_filename, TreeType &a_tree) {
  string db_line; 
  ifstream inFile;
  inFile.open(db_filename);
  if(inFile.fail()) { exit(1); }
  //the first 10 lines of rebase210.txt is the header, we ignore this.
  for(int i = 0; i < 10; i++) { getline(inFile, db_line); }
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
  // a_tree.printTree();
}
//####################################################

//this function takes advantage of the tree functions created and logs them down.
template<typename TreeType>
void calculateValues(TreeType &a_tree, int a) {
  int node_count = a_tree.numberOfNodes();
  //now we're just using type casting and using the tree function
  float average_depth =  (float)a_tree.internalPathLength()/node_count;
  float LogRatio = average_depth/(log2(node_count));
  if (a == 1) {
    cout << "2: " << node_count << endl;
    cout << "3a: " << setprecision(3) << (float)average_depth << endl;
    cout <<  "3b: " << setprecision(3) << (float)LogRatio << endl;
  }
  else if (a == 2){
    cout << "6a: " << node_count << endl;
    cout << "6b: " << setprecision(2) << (float)average_depth << endl;
    cout <<  "6c: " << setprecision(2) << (float)LogRatio << endl;
  }
}

// counts the number of lines in sequences.txt
template<typename TreeType>
void QueryAndCount(TreeType &a_tree, const string &sequenceFileName) {
  //creating 3 variables to
  int counter = 0, found = 0, calls = 0;
  string recog_seq;
  ifstream inFile;
  inFile.open(sequenceFileName);
  if(inFile.fail() ) exit(1);
  while(getline(inFile, recog_seq)) {
    //counter counts how many times
    counter++;
    SequenceMap seqMap(recog_seq, "");

    //contains tree private func returns true if the sequence map 
    bool n = a_tree.contains(seqMap, calls);
    if(n) found++;
  }
  inFile.close();
  cout << "4a: " << counter << endl;
  cout << "4b: " << (float)calls/counter << endl;
}

// This function takes in sequences.txt and removes from the current Tree, the corresponding sequences
template<typename TreeType>
void RemoveSequences(const string &sequenceFileName, TreeType &a_tree) {
  ifstream inFile;
  string sequence;
  int counter = 0;
  int counter2 = 0;
  int removes = 0;
  // int numNode = a_tree.numberOfNodes();
  inFile.open(sequenceFileName);
  if(inFile.fail()) exit(1);
  while(getline(inFile, sequence)){
    //counter2 represents number of remove calls
    counter2++;
      bool removed = false;
      SequenceMap seqMap(sequence, "");
      //the counter in this remove function is stored as a parameter
      // to record the amount of recursive calls needed to finish this func
      a_tree.remove(seqMap, counter, removed);
      if (removed == true){
        //increments everytime the item is removed
        removes++;
      }
      //skipping every other sequence
      getline(inFile, sequence);
  }
  cout << "5a: " << setprecision(2) << removes << endl;
  cout << "5b: " << setprecision(2) << (float)counter/counter2 << endl;
}

// @db_filename: an input database filename.
// @seq_filename: an input sequences filename.
// @a_tree: an input tree of the type TreeType. It is assumed to be
//  empty.
template <typename TreeType>
void TestTree(const string &db_filename, const string &seq_filename, TreeType &a_tree) {
  // Code for running Part2(b)  
  QueryTree(db_filename, a_tree);
  calculateValues(a_tree, 1);
  QueryAndCount(a_tree, seq_filename);
  RemoveSequences(seq_filename, a_tree);
  calculateValues(a_tree, 2);
}

}  // namespace

int main(int argc, char **argv) {
  // int start = clock();
  if (argc != 4) {
    cout << "Usage: " << argv[0] << " <databasefilename> <queryfilename> <tree-type>" << endl;
    return 0;
  }
  const string db_filename(argv[1]);
  const string seq_filename(argv[2]);
  const string param_tree(argv[3]);
  cout << "Input file is " << db_filename << ", and sequences file is " << seq_filename << endl;
  cout << "Type of tree is " << param_tree << endl;
  if (param_tree == "BST") {
    // Note that you will replace BinarySearchTree<int> with BinarySearchTree<SequenceMap>
    BinarySearchTree<SequenceMap> a_tree;
    TestTree(db_filename, seq_filename, a_tree);
  } else if (param_tree == "AVL") {
    // Note that you will replace AvlTree<int> with AvlTree<SequenceMap>
    AvlTree<SequenceMap> a_tree;
    TestTree(db_filename, seq_filename, a_tree);
  } else {
    cout << "Unknown tree type " << param_tree << " (User should provide BST, or AVL)" << endl;
  }
  // int stop = clock();

  //i just used this to help in understanding which tree structure is faster.
  // cout << "time: " << (stop-start)/double(CLOCKS_PER_SEC)*1000 << endl;
  return 0;
}
