#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "funcs.h"
#include "doctest.h"

TEST_CASE("Testing funcs")
{
	SUBCASE("Testing east storage")
	{
		CHECK(east_storage("01/12/2016") == 72.69);
		CHECK(east_storage("03/22/2016") == 71.64);
		CHECK(east_storage("03/22/2015") == 0.0);
		CHECK(east_storage("03/22/2017") == 0.0);
	}

	SUBCASE("Testing maxeast")
	{
		CHECK(maxeast() == 81);
	}

	SUBCASE("Testing mineast")
	{
		CHECK(mineast() == 49.34);
	}

	SUBCASE("Testing compare")
	{
		CHECK(compare("09/13/2016", "09/16/2016") == "09/13/2016 East\n09/14/2016 East\n09/15/2016 Equal\n09/16/2016 West\n");
	}
	SUBCASE("Testing reverse_order")
	{
		CHECK(reverse_order("05/29/2016","06/02/2016") == "06/02/2016 587.66 ft\n06/01/2016 587.81 ft\n05/31/2016 587.93 ft\n05/30/2016 588.02 ft\n05/29/2016 588.17 ft\n");
	}
}