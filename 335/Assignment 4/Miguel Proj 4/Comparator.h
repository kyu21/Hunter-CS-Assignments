/*
custom comparator file to compare the distances between each vertex
*/
#ifndef COMPARATOR_H
#define COMPARATOR_H

#include <iostream>

using namespace std;

template<class T>
class Comparator{
	public:
		bool operator()(const T& a, const T& b){
			return (a->distance > b->distance);
		}
};

#endif //COMPARATOR_H