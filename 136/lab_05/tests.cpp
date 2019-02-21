#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include "funcs.h"
#include "doctest.h"
using namespace std;

TEST_CASE("Testing isDivisbleBy") {
	cout << "\nisDivisbleBy\n";
	CHECK(isDivisbleBy(100, 25) == true);
	CHECK(isDivisbleBy(20, 3) == false);
	CHECK(isDivisbleBy(1032, 2) == true);
}

TEST_CASE("Testing isPrime") {
	cout << "\nisPrime\n";
	CHECK(isPrime(2) == true);
	CHECK(isPrime(3) == true);
	CHECK(isPrime(9) == false);
}

TEST_CASE("Testing nextPrime") {
	cout << "\nnextPrime\n";
	CHECK(nextPrime(4) == 5);
	CHECK(nextPrime(10) == 11);
	CHECK(nextPrime(100) == 101);
}

TEST_CASE("Testing countPrimes") {
	cout << "\ncountPrimes\n";
	CHECK(countPrimes(2, 10) == 4);
	CHECK(countPrimes(3, 4) == 1);
	CHECK(countPrimes(10, 20) == 4);
}

TEST_CASE("Testing isTwinPrime") {
	cout << "\nisTwinPrime\n";
	CHECK(isTwinPrime(3) == true);
	CHECK(isTwinPrime(7) == true);
	CHECK(isTwinPrime(37) == false);
}

TEST_CASE("Testing nextTwinPrime") {
	cout << "\nnextTwinPrime\n";
	CHECK(nextTwinPrime(3) == 5);
	CHECK(nextTwinPrime(9) == 11);
	CHECK(nextTwinPrime(19) == 29);	
}

TEST_CASE("Testing largestTwinPrime") {
	cout << "\nlargestTwinPrime\n";
	CHECK(largestTwinPrime(5, 18) == 17);
	CHECK(largestTwinPrime(1, 31) == 31);
	CHECK(largestTwinPrime(14, 16) == -1);
}