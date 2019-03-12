#include <iostream>
#include <string>

#include "funcs.h"
#include "labstructs.h"

using std::cout;

int main() {
	// cout << minutesUntil( {13, 40}, {10, 30}  ) << std::endl;
	// cout << printTime(addMinutes({8, 10}, 75)) << std::endl;
	Movie movie1 = {"Back to the Future", COMEDY, 116};
	Movie movie2 = {"Black Panther", ACTION, 134};

	TimeSlot morning = {movie1, {9, 15}};  
	TimeSlot daytime = {movie2, {12, 15}}; 
	TimeSlot evening = {movie2, {16, 45}}; 
	cout << TimeSlotString(morning) << std::endl;;
	return 0;
}