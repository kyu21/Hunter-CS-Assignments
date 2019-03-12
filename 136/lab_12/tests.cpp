#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include "def.h"
#include "doctest.h"
using namespace std;

TEST_CASE("B") {
    CHECK(sumRange(1,100) == 5050);
    CHECK(sumRange(0,0) == 0);
    CHECK(sumRange(-1,1) == 0);
}

TEST_CASE("C") {
    int size = 5;
    int *arr = new int[size];
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 1;
    arr[3] = 1;
    arr[4] = 1;
    CHECK(sumArray(arr, size) == 5);

    arr[0] = 0;
    arr[1] = 0;
    arr[2] = 0;
    arr[3] = 0;
    arr[4] = 0;
    CHECK(sumArray(arr, size) == 0);
    delete[] arr;
}

TEST_CASE("D") {
    CHECK(isAlphanumeric("Abcd1234xyz") == true);
    CHECK(isAlphanumeric("KLMN 8-7-6") == false);
}

TEST_CASE("E") {
    CHECK(nestedParens("((()))") == true);
    CHECK(nestedParens("") == true);

    CHECK(nestedParens("(((") == false);
    CHECK(nestedParens("(()") == false);
    CHECK(nestedParens("a(b)c") == false);
}

TEST_CASE("F") {
    int prices [] = {10, 15, 12, 18, 19};
    CHECK(divisible(prices, 5) == true);

    int prices2 [] = {1};
    CHECK(divisible(prices, 1) == false);
}