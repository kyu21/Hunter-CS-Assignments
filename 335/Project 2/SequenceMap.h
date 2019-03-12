// Kun Yu
// Part 1 of Homework

#ifndef SEQUENCE_MAP_H
#define SEQUENCE_MAP_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class SequenceMap {
	public:
		SequenceMap() = default; // Default Constructor
		// Default values for Big 5
		~SequenceMap() = default; // Destructor
		SequenceMap(const SequenceMap &rhs) = default; // Copy-constructor
		SequenceMap &operator=(const SequenceMap &rhs) = default; // Copy-assignment
		SequenceMap(SequenceMap &&rhs) = default; // Move-constructor
		SequenceMap &operator=(SequenceMap &&rhs) = default; // Move-assignment

		// @Params: a_req_seq -  a recognition sequence
		//			an_enz_acro - an enzyme sequence
		// Parametrized Constructor
		SequenceMap(const string &a_rec_seq, const string &an_enz_acro) {
			recognition_sequence_ = a_rec_seq;
			enzyme_acronyms_.push_back(an_enz_acro);
		}

		// @ Params: other_sequence - another SeqeuenceMap
		// Assumes recongiztion_sequence_ of both maps are the same
		// Merges other sequence's enzyme acronyms into this object's enzyme acronym
		void merge(const SequenceMap &other_sequence) {
			for (auto &x : other_sequence.enzyme_acronyms_) {
				enzyme_acronyms_.push_back(x);
			}
		}

		// @ Params: rhs - another SeqeuenceMap
		// Compares recongition sequences
		bool operator < (const SequenceMap &rhs) const{
			return (recognition_sequence_ < rhs.recognition_sequence_);
		}

		// Overloaded << operator, to print each enzyme acronym
		friend std::ostream &operator << (std::ostream &out, const SequenceMap &a_map) {
			for (auto &x : a_map.enzyme_acronyms_) {
				out << x << " ";
			}

			return out;
		}

	private:
		string recognition_sequence_;
		vector<string> enzyme_acronyms_;
};
#endif