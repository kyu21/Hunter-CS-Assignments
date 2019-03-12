// Kun Yu
// Represents a sequence of 2-dimensional points
// Implements Big-five functions
// Also overrides +, <<, [] operators

#ifndef CSCI335_HOMEWORK1_POINTS2_H_
#define CSCI335_HOMEWORK1_POINTS2_H_

#include <array>
#include <iostream>
#include <cstddef>
#include <string>
#include <sstream>

namespace teaching_project {
template<typename Object>
class Points2 {
 public:
  // Zero-parameter constructor. 
  // Set size to 0.
  Points2() {
    size_ = 0;
    sequence_ = nullptr;
  }

  // Copy-constructor.
  Points2(const Points2 &rhs) {
    size_ = rhs.size_;
    sequence_ = new std::array<Object, 2> [size_];

    for (size_t i = 0; i < size_; ++i) {
      sequence_[i][0] = rhs.sequence_[i][0];
      sequence_[i][1] = rhs.sequence_[i][1];
    }
  }

  // Copy-assignment.
  Points2& operator=(const Points2 &rhs) {
    Points2 copy = rhs; 
    std::swap(*this, copy);
    return *this;
  }

  // Move-constructor. 
  Points2(Points2 &&rhs) : sequence_{std::move(rhs.sequence_)}, size_{rhs.size_}
    {
      rhs.size_ = 0;
      rhs.sequence_ = nullptr;
    }

  // Move-assignment.
  Points2& operator=(Points2 &&rhs) {
    std::swap(size_, rhs.size_);
    std::swap(sequence_, rhs.sequence_);
    return *this;
  }

  ~Points2() {
    delete[] sequence_;
  }

  // End of big-five.

  // One parameter constructor.
  Points2(const std::array<Object, 2>& item) {
    size_ = 1;
    sequence_ = new std::array<Object, 2>[size_];
    sequence_[0][0] = item[0];
    sequence_[0][1] = item[1];
  }

  // Read a chain from standard input.
  void ReadPoints2() {
    // Part of code included (without error checking).
    std::string input_line;
    std::getline(std::cin, input_line); 
    std::stringstream input_stream(input_line);
    if (input_line.empty()) return;

    // Read size of sequence (an integer).
    // Assumes size of sequence is first int in line and is positive
    int size_of_sequence;
    input_stream >> size_of_sequence;

    // Allocate space for sequence.
    size_ = size_of_sequence;
    sequence_ = new std::array<Object, 2>[size_];
    
    Object token;
    for (int i = 0 ;input_stream >> token; ++i) {
      // Read coordinates.
      // Fill sequence_ here.
      sequence_[i][0] = token;
      input_stream >> token;
      sequence_[i][1] = token;
    }
    
  }

  size_t size() const {
    return size_;
  }

  // @location: an index to a location in the sequence.
  // @returns the point at @location.
  // const version.
  // abort() if out-of-range.
  const std::array<Object, 2>& operator[](size_t location) const { 
    // Checks if location is either too big or negative, abort if true
    if (location >= size_ || location < 0)
      abort();
    return sequence_[location];
  }

 //  @c1: A sequence.
 //  @c2: A second sequence.
 //  @return their sum. If the sequences are not of the same size, append the
 //    result with the remaining part of the larger sequence.
 friend Points2 operator+(const Points2 &c1, const Points2 &c2) {
   size_t c1_size = c1.size_;
   size_t c2_size = c2.size_;
   size_t max_size = std::max(c1_size, c2_size);
   Points2 c3;
   c3.size_ = max_size;
   c3.sequence_ = new std::array<Object, 2>[max_size];
   size_t i = 0;

   // Adds the points in the i-position of the two sequences
   while (i < c1_size && i < c2_size) {
    c3.sequence_[i][0] = c1.sequence_[i][0] + c2.sequence_[i][0];
    c3.sequence_[i][1] = c1.sequence_[i][1] + c2.sequence_[i][1];
    i++;
   }

   // Checks if there are any points leftover, if so, appends to end of new sequence
   if (max_size == c1_size) {
    for (size_t j = i; j < c1_size; ++j) {
      c3.sequence_[j][0] = c1.sequence_[j][0];
      c3.sequence_[j][1] = c1.sequence_[j][1];
    }
   }
   else {
    for (size_t j = i; j < c2_size; ++j) {
      c3.sequence_[j][0] = c2.sequence_[j][0];
      c3.sequence_[j][1] = c2.sequence_[j][1];
    }
   }

   return c3;
 }

 // Overloading the << operator.
 friend std::ostream &operator<<(std::ostream &out, const Points2 &some_points2) {
   // if empty sequence, return empty set of parentheses
   if (some_points2.size_ == 0) {
    return out << "()\n";
   }
   // else print them in pairs seperated by a comma
   for (size_t i = 0; i < some_points2.size_; i++) {
    out << "(" << some_points2.sequence_[i][0] << ", " << some_points2.sequence_[i][1] << ") ";
   }
   return out << "\n";
 }
 
 private:
  // Sequence of points. 
  std::array<Object, 2> *sequence_;
  // Size of sequence.
  size_t size_;

};

}  // namespace teaching_project
#endif // CSCI_335_HOMEWORK1_POINTS2_H_