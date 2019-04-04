// Kun Yu
// Spring CSCI 335
// Assignment 3

#include "linear_probing.h"
#include "quadratic_probing.h"
#include "double_probing.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

template <typename HashTableType>
void TestFunctionForHashTable(HashTableType &hash_table, const string &words_filename, const string &query_filename)
{
	cout << "TestFunctionForHashTables..." << endl;
	cout << "Words filename: " << words_filename << endl;
	cout << "Query filename: " << query_filename << endl;
	hash_table.MakeEmpty();

	// rests num_collisions to 0
	hash_table.resetNumCollisions();

	// opens words file
	ifstream words_file;
	string words_line;

	words_file.open(words_filename);
	if (words_file.fail())
	{
		cout << "Unable to open file\n";
		exit(1);
	}

	// hashes words into hash table
	while (getline(words_file, words_line))
	{
		hash_table.Insert(words_line);
	}

	// Calculate statistics
	cout << "Collisions: " << hash_table.getNumCollisions() << endl;
	cout << "Number of items: " << hash_table.getNumElements() << endl;
	cout << "Size of hash table: " << hash_table.getHashTableSize() << endl;
	cout << "Load factor: " << (hash_table.getNumElements()) / ((double)hash_table.getHashTableSize()) << endl;
	cout << "Avg. number of collisions: " << (hash_table.getNumCollisions()) / ((double)hash_table.getNumElements()) << endl;
	cout << endl;

	// Rests collisions to 0
	hash_table.resetNumCollisions();

	// Opens files for words to query
	ifstream query_file;
	string query_line;

	query_file.open(query_filename);
	if (query_file.fail())
	{
		cout << "Unable to open file\n";
		exit(1);
	}

	// Looks for words in query file
	while (getline(query_file, query_line))
	{
		// +1, because it took num_collisions + 1 more hash to find/not find it
		if (hash_table.Contains(query_line))
		{
			cout << query_line << ": Found in " << hash_table.getNumCollisions() + 1 << " probes" << endl;
			hash_table.resetNumCollisions();
		}
		else
		{
			cout << query_line << ": Not found in " << hash_table.getNumCollisions() + 1 << " probes" << endl;
			hash_table.resetNumCollisions();
		}
	}

	// close files
	words_file.close();
	query_file.close();
}

// Sample main for program create_and_test_hash
int main(int argc, char **argv)
{
	if (argc != 4)
	{
		cout << "Usage: " << argv[0] << " <wordsfilename> <queryfilename> <flag>" << endl;
		return 0;
	}

	const string words_filename(argv[1]);
	const string query_filename(argv[2]);
	const string param_flag(argv[3]);

	if (param_flag == "linear")
	{
		HashTableLinear<string> linear_probing_table;
		TestFunctionForHashTable(linear_probing_table, words_filename, query_filename);
	}
	else if (param_flag == "quadratic")
	{
		HashTable<string> quadratic_probing_table;
		TestFunctionForHashTable(quadratic_probing_table, words_filename, query_filename);
	}
	else if (param_flag == "double")
	{
		HashTableDouble<string> double_probing_table;
		TestFunctionForHashTable(double_probing_table, words_filename, query_filename);
	}
	else
	{
		cout << "Uknown tree type " << param_flag << " (User should provide linear, quadratic, or double)" << endl;
	}
	return 0;
}
