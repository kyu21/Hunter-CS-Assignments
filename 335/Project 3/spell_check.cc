// Kun Yu
// Spring 2019 CS 335
// Assignment 3 Part 3

#include "double_probing.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string RemovePunctuation(const string &word, bool &hasApostrophe)
{
	string new_word = "";

	for (auto l : word)
	{
		if (l == '\'')
		{
			hasApostrophe = true;
			return word;
		}

		l = tolower(l);
		if (((l >= 'a') && (l <= 'z')) || l == '-')
		{
			new_word += l;
		}
	}

	return new_word;
}

template <typename HashTableType>
void SpellChecker(HashTableType &hash_table, const string &document_filename, const string &dictionary_filename)
{
	// Reset hash table
	hash_table.MakeEmpty();
	hash_table.resetNumCollisions();

	// Open Document
	ifstream document_file;
	string document_word;

	document_file.open(document_filename);
	if (document_file.fail())
	{
		cout << "Unable to open file\n";
		exit(1);
	}

	// Open Dictionary
	ifstream dictionary_file;
	string dictionary_line;

	dictionary_file.open(dictionary_filename);
	if (dictionary_file.fail())
	{
		cout << "Unable to open file\n";
		exit(1);
	}

	// Fills hash table with words from dictionary
	while (getline(dictionary_file, dictionary_line))
	{
		hash_table.Insert(dictionary_line);
	}

	// Parse Document word by word
	while (document_file >> document_word)
	{
		bool hasApostrophe = false;
		string word_to_lookup = RemovePunctuation(document_word, hasApostrophe);

		vector<string> candidates;

		// Skips word if it has an apostrophe
		if (hasApostrophe)
		{
			continue;
		}

		// Skips word if its an empty string (i.e. was a number)
		if (word_to_lookup == "")
		{
			continue;
		}

		// Skips "i" because its a correct word
		if (word_to_lookup == "i")
		{
			continue;
		}

		if (!(hash_table.Contains(word_to_lookup)))
		{
			string changed_word = word_to_lookup;
			// Case 1 - Adding one character in each possible position
			for (size_t i = 0; i < word_to_lookup.length() + 1; ++i)
			{
				// iterating through alphabet
				for (char c = 'a'; c <= 'z'; ++c)
				{
					// inserting character at position i
					changed_word.insert(i, 1, c);

					if (hash_table.Contains(changed_word))
					{
						candidates.push_back(changed_word);
						// cout << word_to_lookup << " -> " << changed_word << " (Case 1)" << endl;
					}
					// reseting word to try again with next character
					changed_word = word_to_lookup;
				}
			}

			// resetting word to check case 2
			changed_word = word_to_lookup;
			// Case 2 - Remove one character from the word
			for (size_t i = 0; i < word_to_lookup.length(); ++i)
			{
				// Removes ith character in word
				changed_word.erase(i, 1);

				if (hash_table.Contains(changed_word))
				{
					candidates.push_back(changed_word);
					// cout << word_to_lookup << " -> " << changed_word << " (Case 2)" << endl;
				}
				// reseting word to try again with next character
				changed_word = word_to_lookup;
			}

			// resetting word to check case 3
			changed_word = word_to_lookup;
			// Case 3 - Swapping adjancent characters in word
			for (size_t i = 0; i < word_to_lookup.length() - 1; ++i)
			{
				// swaps adjancent characters
				swap(changed_word[i], changed_word[i + 1]);

				if (hash_table.Contains(changed_word))
				{
					candidates.push_back(changed_word);
					// cout << word_to_lookup << " -> " << changed_word << " (Case 3)" << endl;
				}
				// reseting word to try again with next pair
				changed_word = word_to_lookup;
			}
		}
		// Remove duplicate alternative spellings
		candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());

		if (candidates.size() > 0)
		{
			// Prints list of candidate corrections
			cout << word_to_lookup << " -> ";
			for (auto word : candidates)
			{
				cout << "(" << word << ") ";
			}
			cout << endl;
		}
	} // end while loop
}

// Sample main for program spell_check
int main(int argc, char **argv)
{
	if (argc != 3)
	{
		cout << "Usage: " << argv[0] << " <document-file> <dictionary-file>" << endl;
		return 0;
	}

	const string document_filename(argv[1]);
	const string dictionary_filename(argv[2]);

	cout << "Input document filename is " << document_filename << endl;
	cout << "Input dictionary filename is " << dictionary_filename << endl;

	// Call functions implementing the assignment requirements.
	HashTableDouble<string> double_probing_table;
	SpellChecker(double_probing_table, document_filename, dictionary_filename);
	return 0;
}
