#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include "funcs.h"
#include "doctest.h"
using namespace std;

TEST_CASE("Testing shiftChar") {
	CHECK(shiftChar('a', 26) == 'a');
	CHECK(shiftChar('a', 0) == 'a');
	CHECK(shiftChar('a', 5) == 'f');
	CHECK(shiftChar('b', -1) == 'a');
}

TEST_CASE("Testing encryptCaesar") {
	CHECK(encryptCaesar("Way to Go!", 5) == "Bfd yt Lt!");
	CHECK(encryptCaesar("Hello, World!", 10) == "Rovvy, Gybvn!");
	CHECK(encryptCaesar("Hello, World!", 26) == "Hello, World!");
}

TEST_CASE("Testing encryptVigenere") {
	CHECK(encryptVigenere("Hello, World!", "cake") == "Jevpq, Wyvnd!");
	CHECK(encryptVigenere("Hello, World!", "hello") == "Oiwwc, Dscwr!");
}

TEST_CASE("Testing decryptCaesar") {
	CHECK(decryptCaesar("Bfd yt Lt!", 5) == "Way to Go!");
	CHECK(decryptCaesar("Rovvy, Gybvn!", 10) == "Hello, World!");
}

TEST_CASE("Testing decryptVigenere") {
	CHECK(decryptVigenere("Jevpq, Wyvnd!", "cake") == "Hello, World!");
	CHECK(decryptVigenere("Oiwwc, Dscwr!", "hello") == "Hello, World!");
}