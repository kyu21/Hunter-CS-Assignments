// Name: Miguel Acero

#ifndef SEQUENCE_MAP_H
#define SEQUENCE_MAP_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
/*
Sequence Map Class

*/
class SequenceMap {
	public: 
		//setting default values for the big 5
		SequenceMap() = default;
		~SequenceMap() = default;
		SequenceMap(const SequenceMap &rhs) = default;
		SequenceMap &operator=(const SequenceMap &rhs) = default;
		SequenceMap(SequenceMap &&rhs) = default;
		SequenceMap &operator=(SequenceMap &&rhs) = default;

		// @Param : takes in the enzyme sequence, and a recognition sequence
		SequenceMap(const string &recog_seq, const string &enz_acro) {
			recognition_sequence_ = recog_seq;
			enzyme_acronyms_.push_back(enz_acro);
		}

		bool operator < (const SequenceMap &rhs) const {
			return (recognition_sequence_ < rhs.recognition_sequence_);
		}

		void merge(const SequenceMap &other_sequence) {
			for (auto &x: other_sequence.enzyme_acronyms_){
			            enzyme_acronyms_.push_back(x);
		        }
			// int s = 
			// for (size_t i = 0; i < other_sequence.size(); i++) {
				// enzyme_acronyms_.push_back(other_sequence.enzyme_acronyms_[i]);
			// }
		}

		friend std::ostream &operator << (std::ostream &out, const SequenceMap  &a_map) {
			for (auto &x: a_map.enzyme_acronyms_) {
				out << x << " ";
			}
			return out;
		}

	private:
		string recognition_sequence_;
		vector<string> enzyme_acronyms_;
};
#endif