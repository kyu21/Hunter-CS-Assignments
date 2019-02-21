#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include "def.h"
#include "doctest.h"
using namespace std;

TEST_CASE("A") {
	Coord3D pointP = {0,0,0};
	CHECK(length(&pointP) == 0.0);

	pointP = {1,0,0};
	CHECK(length(&pointP) == 1.0);

	pointP = {3,4,12};
	CHECK(length(&pointP) == 13.0);
}

TEST_CASE("B") {
    Coord3D pointP = {2, 0, 0};
    Coord3D pointQ = {1, 0, 0};
    CHECK(fartherFromOrigin(&pointP, &pointQ) == &pointP);

    pointP = {3,4,5};
    pointQ = {3,5,5};
	CHECK(fartherFromOrigin(&pointP, &pointQ) == &pointQ);

    pointP = {15,11,12};
    pointQ = {7,15,20};
	CHECK(fartherFromOrigin(&pointP, &pointQ) == &pointQ);
}

TEST_CASE("C") {
    Coord3D pos = {0, 0, 100.0};
    Coord3D vel = {1, -5, 0.2};
    move(&pos, &vel, 5.0);
    CHECK(pos.x == 5.0);

    pos = {1,1,1};
    vel = {0,3,7};
    move(&pos, &vel, 10.0);
    CHECK(pos.z == 71.0);
}