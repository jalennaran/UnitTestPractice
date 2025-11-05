/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

// Tests for count_leading_characters function
TEST(PasswordTest, empty_string)
{
	Password my_password;
	int actual = my_password.count_leading_characters("");
	ASSERT_EQ(0, actual);
}

TEST(PasswordTest, multiple_same_characters)
{
	Password my_password;
	int actual = my_password.count_leading_characters("ZZZZ");
	ASSERT_EQ(4, actual);
}

TEST(PasswordTest, two_same_then_different)
{
	Password my_password;
	int actual = my_password.count_leading_characters("AAB");
	ASSERT_EQ(2, actual);
}

TEST(PasswordTest, all_different_characters)
{
	Password my_password;
	int actual = my_password.count_leading_characters("ABCD");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, case_sensitive_lowercase)
{
	Password my_password;
	int actual = my_password.count_leading_characters("aaAAA");
	ASSERT_EQ(2, actual);
}

TEST(PasswordTest, case_sensitive_uppercase)
{
	Password my_password;
	int actual = my_password.count_leading_characters("ZZzZZ");
	ASSERT_EQ(2, actual);
}

TEST(PasswordTest, numbers_repeated)
{
	Password my_password;
	int actual = my_password.count_leading_characters("333abc");
	ASSERT_EQ(3, actual);
}

TEST(PasswordTest, special_characters_repeated)
{
	Password my_password;
	int actual = my_password.count_leading_characters("!!!Hello");
	ASSERT_EQ(3, actual);
}

TEST(PasswordTest, space_character_repeated)
{
	Password my_password;
	int actual = my_password.count_leading_characters("   test");
	ASSERT_EQ(3, actual);
}

TEST(PasswordTest, long_string_all_same)
{
	Password my_password;
	int actual = my_password.count_leading_characters("aaaaaaaaaa");
	ASSERT_EQ(10, actual);
}

// Tests for has_mixed_case function
TEST(PasswordTest, mixed_case_simple)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("Password");
	ASSERT_TRUE(actual);
}

TEST(PasswordTest, only_uppercase)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("PASSWORD");
	ASSERT_FALSE(actual);
}

TEST(PasswordTest, only_lowercase)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("password");
	ASSERT_FALSE(actual);
}

TEST(PasswordTest, mixed_case_empty_string)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("");
	ASSERT_FALSE(actual);
}

TEST(PasswordTest, mixed_case_single_upper)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("A");
	ASSERT_FALSE(actual);
}

TEST(PasswordTest, mixed_case_single_lower)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("a");
	ASSERT_FALSE(actual);
}

TEST(PasswordTest, mixed_case_with_numbers)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("Pass123");
	ASSERT_TRUE(actual);
}

TEST(PasswordTest, mixed_case_with_special_chars)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("P@ssw0rd!");
	ASSERT_TRUE(actual);
}

TEST(PasswordTest, only_numbers)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("12345");
	ASSERT_FALSE(actual);
}

TEST(PasswordTest, only_special_characters)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("!@#$%");
	ASSERT_FALSE(actual);
}

TEST(PasswordTest, mixed_case_numbers_and_symbols_only)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("123!@#");
	ASSERT_FALSE(actual);
}

TEST(PasswordTest, one_upper_one_lower)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("Aa");
	ASSERT_TRUE(actual);
}

TEST(PasswordTest, lower_at_start_upper_at_end)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("aZ");
	ASSERT_TRUE(actual);
}

TEST(PasswordTest, mixed_case_spaces_between)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("Pass Word");
	ASSERT_TRUE(actual);
}
