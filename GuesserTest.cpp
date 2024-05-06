/**
 * Unit Tests for the class
**/

#include <gtest/gtest.h>
#include "Guesser.h"

class GuesserTest : public ::testing::Test
{
	protected:
		GuesserTest(){} //constructor runs before each test
		virtual ~GuesserTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

/* Example test
TEST(GuesserTest, smoke_test)
{
    ASSERT_EQ( 1+1, 2 );
}
*/

TEST(GuesserTest, check_constructor)
{
	Guesser test("Hello");
	bool actual = test.match("Hello");
    ASSERT_EQ( true, actual );
}

TEST(GuesserTest, check_distance_beyond_max)
{
	Guesser test("Hello");
	bool actual = test.match("Hellohello");
    ASSERT_EQ( false, actual );
}

TEST(GuesserTest, check_get_locked_out_after_3)
{
	Guesser test("Hello");
	test.match("Hello!");
	test.match("Helloo");
	test.match("Helloh");
	bool actual = test.match("Hello");
    ASSERT_EQ( false, actual );
}

TEST(GuesserTest, check_works_after_1_wrong)
{
	Guesser test("Hello");
	test.match("Hello!");
	bool actual = test.match("Hello");
    ASSERT_EQ( true, actual );
}

TEST(GuesserTest, check_works_after_2_wrong)
{
	Guesser test("Hello");
	test.match("Hello!");
	test.match("Helloo");
	bool actual = test.match("Hello");
    ASSERT_EQ( true, actual );
}

TEST(GuesserTest, check_works_after_3_wrong)
{
	Guesser test("Hello");
	test.match("Hello!");
	test.match("Helloo");
	test.match("Hellos");
	bool actual = test.match("Hello");
    ASSERT_EQ( false, actual );
}

TEST(GuesserTest, check_get_locked_off_by_more_than_2)
{
	Guesser test("Hello");
	test.match("Hello217");
	bool actual = test.match("Hello");
    ASSERT_EQ( false, actual );
}

TEST(GuesserTest, check_get_remaining)
{
	Guesser test("Hello");
	unsigned int actual = test.remaining();
    ASSERT_EQ( 3, actual );
}

TEST(GuesserTest, check_get_remaining_1)
{
	Guesser test("Hello");
	test.match("Hello21");
	unsigned int actual = test.remaining();
    ASSERT_EQ( 2, actual );
}

TEST(GuesserTest, check_stops_at_32_chars)
{
	Guesser test("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz");
	bool actual = test.match("abcdefghijklmnopqrstuvwxyzabcdef");
    ASSERT_EQ( true, actual );
}